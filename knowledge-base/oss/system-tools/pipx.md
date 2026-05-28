---
title: "Pipx快速入门"
date: 2021-12-06T00:14:50+08:00
tags:
  - python
categories:
  - dev
---

python 默认的包管理器是 pip，但是你要是真的用 pip 来管理你的 python 依赖的话，那么事情就麻烦了。因为 pip 只会简单的把包下载到本地，所以当你有多个项目需要不同版本的依赖时，就会出现问题。所以后来出现了很多虚拟环境之类的工具，就是为了帮助解决这个问题。甚至有些工具会直接给你一个建议，不要用 pip 安装包，用我们自己的方法。

如果你遇到这类问题，可以尝试一下 pipx。这是一个改进的包管理器，直接对标 brew、npx 以及 apt 这类工具，目的就是为 python 包创建一个隔离的环境保存自己的依赖，如此一来我们在安装 python 包的时候就不会遇到依赖冲突的问题了。

## 安装

安装 pipx 很简单，linux 下：

```sh
python3 -m pip install --user pipx
python3 -m pipx ensurepath
```

windows 下：

```sh
python -m pip install --user pipx
pipx ensurepath
```

好吧，其实是一样的命令。pipx 会把包安装到用户家目录的一个文件夹中，为了能够在终端中直接使用安装的包，你需要 `pipx ensurepath` 来将可执行文件的目录添加到环境变量中。如果你喜欢自己管理 dotfile 的话，可能还得自己编辑一下文件，将自动添加的环境变量放到合适的位置。

如果你使用 linux 的话，还可以查看一下如何设置 pipx 的补全。下面这条命令会列出添加补全的方式，bash、zsh 以及 fish 的办法都有。

```sh
pipx completions
```

## 使用

### 常用命令

其实 pipx 的使用方法和 pip 大体相同，而且如果你配置好了补全的话，其实已经完全可以自己输入命令玩了。不过这里还是简单列一下比较常用的命令，其实从这里也可以看出，我们完全可以用 pipx 替代 pip 完成日常的工作，至少它还有个升级所有包的选项不是。

```sh
pipx
    install             安装包
    inject              安装包到一个已有的虚拟环境中
    upgrade             升级包
    upgrade-all         升级所有包.为每个包运行`pip install -U <pkgname>`命令
    uninstall           卸载包
    uninstall-all       卸载所有包
    reinstall           重装包
    reinstall-all       重装所有包
    list                列出所有已安装的包
    run                 临时运行包
```

### pipx run

这里简单提一下 pipx 的一个有趣功能，临时运行包。这个功能会把软件包临时安装到一个虚拟环境中，pipx 会将这个环境保留几天，然后在删掉它。所以我们可以安心的使用这个功能临时运行一些包，然后把它忘掉。对了，这个功能还支持软件包的参数，所以，放心用吧！

```sh
pipx run pycowsay moo
```

如果你需要完整的文档的话，可以查看这里<https://pypa.github.io/pipx/docs/>。
