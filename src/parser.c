#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 140
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 80
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 8

enum {
  sym_identifier = 1,
  anon_sym_SEMI = 2,
  sym_unique_id = 3,
  anon_sym_using = 4,
  anon_sym_EQ = 5,
  anon_sym_import = 6,
  anon_sym_DOT = 7,
  anon_sym_DOLLAR = 8,
  anon_sym_LPAREN = 9,
  anon_sym_RPAREN = 10,
  anon_sym_struct = 11,
  anon_sym_LBRACE = 12,
  anon_sym_RBRACE = 13,
  anon_sym_enum = 14,
  anon_sym_AT = 15,
  anon_sym_COLONunion = 16,
  anon_sym_COLON = 17,
  anon_sym_Bool = 18,
  anon_sym_Int8 = 19,
  anon_sym_Int16 = 20,
  anon_sym_Int32 = 21,
  anon_sym_Int64 = 22,
  anon_sym_UInt8 = 23,
  anon_sym_UInt16 = 24,
  anon_sym_UInt32 = 25,
  anon_sym_UInt64 = 26,
  anon_sym_Float32 = 27,
  anon_sym_Float64 = 28,
  anon_sym_Text = 29,
  anon_sym_Data = 30,
  anon_sym_Void = 31,
  anon_sym_List = 32,
  anon_sym_group = 33,
  sym_number = 34,
  sym_field_version = 35,
  sym_float = 36,
  anon_sym_true = 37,
  anon_sym_false = 38,
  anon_sym_LBRACK = 39,
  anon_sym_COMMA = 40,
  anon_sym_RBRACK = 41,
  sym_void = 42,
  sym_string_literal = 43,
  sym_comment = 44,
  sym_message = 45,
  sym_statement = 46,
  sym_using_directive = 47,
  sym_replace_using = 48,
  sym_import_using = 49,
  sym_annotation_call = 50,
  sym_definition = 51,
  sym_struct = 52,
  sym_nested_struct = 53,
  sym_enum = 54,
  sym_nested_enum = 55,
  sym_struct_field = 56,
  sym_enum_field = 57,
  sym_union_field = 58,
  sym_field = 59,
  sym_primitive_field = 60,
  sym_field_type = 61,
  sym_primitive_type = 62,
  sym_container_type = 63,
  sym_list_type = 64,
  sym_group_type = 65,
  sym_const_value = 66,
  sym_boolean = 67,
  sym_const_list = 68,
  sym_generic_parameters = 69,
  sym_import_path = 70,
  aux_sym_message_repeat1 = 71,
  aux_sym_message_repeat2 = 72,
  aux_sym_import_using_repeat1 = 73,
  aux_sym_annotation_call_repeat1 = 74,
  aux_sym_struct_repeat1 = 75,
  aux_sym_enum_repeat1 = 76,
  aux_sym_union_field_repeat1 = 77,
  aux_sym_const_list_repeat1 = 78,
  aux_sym_generic_parameters_repeat1 = 79,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_SEMI] = ";",
  [sym_unique_id] = "unique_id",
  [anon_sym_using] = "using",
  [anon_sym_EQ] = "=",
  [anon_sym_import] = "import",
  [anon_sym_DOT] = ".",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_struct] = "struct",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_enum] = "enum",
  [anon_sym_AT] = "@",
  [anon_sym_COLONunion] = ":union",
  [anon_sym_COLON] = ":",
  [anon_sym_Bool] = "Bool",
  [anon_sym_Int8] = "Int8",
  [anon_sym_Int16] = "Int16",
  [anon_sym_Int32] = "Int32",
  [anon_sym_Int64] = "Int64",
  [anon_sym_UInt8] = "UInt8",
  [anon_sym_UInt16] = "UInt16",
  [anon_sym_UInt32] = "UInt32",
  [anon_sym_UInt64] = "UInt64",
  [anon_sym_Float32] = "Float32",
  [anon_sym_Float64] = "Float64",
  [anon_sym_Text] = "Text",
  [anon_sym_Data] = "Data",
  [anon_sym_Void] = "Void",
  [anon_sym_List] = "List",
  [anon_sym_group] = "group",
  [sym_number] = "number",
  [sym_field_version] = "field_version",
  [sym_float] = "float",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_void] = "void",
  [sym_string_literal] = "string_literal",
  [sym_comment] = "comment",
  [sym_message] = "message",
  [sym_statement] = "statement",
  [sym_using_directive] = "using_directive",
  [sym_replace_using] = "replace_using",
  [sym_import_using] = "import_using",
  [sym_annotation_call] = "annotation_call",
  [sym_definition] = "definition",
  [sym_struct] = "struct",
  [sym_nested_struct] = "nested_struct",
  [sym_enum] = "enum",
  [sym_nested_enum] = "nested_enum",
  [sym_struct_field] = "struct_field",
  [sym_enum_field] = "enum_field",
  [sym_union_field] = "union_field",
  [sym_field] = "field",
  [sym_primitive_field] = "primitive_field",
  [sym_field_type] = "field_type",
  [sym_primitive_type] = "primitive_type",
  [sym_container_type] = "container_type",
  [sym_list_type] = "list_type",
  [sym_group_type] = "group_type",
  [sym_const_value] = "const_value",
  [sym_boolean] = "boolean",
  [sym_const_list] = "const_list",
  [sym_generic_parameters] = "generic_parameters",
  [sym_import_path] = "import_path",
  [aux_sym_message_repeat1] = "message_repeat1",
  [aux_sym_message_repeat2] = "message_repeat2",
  [aux_sym_import_using_repeat1] = "import_using_repeat1",
  [aux_sym_annotation_call_repeat1] = "annotation_call_repeat1",
  [aux_sym_struct_repeat1] = "struct_repeat1",
  [aux_sym_enum_repeat1] = "enum_repeat1",
  [aux_sym_union_field_repeat1] = "union_field_repeat1",
  [aux_sym_const_list_repeat1] = "const_list_repeat1",
  [aux_sym_generic_parameters_repeat1] = "generic_parameters_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_unique_id] = sym_unique_id,
  [anon_sym_using] = anon_sym_using,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_COLONunion] = anon_sym_COLONunion,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_Bool] = anon_sym_Bool,
  [anon_sym_Int8] = anon_sym_Int8,
  [anon_sym_Int16] = anon_sym_Int16,
  [anon_sym_Int32] = anon_sym_Int32,
  [anon_sym_Int64] = anon_sym_Int64,
  [anon_sym_UInt8] = anon_sym_UInt8,
  [anon_sym_UInt16] = anon_sym_UInt16,
  [anon_sym_UInt32] = anon_sym_UInt32,
  [anon_sym_UInt64] = anon_sym_UInt64,
  [anon_sym_Float32] = anon_sym_Float32,
  [anon_sym_Float64] = anon_sym_Float64,
  [anon_sym_Text] = anon_sym_Text,
  [anon_sym_Data] = anon_sym_Data,
  [anon_sym_Void] = anon_sym_Void,
  [anon_sym_List] = anon_sym_List,
  [anon_sym_group] = anon_sym_group,
  [sym_number] = sym_number,
  [sym_field_version] = sym_field_version,
  [sym_float] = sym_float,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_void] = sym_void,
  [sym_string_literal] = sym_string_literal,
  [sym_comment] = sym_comment,
  [sym_message] = sym_message,
  [sym_statement] = sym_statement,
  [sym_using_directive] = sym_using_directive,
  [sym_replace_using] = sym_replace_using,
  [sym_import_using] = sym_import_using,
  [sym_annotation_call] = sym_annotation_call,
  [sym_definition] = sym_definition,
  [sym_struct] = sym_struct,
  [sym_nested_struct] = sym_nested_struct,
  [sym_enum] = sym_enum,
  [sym_nested_enum] = sym_nested_enum,
  [sym_struct_field] = sym_struct_field,
  [sym_enum_field] = sym_enum_field,
  [sym_union_field] = sym_union_field,
  [sym_field] = sym_field,
  [sym_primitive_field] = sym_primitive_field,
  [sym_field_type] = sym_field_type,
  [sym_primitive_type] = sym_primitive_type,
  [sym_container_type] = sym_container_type,
  [sym_list_type] = sym_list_type,
  [sym_group_type] = sym_group_type,
  [sym_const_value] = sym_const_value,
  [sym_boolean] = sym_boolean,
  [sym_const_list] = sym_const_list,
  [sym_generic_parameters] = sym_generic_parameters,
  [sym_import_path] = sym_import_path,
  [aux_sym_message_repeat1] = aux_sym_message_repeat1,
  [aux_sym_message_repeat2] = aux_sym_message_repeat2,
  [aux_sym_import_using_repeat1] = aux_sym_import_using_repeat1,
  [aux_sym_annotation_call_repeat1] = aux_sym_annotation_call_repeat1,
  [aux_sym_struct_repeat1] = aux_sym_struct_repeat1,
  [aux_sym_enum_repeat1] = aux_sym_enum_repeat1,
  [aux_sym_union_field_repeat1] = aux_sym_union_field_repeat1,
  [aux_sym_const_list_repeat1] = aux_sym_const_list_repeat1,
  [aux_sym_generic_parameters_repeat1] = aux_sym_generic_parameters_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [sym_unique_id] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_using] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLONunion] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Int8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Int16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Int32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Int64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UInt8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UInt16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UInt32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UInt64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Float32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Float64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Text] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Data] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_List] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_group] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_field_version] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_void] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_message] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_using_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_replace_using] = {
    .visible = true,
    .named = true,
  },
  [sym_import_using] = {
    .visible = true,
    .named = true,
  },
  [sym_annotation_call] = {
    .visible = true,
    .named = true,
  },
  [sym_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_struct] = {
    .visible = true,
    .named = true,
  },
  [sym_nested_struct] = {
    .visible = true,
    .named = true,
  },
  [sym_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_nested_enum] = {
    .visible = true,
    .named = true,
  },
  [sym_struct_field] = {
    .visible = true,
    .named = true,
  },
  [sym_enum_field] = {
    .visible = true,
    .named = true,
  },
  [sym_union_field] = {
    .visible = true,
    .named = true,
  },
  [sym_field] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_field] = {
    .visible = true,
    .named = true,
  },
  [sym_field_type] = {
    .visible = true,
    .named = true,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_container_type] = {
    .visible = true,
    .named = true,
  },
  [sym_list_type] = {
    .visible = true,
    .named = true,
  },
  [sym_group_type] = {
    .visible = true,
    .named = true,
  },
  [sym_const_value] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_const_list] = {
    .visible = true,
    .named = true,
  },
  [sym_generic_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_import_path] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_message_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_message_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_import_using_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_annotation_call_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_struct_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_union_field_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_const_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_generic_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_attribute = 1,
  field_generic_parameter = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_attribute] = "attribute",
  [field_generic_parameter] = "generic_parameter",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 1},
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_generic_parameter, 0},
  [1] =
    {field_attribute, 1},
  [2] =
    {field_attribute, 0, .inherited = true},
    {field_attribute, 1, .inherited = true},
  [4] =
    {field_generic_parameter, 0},
    {field_generic_parameter, 1, .inherited = true},
  [6] =
    {field_generic_parameter, 1},
  [7] =
    {field_generic_parameter, 0, .inherited = true},
    {field_generic_parameter, 1, .inherited = true},
  [9] =
    {field_attribute, 2, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(25);
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '#') ADVANCE(49);
      if (lookahead == '$') ADVANCE(31);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == '(') ADVANCE(32);
      if (lookahead == ')') ADVANCE(33);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(9);
      if (lookahead == ',') ADVANCE(45);
      if (lookahead == '.') ADVANCE(30);
      if (lookahead == '0') ADVANCE(39);
      if (lookahead == ':') ADVANCE(38);
      if (lookahead == ';') ADVANCE(26);
      if (lookahead == '=') ADVANCE(28);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '[') ADVANCE(44);
      if (lookahead == '\\') SKIP(24)
      if (lookahead == ']') ADVANCE(46);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(48);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(5)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '\r') SKIP(1)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(7)
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\r') SKIP(3)
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '#') ADVANCE(49);
      if (lookahead == '$') ADVANCE(31);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(9);
      if (lookahead == ',') ADVANCE(45);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '0') ADVANCE(39);
      if (lookahead == '@') ADVANCE(10);
      if (lookahead == '[') ADVANCE(44);
      if (lookahead == '\\') SKIP(2)
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(5)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(48);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(47);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(49);
      if (lookahead == '(') ADVANCE(32);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == ':') ADVANCE(15);
      if (lookahead == ';') ADVANCE(26);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead == '\\') SKIP(4)
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(7)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 8:
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '\\') ADVANCE(22);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '0') ADVANCE(39);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 10:
      if (lookahead == '0') ADVANCE(16);
      END_STATE();
    case 11:
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 12:
      if (lookahead == 'n') ADVANCE(11);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(20);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 21:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 22:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 23:
      if (eof) ADVANCE(25);
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 24:
      if (eof) ADVANCE(25);
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(23)
      END_STATE();
    case 25:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_unique_id);
      if (lookahead == '_') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_COLONunion);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '0') ADVANCE(40);
      if (lookahead == '_') ADVANCE(18);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(17);
      if (lookahead == '_') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '_') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_field_version);
      if (lookahead == '_') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_float);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_string_literal);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(48);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '#') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(49);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'B') ADVANCE(1);
      if (lookahead == 'D') ADVANCE(2);
      if (lookahead == 'F') ADVANCE(3);
      if (lookahead == 'I') ADVANCE(4);
      if (lookahead == 'L') ADVANCE(5);
      if (lookahead == 'T') ADVANCE(6);
      if (lookahead == 'U') ADVANCE(7);
      if (lookahead == 'V') ADVANCE(8);
      if (lookahead == '\\') SKIP(9)
      if (lookahead == 'e') ADVANCE(10);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'g') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 's') ADVANCE(14);
      if (lookahead == 't') ADVANCE(15);
      if (lookahead == 'u') ADVANCE(16);
      if (lookahead == 'v') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(19);
      END_STATE();
    case 3:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 4:
      if (lookahead == 'n') ADVANCE(21);
      END_STATE();
    case 5:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 7:
      if (lookahead == 'I') ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(26)
      END_STATE();
    case 10:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 13:
      if (lookahead == 'm') ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 16:
      if (lookahead == 's') ADVANCE(33);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 18:
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 20:
      if (lookahead == 'o') ADVANCE(37);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 22:
      if (lookahead == 's') ADVANCE(39);
      END_STATE();
    case 23:
      if (lookahead == 'x') ADVANCE(40);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 25:
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 26:
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 27:
      if (lookahead == 'u') ADVANCE(43);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(44);
      END_STATE();
    case 29:
      if (lookahead == 'o') ADVANCE(45);
      END_STATE();
    case 30:
      if (lookahead == 'p') ADVANCE(46);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 32:
      if (lookahead == 'u') ADVANCE(48);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 34:
      if (lookahead == 'i') ADVANCE(50);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(51);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(53);
      END_STATE();
    case 38:
      if (lookahead == '1') ADVANCE(54);
      if (lookahead == '3') ADVANCE(55);
      if (lookahead == '6') ADVANCE(56);
      if (lookahead == '8') ADVANCE(57);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(58);
      END_STATE();
    case 40:
      if (lookahead == 't') ADVANCE(59);
      END_STATE();
    case 41:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(61);
      END_STATE();
    case 43:
      if (lookahead == 'm') ADVANCE(62);
      END_STATE();
    case 44:
      if (lookahead == 's') ADVANCE(63);
      END_STATE();
    case 45:
      if (lookahead == 'u') ADVANCE(64);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 47:
      if (lookahead == 'u') ADVANCE(66);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(68);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(69);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_Bool);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_Data);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(70);
      END_STATE();
    case 54:
      if (lookahead == '6') ADVANCE(71);
      END_STATE();
    case 55:
      if (lookahead == '2') ADVANCE(72);
      END_STATE();
    case 56:
      if (lookahead == '4') ADVANCE(73);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_Int8);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_List);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_Text);
      END_STATE();
    case 60:
      if (lookahead == '1') ADVANCE(74);
      if (lookahead == '3') ADVANCE(75);
      if (lookahead == '6') ADVANCE(76);
      if (lookahead == '8') ADVANCE(77);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_Void);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 64:
      if (lookahead == 'p') ADVANCE(79);
      END_STATE();
    case 65:
      if (lookahead == 'r') ADVANCE(80);
      END_STATE();
    case 66:
      if (lookahead == 'c') ADVANCE(81);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 68:
      if (lookahead == 'g') ADVANCE(82);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_void);
      END_STATE();
    case 70:
      if (lookahead == '3') ADVANCE(83);
      if (lookahead == '6') ADVANCE(84);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_Int16);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_Int32);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_Int64);
      END_STATE();
    case 74:
      if (lookahead == '6') ADVANCE(85);
      END_STATE();
    case 75:
      if (lookahead == '2') ADVANCE(86);
      END_STATE();
    case 76:
      if (lookahead == '4') ADVANCE(87);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_UInt8);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_group);
      END_STATE();
    case 80:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 81:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_using);
      END_STATE();
    case 83:
      if (lookahead == '2') ADVANCE(90);
      END_STATE();
    case 84:
      if (lookahead == '4') ADVANCE(91);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_UInt16);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_UInt32);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_UInt64);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_Float32);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_Float64);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 5},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 5},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 5},
  [38] = {.lex_state = 5},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 5},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 5},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 7},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 7},
  [79] = {.lex_state = 7},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 7},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 7},
  [85] = {.lex_state = 7},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 7},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 7},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 7},
  [94] = {.lex_state = 5},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 5},
  [97] = {.lex_state = 7},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 7},
  [111] = {.lex_state = 7},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 7},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_using] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_Bool] = ACTIONS(1),
    [anon_sym_Int8] = ACTIONS(1),
    [anon_sym_Int16] = ACTIONS(1),
    [anon_sym_Int32] = ACTIONS(1),
    [anon_sym_Int64] = ACTIONS(1),
    [anon_sym_UInt8] = ACTIONS(1),
    [anon_sym_UInt16] = ACTIONS(1),
    [anon_sym_UInt32] = ACTIONS(1),
    [anon_sym_UInt64] = ACTIONS(1),
    [anon_sym_Float32] = ACTIONS(1),
    [anon_sym_Float64] = ACTIONS(1),
    [anon_sym_Text] = ACTIONS(1),
    [anon_sym_Data] = ACTIONS(1),
    [anon_sym_Void] = ACTIONS(1),
    [anon_sym_List] = ACTIONS(1),
    [anon_sym_group] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_field_version] = ACTIONS(1),
    [sym_float] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_void] = ACTIONS(1),
    [sym_string_literal] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_message] = STATE(134),
    [aux_sym_message_repeat1] = STATE(94),
    [sym_unique_id] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      sym_identifier,
    ACTIONS(13), 1,
      anon_sym_List,
    ACTIONS(15), 1,
      anon_sym_group,
    STATE(80), 1,
      sym_list_type,
    STATE(101), 1,
      sym_field_type,
    STATE(82), 3,
      sym_primitive_type,
      sym_container_type,
      sym_group_type,
    ACTIONS(11), 14,
      anon_sym_Bool,
      anon_sym_Int8,
      anon_sym_Int16,
      anon_sym_Int32,
      anon_sym_Int64,
      anon_sym_UInt8,
      anon_sym_UInt16,
      anon_sym_UInt32,
      anon_sym_UInt64,
      anon_sym_Float32,
      anon_sym_Float64,
      anon_sym_Text,
      anon_sym_Data,
      anon_sym_Void,
  [40] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      anon_sym_List,
    ACTIONS(15), 1,
      anon_sym_group,
    ACTIONS(17), 1,
      sym_identifier,
    STATE(80), 1,
      sym_list_type,
    STATE(117), 1,
      sym_field_type,
    STATE(82), 3,
      sym_primitive_type,
      sym_container_type,
      sym_group_type,
    ACTIONS(11), 14,
      anon_sym_Bool,
      anon_sym_Int8,
      anon_sym_Int16,
      anon_sym_Int32,
      anon_sym_Int64,
      anon_sym_UInt8,
      anon_sym_UInt16,
      anon_sym_UInt32,
      anon_sym_UInt64,
      anon_sym_Float32,
      anon_sym_Float64,
      anon_sym_Text,
      anon_sym_Data,
      anon_sym_Void,
  [80] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(95), 1,
      sym_primitive_type,
    ACTIONS(19), 14,
      anon_sym_Bool,
      anon_sym_Int8,
      anon_sym_Int16,
      anon_sym_Int32,
      anon_sym_Int64,
      anon_sym_UInt8,
      anon_sym_UInt16,
      anon_sym_UInt32,
      anon_sym_UInt64,
      anon_sym_Float32,
      anon_sym_Float64,
      anon_sym_Text,
      anon_sym_Data,
      anon_sym_Void,
  [103] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      anon_sym_using,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_struct,
    ACTIONS(29), 1,
      anon_sym_enum,
    STATE(13), 2,
      sym_statement,
      aux_sym_message_repeat2,
    STATE(36), 2,
      sym_struct,
      sym_enum,
    STATE(35), 3,
      sym_using_directive,
      sym_annotation_call,
      sym_definition,
  [135] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_using,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_struct,
    ACTIONS(29), 1,
      anon_sym_enum,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    STATE(12), 2,
      sym_statement,
      aux_sym_message_repeat2,
    STATE(36), 2,
      sym_struct,
      sym_enum,
    STATE(35), 3,
      sym_using_directive,
      sym_annotation_call,
      sym_definition,
  [167] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    ACTIONS(39), 1,
      anon_sym_enum,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(11), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [199] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(41), 1,
      sym_identifier,
    ACTIONS(44), 1,
      anon_sym_struct,
    ACTIONS(47), 1,
      anon_sym_RBRACE,
    ACTIONS(49), 1,
      anon_sym_enum,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(8), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [231] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(39), 1,
      anon_sym_enum,
    ACTIONS(52), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(8), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [263] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(39), 1,
      anon_sym_enum,
    ACTIONS(52), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(15), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [295] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(39), 1,
      anon_sym_enum,
    ACTIONS(54), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(8), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [327] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      anon_sym_using,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_struct,
    ACTIONS(29), 1,
      anon_sym_enum,
    STATE(18), 2,
      sym_statement,
      aux_sym_message_repeat2,
    STATE(36), 2,
      sym_struct,
      sym_enum,
    STATE(35), 3,
      sym_using_directive,
      sym_annotation_call,
      sym_definition,
  [359] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_using,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_struct,
    ACTIONS(29), 1,
      anon_sym_enum,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    STATE(18), 2,
      sym_statement,
      aux_sym_message_repeat2,
    STATE(36), 2,
      sym_struct,
      sym_enum,
    STATE(35), 3,
      sym_using_directive,
      sym_annotation_call,
      sym_definition,
  [391] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(39), 1,
      anon_sym_enum,
    ACTIONS(54), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(16), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [423] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    ACTIONS(39), 1,
      anon_sym_enum,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(8), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [455] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(39), 1,
      anon_sym_enum,
    ACTIONS(58), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(8), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [487] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_struct,
    ACTIONS(39), 1,
      anon_sym_enum,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    STATE(51), 1,
      sym_struct,
    STATE(53), 1,
      sym_enum,
    STATE(9), 2,
      sym_struct_field,
      aux_sym_struct_repeat1,
    STATE(42), 4,
      sym_nested_struct,
      sym_nested_enum,
      sym_union_field,
      sym_field,
  [519] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(62), 1,
      ts_builtin_sym_end,
    ACTIONS(64), 1,
      anon_sym_using,
    ACTIONS(67), 1,
      anon_sym_DOLLAR,
    ACTIONS(70), 1,
      anon_sym_struct,
    ACTIONS(73), 1,
      anon_sym_enum,
    STATE(18), 2,
      sym_statement,
      aux_sym_message_repeat2,
    STATE(36), 2,
      sym_struct,
      sym_enum,
    STATE(35), 3,
      sym_using_directive,
      sym_annotation_call,
      sym_definition,
  [551] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(82), 1,
      sym_string_literal,
    STATE(71), 1,
      sym_const_value,
    ACTIONS(78), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 2,
      sym_boolean,
      sym_const_list,
    ACTIONS(76), 4,
      sym_number,
      sym_float,
      sym_void,
      sym_identifier,
  [578] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(82), 1,
      sym_string_literal,
    STATE(123), 1,
      sym_const_value,
    ACTIONS(78), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 2,
      sym_boolean,
      sym_const_list,
    ACTIONS(76), 4,
      sym_number,
      sym_float,
      sym_void,
      sym_identifier,
  [605] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(82), 1,
      sym_string_literal,
    STATE(138), 1,
      sym_const_value,
    ACTIONS(78), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 2,
      sym_boolean,
      sym_const_list,
    ACTIONS(76), 4,
      sym_number,
      sym_float,
      sym_void,
      sym_identifier,
  [632] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(82), 1,
      sym_string_literal,
    STATE(90), 1,
      sym_const_value,
    ACTIONS(78), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 2,
      sym_boolean,
      sym_const_list,
    ACTIONS(76), 4,
      sym_number,
      sym_float,
      sym_void,
      sym_identifier,
  [659] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(84), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(86), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [674] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(88), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(90), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [689] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(92), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(94), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [704] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(96), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(98), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [719] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(100), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(102), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [734] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(104), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(106), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [749] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(108), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(110), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [764] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(112), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(114), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [779] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(116), 3,
      ts_builtin_sym_end,
      anon_sym_DOLLAR,
      anon_sym_RBRACE,
    ACTIONS(118), 4,
      anon_sym_using,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [794] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(120), 6,
      ts_builtin_sym_end,
      anon_sym_using,
      anon_sym_DOLLAR,
      anon_sym_struct,
      anon_sym_LBRACE,
      anon_sym_enum,
  [806] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(122), 6,
      ts_builtin_sym_end,
      anon_sym_using,
      anon_sym_DOLLAR,
      anon_sym_struct,
      anon_sym_LBRACE,
      anon_sym_enum,
  [818] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(124), 1,
      sym_identifier,
    ACTIONS(126), 1,
      sym_unique_id,
    ACTIONS(128), 1,
      anon_sym_LBRACE,
    STATE(47), 1,
      sym_generic_parameters,
    STATE(129), 1,
      sym_annotation_call,
  [840] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(130), 5,
      ts_builtin_sym_end,
      anon_sym_using,
      anon_sym_DOLLAR,
      anon_sym_struct,
      anon_sym_enum,
  [851] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(132), 5,
      ts_builtin_sym_end,
      anon_sym_using,
      anon_sym_DOLLAR,
      anon_sym_struct,
      anon_sym_enum,
  [862] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_generic_parameters_repeat1,
    ACTIONS(134), 3,
      sym_unique_id,
      anon_sym_DOLLAR,
      anon_sym_LBRACE,
  [877] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_generic_parameters_repeat1,
    ACTIONS(138), 3,
      sym_unique_id,
      anon_sym_DOLLAR,
      anon_sym_LBRACE,
  [892] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 5,
      ts_builtin_sym_end,
      anon_sym_using,
      anon_sym_DOLLAR,
      anon_sym_struct,
      anon_sym_enum,
  [903] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_COMMA,
    STATE(37), 1,
      aux_sym_generic_parameters_repeat1,
    ACTIONS(145), 3,
      sym_unique_id,
      anon_sym_DOLLAR,
      anon_sym_LBRACE,
  [918] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(149), 1,
      anon_sym_RBRACE,
    STATE(45), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [932] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    ACTIONS(151), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [944] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    ACTIONS(155), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [956] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      sym_identifier,
    ACTIONS(162), 1,
      anon_sym_RBRACE,
    STATE(44), 2,
      sym_primitive_field,
      aux_sym_union_field_repeat1,
  [970] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(164), 1,
      sym_identifier,
    ACTIONS(167), 1,
      anon_sym_RBRACE,
    STATE(45), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [984] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(149), 1,
      anon_sym_RBRACE,
    STATE(55), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [998] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(169), 1,
      sym_unique_id,
    ACTIONS(171), 1,
      anon_sym_LBRACE,
    STATE(112), 1,
      sym_annotation_call,
  [1014] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(175), 1,
      anon_sym_RBRACE,
    ACTIONS(173), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [1026] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(177), 1,
      anon_sym_RBRACE,
    STATE(62), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [1040] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 1,
      sym_identifier,
    ACTIONS(181), 1,
      anon_sym_RBRACE,
    STATE(54), 2,
      sym_primitive_field,
      aux_sym_union_field_repeat1,
  [1054] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(185), 1,
      anon_sym_RBRACE,
    ACTIONS(183), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [1066] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 1,
      sym_identifier,
    ACTIONS(187), 1,
      anon_sym_RBRACE,
    STATE(61), 2,
      sym_primitive_field,
      aux_sym_union_field_repeat1,
  [1080] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_RBRACE,
    ACTIONS(189), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [1092] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 1,
      sym_identifier,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    STATE(44), 2,
      sym_primitive_field,
      aux_sym_union_field_repeat1,
  [1106] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(195), 1,
      anon_sym_RBRACE,
    STATE(45), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [1120] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    ACTIONS(197), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [1132] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 4,
      sym_unique_id,
      anon_sym_DOLLAR,
      anon_sym_LBRACE,
      anon_sym_COMMA,
  [1142] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(203), 1,
      anon_sym_RBRACE,
    STATE(41), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [1156] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_RBRACE,
    ACTIONS(205), 3,
      anon_sym_struct,
      anon_sym_enum,
      sym_identifier,
  [1168] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(209), 1,
      sym_unique_id,
    ACTIONS(211), 1,
      anon_sym_LBRACE,
    STATE(130), 1,
      sym_annotation_call,
  [1184] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 1,
      sym_identifier,
    ACTIONS(213), 1,
      anon_sym_RBRACE,
    STATE(44), 2,
      sym_primitive_field,
      aux_sym_union_field_repeat1,
  [1198] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      sym_identifier,
    ACTIONS(203), 1,
      anon_sym_RBRACE,
    STATE(45), 2,
      sym_enum_field,
      aux_sym_enum_repeat1,
  [1212] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 1,
      sym_identifier,
    ACTIONS(217), 1,
      anon_sym_import,
    STATE(113), 2,
      sym_replace_using,
      sym_import_using,
  [1226] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(219), 1,
      anon_sym_LBRACE,
    STATE(125), 1,
      sym_annotation_call,
  [1239] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [1248] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 1,
      anon_sym_COMMA,
    ACTIONS(226), 1,
      anon_sym_RBRACK,
    STATE(66), 1,
      aux_sym_const_list_repeat1,
  [1261] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1270] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      anon_sym_COMMA,
    ACTIONS(232), 1,
      anon_sym_RBRACK,
    STATE(66), 1,
      aux_sym_const_list_repeat1,
  [1283] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_SEMI,
    ACTIONS(236), 1,
      anon_sym_DOT,
    STATE(69), 1,
      aux_sym_import_using_repeat1,
  [1296] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(239), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1305] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      anon_sym_COMMA,
    ACTIONS(241), 1,
      anon_sym_RBRACK,
    STATE(68), 1,
      aux_sym_const_list_repeat1,
  [1318] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(243), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [1327] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(245), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [1336] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1345] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    STATE(103), 1,
      sym_annotation_call,
  [1358] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(251), 3,
      anon_sym_SEMI,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1367] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(253), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [1376] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(255), 1,
      anon_sym_DOT,
    ACTIONS(257), 1,
      anon_sym_LPAREN,
    STATE(84), 1,
      aux_sym_annotation_call_repeat1,
  [1389] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 1,
      anon_sym_SEMI,
    ACTIONS(261), 1,
      anon_sym_DOT,
    STATE(85), 1,
      aux_sym_import_using_repeat1,
  [1402] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [1411] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(265), 1,
      anon_sym_DOT,
    ACTIONS(268), 1,
      anon_sym_LPAREN,
    STATE(81), 1,
      aux_sym_annotation_call_repeat1,
  [1424] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(270), 3,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_RPAREN,
  [1433] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(171), 1,
      anon_sym_LBRACE,
    STATE(112), 1,
      sym_annotation_call,
  [1446] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(255), 1,
      anon_sym_DOT,
    ACTIONS(272), 1,
      anon_sym_LPAREN,
    STATE(81), 1,
      aux_sym_annotation_call_repeat1,
  [1459] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 1,
      anon_sym_DOT,
    ACTIONS(274), 1,
      anon_sym_SEMI,
    STATE(69), 1,
      aux_sym_import_using_repeat1,
  [1472] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(276), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1480] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(278), 2,
      anon_sym_SEMI,
      anon_sym_DOT,
  [1488] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1496] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(282), 2,
      anon_sym_DOT,
      anon_sym_LPAREN,
  [1504] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1512] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(284), 2,
      anon_sym_RBRACE,
      sym_identifier,
  [1520] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(286), 1,
      sym_string_literal,
    STATE(105), 1,
      sym_import_path,
  [1530] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 2,
      anon_sym_SEMI,
      anon_sym_DOT,
  [1538] = 3,
    ACTIONS(288), 1,
      sym_unique_id,
    ACTIONS(290), 1,
      sym_comment,
    STATE(96), 1,
      aux_sym_message_repeat1,
  [1548] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(292), 1,
      anon_sym_SEMI,
    ACTIONS(294), 1,
      anon_sym_EQ,
  [1558] = 3,
    ACTIONS(296), 1,
      sym_unique_id,
    ACTIONS(298), 1,
      sym_comment,
    STATE(96), 1,
      aux_sym_message_repeat1,
  [1568] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(301), 1,
      anon_sym_AT,
    ACTIONS(303), 1,
      anon_sym_COLONunion,
  [1578] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_SEMI,
    ACTIONS(307), 1,
      anon_sym_EQ,
  [1588] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(286), 1,
      sym_string_literal,
    STATE(79), 1,
      sym_import_path,
  [1598] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(309), 1,
      sym_identifier,
    ACTIONS(311), 1,
      anon_sym_import,
  [1608] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(313), 1,
      anon_sym_SEMI,
    ACTIONS(315), 1,
      anon_sym_EQ,
  [1618] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(317), 1,
      sym_identifier,
  [1625] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(319), 1,
      anon_sym_LBRACE,
  [1632] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(321), 1,
      anon_sym_SEMI,
  [1639] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(323), 1,
      anon_sym_SEMI,
  [1646] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(325), 1,
      anon_sym_LPAREN,
  [1653] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(327), 1,
      anon_sym_LBRACE,
  [1660] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(329), 1,
      anon_sym_SEMI,
  [1667] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(331), 1,
      sym_string_literal,
  [1674] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(333), 1,
      sym_field_version,
  [1681] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(335), 1,
      sym_field_version,
  [1688] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
  [1695] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(305), 1,
      anon_sym_SEMI,
  [1702] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(337), 1,
      sym_identifier,
  [1709] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(339), 1,
      anon_sym_COLON,
  [1716] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(270), 1,
      anon_sym_RPAREN,
  [1723] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(341), 1,
      anon_sym_RPAREN,
  [1730] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(343), 1,
      anon_sym_RPAREN,
  [1737] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(345), 1,
      sym_identifier,
  [1744] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(347), 1,
      sym_identifier,
  [1751] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(349), 1,
      sym_string_literal,
  [1758] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(351), 1,
      sym_identifier,
  [1765] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(353), 1,
      anon_sym_SEMI,
  [1772] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(355), 1,
      anon_sym_AT,
  [1779] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(357), 1,
      anon_sym_LBRACE,
  [1786] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(359), 1,
      anon_sym_AT,
  [1793] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(361), 1,
      anon_sym_LBRACE,
  [1800] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(363), 1,
      anon_sym_SEMI,
  [1807] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(171), 1,
      anon_sym_LBRACE,
  [1814] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_LBRACE,
  [1821] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(365), 1,
      sym_field_version,
  [1828] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(367), 1,
      anon_sym_SEMI,
  [1835] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(369), 1,
      sym_identifier,
  [1842] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(371), 1,
      ts_builtin_sym_end,
  [1849] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(373), 1,
      anon_sym_SEMI,
  [1856] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(375), 1,
      anon_sym_SEMI,
  [1863] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(377), 1,
      anon_sym_RPAREN,
  [1870] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 1,
      anon_sym_SEMI,
  [1877] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(381), 1,
      anon_sym_COLON,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 40,
  [SMALL_STATE(4)] = 80,
  [SMALL_STATE(5)] = 103,
  [SMALL_STATE(6)] = 135,
  [SMALL_STATE(7)] = 167,
  [SMALL_STATE(8)] = 199,
  [SMALL_STATE(9)] = 231,
  [SMALL_STATE(10)] = 263,
  [SMALL_STATE(11)] = 295,
  [SMALL_STATE(12)] = 327,
  [SMALL_STATE(13)] = 359,
  [SMALL_STATE(14)] = 391,
  [SMALL_STATE(15)] = 423,
  [SMALL_STATE(16)] = 455,
  [SMALL_STATE(17)] = 487,
  [SMALL_STATE(18)] = 519,
  [SMALL_STATE(19)] = 551,
  [SMALL_STATE(20)] = 578,
  [SMALL_STATE(21)] = 605,
  [SMALL_STATE(22)] = 632,
  [SMALL_STATE(23)] = 659,
  [SMALL_STATE(24)] = 674,
  [SMALL_STATE(25)] = 689,
  [SMALL_STATE(26)] = 704,
  [SMALL_STATE(27)] = 719,
  [SMALL_STATE(28)] = 734,
  [SMALL_STATE(29)] = 749,
  [SMALL_STATE(30)] = 764,
  [SMALL_STATE(31)] = 779,
  [SMALL_STATE(32)] = 794,
  [SMALL_STATE(33)] = 806,
  [SMALL_STATE(34)] = 818,
  [SMALL_STATE(35)] = 840,
  [SMALL_STATE(36)] = 851,
  [SMALL_STATE(37)] = 862,
  [SMALL_STATE(38)] = 877,
  [SMALL_STATE(39)] = 892,
  [SMALL_STATE(40)] = 903,
  [SMALL_STATE(41)] = 918,
  [SMALL_STATE(42)] = 932,
  [SMALL_STATE(43)] = 944,
  [SMALL_STATE(44)] = 956,
  [SMALL_STATE(45)] = 970,
  [SMALL_STATE(46)] = 984,
  [SMALL_STATE(47)] = 998,
  [SMALL_STATE(48)] = 1014,
  [SMALL_STATE(49)] = 1026,
  [SMALL_STATE(50)] = 1040,
  [SMALL_STATE(51)] = 1054,
  [SMALL_STATE(52)] = 1066,
  [SMALL_STATE(53)] = 1080,
  [SMALL_STATE(54)] = 1092,
  [SMALL_STATE(55)] = 1106,
  [SMALL_STATE(56)] = 1120,
  [SMALL_STATE(57)] = 1132,
  [SMALL_STATE(58)] = 1142,
  [SMALL_STATE(59)] = 1156,
  [SMALL_STATE(60)] = 1168,
  [SMALL_STATE(61)] = 1184,
  [SMALL_STATE(62)] = 1198,
  [SMALL_STATE(63)] = 1212,
  [SMALL_STATE(64)] = 1226,
  [SMALL_STATE(65)] = 1239,
  [SMALL_STATE(66)] = 1248,
  [SMALL_STATE(67)] = 1261,
  [SMALL_STATE(68)] = 1270,
  [SMALL_STATE(69)] = 1283,
  [SMALL_STATE(70)] = 1296,
  [SMALL_STATE(71)] = 1305,
  [SMALL_STATE(72)] = 1318,
  [SMALL_STATE(73)] = 1327,
  [SMALL_STATE(74)] = 1336,
  [SMALL_STATE(75)] = 1345,
  [SMALL_STATE(76)] = 1358,
  [SMALL_STATE(77)] = 1367,
  [SMALL_STATE(78)] = 1376,
  [SMALL_STATE(79)] = 1389,
  [SMALL_STATE(80)] = 1402,
  [SMALL_STATE(81)] = 1411,
  [SMALL_STATE(82)] = 1424,
  [SMALL_STATE(83)] = 1433,
  [SMALL_STATE(84)] = 1446,
  [SMALL_STATE(85)] = 1459,
  [SMALL_STATE(86)] = 1472,
  [SMALL_STATE(87)] = 1480,
  [SMALL_STATE(88)] = 1488,
  [SMALL_STATE(89)] = 1496,
  [SMALL_STATE(90)] = 1504,
  [SMALL_STATE(91)] = 1512,
  [SMALL_STATE(92)] = 1520,
  [SMALL_STATE(93)] = 1530,
  [SMALL_STATE(94)] = 1538,
  [SMALL_STATE(95)] = 1548,
  [SMALL_STATE(96)] = 1558,
  [SMALL_STATE(97)] = 1568,
  [SMALL_STATE(98)] = 1578,
  [SMALL_STATE(99)] = 1588,
  [SMALL_STATE(100)] = 1598,
  [SMALL_STATE(101)] = 1608,
  [SMALL_STATE(102)] = 1618,
  [SMALL_STATE(103)] = 1625,
  [SMALL_STATE(104)] = 1632,
  [SMALL_STATE(105)] = 1639,
  [SMALL_STATE(106)] = 1646,
  [SMALL_STATE(107)] = 1653,
  [SMALL_STATE(108)] = 1660,
  [SMALL_STATE(109)] = 1667,
  [SMALL_STATE(110)] = 1674,
  [SMALL_STATE(111)] = 1681,
  [SMALL_STATE(112)] = 1688,
  [SMALL_STATE(113)] = 1695,
  [SMALL_STATE(114)] = 1702,
  [SMALL_STATE(115)] = 1709,
  [SMALL_STATE(116)] = 1716,
  [SMALL_STATE(117)] = 1723,
  [SMALL_STATE(118)] = 1730,
  [SMALL_STATE(119)] = 1737,
  [SMALL_STATE(120)] = 1744,
  [SMALL_STATE(121)] = 1751,
  [SMALL_STATE(122)] = 1758,
  [SMALL_STATE(123)] = 1765,
  [SMALL_STATE(124)] = 1772,
  [SMALL_STATE(125)] = 1779,
  [SMALL_STATE(126)] = 1786,
  [SMALL_STATE(127)] = 1793,
  [SMALL_STATE(128)] = 1800,
  [SMALL_STATE(129)] = 1807,
  [SMALL_STATE(130)] = 1814,
  [SMALL_STATE(131)] = 1821,
  [SMALL_STATE(132)] = 1828,
  [SMALL_STATE(133)] = 1835,
  [SMALL_STATE(134)] = 1842,
  [SMALL_STATE(135)] = 1849,
  [SMALL_STATE(136)] = 1856,
  [SMALL_STATE(137)] = 1863,
  [SMALL_STATE(138)] = 1870,
  [SMALL_STATE(139)] = 1877,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_message, 3),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_message, 2),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_repeat1, 2), SHIFT_REPEAT(97),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_repeat1, 2), SHIFT_REPEAT(119),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_struct_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_struct_repeat1, 2), SHIFT_REPEAT(114),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_message, 4),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_message_repeat2, 2),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_message_repeat2, 2), SHIFT_REPEAT(63),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_message_repeat2, 2), SHIFT_REPEAT(122),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_message_repeat2, 2), SHIFT_REPEAT(119),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_message_repeat2, 2), SHIFT_REPEAT(114),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct, 7),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct, 7),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct, 5),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct, 5),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 4),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 4),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 5),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 5),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct, 4),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct, 4),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 7),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 7),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct, 6),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct, 6),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum, 6),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_enum, 6),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct, 8),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct, 8),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation_call, 6),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotation_call, 7, .production_id = 7),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition, 1),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_parameters, 2, .production_id = 4),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_generic_parameters_repeat1, 2, .production_id = 6),
  [140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_generic_parameters_repeat1, 2, .production_id = 6), SHIFT_REPEAT(120),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_using_directive, 3),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_parameters, 1, .production_id = 1),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_struct_field, 1),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_struct_field, 1),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_union_field, 4),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_field, 4),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_union_field_repeat1, 2), SHIFT_REPEAT(124),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_union_field_repeat1, 2),
  [164] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2), SHIFT_REPEAT(126),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_enum_repeat1, 2),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_union_field, 5),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_union_field, 5),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_nested_struct, 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nested_struct, 1),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_nested_enum, 1),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nested_enum, 1),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field, 8),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 8),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_generic_parameters_repeat1, 2, .production_id = 5),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field, 6),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 6),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_type, 1),
  [223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_const_list_repeat1, 2), SHIFT_REPEAT(22),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_const_list_repeat1, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_list, 4),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_import_using_repeat1, 2),
  [236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_import_using_repeat1, 2), SHIFT_REPEAT(133),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_list, 3),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_group_type, 4),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_type, 4),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_value, 1),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_group_type, 3),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_using, 2),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_container_type, 1),
  [265] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_annotation_call_repeat1, 2, .production_id = 3), SHIFT_REPEAT(102),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_annotation_call_repeat1, 2, .production_id = 3),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_type, 1),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_using, 3),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_enum_field, 4),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_path, 1),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_field, 8),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_annotation_call_repeat1, 2, .production_id = 2),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primitive_field, 6),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_message_repeat1, 2),
  [298] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_message_repeat1, 2), SHIFT_REPEAT(96),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [309] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [311] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_using, 4),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [371] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_replace_using, 3),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_capnp(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
