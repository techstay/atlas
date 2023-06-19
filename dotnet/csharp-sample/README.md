# csharp-sample

我的 c#学习笔记.

微软新出的 polyglot-notebook 非常适合用来学习 C#和 F#,但是目前因为没有代码格式化的功能,而我恰好就是一个代码强迫症患者,没有格式化的代码就会让我如鲠在喉.所以目前 C#的学习进度就先搁置一下.等到过段时间扩展完善了之后,我再回来补充吧.

## 开发环境

### 配置 vscode

这里使用 vscode 作为开发环境,需要安装以下扩展:

- 官方 C#扩展
- Code Runner
- Polyglot Notebooks

代码文件以单文件的方式编排,方便各自单独执行.要运行 C#文件,有以下几种方式.

#### dotnet-script

第一种办法是使用 dotnet-script 工具.首先需要安装 dotnet-script 工具.

```sh
dotnet tool install -g dotnet-script
```

然后将你的 C#文件保存为`.csx`格式,然后使用以下命令就可以运行了.

```sh
dotnet script helloworld.csx
```

每次使用命令运行也比较麻烦,可以将其配置到 Code Runner 中,这样以后只需要点击编辑器右上角的运行按钮就可以运行文件了.

```json
{
  "code-runner.executorMap": {
    "csharp": "dotnet script"
  }
}
```

#### polyglot-notebook

第二种办法是使用 polyglot-notebook,这是微软开发的一个交互式环境,可以像 jupyter-noteobook 那样用交互式的方式来运行 C#和 F#等 dotnet 平台的语言.目前还在预览阶段,所以功能还不够成熟,比如目前就没有代码格式化的功能,这是一个缺憾,其他方面倒还不错,已经属于可用阶段.

安装好扩展之后,创建`.dib`或者`.ipynb`格式的文件,然后就可以在其中编写代码并交互式执行了.

## 学习

- [微软官方文档](https://learn.microsoft.com/en-us/dotnet/csharp/)
