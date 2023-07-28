from ._tree_sitter_capnp import lib as _lib

def language():
    """Get the tree-sitter language for this grammar."""
    return _lib.tree_sitter_capnp()
