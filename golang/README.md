# Golang

Go 语言由 Rob Pike 等人设计，在参考了 C、Java 等语言后，选择了做减法的设计哲学。Go 摒弃了繁杂的语言特性，体现出大道至简的美学。其 goroutine 协程实现非常成功，对众多编程语言产生了深远影响——例如我喜爱的 Kotlin 协程就借鉴了 goroutine 的设计，了解其中任意一个都能轻松上手另一个。

然而，我入门编程时受 Java 影响较深，因此对 Go 的诸多特性感到不太适应：结构体实现接口、数据与实现分离、函数返回错误码而非异常等设计，都让我觉得颇为别捏。尽管 Go 性能出色且应用广泛，我仍无法将其作为主力语言使用。

当然，这仅是个人偏好。Go 语言多年来的成就有目共睹，其在语言特性上的取舍不能简单从单一维度评价——Go 的编译速度极快，运行体验近乎无需编译的脚本语言。可以说，Go 在多个维度上做出了恰当的取舍，这或许也是一门语言成功落地的必要代价。

整体而言，如果你欣赏 C 语言的简洁风格，而非 Java 式的面向对象编程，那么 Go 语言应该会很合你的胃口。

## 学习资料

建议优先阅读英文官方文档，许多中文资料更新滞后，可能存在翻译错误，容易让人困惑。

- [Official Documentation](https://go.dev/doc/)
- [A Tour of Go](https://go.dev/tour/list) —— 交互式入门教程
- [Go 入门指南](https://learnku.com/docs/the-way-to-go)
- [Go Web 编程](https://learnku.com/docs/build-web-application-with-golang)
- [Go 编码指南](https://learnku.com/go/wikis/38174)
- [Effective Go](https://learnku.com/docs/effective-go/2020)

## 开发环境

### 安装 Go

```sh
scoop install go
```

### VS Code 配置

需要安装以下扩展：

- Go 扩展，参考 [VS Code Go 文档](https://code.visualstudio.com/docs/languages/go)
- [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) —— 用于运行单文件代码

首次打开 Go 源代码文件时，VS Code 会提示安装必要的工具，全部安装完成后即可开始开发。

推荐配置：

```json
{
  "[go]": {
    "editor.defaultFormatter": "golang.go"
  },
  "go.formatTool": "goimports",
  "go.toolsManagement.autoUpdate": true,
  "go.useLanguageServer": true,
  "gopls": {
    "formatting.gofumpt": true,
    "ui.semanticTokens": true
  }
}
```

如需隔离开发环境，也可使用 VS Code 的 Dev Container 功能。本地开发通常足够，但若使用 Avast 等杀毒软件，可能会对生成的 exe 文件进行扫描影响效率，此时容器化开发是更好的选择。

## 代码示例

- **go-demo** —— Go 基础示例，全部为单文件无依赖代码，用于学习 Go 基础语法
- **gomod-demo** —— Go Modules 示例

---

My Go language learning notes.

Go was designed by Rob Pike and others. After referencing languages like C and Java, they chose a minimalist design philosophy. Go abandons complex language features, embodying the beauty of simplicity through subtraction. Its goroutine implementation is highly successful and has had a profound impact on many programming languages—for example, Kotlin coroutines, which I love, draw from goroutine design. Knowing either one makes learning the other quite easy.

However, I was heavily influenced by Java when I started programming, so many of Go's features feel unfamiliar to me: structs implementing interfaces, the separation of data and implementation, functions returning error codes instead of exceptions—all feel quite awkward to me. Although Go performs well in various aspects and is now very popular in many domains, I still cannot use it as my primary language.

Of course, this is just my personal preference. Go's achievements over the years are undeniable, and its choices in language features cannot be simply evaluated from a single perspective—Go's compilation speed is truly fast, giving me a feeling of a scripting language that doesn't need compilation. It's fair to say that Go has made good trade-offs in several aspects, perhaps at the necessary cost of successfully bringing a language to production.

Overall, if you like C's approach rather than Java-style object-oriented programming, then you should also like Go.

## Learning Resources

It is recommended to prioritize reading English official documentation. Many Chinese resources are slow to update and may contain translation errors, which can be confusing.

- [Official Documentation](https://go.dev/doc/)
- [A Tour of Go](https://go.dev/tour/list) — Interactive beginner's tutorial
- [The Way to Go](https://learnku.com/docs/the-way-to-go)
- [Build Web Application with Golang](https://learnku.com/docs/build-web-application-with-golang)
- [Go Coding Guide](https://learnku.com/go/wikis/38174)
- [Effective Go](https://learnku.com/docs/effective-go/2020)

## Development Environment

### Installing Go

```sh
scoop install go
```

### VS Code Configuration

The following extensions need to be installed:

- Go extension, refer to [VS Code Go documentation](https://code.visualstudio.com/docs/languages/go)
- [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) — for running single-file code

When you first open a Go source code file, VS Code will prompt you to install necessary tools. Once all are installed, you can start developing.

Recommended configuration:

```json
{
  "[go]": {
    "editor.defaultFormatter": "golang.go"
  },
  "go.formatTool": "goimports",
  "go.toolsManagement.autoUpdate": true,
  "go.useLanguageServer": true,
  "gopls": {
    "formatting.gofumpt": true,
    "ui.semanticTokens": true
  }
}
```

If you need an isolated development environment, you can also use VS Code's Dev Container feature. Local development is usually sufficient, but if you use antivirus software like Avast, it may scan generated exe files and affect efficiency—in such cases, containerized development is a better choice.

## Code Examples

- **go-demo** — Go basic examples, all single-file instances with no dependencies, for learning Go fundamentals
- **gomod-demo** — Go Modules examples
