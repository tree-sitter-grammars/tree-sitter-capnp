module.exports = grammar({
  name: 'capnp',

  extras: ($) => [/[\s\f\uFEFF\u2060\u200B]|\\\r?\n/, $.comment],

  rules: {
    source_file: ($) => seq($.unique_id, repeat($._declaration)),

    // @0x9eb32e19f86ee174;
    unique_id: () => token(seq('@', /[0x|0X][\da-fA-F](_?[\da-fA-F])*/)),

    _declaration: ($) => choice(
    ),


    hex_literal: () => token(seq(
      /[0x|0X][\da-fA-F](_?[\da-fA-F])*/,
    )),

    comment: () => token(repeat1(seq('#', /.*/))),
    // a "multiline" comment in capn proto is just any number of lines that start with #, so can we match that too?
    // kinda like how in C it's seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'),
    // for /* */ comments
    // so lets apply that to the # comment if it spans multiple lines
  },
});
