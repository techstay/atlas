---
title: "安装Garuda Linux之后要做的几件事"
date: 2022-03-17T19:40:15+08:00
tags:
  - linux
categories:
  - linux
---

Garuda Linux 有以下特点：

- 基于 Arch，滚动更新
- 使用 Linux Zen 内核，调教激进
- 一套华丽胡哨的桌面环境
- 默认使用 btrfs 文件系统
- 提供了图形化配置工具 Garuda Assistant，使用方便
- 使用 paru 作为 AUR 包管理器

我安装体验了一下感觉挺不错的。

## 准备工作

任何时候使用 Linux，都最好准备好 🪜，如果需要下载 Github 资源的话，推荐<https://shrill-pond-3e81.hunsh.workers.dev>。

## 安装

到官网下载系统镜像，推荐使用 Garuda KDE Dr460nized 版，这是定制版的 KDE 桌面，样子很酷。

安装的时候正常安装即可，唯一需要注意的就是 Garuda 只支持 btrfs 文件系统，安装到 Windows 混合分区上可能会失败，最好找一个单独的硬盘驱动器来安装。

## 配置

Garuda Assistant 带有很多系统配置功能，可以轻松帮助我们完成一些常用的系统配置。

### dotfiles

stow 虽然也可以管理 dotfiles，但是毕竟还是太简陋了，所以我改用 yadm 这个专门用来管理 dotfiles 的工具。

初次使用需要初始化仓库。

```sh
yadm init
```

以后使用则直接克隆仓库即可。

```sh
yadm clone <url>
yadm status
```

### 系统镜像源

打开 Garuda Assistant -> Maintenance -> Refresh mirrorlist，选择最合适的镜像源。

### 输入法

打开 Garuda Assistant -> System Compenants -> Fcitx5，或者使用命令行安装 Fcitx5 组件。

```sh
sudo pacman -S fcitx5-im fcitx5-chinese-addons fcitx5-material-color fcitx5-lua
```

注销并重新登录之后即可生效。

### 终端

Garuda 默认的 fish 终端已经非常好用了，不过因为语法有些不兼容，如果不喜欢的话，也可以使用 zsh。推荐同时安装 `Meslo Nerd Fonts` 字体。

```sh
# 安装zsh
sudo pacman -S zsh
# 安装meslo字体
paru nerd-fonts-meslo
# 配置zsh
chsh -s /bin/zsh
```

## 软件安装

### 浏览器

Garuda 自带的 Firedragon 不太好用，我喜欢使用 vivaldi。

```sh
# 安装vivaldi
sudo pacman -S vivaldi vivaldi-ffmpeg-codecs

# 卸载firedragon
sudo pacman -Rc firedragon
```

### 音乐

安装 YesPlayMusic，这是一个第三方的网易云音乐播放器，功能强大。

```sh
paru yesplaymusic
```

### vscode

```sh
paru visual-studio-code-bin
```

安装完成后可能遇到无法进行设备同步的问题，安装下面的包即可解决。

```sh
sudo pacman -S gnome-keyring libsecret libgnome-keyring
```

### keepass

安装 KeePassXC，开源免费、界面美观，兼容 KeePass。

```sh
sudo pacman -S keepassxc
```

### onedrive

```sh
sudo pacman -S onedrive-abraunegg
```

然后调用 `onedrive --synchronize` 执行一次同步。

### 网络测速

```sh
sudo pacman -S speedtest-cli
```

还有一些东西就留着以后补充吧。
