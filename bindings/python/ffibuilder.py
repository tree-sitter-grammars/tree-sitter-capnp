import sys

from cffi import FFI

output_name = sys.argv[1]

ffibuilder = FFI()
ffibuilder.set_source(
    'tree_sitter_capnp._tree_sitter_capnp',
    """
    #include "../../../src/tree_sitter/parser.h"
    extern const TSLanguage *tree_sitter_capnp();
    """,
    include_dirs=["../../src"],
)

ffibuilder.cdef("""
    typedef struct TSLanguage TSLanguage;
    const TSLanguage *tree_sitter_capnp(void);
""")

if __name__ == '__main__':
    ffibuilder.emit_c_code(output_name)
