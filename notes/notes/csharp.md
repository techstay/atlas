---
id: yv62zuikybassv1ad56kur4
title: Csharp
desc: ""
updated: 1753733058997
created: 1753732864256
---

我的 c# 学习笔记。

## 开发环境

C#作为一门主流的语言，各种开发环境的支持也比较完善。像 Visual Studio、Rider 都是很流行的 IDE，开箱即用。这里简单记录一下折腾 vscode 的经验。

### dotnet sdk

首先需要安装 dotnet sdk，可以安装[dotnet coding pack](https://aka.ms/dotnet-coding-pack-win)，包含了 vscode、dotnet sdk 等工具链，方便初学者安装。如果喜欢自己折腾，也可以先安装[dotnet sdk](https://aka.ms/vscDocs/dotnet/download)。

### 配置 vscode

这里使用 vscode 作为开发环境，需要安装以下扩展:

- [dotnet extension pack](https://marketplace.visualstudio.com/items?itemName=ms-dotnettools.vscode-dotnet-pack)
- Code Runner
- Polyglot Notebooks

代码文件按照不同的方式组织，其实我觉得学习一个语言比较好的实践就是每一个例子单独一个文件运行，最好像 jupyter notebook 那种交互式方式，最适合初学者学习。但是折中方式最适合脚本语言，像 C#这种语言并没有完善的相关工具，所以到最后我还是老办法，整一个项目，用单元测试的方式，每个例子一个单元测试文件。

对于简单的例子，用单元测试的方式要写大量样板代码，徒增复杂度，所以这种情况我选择编写`.csx`脚本文件，直接运行单个文件，更加方便。

#### dotnet-script

第一种办法是使用 dotnet-script 工具。首先需要安装 dotnet-script 工具。

```sh
dotnet tool install -g dotnet-script
```

然后将你的 C#文件保存为`.csx`格式，然后使用以下命令就可以运行了。

```sh
dotnet script helloworld.csx
```

每次使用命令运行也比较麻烦，可以将其配置到 Code Runner 中，这样以后只需要点击编辑器右上角的运行按钮就可以运行文件了。

```json
{
  "code-runner.executorMap": {
    "csharp": "dotnet script"
  }
}
```

#### polyglot-notebook

第二种办法是使用 polyglot-notebook，这是微软开发的一个交互式环境，可以像 jupyter notebook 那样用交互式的方式来运行 C#和 F#等 dotnet 平台的语言。目前还在预览阶段，所以功能还不够成熟，比如目前就没有代码格式化的功能，这是一个缺憾，其他方面倒还不错，已经属于可用阶段。

安装好扩展之后，创建`.dib`或者`.ipynb`格式的文件，然后就可以在其中编写代码并交互式执行了。

## 学习

- [微软官方文档](https://learn.microsoft.com/en-us/dotnet/csharp/)

## WinUI3

- MSDN 文档<https://learn.microsoft.com/en-us/windows/apps/desktop/>
- 官方设计文档<https://learn.microsoft.com/en-us/windows/apps/design/>
- [样例程序](https://learn.microsoft.com/en-us/windows/apps/design/downloads/)

## WPF

- [WPF 教程](https://wpf-tutorial.com/Localization/LanguageStatus/zh/)
