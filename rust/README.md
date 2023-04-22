# rust

我的 rust 学习笔记

rust 是一门强大、安全且高性能的系统编程语言。

- [rust-sample](./rust-sample//README.md)，一些 rust 示例
- [thirdparty-crates](./thirdparty-crates/README.md)，一些第三方 crates 的示例

## 开发环境

这里采用 vscode 编辑器配合 rust-analyzer LSP 实现 IDE 功能。

### rustup

安装 rustup 工具，同时会自动为我们安装最新的稳定版 rust 工具链。

```sh
scoop install rustup
```

检查编译器版本

```sh
rustc --version
```

### 编辑器

rust-analyzer 是官方的语言分析模块，支持多种 IDE 和编辑器，可通过 vscode 安装。以下是我的配置，启用了 clippy 以提供更详细的代码检查。

```json
{
  "rust-analyzer.check.command": "clippy",
  "rust-analyzer.diagnostics.experimental.enable": true,
  "rust-analyzer.hover.actions.references.enable": true,
  "rust-analyzer.interpret.tests": true,
  "rust-analyzer.lens.references.adt.enable": true,
  "rust-analyzer.lens.references.enumVariant.enable": true,
  "rust-analyzer.lens.references.method.enable": true,
  "rust-analyzer.lens.references.trait.enable": true,
  "rust-analyzer.semanticHighlighting.operator.specialization.enable": true,
  "rust-analyzer.semanticHighlighting.punctuation.enable": true,
  "rust-analyzer.semanticHighlighting.punctuation.specialization.enable": true,
  "rust-analyzer.typing.autoClosingAngleBrackets.enable": true
}
```

配置完成后，就可以编写代码了。rust 语言有官方的管理工具 cargo，可以非常方便的进行项目的编译、测试、运行、依赖、打包、发布等。为了省事，我自己的代码就以 example 的形式写在`examples/`目录下，可以通过`cargo run --example <filename>`的方式运行。工具链正常的话，在 vscode 中也会显示运行命令，点击即可运行代码。

## 学习

- [官方文档](https://www.rust-lang.org/learn)
- [标准库文档](https://doc.rust-lang.org/std/index.html)
- [rust 程序设计语言中文版](https://kaisery.github.io/trpl-zh-cn/foreword.html)
- [rust 程序设计语言英文原版](https://doc.rust-lang.org/stable/book/foreword.html)
- [rust by example](https://doc.rust-lang.org/stable/rust-by-example/meta/doc.html)
- [cargo book](https://doc.rust-lang.org/cargo/index.html)
- <https://lib.rs/>
- [学习经验](https://alabaster-linen-4dc.notion.site/Rust-26d05fe77cd44d18a294510cb23dd2c5)
