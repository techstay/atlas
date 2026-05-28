# dotnet

我的 dotnet 学习笔记。

## 开发环境

C# 是主流编程语言之一，开发环境支持也很完善。Visual Studio 和 Rider 都是非常流行的 IDE，开箱即用。这里简单记录一下 VS Code 的配置经验。

### dotnet SDK

首先需要安装 dotnet SDK。可以安装 [dotnet coding pack](https://aka.ms/dotnet-coding-pack-win)，它包含了 VS Code、dotnet SDK 等工具链，方便初学者使用。如果喜欢自行折腾，也可以直接安装 [dotnet SDK](https://aka.ms/vscDocs/dotnet/download)。

### 配置 VS Code

使用 VS Code 作为开发环境，需要安装以下扩展：

- [dotnet extension pack](https://marketplace.visualstudio.com/items?itemName=ms-dotnettools.vscode-dotnet-pack)
- Code Runner
- Polyglot Notebooks

对于学习一门语言，比较好的实践是把每个例子单独放在一个文件中运行。如果能像 Jupyter Notebook 那样交互式运行，对初学者来说最为友好。但这种折中方案比较适合脚本语言，而 C# 这类语言目前还没有成熟的类似工具。

因此我采用了混合方案：创建一个项目，用单元测试的方式为每个例子编写一个单元测试文件。对于简单的例子，用单元测试需要写大量样板代码，增加复杂度，这时我会选择编写 `.csx` 脚本文件，直接运行单个文件，更加方便。

#### dotnet-script

第一种方法是使用 dotnet-script 工具。首先需要全局安装 dotnet-script：

```sh
dotnet tool install -g dotnet-script
```

将 C# 文件保存为 `.csx` 格式，然后使用以下命令运行：

```sh
dotnet script helloworld.csx
```

每次输入命令比较麻烦，可以将 dotnet-script 配置到 Code Runner 中。之后只需点击编辑器右上角的运行按钮即可执行文件。

```json
{
  "code-runner.executorMap": {
    "csharp": "dotnet script"
  }
}
```

#### polyglot-notebook

第二种方法是使用 Polyglot Notebooks，这是微软开发的交互式环境，可以像 Jupyter Notebook 一样交互式运行 C# 和 F# 等 .NET 平台的语言。目前还在预览阶段，功能尚不成熟，比如缺少代码格式化功能，但整体已属于可用状态。

安装扩展后，创建 `.dib` 或 `.ipynb` 格式的文件，即可在其中编写代码并交互式执行。

### 学习资源

- [微软官方文档](https://learn.microsoft.com/en-us/dotnet/csharp/)

### WinUI3

- [MSDN 文档](https://learn.microsoft.com/en-us/windows/apps/desktop/)
- [官方设计文档](https://learn.microsoft.com/en-us/windows/apps/design/)
- [样例程序](https://learn.microsoft.com/en-us/windows/apps/design/downloads/)

### WPF

- [WPF 教程](https://wpf-tutorial.com/Localization/LanguageStatus/zh/)

### 代码示例

- [csharp-sample](./csharp-sample/README.md) — C# 学习笔记
- [fsharp-sample](./fsharp-sample/README.md) — F# 学习笔记
- [VisualBasicStudy](./VisualBasicStudy/README.md) — VB 学习笔记
- [dotnet-libraries](./dotnet-libraries/README.md) — 一些 .NET 类库的例子

---

### Development Environment (EN)

C# is one of the mainstream programming languages with excellent IDE support. Both Visual Studio and Rider are popular IDEs that work out of the box. Here I'll briefly record my experience with VS Code configuration.

#### dotnet SDK (EN)

First, you need to install the dotnet SDK. You can install the [dotnet coding pack](https://aka.ms/dotnet-coding-pack-win), which includes VS Code, dotnet SDK, and other toolchains, making it convenient for beginners. If you prefer to set things up yourself, you can directly install the [dotnet SDK](https://aka.ms/vscDocs/dotnet/download).

#### VS Code Configuration (EN)

Using VS Code as the development environment requires installing the following extensions:

- [dotnet extension pack](https://marketplace.visualstudio.com/items?itemName=ms-dotnettools.vscode-dotnet-pack)
- Code Runner
- Polyglot Notebooks

For learning a language, a good practice is to put each example in a separate file. Being able to run interactively like Jupyter Notebook is most friendly for beginners. However, this approach works best for scripting languages, and C# doesn't have mature similar tools yet.

So I use a hybrid approach: create a project and write unit tests for each example. For simple examples, using unit tests requires a lot of boilerplate code, adding complexity. In such cases, I write `.csx` script files and run them directly, which is more convenient.

##### dotnet-script (EN)

The first method is to use the dotnet-script tool. First, install it globally:

```sh
dotnet tool install -g dotnet-script
```

Save your C# file as `.csx` format and run it with:

```sh
dotnet script helloworld.csx
```

Typing the command every time is cumbersome. You can configure dotnet-script in Code Runner, then simply click the run button in the editor's top-right corner to execute files.

```json
{
  "code-runner.executorMap": {
    "csharp": "dotnet script"
  }
}
```

##### Polyglot Notebooks (EN)

The second method is to use Polyglot Notebooks, an interactive environment developed by Microsoft that allows running C# and F# and other .NET languages interactively like Jupyter Notebook. It's still in preview, so the features aren't fully mature—for example, it lacks code formatting. But overall, it's already usable.

After installing the extension, create a `.dib` or `.ipynb` file, then you can write code and execute it interactively.

### Learning Resources (EN)

- [Microsoft Official Documentation](https://learn.microsoft.com/en-us/dotnet/csharp/)

### WinUI3 (EN)

- [MSDN Documentation](https://learn.microsoft.com/en-us/windows/apps/desktop/)
- [Official Design Documentation](https://learn.microsoft.com/en-us/windows/apps/design/)
- [Sample Programs](https://learn.microsoft.com/en-us/windows/apps/design/downloads/)

### WPF (EN)

- [WPF Tutorial](https://wpf-tutorial.com/Localization/LanguageStatus/zh/)

### Code Samples (EN)

- [csharp-sample](./csharp-sample/README.md) — C# Learning Notes
- [fsharp-sample](./fsharp-sample/README.md) — F# Learning Notes
- [VisualBasicStudy](./VisualBasicStudy/README.md) — VB Learning Notes
- [dotnet-libraries](./dotnet-libraries/README.md) — Examples of .NET Libraries
