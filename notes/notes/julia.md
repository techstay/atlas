---
id: 3pougjv4bww667lw4b6or6a
title: Julia
desc: ""
updated: 1753733310866
created: 1753733310866
---

julia 是一门新设计的用于科学计算的高性能语言。我个人还是挺喜欢 julia 的，但是看了一圈文档抄了一遍例子，感觉 julia 这个语言的问题还是在于社区和生态不够完善。这其实是很多新生语言的共同问题，而这个问题又会极大的影响后来者的学习。

比如 Python 这门语言，借着人工智能等风口，起飞了一次又一次，社区生态非常完善，各式各样的类库应有尽有。仅拿编写代码来说，Python 就有非常完善的代码格式化、提示、纠错等第三方类库和扩展的支持，在 vscode 中编写代码非常舒适，交互式生态也做的非常完善，jupyter notebook 几乎可以说是业界标准。更别说海量的类库，几乎可以帮助完成任何工作。julia 在这些方面几乎完全不可能赶上。

抛开这些不谈，julia 语言设计的一些地方还是很戳我的，像常数和变量之间可以无需乘号，像输入`\pi`就能直接转换成对应的 unicode 字符`π`，都是让人眼前一亮的小功能。这些小细节配合各种类库使用起来，应该也会给人更好的体验。希望 julia 能够在这些方面赶上来。

## 开发环境

### 安装 julia

```sh
scoop install julia
```

### vscode 配置

首先安装`julia-vscode`扩展，这样即可启用 julia 的语法高亮和代码提示等功能。julia 扩展默认没有自带代码格式化功能，需要额外安装第三方包才能实现。

运行代码最方便的方式就是使用快捷键`Shift+Alt+Enter`，启动`Julia: Execute Code Cell in REPL`命令，这样按照交互式代码格的方式来执行 julia 代码，返回值会实时显示在语句旁边。各个单元格之间以`##`符号分隔开。

### 代码格式化

安装 JuliaFormatter，在 julia 交互环境中输入以下命令

```sh
]add JuliaFormatter
```

### Pluto.jl

一个 julia web 界面交互工具。

打开`julia`交互终端，输入`]`进入包管理界面，输入`add Pluto`安装 Pluto。

然后就可以在代码中利用 Pluto 了。

参考<https://github.com/fonsp/Pluto.jl/blob/main/sample/Basic.jl>

## 学习

- [julia 官方文档](https://docs.julialang.org/en/v1/)
- [julia 中文文档](https://docs.juliacn.com/latest/)，英文不好的同学可以看看，我估计大多数人应该都会先看中文文档吧，毕竟 julia 文档里专业词汇还挺多的，直接看英文版太费劲了。可惜中文版翻译并不及时，目前最新文档版本 1.9，而中文版文档只有 1.7，需要查阅最新内容的话还是需要翻一翻最新文档的
- [style guide](https://docs.julialang.org/en/v1/manual/style-guide/#Style-Guide)
- [mth229](https://mth229.github.io/)
