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

const builtin_types = [
  'annotation',
  'enum',
  'group',
  'interface',
  'struct',
  'union',
];

const annotation_targets = [
  '*',
  'const',
  'enumerant',
  'field',
  'file',
  'method',
  'param',
  ...builtin_types,
];

module.exports = grammar({
  name: 'capnp',

  extras: ($) => [/[\s\f\uFEFF\u2060\u200B]|\\\r?\n/, $.comment],

  word: ($) => $.identifier,

  inline: ($) => [
    $._single_named_return_type,

    $._annotation_identifier,
    $._const_identifier,
    $._enum_identifier,
    $._enum_member,
    $._field_identifier,
    $._generic_identifier,
    $._param_identifier,
    $._return_identifier,
    $._type_identifier,
    $._extend_type,

    $._property,

    $._string_literal,
    $._multi_string_literal,
    $._namespace,
    $._import_path,

    $._annotation_call,
  ],

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
        choice($._type_identifier, $.replace_using, $.import_using),
        ';',
      ),
    // using T = Foo.Bar;
    replace_using: ($) =>
      seq(
        $._type_identifier,
        '=',
        $._type_identifier,
      ),
    import_using: ($) =>
      choice(
        // using import "bar.capnp".Baz;
        seq(
          'import',
          $._import_path,
          optional(repeat(seq('.', $._type_identifier))),
        ),
        // using Bar = import "bar.capnp";
        seq(
          $._type_identifier,
          '=',
          'import',
          $._import_path,
        ),
      ),

    // $import "/capnp/c++.capnp".namespace("capnp");
    import: ($) =>
      seq(
        '$import',
        $._import_path,
        '.',
        'namespace',
        '(',
        $._namespace,
        ')',
        ';',
      ),
    _namespace: ($) => alias($._string_literal, $.namespace),

    lang_declaration: ($) =>
      seq(
        '$',
        $.lang_attrs,
        ';',
      ),

    // $Cxx.namespace("capnp::compiler");
    lang_attrs: ($) =>
      seq(
        token.immediate(/[A-Za-z_][A-Za-z0-9._]*/, $._type_identifier),
        optional(
          seq('(',
            $._namespace,
            ')',
          ),
        ),
      ),

    // annotation myAnnotation(struct) :Int32 $baz(10);
    annotation: ($) =>
      seq(
        'annotation',
        $._annotation_identifier,
        optional($.unique_id),
        '(',
        list_seq($.annotation_target, ','),
        ')',
        optional(seq(':', $.field_type)),
        optional($._annotation_call),
        ';',
      ),

    annotation_target: () => choice(...annotation_targets),

    // $Cxx.allowCancellation;
    _annotation_call: ($) =>
      seq(
        '$',
        alias(
          seq($._annotation_identifier,
            repeat(seq('.', alias($.identifier, $.attribute))),
            optional(choice($.annotation_array, $.annotation_namespace_definition))),
          $.annotation_call),
      ),

    annotation_namespace_definition: ($) =>
      seq(
        '(',
        $._string_literal,
        ')',
      ),

    annotation_array: ($) =>
      choice(
        seq('[', $.annotation_array, ']'),
        seq('(', $.annotation_array, ')'),
        $._annotation_array_def,
      ),

    _annotation_array_def: ($) =>
      choice(
        list_seq(
          seq(
            $._field_identifier,
            '=',
            $.annotation_value,
          ),
          ',',
        ),
        '()',
      ),

    annotation_value: ($) => $._string_literal,

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
        $._type_identifier,
        optional($.generic_parameters),
        optional($.unique_id),
        optional($._annotation_call),
        '{',
        repeat(choice($.field, $.using_directive)),
        '}',
      ),
    nested_struct: ($) => $.struct,

    enum: ($) =>
      seq(
        'enum',
        $._enum_identifier,
        optional($.unique_id),
        optional($._annotation_call),
        '{',
        repeat($.enum_field),
        '}',
      ),
    nested_enum: ($) => $.enum,

    enum_field: ($) =>
      seq(
        $._enum_member,
        $.field_version,
        optional($._annotation_call),
        ';',
      ),

    group: ($) =>
      seq(
        $._type_identifier,
        ':group',
        repeat($._annotation_call),
        '{',
        repeat($.field),
        '}',
      ),

    // for struct/group
    field: ($) =>
      choice(
        // Base type
        seq(
          $._field_identifier,
          $.field_version,
          ':',
          $.field_type,
          optional(seq('=', $.const_value)),
          optional($._annotation_call),
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
            $._type_identifier,
            $.field_version,
            ':',
            'union',
            repeat($._annotation_call),
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
          $._field_identifier,
          $.field_version,
          ':',
          $.field_type,
          optional($._annotation_call),
          ';',
        ),

        $.group,
        $.nested_union,
      ),

    interface: ($) =>
      seq(
        'interface',
        $._type_identifier,
        optional($.unique_id),
        optional(seq('(', $.generic_parameters, ')')),
        optional(seq('extends', '(', $.extend_type, ')')),
        optional($._annotation_call),
        '{',
        repeat(choice($.method, $.interface, $.struct, $.enum)),
        '}',
      ),

    method: ($) =>
      seq(
        $._method_identifier,
        $.field_version,
        choice(
          // method @0 (...)
          seq('(', optional($.parameters), ')'),
          // method @0 Foo
          $._type_identifier,
        ),
        // (...) -> (...);
        // (...) -> ();
        // (...);
        optional(seq('->', $.return_type)),
        optional($._annotation_call),
        ';',
      ),

    parameters: ($) => list_seq($.parameter, ','),

    parameter: ($) =>
      seq(
        $._param_identifier,
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

    unnamed_return_type: ($) => $._type_identifier,

    _single_named_return_type: ($) =>
      seq(
        $._return_identifier,
        ':',
        $._type_identifier, // type
      ),

    named_return_type: ($) => list_seq($._single_named_return_type, ','),

    field_type: ($) => choice($.primitive_type, $.list_type, $.custom_type),

    primitive_type: () => choice(...primitives),

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
        $._const_identifier,
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
        $._string_literal,
        $._multi_string_literal,
        $.struct_shorthand,
        $.identifier,
        $.data,
        $.const_list,
        $.void,
      ),

    number: () => {
      const hex_literal = seq(
        optional('-'),
        choice('0x', '0X'),
        /[\da-fA-F](_?[\da-fA-F])*/,
      );

      // inf, -inf, nan
      const special_literal = choice(seq(optional('-'), 'inf'), 'nan');

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
        special_literal,
      ));
    },

    field_version: ($) => choice($._normal_version, $._inline_version),

    // normal is just @ followed by a number
    _normal_version: () => token(seq('@', /\d+/)),

    // inline is @ followed by a number then a !
    _inline_version: ($) => alias(token(seq('@', /\d+/, '!')), $.inline_field),

    float: () => /[+-]?(\d+(\.\d+)?|\.\d+)([Ee][+-]?\d+)?/,

    boolean: ($) => choice($.true, $.false),
    true: () => 'true',
    false: () => 'false',

    // 0x"62 61 72"; # "bar"
    // data can be spaced or not?
    data: ($) => seq('0x', alias(/"([0-9A-Fa-f]{2} ?)*"/, $.data_string)),

    const_list: ($) =>
      seq('[', comma_sep1($.const_value), ']'),

    void: () => 'void',

    struct_shorthand: ($) => seq('(', repeat(seq($._property, '=', $.const_value, optional(','))), ')'),

    generic_parameters: ($) => comma_sep1($._generic_identifier),

    _string_literal: ($) => alias(/"([^"\\]|\\.)*"|'([^'\\]|\\.)*'/, $.string_literal),

    // multiple string literals only separated by whitespace, effectively a string concatenation
    _multi_string_literal: ($) =>
      alias(
        seq(
          $._string_literal,
          repeat1(seq(
            /\s+/,
            $._string_literal,
          )),
        ),
        $.string_concatenation,
      ),

    _import_path: ($) => alias($._string_literal, $.import_path),

    identifier: () => /[A-Za-z_][A-Za-z0-9._]*/,

    _annotation_identifier: ($) => alias($.identifier, $.annotation_identifier),
    _const_identifier: ($) => alias($.identifier, $.const_identifier),
    _enum_identifier: ($) => alias($.identifier, $.enum_identifier),
    _enum_member: ($) => alias($.identifier, $.enum_member),
    _field_identifier: ($) => alias($.identifier, $.field_identifier),
    _generic_identifier: ($) => alias($.identifier, $.generic_identifier),
    _method_identifier: ($) => alias($.identifier, $.method_identifier),
    _param_identifier: ($) => alias($.identifier, $.param_identifier),
    _return_identifier: ($) => alias($.identifier, $.return_identifier),
    _type_identifier: ($) => alias($.identifier, $.type_identifier),
    _extend_type: ($) => alias($.identifier, $.extend_type),

    _property: ($) => alias($.identifier, $.property),

    comment: () => token(repeat1(seq('#', /.*/))),
  },
});
