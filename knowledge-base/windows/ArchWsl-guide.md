---
title: "在WSL中安装Arch Linux"
date: 2022-02-26T03:28:32+08:00
tags:
  - wsl
  - windows
  - linux
categories:
  - windows
---

这里采用 [ArchWSL](https://github.com/yuk7/ArchWSL) 来在在 WSL 中安装 Arch Linux。

## 安装

到项目官网下载 appx 安装文件或者用 scoop 直接安装。

```sh
scoop install archwsl
```

## 配置

首先启动 Arch WSL。先配置用户和密码。

```sh
# root密码
passwd
# 新建用户
user_name=techstay
echo "$user_name ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/$user_name
useradd -m -G wheel -s /bin/bash $user_name
passwd $user_name
```

退出 WSL，在 windows 终端中运行以下命令，将用户设置为默认用户。

```sh
wsl --manage archlinux --set-default-user techstay
```

再次进入 WSL，应该可以看到默认用户已经变成了这里创建的。然后继续配置 pacman 包管理器。

```sh
sudo pacman-key --init
sudo pacman-key --populate
sudo pacman -Syy archlinux-keyring
# 直接将清华镜像添加到列表第一行
sudo sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch' /etc/pacman.d/mirrorlist
# 或者使用reflector
sudo pacman -S reflector
sudo reflector --country "China" --protocol https --sort rate --save /etc/pacman.d/mirrorlist
# 更新系统
sudo pacman -Syu
```

配置系统语言。

```sh
sudo sed -i 's/^# \?zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/g' /etc/locale.gen
sudo locale-gen
echo 'LANG=zh_CN.UTF-8' | sudo tee /etc/locale.conf
```

美化终端。

```sh
# 安装必要软件
sudo pacman -S --needed base-devel git stow zsh wget neofetch thefuck lua openssh fd exa bat fzf neofetch
# 有代理的话可以配置一下，加速下载
export all_proxy=http://192.168.31.100:7890
# 安装yay
git clone https://aur.archlinux.org/yay-bin.git ~/.yay-bin
cd yay-bin
makepkg -si
# 克隆dotfiles
git clone https://github.com/techstay/dotfiles.git ~/.dotfiles
cd ~/.dotfiles
stow zim
# 切换到zsh
zsh
chsh -s /bin/zsh
```

这样就算配置完成了。
