package tree_sitter_capnp_test

import (
	"testing"

	"github.com/amaanq/tree-sitter-capnp"
)

func TestCanLoadGrammar(t *testing.T) {
	parser := tree_sitter_capnp.Language()
	if parser == nil {
		t.Errorf("Error loading Capnp grammar")
	}
}
