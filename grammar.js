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

module.exports = grammar({
  name: 'capnp',

  extras: ($) => [/[\s\f\uFEFF\u2060\u200B]|\\\r?\n/, $.comment],

  word: ($) => $.identifier,

  rules: {
    message: ($) => seq(repeat($.comment), $.unique_id, ';', repeat($.statement)),

    // @0x9eb32e19f86ee174;
    unique_id: () => token(seq('@', /0[xX][\da-fA-F](_?[\da-fA-F])*/)),

    statement: ($) =>
      choice(
        $.using_directive,
        $.annotation_call,
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

    annotation_call: ($) =>
      seq(
        '$',
        $.identifier,
        repeat(seq('.', field('attribute', $.identifier))),
        '(',
        $.string_literal,
        ')',
        ';',
      ),

    definition: ($) =>
      choice(
        $.struct,
        $.enum,
      ),

    struct: ($) =>
      seq(
        'struct',
        $.identifier,
        optional($.generic_parameters),
        optional($.unique_id),
        optional($.annotation_call),
        '{',
        repeat($.struct_field),
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

    struct_field: ($) =>
      choice(
        $.field,
        $.nested_struct,
        $.nested_enum,
        $.union_field,
      ),

    enum_field: ($) =>
      seq(
        $.identifier,
        seq('@', $.field_version),
        ';',
      ),

    union_field: ($) =>
      seq(
        $.identifier,
        ':union',
        '{',
        repeat($.primitive_field),
        '}',
      ),

    field: ($) =>
      seq(
        $.identifier,
        seq('@', $.field_version),
        ':',
        $.field_type,
        optional(seq('=', $.const_value)),
        ';',
      ),

    primitive_field: ($) =>
      seq(
        $.identifier,
        seq('@', $.field_version),
        ':',
        $.primitive_type,
        optional(seq('=', $.const_value)),
        ';',
      ),

    field_type: ($) => prec.left(choice($.primitive_type, $.container_type, $.group_type, $.identifier)),

    primitive_type: () => choice(...primitives),

    container_type: ($) => $.list_type,

    list_type: ($) =>
      seq(
        'List',
        '(',
        choice($.field_type, $.identifier),
        ')',
      ),

    group_type: ($) =>
      seq(
        'group',
        '{',
        repeat($.primitive_field),
        '}',
      ),

    const_value: ($) =>
      choice(
        $.number,
        $.float,
        $.boolean,
        $.string_literal,
        $.identifier,
        $.const_list,
        $.void,
      ),


    number: () => {
      // const hex_literal = seq(
      //   optional(choice('-', '+')),
      //   choice('0x', '0X'), // Hex
      //   /[\da-fA-F](_?[\da-fA-F])*/,
      // );

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

      return token(decimal_literal);
    },

    field_version: () => /\d(_?\d)*/,

    float: () => /[+-]?(\d+(\.\d+)?|\.\d+)/,

    boolean: () => choice('true', 'false'),

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
