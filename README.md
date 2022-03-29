# 我的学习笔记仓库

<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->

[![All Contributors](https://img.shields.io/badge/all_contributors-1-orange.svg?style=flat-square)](#contributors-)

<!-- ALL-CONTRIBUTORS-BADGE:END -->

## 目录

- [linux 笔记](linux/README.md)
  - [openssh](linux/openssh.md)
- [windows 笔记](windows/README.md)
  - [scoop 包管理器](windows/scoop.md)

## 写在后面

### 动机

之前我还是很爱写博客的，不过博客散落在 CSDN、简书等好几个地方，到最后我自己都不好管理了。而各种笔记和博客分散在各处，也不利于整理，这一点对于 github 仓库也是一样。既然如此，为什么不把它们合并到一起呢？这也正是本仓库的目的，这个仓库会存放我所有的笔记和学习代码，统一管理，后面我也会逐步将以前的代码整理进来，然后清理不需要的仓库，最后把我的 github 整理成一个干净的状态。

### 项目规范

#### 编码约定

编码和写作的基本原则是方便、简单和统一。每个项目要添加必要的说明，使用读我介绍项目的用途，代码尽量简洁干净，满足可读性。笔记类的文章要简洁易读，这和编写博客类文章还不太一样，博客主要面向大众读者，写作时候要介绍不少基本概念；而笔记主要用来记录一些关键知识，不用做过多介绍，直击主题即可。

#### 开发环境

为了保证多平台的开发环境的一致性，在项目中也要明确指定环境和相关软件的配置，做到跨平台的一致性。

各项目的具体配置在各项目的读我文件中指定。对于 markdown 文件使用 vscode 编辑器来编辑，使用`esbenp.prettier-vscode`扩展来格式化。

其余项目的配置要求在相应的读我文件中说明。

#### git 规范

本项目只是一个笔记仓库，所以这里只采用一个比较简单的分支流程。main 作为主分支，添加新项目的时候在本地建立一个新的 feature 分支并添加代码，提交完毕之后变基到主分支上，然后提交到 Github 上，之后就可以安全的删除 feature 分支了。

gitmoji 是一个提交规范，借由 emoji 表情让 git 提交变得轻松活泼，同时也规定了可以使用的表情防止滥用，不过个人项目嘛，emoji 会使用的更加自由一些。如果你使用 vscode 的话，也可以安装 [gitmoji 扩展](https://marketplace.visualstudio.com/items?itemName=seatonjiang.gitmoji-vscode)，在 git 提交的时候查找和插入表情。

- [😏gitmoji 规范](https://gitmoji.dev)
