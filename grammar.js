/* eslint-disable camelcase */

const list_seq = (rule, separator, trailing_separator = false) =>
  trailing_separator ?
    seq(rule, repeat(seq(separator, rule)), optional(separator)) :
    seq(rule, repeat(seq(separator, rule)));

const comma_sep1 = (rule) => list_seq(rule, ',');

const primitives = [
  'Bool',
  'Int8',
  'Int16',
  'Int32',
  'Int64',
  'UInt8',
  'UInt16',
  'UInt32',
  'UInt64',
  'Float32',
  'Float64',
  'Text',
  'Data',
  'Void',
];

const annotation_targets = [
  '*',
  'annotation',
  'const',
  'enum',
  'enumerant',
  'field',
  'file',
  'group',
  'interface',
  'method',
  'param',
  'struct',
  'union',
];

module.exports = grammar({
  name: 'capnp',

  extras: ($) => [/[\s\f\uFEFF\u2060\u200B]|\\\r?\n/, $.comment],

  word: ($) => $.identifier,

  inline: ($) => [$._single_named_return_type],

  rules: {
    message: ($) => repeat($.statement),

    // @0x9eb32e19f86ee174;
    unique_id: () => token(seq('@', /0[xX][\da-fA-F](_?[\da-fA-F])*/)),

    statement: ($) =>
      choice(
        seq($.unique_id, ';'),
        $.using_directive,
        $.import,
        $.annotation,
        $.lang_declaration,
        $.definition,
      ),

    using_directive: ($) =>
      seq(
        'using',
        choice($.identifier, $.replace_using, $.import_using),
        ';',
      ),
    // using T = Foo.Bar;
    replace_using: ($) =>
      seq(
        $.identifier,
        '=',
        $.identifier,
      ),
    import_using: ($) =>
      choice(
        // using import "bar.capnp".Baz;
        seq(
          'import',
          $.import_path,
          optional(repeat(seq('.', $.identifier))),
        ),
        // using Bar = import "bar.capnp";
        seq(
          $.identifier,
          '=',
          'import',
          $.import_path,
        ),
      ),

    // $import "/capnp/c++.capnp".namespace("capnp");
    import: ($) =>
      seq(
        '$import',
        $.import_path,
        '.namespace',
        '(',
        $.namespace,
        ')',
        ';',
      ),
    namespace: ($) => $.string_literal,

    lang_declaration: ($) =>
      seq(
        '$',
        $.lang_attrs,
        ';',
      ),

    // $Cxx.namespace("capnp::compiler");
    lang_attrs: ($) =>
      seq(
        token.immediate(/[A-Za-z_][A-Za-z0-9._]*/, $.identifier),
        optional(
          seq('(',
            $.namespace,
            ')',
          ),
        ),
      ),

    // annotation myAnnotation(struct) :Int32 $baz(10);
    annotation: ($) =>
      seq(
        'annotation',
        $.identifier,
        optional($.unique_id),
        '(',
        list_seq($.annotation_target, ','),
        ')',
        optional(seq(':', $.field_type)),
        optional($.annotation_call),
        ';',
      ),

    annotation_target: () => choice(...annotation_targets),

    // $Cxx.allowCancellation;
    annotation_call: ($) =>
      seq(
        '$',
        $.identifier,
        repeat(seq('.', alias($.identifier, $.attribute))),
        optional(choice($.annotation_array, $.annotation_namespace_definition)),
      ),

    annotation_namespace_definition: ($) =>
      seq(
        '(',
        $.string_literal,
        ')',
      ),

    annotation_array: ($) =>
      choice(
        seq('[', $.annotation_array, ']'),
        seq('(', $.annotation_array, ')'),
        $.annotation_array_def,
      ),

    annotation_array_def: ($) =>
      choice(
        list_seq(
          seq(
            $.identifier,
            '=',
            $.annotation_value,
          ),
          ',',
        ),
        '()',
      ),

    annotation_value: ($) => $.string_literal,

    // annotation_function_call: () =>
    //   choice(
    //     $.annotation_function_call_no_args,
    //     $.annotation_function_call_args,
    //   ),
    //
    // annotation_function_call_no_args: ($) => '()',
    //
    // annotation_function_call_args: ($) =>
    // seq(
    // ),

    definition: ($) =>
      choice(
        $.struct,
        $.enum,
        $.const,
        $.interface,
      ),

    struct: ($) =>
      seq(
        'struct',
        $.identifier,
        optional($.generic_parameters),
        optional($.unique_id),
        optional($.annotation_call),
        '{',
        repeat(choice($.field, $.using_directive)),
        '}',
      ),
    nested_struct: ($) => $.struct,

    enum: ($) =>
      seq(
        'enum',
        $.identifier,
        optional($.unique_id),
        optional($.annotation_call),
        '{',
        repeat($.enum_field),
        '}',
      ),
    nested_enum: ($) => $.enum,

    enum_field: ($) =>
      seq(
        $.identifier,
        seq('@', $.field_version),
        optional($.annotation_call),
        ';',
      ),

    group: ($) =>
      seq(
        $.identifier,
        // token(seq(':group', /[\s\f\uFEFF\u2060\u200B]|\\\r?\n/, '{')),
        ':group',
        repeat($.annotation_call),
        '{',
        repeat($.field),
        '}',
      ),

    // for struct/group
    field: ($) =>
      choice(
        // Base type
        seq(
          $.identifier,
          seq('@', $.field_version),
          ':',
          $.field_type,
          optional(seq('=', $.const_value)),
          optional($.annotation_call),
          ';',
        ),

        $.annotation,
        $.nested_struct,
        $.nested_enum,
        $.const,
        $.group,
        $.union,
      ),

    union: ($) =>
      seq(
        choice(
          seq(
            $.identifier,
            ':',
            'union',
            repeat($.annotation_call),
            '{',
          ),
          token(/union\s*\{/),
        ),
        repeat($.union_field),
        '}',
      ),
    nested_union: ($) => $.union,

    union_field: ($) =>
      choice(
        // only difference with a field is it cannot have a default value..right?
        seq(
          $.identifier,
          '@',
          $.field_version,
          ':',
          $.field_type,
          optional($.annotation_call),
          ';',
        ),

        $.group,
        $.nested_union,
      ),

    interface: ($) =>
      seq(
        'interface',
        $.identifier,
        optional($.unique_id),
        optional(seq('(', $.generic_parameters, ')')),
        optional(seq('extends', '(', $.identifier, ')')),
        optional($.annotation_call),
        '{',
        repeat(choice($.method, $.interface, $.struct)),
        '}',
      ),

    method: ($) =>
      seq(
        $.identifier,
        seq('@', $.field_version),
        choice(
          // method @0 (...)
          seq('(', optional($.parameters), ')'),
          // method @0 Foo
          $.identifier,
        ),
        // (...) -> (...);
        // (...) -> ();
        // (...);
        optional(seq('->', $.return_type)),
        optional($.annotation_call),
        ';',
      ),

    parameters: ($) => list_seq($.parameter, ','),

    parameter: ($) =>
      seq(
        $.identifier,
        ':',
        $.field_type,
        optional(seq('=', $.const_value)),
      ),

    return_type: ($) =>
      choice(
        seq(
          '(',
          $.named_return_type,
          ')',
        ),
        $.unnamed_return_type,
      ),

    unnamed_return_type: ($) => $.identifier,

    _single_named_return_type: ($) =>
      seq(
        $.identifier,
        ':',
        $.field_type,
      ),

    named_return_type: ($) => list_seq($._single_named_return_type, ','),

    primitive_field: ($) =>
      seq(
        $.identifier,
        seq('@', $.field_version),
        ':',
        $.primitive_type,
        optional(seq('=', $.const_value)),
        optional($.annotation_call),
        ';',
      ),

    field_type: ($) => prec.left(choice($.primitive_type, $.container_type, $.custom_type)),

    primitive_type: () => choice(...primitives),

    container_type: ($) => $.list_type,

    list_type: ($) =>
      seq(
        'List',
        '(',
        // the types have an optional : due to the field_type here, list inner types don't have a :
        $.field_type,
        ')',
      ),

    custom_type: ($) => $.identifier,

    const: ($) =>
      seq(
        'const',
        $.identifier,
        ':',
        $.field_type,
        '=',
        $.const_value,
        ';',
      ),

    const_value: ($) =>
      choice(
        $.number,
        $.float,
        $.boolean,
        $.string_literal,
        $.identifier, // TODO: parse as AnyTypeHere(...)
        $.data,
        $.const_list,
        $.void,
      ),

    number: () => {
      const hex_literal = seq(
        choice('0x', '0X'),
        /[\da-fA-F](_?[\da-fA-F])*/,
      );

      const decimal_digits = /\d(_?\d)*/;
      const signed_integer = seq(optional(choice('-', '+')), decimal_digits);

      const decimal_integer_literal = choice(
        '0',
        seq(optional('0'), /[1-9]/, optional(seq(optional('_'), decimal_digits))),
      );

      const decimal_literal = choice(
        seq(optional(choice('-', '+')), decimal_integer_literal),
        decimal_digits,
        signed_integer,
      );

      return token(choice(
        hex_literal,
        decimal_literal,
      ));
    },

    field_version: () => /\d+/,

    float: () => /[+-]?(\d+(\.\d+)?|\.\d+)([Ee][+-]?\d+)?/,

    boolean: () => choice('true', 'false'),

    // 0x"62 61 72"; # "bar"
    data: () => /0x"([0-9A-Fa-f]{2} ?)*"/,

    const_list: ($) =>
      seq('[', comma_sep1($.const_value), ']'),

    void: () => 'void',

    generic_parameters: ($) => comma_sep1(field('generic_parameter', $.identifier)),

    string_literal: () => /"([^"\\]|\\.)*"|'([^'\\]|\\.)*'/,

    import_path: ($) => $.string_literal,

    identifier: () => /[A-Za-z_][A-Za-z0-9._]*/,

    comment: () => token(repeat1(seq('#', /.*/))),
  },
});
