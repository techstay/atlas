---
id: 97qv1iqlcfp6fbtqqsm81eo
title: Fsharp
desc: ""
updated: 1753732934796
created: 1753732930856
---

我的 fsharp 学习代码。

## 开发环境

目前主流的 F#开发环境有 Visual Studio,Rider 以及 Visual Studio Code,我这里使用 vscode 作为开发环境.

首先安装 [dotnet SDK](https://dotnet.microsoft.com/en-us/download)，一般安装最新版(目前是 DOTNET 7)即可，以及 Visual Studio 2022，安装相应的工作负载。

然后安装以下扩展：

- ionide，vscode 编辑器的 F#扩展，提供完整的 F#语言支持，包括语法高亮、代码补全和格式化等功能
- polyglot notebook，以 jupyter notebook 的交互式方式来编辑和运行 F#以及 C#代码，这个工具目前还在开发中，缺少代码格式化的功能，有点可惜

要执行代码的时候，有三种方式，第一种就是在 F#交互式窗口中运行，先选中要执行的代码，然后按`Alt+Enter`就能在交互式窗口中执行代码了。第二种方式是将代码写成 F#脚本的格式(后缀名`.fsx`)，这样一来，vscode 上就会显示出执行脚本的按钮，点击即可执行单个脚本。

第三种方式是使用 polyglot notebook 扩展，将 F#代码写成 notebook 的形式，可以交互式运行，非常适合学习。唯一缺点就是目前没有代码格式化的功能，只能先在编辑器中写好，然后复制粘贴到 notebook 中。不过代码格式化的功能以后肯定会跟进，可以期待一下。

## 学习资源

- [微软官方 F#文档](https://learn.microsoft.com/en-us/dotnet/fsharp/)
