---
title: "安装Manjaro之后要做的几件事情"
date: 2022-02-28T03:46:30+08:00
tags:
  - linux
categories:
  - linux
---

## 写在前面

如需正常下载 github 资源，可以使用这个加速地址<https://shrill-pond-3e81.hunsh.workers.dev>。后续各种操作都需要良好的网络链接，最好自备梯子。

## 系统配置

### pacman 镜像

```sh
sudo pacman-mirrors -c China
```

### fcitx 输入法

安装以下包。

```sh
sudo pacman -S fcitx5-im fcitx5-chinese-addons fcitx5-material-color fcitx5-lua
```

编辑 `/etc/environment`，添加以下几行。

```sh
sudo tee -a /etc/environment <<EOF
GTK_IM_MODULE=fcitx
QT_IM_MODULE=fcitx
XMODIFIERS=@im=fcitx
SDL_IM_MODULE=fcitx
EOF
```

注销或者重启电脑后就可以使用 fcitx 输入法了。

### 导入 dotfiles

```sh
git clone https://github.com/techstay/dotfiles.git ~/.dotfiles
cd .dotfiles
stow zsh pip spacevim
```

## 系统美化

### 主题设置

Manjaro 自带的主题就比较不错，打开优化工具，选择 Matcha-dark-pueril 主题。

### 终端设置

在上面导入 zsh 配置文件，切换到 zsh 即可启用。记得安装 Meslo NF 字体。

```sh
cd ~/.dotfiles
stow zsh
zsh
# Meslo字体
mkdir -p ~/.fonts
cd ~/.fonts || exit
wget https://github.com/ryanoasis/nerd-fonts/releases/download/v2.1.0/Meslo.zip
unzip Meslo.zip
rm Meslo.zip
fc-cache -f
```

## 软件安装

### vivaldi 浏览器

```sh
sudo pacman -S vivaldi vivaldi-ffmpeg-codecs
```

### vscode

安装微软的包，登录后即可同步各种扩展。

```sh
yay visual-studio-code
```

### 网易云音乐

```sh
yay netease-cloud-music
```

### Onedrive

```sh
sudo pacman -S onedrive-abraunegg
```

先运行 `onedrive`，在浏览器窗口中登录，然后将登录之后的页面粘贴在终端即可完成登录。然后用 `onedrive --synchronize` 执行一次同步操作。

### keepass

```sh
sudo pacman -S keepass
```

### 网络测速

```sh
sudo pacman -S speedtest-cli
```

关于其他设置，可以参考我的 [dotfiles 配置](https://github.com/techstay/dotfiles)。
