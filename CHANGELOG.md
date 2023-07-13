# Changelog

## [1.5.0](https://github.com/amaanq/tree-sitter-capnp/compare/tree-sitter-capnp-v1.4.0...tree-sitter-capnp-v1.5.0) (2023-07-13)


### Features

* add ci ([7d02f68](https://github.com/amaanq/tree-sitter-capnp/commit/7d02f6806f26e6e403827b4b01b41c7bd88413d4))
* add ci ([73cbbc5](https://github.com/amaanq/tree-sitter-capnp/commit/73cbbc50b940b55a9b3f02ab10ef67f233e5c8bb))
* add embedded_files ([b8a15c2](https://github.com/amaanq/tree-sitter-capnp/commit/b8a15c22052e0654d56905b08f796c9eebb68b68))
* add examples ([b272445](https://github.com/amaanq/tree-sitter-capnp/commit/b2724453a41028e22d3c75a0122130fc6826c206))
* add folds, update tests, generate ([22c1bdb](https://github.com/amaanq/tree-sitter-capnp/commit/22c1bdb260779869fa4d30f941f7de1037ec2b53))
* add Swift bindings ([ca52fbd](https://github.com/amaanq/tree-sitter-capnp/commit/ca52fbda8ae4452be9e1296922f7da3c5d376e1a))
* add tests to cover nearly everything ([8897980](https://github.com/amaanq/tree-sitter-capnp/commit/8897980e0cbd5f48268ac974817a3c41726ee36c))
* apply generics to more places where they should be, add block text, refactor annotation_literal and fix conflict, add same-scope constants accessed by . ([009a826](https://github.com/amaanq/tree-sitter-capnp/commit/009a826736cd1cdefe8260541d579b9a179ceda5))
* differentiate escape sequences in strings to highlight them differently, add file docs, remove some redundant aliases ([20e619b](https://github.com/amaanq/tree-sitter-capnp/commit/20e619b36eb2d4d493547a0fbfe1f2bec6248add))
* disable arrow-parens as it doesn't follow convention ([10804f5](https://github.com/amaanq/tree-sitter-capnp/commit/10804f58fc6feeeac6c1a4253f2f74b812bdb364))
* gif of highlights in README ([3e1d867](https://github.com/amaanq/tree-sitter-capnp/commit/3e1d867dbc1429b21fde9b6d7e050212bc64a665))
* initial definitions ([853ae37](https://github.com/amaanq/tree-sitter-capnp/commit/853ae37a489d4eaebba4d3288411c12a147a1f5a))
* initial experimental parser, use segmented identifiers like thrift ([6b8d519](https://github.com/amaanq/tree-sitter-capnp/commit/6b8d5193a66f1c19a7bcb8e0cc6f77b04578bd1d))
* initial queries ([36a103d](https://github.com/amaanq/tree-sitter-capnp/commit/36a103d0b0aecf5668d22129ad541826377a1cd4))
* initial test ([4da19e7](https://github.com/amaanq/tree-sitter-capnp/commit/4da19e7c910a834c0163a09d0ecd9d81ba00bcb1))
* misc tidying ([d1e4fd4](https://github.com/amaanq/tree-sitter-capnp/commit/d1e4fd404c9b8a934d540ca6fc3fadb53fa0f2d4))
* multi-string literal ([6d19dc0](https://github.com/amaanq/tree-sitter-capnp/commit/6d19dc029e8132d048777c38666e010857d14d6b))
* **queries:** update highlights, add indents, injections, and locals ([e022cd0](https://github.com/amaanq/tree-sitter-capnp/commit/e022cd090998961611330f1f6d1ac21ec09cd813))
* README ([c537127](https://github.com/amaanq/tree-sitter-capnp/commit/c5371278f5851ca7f9c85b0c018dcbf2e59d49f3))
* segment parameters for folds ([6c495b1](https://github.com/amaanq/tree-sitter-capnp/commit/6c495b15eed64d8562b4098b0d0accb736a99cab))
* **test:** struct ([097edb4](https://github.com/amaanq/tree-sitter-capnp/commit/097edb450eb185a4b48fb4af486f0b63b4c84a42))
* update highlights ([b44878f](https://github.com/amaanq/tree-sitter-capnp/commit/b44878fadf4720e8e05267587f8678ca490d4019))
* use release-please ([7d9e58d](https://github.com/amaanq/tree-sitter-capnp/commit/7d9e58d480aa1611a3fc5a31935f5080ec5e02a8))
* v1.3.0 ([6136289](https://github.com/amaanq/tree-sitter-capnp/commit/6136289bed7ae0d2cdd58f0c26ea234a6f037a28))
* v1.4.0 ([7d5fa4e](https://github.com/amaanq/tree-sitter-capnp/commit/7d5fa4e94d3643ec15750106113be0d40f9fc1bb))


### Bug Fixes

* apply [@the](https://github.com/the)Hamsta's and @ObserverOfTime's suggestions ([b37a22b](https://github.com/amaanq/tree-sitter-capnp/commit/b37a22b06ba28bfd32018fce39c4277c13bdeb77))
* **highlights:** [@type](https://github.com/type).builtin should've been [@keyword](https://github.com/keyword), List is not a keyword, add property to hl ([a618a8f](https://github.com/amaanq/tree-sitter-capnp/commit/a618a8fed4146f34554cbeb76d5795ecf2a92174))
* identifiers under const_value are a const_identifier ([aa96e50](https://github.com/amaanq/tree-sitter-capnp/commit/aa96e5060e39ee8a25dcdd631499468b4ebb4cc4))
* named_return_types and implicit_generics broke folds ([05383e4](https://github.com/amaanq/tree-sitter-capnp/commit/05383e45b0052ac53a9e75283445e4c7e5187669))
* **queries:** embed ([b85249d](https://github.com/amaanq/tree-sitter-capnp/commit/b85249d15a5800196922cac3cd07d97c8b9fac1c))
* **queries:** remove custom_type duplicate reference ([fc6e2ad](https://github.com/amaanq/tree-sitter-capnp/commit/fc6e2addf103861b9b3dffb82c543eb6b71061aa))
* refactor union to have unnamed be a keyword, but allow it as an ident (fixed bug where this would cause an error without token), refactor annotation and data_hex, make idents in consts [@constant](https://github.com/constant) ([70936e3](https://github.com/amaanq/tree-sitter-capnp/commit/70936e3b78d9ca19321bf5361a63175b1c4d466c))
* remove comment ([5d1e602](https://github.com/amaanq/tree-sitter-capnp/commit/5d1e6029380922d29990f5054240ed75f4169928))
* remove package-lock.json ([8e6b856](https://github.com/amaanq/tree-sitter-capnp/commit/8e6b8561170c4767720857e3f1dec019f49c6084))
* segment group for keyword hl, split up consts in the form of const foo = ident.constant, so the last item can be const-highlighted ([74208c6](https://github.com/amaanq/tree-sitter-capnp/commit/74208c60d1edce8d47f42b98e80d49b78782ef56))
