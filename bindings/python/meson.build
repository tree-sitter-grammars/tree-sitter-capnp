project(
  'tree-sitter-capnp',
  'c',
  license: 'MIT',
  meson_version: '>=0.64.0',
)

python = import('python').find_installation('python3', modules: ['cffi'], pure: false)
python_dep = python.dependency(required: true)

ts_cffi_srcs = configure_file(
  command: [python, files('ffibuilder.py'), '@OUTPUT@'],
  output: '_tree_sitter_capnp.c',
)

python.extension_module(
    '_tree_sitter_capnp',
    ts_cffi_srcs,
    '../../src/parser.c',
    # if you have a scanner, uncomment next line
    # '../../src/scanner.c',
    install: true,
    subdir: 'tree_sitter_capnp',
)

python.install_sources('tree_sitter_capnp/__init__.py', preserve_path: true)
