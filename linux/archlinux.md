# archlinux

ArchLinux 的安装和配置。

## 快速开始

### 下载

第一步自然是要下载镜像。

- [阿里云镜像](http://mirrors.aliyun.com/archlinux/iso/latest/)
- [清华大学镜像](https://mirrors.tuna.tsinghua.edu.cn/archlinux/iso/latest/)

下载的时候最好同时下载校验文件，方便确认文件的完整性。

可以使用 md5sum 校验。

```sh
md5sum -c md5sums.txt
```

也可以用 gpg 校验。

```sh
gpg --keyserver-options auto-key-retrieve --verify archlinux.iso.sig
```

### 安装

archwiki 有官方安装指导，可以一步一步跟着安装，实际操作起来也不难。不过现在有了更简单的安装方式，那就是使用 archinstall 安装脚本，这是 Python 写成的库，专门用来管理 archlinux 的安装。

启动安装镜像，直接执行`archinstall`，然后按照提示选择。该安装脚本会提供包括键盘布局到文件系统等系统配置所必须的各种选项，按照自己的需求选择即可。因为我这里是虚拟机安装，所以在选择安装位置的时候可以放心的清除磁盘重新安装。然而在真机上安装的时候，就要格外小心了，这也是命令行安装系统最容易失误的地方。

如果对自己不太有信心的话，也可以使用 ArchLinuxGUI，这个项目提供了易用的图形化安装界面，同时可以安装原汁原味的 ArchLinux，也是那些想用 ArchLinux 的一个很好的选择。

### ArchLinuxGUI

这个项目简称[ALG](https://archlinuxgui.in)，向那些不喜欢命令行界面安装的用户提供的图形化界面安装方式，拥有 Plasma、Gnome、Xfce、窗口管理器等多种风味，可以满足不同用户的需求。

安装这个版本和其他那些拥有图形界面的版本类似，按照提示进行就可以，这里不再做更多介绍。

## 系统配置

ArchLinux 是一个定制性极强的系统，很多地方都可以配置。对于最小化安装和图形界面安装的 ArchLinux 来说，需要配置的地方也各有不同，可以根据实际情况来进行配置。

### 一些必需软件

最小化安装之后的系统只是一个空壳子，什么都没有，所以还需要安装和配置很多东西。

先安装一些必需软件。

```sh
pacman -S --needed openssh zsh git curl wget vi nano ntp iptables-nft base-devel
```

### 启用 SSH 登录

开启 sshd 服务。

```sh
systemctl enable sshd
systemctl start sshd
```

接下来就可以用 SSH 远程登录，复制粘贴命令会方便很多。

### 创建用户

创建一个用户。

```sh
useradd techstay -m -G wheel -s /bin/zsh
passwd techstay
```

然后启用用户的免密码 sudo 权限，方便后面执行命令。

```sh
echo 'techstay ALL=(ALL:ALL) NOPASSWD: ALL'|sudo tee /etc/sudoers.d/techstay
```

如果你使用了 ALG 等其他办法用图形界面安装了系统，那么应该已经配置好了用户。如果你想要让当前用户免密码的话，使用下面的命令。

```sh
echo "$(whoami) ALL=(ALL:ALL) NOPASSWD: ALL"|sudo tee /etc/sudoers.d/"$(whoami)"
```

### 配置 pacman

将阿里云镜像源添加到`/etc/pacman.d/mirrorlist`最前面。

```sh
sudo sed -i '1i Server = https://mirrors.aliyun.com/archlinux/$repo/os/$arch' /etc/pacman.d/mirrorlist
sudo pacman -Syy
```

或者通过`reflector`来测速并设置镜像源。

```sh
sudo pacman -S reflector
sudo reflector -c China -n 5 --save /etc/pacman.d/mirrorlist
```

配置 pacman 彩色输出。

```sh
sudo sed -i 's/^#Color/Color/g' /etc/pacman.conf
```

### paru

paru 是一个较新的 AUR 助手，使用 rust 编写。

```sh
sudo pacman -S --needed base-devel
git clone https://aur.archlinux.org/paru.git
cd paru
makepkg -si
```

### 第三方仓库

除了直接使用 AUR 的软件之外，还可以添加一些知名的第三方仓库，里面的软件通常经过更多的测试，比 AUR 更稳定。

```sh
# 添加chaotic-aur的软件源
sudo pacman-key --recv-key FBA220DFC880C036 --keyserver keyserver.ubuntu.com
sudo pacman-key --lsign-key FBA220DFC880C036
sudo pacman -U 'https://cdn-mirror.chaotic.cx/chaotic-aur/chaotic-keyring.pkg.tar.zst' 'https://cdn-mirror.chaotic.cx/chaotic-aur/chaotic-mirrorlist.pkg.tar.zst'

# 配置pacman.conf文件
sudo tee -a /etc/pacman.conf <<'EOL'
[chaotic-aur]
Include = /etc/pacman.d/chaotic-mirrorlist

[archlinuxcn]
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
EOL

# 安装密钥环
sudo pacman -Sy && sudo pacman -S archlinuxcn-keyring
```

之后就可以安装这些仓库里面的软件了。

如果想要更快的速度，还可以安装 powerpill，它会将软件包分片，通过不同的镜像来下载，以实现更快的速度。powerpill 的使用方法和 pacman 类似。

```sh
# 安装
paru powerpill
# 更新
sudo pacman -Sy && sudo powerpill -Su && paru -Su
```

如果遇到了问题，还需要在`/etc/pacman.conf`中配置。

```ini
[options]
SigLevel = PackageRequired
```

### 配置区域和语言

因为我主要使用 SSH 连接，所以将系统全局语言设置为中文是没有问题的。但是这样做会导致 tty 界面乱码。遇到此类问题是可以将全局语言设为英文，然后将用户语言设为中文。

```sh
sudo sed -i 's/^# \?zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/g' /etc/locale.gen
sudo locale-gen

sudo localectl set-locale LANG=zh_CN.UTF-8
echo 'LANG=zh_CN.UTF-8' | sudo tee /etc/locale.conf
echo 'LANG=zh_CN.UTF-8' | tee ~/.config/locale.conf

sudo timedatectl set-timezone Asia/Shanghai
sudo timedatectl set-ntp 1
sudo ntpdate ntp.ntsc.ac.cn
```

### 微码

微码包含了处理器厂商的修复和优化，建议安装。根据处理器的不同，安装下列之一。

```sh
sudo pacman -S intel-ucode
sudo pacman -S amd-ucode
```

### 终端美化

参考[zsh 配置](zsh/README.md)。

### 系统美化

如果是图形界面 ArchLinux 的话，默认界面应该很难看，要做的工作也不少。

首先要安装几个常用的字体。

```sh
sudo pacman -S --needed wqy-bitmapfont wqy-microhei wqy-zenhei \
  adobe-source-han-sans-cn-fonts adobe-source-han-sans-jp-fonts \
  adobe-source-han-sans-tw-fonts
```

### 安装其他软件

现在安装的还只是一个最小化系统，什么都还没有呢。如果还有其他需求，可以自己写个脚本来安装和配置。这里是个简单的例子。

```sh
#! /bin/bash

# 一些语言和类库
sudo pacman -S --noconfirm --needed jdk-openjdk openjdk-doc openjdk-src gradle groovy scala kotlin maven \
    python ruby nodejs ghc typescript autopep8 npm python-pip ruby-bundler \
    dotnet-sdk lua go

# zsh相关
sudo pacman -S --noconfirm --needed zsh zsh-doc zshdb grml-zsh-config

# 杂项
sudo pacman -S --noconfirm --needed neofetch cowsay sl man-db shellcheck curl wget vim nano \
    powerline-vim yadm shfmt thefuck ufw nmap iptables-nft fd fzf ntp exa subversion man bat bottom asciiquarium
```
