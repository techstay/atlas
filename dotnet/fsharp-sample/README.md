# fsharp-sample

我的 F# 学习代码。

---

## 开发环境

目前主流的 F# 开发环境有 Visual Studio、Rider 以及 Visual Studio Code。我这里使用 VSCode 作为开发环境。

首先安装 [dotnet SDK](https://dotnet.microsoft.com/en-us/download)，一般安装最新版（目前是 .NET 7）即可，以及 Visual Studio 2022，安装相应的工作负载。

然后安装以下扩展：

- **ionide**：VSCode 编辑器的 F# 扩展，提供完整的 F# 语言支持，包括语法高亮、代码补全和格式化等功能
- **polyglot notebook**：以 Jupyter Notebook 的交互式方式来编辑和运行 F# 以及 C# 代码。这个工具目前还在开发中，缺少代码格式化的功能，有点可惜

要执行代码的时候，有三种方式：

1. **F# 交互式窗口**：选中要执行的代码，然后按 `Alt+Enter` 就能在交互式窗口中执行代码了
2. **F# 脚本**：将代码写成 F# 脚本的格式（后缀名 `.fsx`），这样 VSCode 上就会显示出执行脚本的按钮，点击即可执行单个脚本
3. **Polyglot Notebook**：使用 polyglot notebook 扩展，将 F# 代码写成 Notebook 的形式，可以交互式运行，非常适合学习。唯一缺点就是目前没有代码格式化的功能，只能先在编辑器中写好，然后复制粘贴到 Notebook 中。不过代码格式化的功能以后肯定会跟进，可以期待一下

## 学习资源

- [微软官方 F# 文档](https://learn.microsoft.com/en-us/dotnet/fsharp/)

---

## Development Environment

The mainstream F# development environments are Visual Studio, Rider, and Visual Studio Code. I use VSCode as my development environment here.

First, install the [dotnet SDK](https://dotnet.microsoft.com/en-us/download) (usually the latest version, currently .NET 7) and Visual Studio 2022 with the appropriate workloads.

Then install the following extensions:

- **ionide**: An F# extension for VSCode that provides complete F# language support, including syntax highlighting, code completion, and formatting
- **polyglot notebook**: Allows editing and running F# and C# code in an interactive Jupyter Notebook style. This tool is still in development and lacks code formatting functionality, which is a bit of a shame

There are three ways to execute code:

1. **F# Interactive Window**: Select the code to execute and press `Alt+Enter` to run it in the interactive window
2. **F# Script**: Write code in F# script format (with `.fsx` extension). VSCode will show a button to execute the script
3. **Polyglot Notebook**: Use the polyglot notebook extension to write F# code in Notebook format for interactive execution, which is great for learning. The only drawback is the lack of code formatting, so you need to write the code in an editor first and then copy it to the Notebook. However, code formatting will likely be added in the future

## Learning Resources

- [Microsoft Official F# Documentation](https://learn.microsoft.com/en-us/dotnet/fsharp/)
