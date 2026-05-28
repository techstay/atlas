---
title: "搭建msys2开发环境"
date: 2022-01-26T14:11:46+08:00
tags:
  - linux
  - Windows
categories:
  - dev
---

msys2 是一套用于创建 windows 应用程序的工具集，提供了类似 linux 的命令行界面和接口。虽然 windows 现在有了 wsl（linux 子系统）功能，但是如果要开发 windows 应用程序的话，还是最好装一个 msys2，而且 msys2 使用起来也很方便。

## 安装 msys2

安装 msys2 很简单，你可以直接在官网下载安装，也可以使用像 scoop 这样的包管理器来安装。安装完根据提示运行 msys2，然后重启终端，完成安装工作。

```sh
scoop install msys2
```

然后，就可以利用 msys 安装一些工具了，下面简单举几个例子。

## ruby 开发环境

首先安装 ruby：

```sh
scoop install ruby
```

然后需要安装 msys2 环境，当然这里我们已经安装了，所以直接运行 `ridk` 脚本安装剩余的工具链。

```sh
ridk install
```

## Qt 开发环境

安装工具链：

```sh
pacman -S --needed base-devel git mercurial cvs wget p7zip
pacman -S --needed perl ruby python mingw-w64-x86_64-toolchain

```

安装 qt 类库：

```sh
pacman -S --needed mingw-w64-x86_64-qt6 mingw-w64-x86_64-cmake
pacman -S --needed mingw-w64-x86_64-qt6-static
```

安装 qt creator：

```sh
pacman -S mingw-w64-x86_64-qt-creator
```

然后就可以用 qt 来开发跨平台的图形界面程序啦。

或者如果你使用 xmake 的话，可以先创建一个 qt 项目。

```sh
xmake create -t qt.quickapp qt-test
```

然后切换进项目目录中，指定要使用的 mingw 路径。

```powershell
cd qt-test
xmake f -p mingw --sdk=$HOME\scoop\apps\msys2\current\mingw64
```

然后就可以编译和运行啦。

```sh
xmake
xmake run
```
