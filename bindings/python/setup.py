"""Capnp grammar for tree-sitter"""

__version__ = "0.0.1"

from cffi import FFI
from setuptools import find_packages, setup

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
    file = ffibuilder.compile(verbose=True)
    setup(
        name="tree-sitter-capnp",
        version=__version__,
        description="Capnp grammar for tree-sitter",
        url="http://github.com/tree-sitter/tree-sitter-capnp",
        license="MIT",
        packages=find_packages(),
        package_data={
            "tree_sitter_capnp": [file.split("/")[-1]],
        },
        zip_safe=False,
        setup_requires=["cffi"]
    )
