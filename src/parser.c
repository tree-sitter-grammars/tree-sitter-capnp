#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 6
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 7
#define ALIAS_COUNT 0
#define TOKEN_COUNT 4
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 1

enum {
  sym_unique_id = 1,
  sym_hex_literal = 2,
  sym_comment = 3,
  sym_source_file = 4,
  sym__declaration = 5,
  aux_sym_source_file_repeat1 = 6,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_unique_id] = "unique_id",
  [sym_hex_literal] = "hex_literal",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym__declaration] = "_declaration",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_unique_id] = sym_unique_id,
  [sym_hex_literal] = sym_hex_literal,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym__declaration] = sym__declaration,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_unique_id] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__declaration] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '@') ADVANCE(1);
      if (lookahead == '\\') SKIP(5)
      if (lookahead == '0' ||
          lookahead == 'X' ||
          lookahead == 'x' ||
          lookahead == '|') ADVANCE(2);
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
      if (lookahead == '0' ||
          lookahead == 'X' ||
          lookahead == 'x' ||
          lookahead == '|') ADVANCE(3);
      END_STATE();
    case 2:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(8);
      END_STATE();
    case 3:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 4:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(4)
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_unique_id);
      if (lookahead == '_') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_unique_id] = ACTIONS(1),
    [sym_hex_literal] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(5),
    [sym_unique_id] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
  },
  [2] = {
    [sym__declaration] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
  },
  [3] = {
    [sym__declaration] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_comment] = ACTIONS(3),
  },
  [4] = {
    [sym__declaration] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [13] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
