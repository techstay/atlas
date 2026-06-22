---
title: "archlinux安装一条龙"
date: 2026-05-15T01:18:06+08:00
tags:
  - linux
  - arch
  - archlinux
categories:
  - Linux
---

### 下载镜像

- [阿里云镜像](http://mirrors.aliyun.com/archlinux/iso/latest/)
- [清华大学镜像](https://mirrors.tuna.tsinghua.edu.cn/archlinux/iso/latest/)

校验文件

```sh
# 几种校验方式选择一种
md5sum -c md5sums.txt
gpg --keyserver-options auto-key-retrieve --verify archlinux.iso.sig
```

### 安装

优化镜像源

```sh
sudo reflector -c China --save /etc/pacman.d/mirrorlist
```

第一次创建虚拟磁盘的话，还需要先初始化磁盘，建立分区表。

```sh
parted
mklabel gpt
quit
```

安装完毕之后，需要进入 `chroot` 环境继续配置一下 SSH，方便后续登录。

```sh
pacman -S openssh avahi nss-mdns --needed --confirm
systemctl enable sshd avahi-daemon
```

编辑 `/etc/hosts` 文件，添加以下几行。

```sh
127.0.0.1   localhost
::1             localhost ip6-localhost ip6-loopback
ff02::1         ip6-allnodes
ff02::2         ip6-allrouters
127.0.1.1   archlinux.localdomain archlinux
```

之后就可以用 `ssh techstay@archlinux.local` 的方式来登录了。

## Arch 衍生版

- [ALG](https://archlinuxgui.in)
- https://github.com/archcraft-os/archcraft-xfce/releases
- <https://manjaro.org/downloads/official/xfce/>
- <https://garudalinux.org/downloads.html>
- <https://endeavouros.com>

如果安装包没有附带中文字体，需要自己手动安装。

```sh
sudo pacman -Sy
sudo pacman -S noto-fonts-cjk
```

## 系统配置

### 创建用户

```sh
newuser=techstay
useradd $newuser -m -G wheel -s /bin/zsh
passwd $newuser
```

### sudo 免密码

```sh
echo "$(whoami) ALL=(ALL:ALL) NOPASSWD: ALL"|sudo tee /etc/sudoers.d/"$(whoami)"
```

### 远程登录

```sh
systemctl enable sshd
systemctl start sshd
```

### pacman 配置

使用清华镜像源。

```sh
sudo sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch' /etc/pacman.d/mirrorlist
sudo pacman -Syy
```

使用工具测试并自动选择。

```sh
sudo pacman -S reflector
sudo reflector -c China -n 5 --sort rate --save /etc/pacman.d/mirrorlist
# manjaro
sudo pacman-mirrors -c China
```

启用 pacman 彩色输出。

```sh
sudo sed -i 's/^#Color/Color/g' /etc/pacman.conf
```

密钥过期后需要重新刷新密钥。

```sh
sudo pacman-key --refresh-keys
sudo pacman-key --init
sudo pacman-key --populate
```

有时候个别软件源无法访问，可以刷新一下 DNS 缓存 (两条命令选一执行)。

```sh
sudo systemd-resolve --flush-caches
sudo resolvectl flush-caches
```

### 第三方仓库

添加 archlinuxcn 仓库。

```sh
# 配置pacman.conf文件
sudo tee -a /etc/pacman.conf <<'EOL'
[archlinuxcn]
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
EOL

# 安装密钥环
sudo pacman -Sy && sudo pacman -S archlinuxcn-keyring
```

### paru

paru 是一个使用 rust 编写的 AUR 安装程序，在启用了第三方源后可以直接从仓库中安装。

```sh
sudo pacman -S paru
```

### 配置区域和语言

```sh
# 生成语言文件
sudo sed -i 's/^# \?zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/g' /etc/locale.gen
sudo locale-gen

# 系统配置
sudo localectl set-locale LANG=zh_CN.UTF-8
echo 'LANG=zh_CN.UTF-8' | sudo tee /etc/locale.conf
# 用户配置
tee ~/.config/locale.conf <<'EOL'
LANG=zh_CN.UTF-8
LC_NUMERIC=zh_CN.UTF-8
LC_TIME=zh_CN.UTF-8
LC_MONETARY=zh_CN.UTF-8
LC_PAPER=zh_CN.UTF-8
LC_MEASUREMENT=zh_CN.UTF-8
EOL

# 时间配置
sudo timedatectl set-timezone Asia/Shanghai
sudo timedatectl set-ntp 1
sudo ntpdate ntp.ntsc.ac.cn
```

### bootloader 配置

将 grub 超时时间设置为 1 秒。

```sh
sudo nano /etc/default/grub

# 修改这一行
GRUB_TIMEOUT=1
```

然后生成新的 grub 配置。

```sh
sudo update-grub
# 一些发行版没有这个命令，只能使用原始命令
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

第三方 grub 主题 [DedSec GRUB Theme - Gnome-look.org](https://www.gnome-look.org/p/1569525)。

```sh
git clone https://github.com/vinceliuice/grub2-themes.git --depth=1
cd grub2-themes
sudo ./install.sh -t whitesur -s 4k
```

使用 systemd-boot 的话，编辑 `/boot/loader/loader.conf`。

```sh
timeout 1
```

### 自动登录

参考 [LightDM - ArchWiki (archlinux.org)](https://wiki.archlinux.org/title/LightDM#Enabling_autologin)。

```sh
# /etc/lightdm/lightdm.conf

# 创建用户组
# groupadd -r autologin
# gpasswd -a _username_ autologin
```

参考 [GDM - ArchWiki (archlinux.org)](https://wiki.archlinux.org/title/GDM#Automatic_login)

```sh
# /etc/gdm/custom.conf
# 添加这两行
[daemon]
AutomaticLogin=_username_
AutomaticLoginEnable=True

# /etc/pam.d/gdm-password
# 添加到首行
auth sufficient pam_succeed_if.so user ingroup nopasswdlogin

```

### 安装其他软件

如果有其他要安装的软件，别忘了安装。

```sh
#! /bin/bash

# 一些语言和类库
sudo pacman -S --noconfirm --needed jdk-openjdk openjdk-doc \
  openjdk-src gradle groovy kotlin maven \
  python ruby nodejs ghc typescript autopep8 npm python-pip ruby-bundler \
  dotnet-sdk lua go

# shell相关
sudo pacman -S --noconfirm --needed man-db shellcheck shfmt man \
  tldr zsh zsh-doc zshdb

# 杂项
sudo pacman -S --needed fastfetch systemd-resolvconf \
  cowsay sl curl wget neovim nano neovim \
  powerline-vim yadm thefuck ufw nmap \
  iptables-nft fd fzf ntp eza bat bottom asciiquarium
```

### 输入法

安装 rime 输入法。

```sh
sudo pacman -S --noconfirm --needed fcitx5-rime fcitx5-qt fcitx5-gtk \
	fcitx5-configtool fcitx5-material-color
```

安装雾凇拼音配置。

```sh
curl -fsSL https://raw.githubusercontent.com/rime/plum/master/rime-install | bash -s -- iDvel/rime-ice:others/recipes/full

# 默认安装为 ibus路径，可以用软链接创建 fcitx5 的配置
mkdir -p ~/.local/share/fcitx5/
ln -s ~/.config/ibus/rime  ~/.local/share/fcitx5/rime
```

创建环境变量文件。

```sh
tee ~/.config/environment.d/envvars.conf <<'EOL'
GTK_IM_MODULE=fcitx
QT_IM_MODULE=fcitx
XMODIFIERS=@im=fcitx
SDL_IM_MODULE=fcitx
GLFW_IM_MODULE=ibus
EOL
```

重新部署让配置生效。

```sh
fcitx5-remote -r
```

## 系统美化

### clash

下载地址 [Releases · zzzgydi/clash-verge (github.com)](https://github.com/zzzgydi/clash-verge/releases)

### 高分辨率缩放

```sh
gsettings set org.gnome.settings-daemon.plugins.xsettings overrides "[{'Gdk/WindowScalingFactor', <2>}]"
gsettings set org.gnome.desktop.interface scaling-factor 2
```

### 启用虚拟机功能

如果在 vmware 虚拟机中安装 arch，那么需要需要安装对应的虚拟机工具才能启用剪贴板复制等高级功能。

```sh
sudo pacman -S open-vm-tools
sudo systemctl enable vmtoolsd.service vmware-vmblock-fuse.service
sudo systemctl start vmtoolsd.service vmware-vmblock-fuse.service
# clipboard support
sudo pacman -S gtkmm3

# virtualbox
sudo pacman -S virtualbox-guest-utils
sudo systemctl enable vboxservice.service
```

一些衍生版增强了对虚拟机的支持，直接安装即可启用，无需额外配置。

```sh
# 软件包名可能是open-vm-tools-desktop
sudo pacman -S open-vm-tools
```

### 字体美化

首先要安装几个常用的字体。

```sh
sudo pacman -S --needed adobe-source-han-sans-cn-fonts \
  adobe-source-han-sans-jp-fonts adobe-source-han-sans-tw-fonts \
  noto-fonts noto-fonts-cjk noto-fonts-emoji ttf-sarasa-gothic
```

默认情况下的字体显示一般般，参考 <https://szclsya.me/zh-cn/posts/fonts/linux-config-guide/> 进行字体配置。

```sh
mkdir -p ~/.config/fontconfig && cd ~/.config/fontconfig
wget https://raw.githubusercontent.com/szclsya/dotfiles/master/fontconfig/fonts.conf
```

### 终端美化

推荐使用 dotfiles 方式管理配置文件，以后就可以随时随地同步配置了。

```sh
yadm clone https://github.com/techstay/dotfiles.git
```

然后选择 zsh 或者 fish 作为默认 shell。

```sh
chsh -s $(which zsh)
```

powerline 主题的一些字符可能不会正常显示，这时候需要安装支持 powerline 的字体。

```sh
paru -S ttf-fantasque-nerd
```

默认的终端程序也可能无法正常显示 powerline 字体，可以安装 kitty，能完美显示 powerline 字符。

在配置 kitty 的时候，可以通过以下命令查看 kitty 找到的字体。

```sh
kitty +list-fonts --psnames
```

最后在 `kitty.conf` 中指定要使用的字体名称即可。

### 主题

安装或启用 user themes、dash to dock 等扩展。

```sh
sudo pacman -S gnome-browser-connector gnome-shell-extension-dash-to-dock webp-pixbuf-loader gnome-tweaks
```

- [vinceliuice/Orchis-theme](https://github.com/vinceliuice/Orchis-theme)
- https://github.com/vinceliuice/WhiteSur-gtk-theme
- 别人配置的 plasma 主题 https://www.reddit.com/r/unixporn/comments/1c7b1b4/plasma_tried_a_light_and_airy_themerice/
- 开启关闭窗口特效 [Burn My Windows - GNOME Shell Extensions](https://extensions.gnome.org/extension/4679/burn-my-windows/)
- 移动窗口特效 https://extensions.gnome.org/extension/3210/compiz-windows-effect/
- 最大化最小化窗口特效 https://extensions.gnome.org/extension/3740/compiz-alike-magic-lamp-effect/
- https://extensions.gnome.org/extension/3843/just-perfection/
- 任务栏系统监视插件 https://extensions.gnome.org/extension/1460/vitals/

```sh
# whitesur
git clone https://github.com/vinceliuice/WhiteSur-gtk-theme.git --depth=1
cd WhiteSur-gtk-theme
./install.sh -m -HD
sudo ./tweaks.sh -g
# whitesur icons
git clone https://github.com/vinceliuice/WhiteSur-icon-theme --depth=1
cd WhiteSur-icon-theme
./install.sh -a
# whitesur wallpapers
git clone https://github.com/vinceliuice/WhiteSur-wallpapers.git --depth=1
cd WhiteSur-wallpapers
sudo ./install-gnome-backgrounds.sh
# orchis
git clone https://github.com/vinceliuice/Orchis-theme.git --depth=1
cd Orchis-theme
./install.sh -t green --tweaks macos
```
