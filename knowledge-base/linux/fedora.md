---
title: "fedora"
date: 2026-05-15T01:18:06+08:00
tags:
  - linux
  - fedora
categories:
  - Linux
---

## 下载和安装

到<https://fedoraproject.org/workstation/download>下载最新的镜像和校验文件，校验完成后安装。

```sh
# 校验需要使用git bash

# 先导入fedora的公钥
curl https://getfedora.org/static/fedora.gpg | gpg --import
# 然后检查校验文件的完整性
gpg --verify-files *-CHECKSUM
# 最后再用校验文件校验镜像的完整性
sha256sum -c *-CHECKSUM
```

## 系统配置

### 系统更新

首先将系统更新到最新版。

```sh
sudo dnf update
```

安装一些必需的软件包。

```sh
sudo dnf install zsh eza fzf util-linux-user fastfetch
```

### sudo 免密码

```sh
echo "$(whoami) ALL=(ALL) NOPASSWD: ALL" | sudo tee "/etc/sudoers.d/$(whoami)"
```

## 系统美化

### shell 美化

首先需要启用 root 用户。

```sh
sudo passwd
```

然后在 root 用户下执行以下命令，将 yadm 安装到系统中。

```sh
su

curl -fLo /usr/local/bin/yadm https://github.com/TheLocehiliosan/yadm/raw/master/yadm && chmod a+x /usr/local/bin/yadm
```

然后使用 yadm 克隆我的 dotfiles 项目。

```sh
yadm clone https://github.com/techstay/dotfiles.git
```

最后选择 zsh 作为默认 shell。

```sh
chsh -s /bin/zsh
```

一些好玩的工具：

```sh
sudo dnf install asciiquarium sl lolcat cmatrix cava
```

### 字体美化

```sh
mkdir -p ~/.local/share/fonts
cd ~/.local/share/fonts
wget https://github.com/ryanoasis/nerd-fonts/releases/download/v3.1.1/Meslo.zip
unarchive Meslo.zip
```

### 桌面美化

安装优化工具和一些 gonme 扩展，然后在优化工具中启用。

```sh
sudo dnf install gnome-tweaks gnome-extensions-app \
  gnome-shell-extension-apps-menu \
  gnome-shell-extension-dash-to-dock \
  gnome-shell-extension-user-theme
```

其他配置参考 [[archlinux安装一条龙#系统美化]]
