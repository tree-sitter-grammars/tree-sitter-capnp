package tree_sitter_capnp

// #cgo CFLAGS: -O3 -Wall -Wextra -std=gnu99 -fPIC
// #include "../../src/tree_sitter/parser.h"
// #include "../../src/parser.c"
// // if you have a scanner, you need to include it here too
import "C"

import (
	"unsafe"

	tree_sitter "github.com/smacker/go-tree-sitter"
)

func GetLanguage() *tree_sitter.Language {
	ptr := unsafe.Pointer(C.tree_sitter_capnp())
	return tree_sitter.NewLanguage(ptr)
}
