---
title: "Poetry快速入门"
date: 2021-12-06T00:47:28+08:00
tags:
  - python
categories:
  - dev
---

其实很久之前我介绍过 pipenv 这么一个 python 环境的依赖管理工具，当时我简单试用了一下，感觉这个东西还是蛮好用的，而且 heroku 当时也支持 pipenv。所以就写了文章介绍了一下这个东东。不过后来也没深入使用，前几天发现了 poetry 这么一个依赖管理工具，我就简单看了一下。一番考察之后，我决定以后就用 poetry 了，所以就有了这么一篇文章，为大家简单介绍一下 poetry 这个工具。

## poetry vs pipenv

首先我们要解决一个问题：为什么要选择 poetry 而不是 pipenv，或者比较的更广泛一点，为什么不直接用 pip 和 requirements.txt 呢？其实答案当然很简单，因为更加方便。当然这个东西其实是有一点主观性的，所以如果你手头上有一大堆基于 pip 和 requirements.txt 的项目，要迁移起来比较麻烦的话，我的建议就是继续用 pip 吧，poetry 不是刚需，没必要给自己没事找事。

但是如果你愿意尝试新东西，玩一点花的，我觉得 poetry 这个东西真的挺不错的。当然当初我也是这么看 pipenv 的，不过 poetry 确实做的比 pipenv 更好一点。所以一番比较之下我决定还是选择 poetry 了。

我选择 poetry 主要有以下几点：

- 标准支持。pipenv 使用自己的配置文件来管理项目依赖。而 poetry 则使用的是 [PEP 518](https://www.python.org/dev/peps/pep-0518/) 标准，以后支持也会更加广泛。
- 配置文件格式。pipenv 使用环境变量来进行配置，在 linux 上还好，多几行 export 的事而已；在 windows 上配置就比较繁琐了。而 poetry 则使用配置文件，可以很方便的进行配置，也更容易保存到 dotfiles 里面。当然 poetry 也支持环境变量配置。
- 更友好的软件行为。虽然当初我试用 pipenv 的感觉还不错，但是搜索了一下发现 pipenv 其实坑还挺多的。而 poetry 也在很多方面对 pipenv 进行了改进，官方 [README](https://github.com/python-poetry/poetry#what-about-pipenv) 也有说明。
- 速度。poetry 的速度也比 pipenv 要快一些。

所以最后我就决定使用 poetry 了。

## 安装

poetry 官方推荐使用它们自己的安装脚本来进行安装。不过我个人其实不太喜欢这种方式，毕竟我一直都觉得这些安装脚本其实挺危险的，别的不说创建一堆乱七八糟的文件夹，强迫症肯定是忍不了了。但是，这里也不建议直接使用 pip 安装，虽然确实可以这么做。因为我确实这么试了一下，然后发现这个东东的依赖还是蛮多的，所以 pip 一口气下载了很多个依赖。但是问题来了，pip 的工作其实很简单，就是把包下载到本地，所以很容易出现依赖冲突的问题。从这个意义上来说，pip 有点像一个学校宿舍里的垃圾桶，你应该放里面放东西，但是其实你又不能往里面放东西。

所以我更推荐用 pipx 来安装 poetry，pipx 是一个 pip 改进版，会单独处理每一个依赖，所以不会出现 pip 的问题，可以放心使用。而 pipx 本身依赖很少，用 pip 来安装 pipx 并不会出现什么问题。虽然有点套娃的味道，但是确实最好这么做。

```sh
pipx install poetry
```

如果你用 linux 的话，可以先找找系统的包管理器里面有没有，有的话直接安装就完事了。

```sh
sudo pacman -S python-poetry
```

当然，其实话说回来直接用 pip 来安装 poetry 也不是不行。毕竟既然都用 poetry 了，那么以后项目肯定也都是虚拟环境了，系统公共依赖怎么样其实也无所谓了。不过正如前面所说，这并不是一个很好的选择。

## 配置

我知道你们肯定想看怎么使用 poetry 了，不过且慢！首先要做的不是用 poetry 运行一个项目，而是修改一下配置。毕竟我估计很多人和我一样，第一次运行完 poetry 命令之后的事情就是搜索它的默认虚拟环境文件夹在哪里，然后跑过去删掉，然后再把虚拟环境改到项目目录下面。

默认情况下，poetry 会把配置文件保存到以下位置。

- macOS: `~/Library/Application Support/pypoetry`
- Windows: `C:\Users\<username>\AppData\Roaming\pypoetry`
- linux: `$XDG_CONFIG_HOME` 里面，通常情况下是 `~/.config/pypoetry`

poetry 的配置也分为全局配置和项目配置，如果要修改项目配置，在命令上添加 `--local` 参数即可。不过大部分配置我们不用关心，一般情况下只需要将虚拟环境的位置放到项目目录里面即可。

```sh
poetry config virtualenvs.in-project true
```

## 使用

这里简单列一下常用命令：

```sh
# 没有文件夹，创建新项目
poetry new my-package
# 已经在项目里面，用poetry初始化配置
poetry init
# 安装依赖，没有参数的话安装所有包，有参数的话安装指定的包
poetry install
# 更新依赖，没有参数的话更新所有包，有参数的话更新指定的包
poetry update
# 将指定的包添加到依赖列表并安装
poetry add <package-name>
# 删除包
poetry remove <package-name>
# 列出依赖项，使用--tree参数以树形方式显示
poetry show --tree
# 构建包
poetry build
# 发布包，如果想在发布的同时构建，添加--build参数
poetry publish --build
# 在虚拟环境中运行命令
poetry run python -V
# 在虚拟环境中打开shell
poetry shell
# 显示或者设置新的版本号，包括大版本、小版本、修复版本、预发布版本等等
poetry version
```

这里只是简单列举一下，其实 poetry 的功能更加强大。例如，安装依赖的时候，你不仅可以安装 PyPI 上已有的包，还可以直接从远程 git 仓库上安装包，甚至可以指定分支或者版本号。如果需要完整命令帮助的话，直接看官方<https://python-poetry.org/docs/cli/>。

```sh
poetry add git+https://github.com/sdispater/pendulum.git#develop
```

好了，本文的内容到此为止，内容也不算多，主要目的就是给大家介绍一下这款很好用的工具。如果你遇到一些问题的话也可以直接看官方文档，讲的还是很好的，很多问题都有涉及。也希望这款工具能够让大家 python 用的更方便吧。
