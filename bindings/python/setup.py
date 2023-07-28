from setuptools import setup, find_packages
from cffi import FFI

ffibuilder = FFI()

ffibuilder.set_source(
    "tree_sitter_capnp._tree_sitter_capnp",
    """
    #include "../../../src/tree_sitter/parser.h"
    extern const TSLanguage *tree_sitter_capnp();
    """,
    # if you have a scanner, you need to include it here too
    sources=["../../src/parser.c"],
    include_dirs=[
        "../../src"
    ],
)

ffibuilder.cdef("""
    typedef struct TSLanguage TSLanguage;
    const TSLanguage *tree_sitter_capnp(void);
""")

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
    setup(
        name='tree-sitter-capnp',
        version='0.0.1',
        description='Capnp grammar for tree-sitter',
        url='http://github.com/tree-sitter/tree-sitter-capnp',
        license='MIT',
        packages=find_packages(),
        package_data={
            'tree_sitter_capnp': ['_tree_sitter_capnp.cpython-311-darwin.so'],
        },
        zip_safe=False
    )
