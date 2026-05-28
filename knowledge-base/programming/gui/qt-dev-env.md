---
title: "Qt开发环境搭建"
date: 2022-02-25T02:56:22+08:00
tags:
  - qt
  - c++
categories:
  - dev
---

## 安装 qt

推荐直接使用 qt 官方提供的在线安装包，下载地址如下。如果访问不了的话可以改用清华镜像源。

- <https://download.qt.io/archive/online_installers/>
- <https://mirrors.tuna.tsinghua.edu.cn/qt/official_releases/online_installers/>

提示：使用命令行参数指定镜像安装速度会更快哦！

```sh
installer(.exe) --mirror https://mirrors.tuna.tsinghua.edu.cn/qt
```

qt 官方的 qt creator 已经足够使用，不过如果你不喜欢 qt creaotr，那么也可以使用其它替代品。

## 构建工具

构建工具我选择 xmake，虽然只是一个个人项目但是使用起来还是非常方便的。

安装 xmake 也很简单，直接在 powershell 终端中运行：

```powershell
Invoke-Expression (Invoke-Webrequest 'https://xmake.io/psget.text' -UseBasicParsing).Content
```

安装完毕之后就可以使用 xmake 来创建 qt 项目了。

## 新建项目

xmake 内置 qt 项目的模板，可以直接创建。

```sh
xmake create -t qt.quickapp qt-test
```

指定 SDK 的路径，注意 MinGW 是 Tools 文件夹下的。

```sh
xmake f -p mingw --sdk=C:\Qt\Tools\mingw900_64
```

然后就可以编译项目。

```sh
xmake
```

最后就可以运行程序了。

```sh
xmake run
```
