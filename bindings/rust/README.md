# tree-sitter-capnp

This crate provides a Cap'n Proto grammar for the [tree-sitter][] parsing library.
To use this crate, add it to the `[dependencies]` section of your `Cargo.toml`
file. (Note that you will probably also need to depend on the
[`tree-sitter`][tree-sitter crate] crate to use the parsed result in any useful
way.)

```toml
[dependencies]
tree-sitter = "~0.20.3"
tree-sitter-capnp = "1.6.0"
```

Typically, you will use the [language][language func] function to add this
grammar to a tree-sitter [Parser][], and then use the parser to parse some code:

```rust
let code = r#"
@0xa73956d2621fc3ee;

using Cxx = import "/capnp/c++.capnp";

$Cxx.namespace("capnp::compiler");

struct Token {
  union {
    identifier @0 :Text;
    stringLiteral @1 :Text;
    binaryLiteral @9 :Data;
    integerLiteral @2 :UInt64;
    floatLiteral @3 :Float64;
    operator @4 :Text;
    parenthesizedList @5 :List(List(Token));
    bracketedList @6 :List(List(Token));
  }

  startByte @7 :UInt32;
  endByte @8 :UInt32;
}

struct Statement {
  tokens @0 :List(Token);
  union {
    line @1 :Void;
    block @2 :List(Statement);
  }

  docComment @3 :Text;

  startByte @4 :UInt32;
  endByte @5 :UInt32;
}

struct LexedTokens {
  # Lexer output when asked to parse tokens that don't form statements.

  tokens @0 :List(Token);
}

struct LexedStatements {
  # Lexer output when asked to parse statements.

  statements @0 :List(Statement);
}
"#;
let mut parser = Parser::new();
parser.set_language(tree_sitter_capnp::language()).expect("Error loading Cap'n Proto grammar");
let parsed = parser.parse(code, None);
```

If you have any questions, please reach out to us in the [tree-sitter
discussions] page.

[language func]: https://docs.rs/tree-sitter-capnp/*/tree_sitter_capnp/fn.language.html
[parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
[tree-sitter]: https://tree-sitter.github.io/
[tree-sitter crate]: https://crates.io/crates/tree-sitter
[tree-sitter discussions]: https://github.com/tree-sitter/tree-sitter/discussions
