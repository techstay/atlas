---
title: "在虚拟机中安装无GUI的ArchLinux"
date: 2021-12-13T01:23:53+08:00
tags:
  - linux
categories:
  - linux
---

因为重装了系统，所以可以方便的使用 WSL 了。不过 WSL 有些情况下还是不能替代虚拟机，所以该装的虚拟机还是要装的啊。而 ArchLinux 我认为最好的用法就是直接装成无界面的虚拟机，启动仅需几秒，可以当成一个完整的 Linux 来使用，也不用费时费力折腾那个动不动就出问题的 Linux 桌面，简直完美！

之前也写了不少文章介绍如何安装 ArchLinux，不过后来 ArchLinux 官方出了一个名字叫 Archinstall 的 Python 包，彻底解决了这个问题。虽然这个包并不能完全替代命令行配置，但是对于我在虚拟机里安装 Arch 则完全可以满足需求。所以我当初写的那个丑陋不堪的安装脚本也扔掉了，简简单单写一个 JSON 配置文件，就可以看着终端自动安装 Arch，岂不美哉？但是当我用配置文件安装 Arch 的时候，遇到了一些奇奇怪怪的问题。当然，这其实是挺正常的，毕竟这个功能还只是实验性质的，但是看着以前写好的配置文件又不能用了，我当场被气晕。

没办法，只好自己动手重新安装一遍了。好在用 Archinstall 的向导安装起来也并不费事，但是因为要重新输入很多命令，为了避免以后到处翻找再复制命令，这里就写一篇文章记录一下吧。

## 新建虚拟机

我用的 VMWare 虚拟机，新建完成之后，别忘了将启动方式改成 EFI。为了让虚拟机运行速度更快，我直接把虚拟磁盘文件放到了固态硬盘里，并把启动设备也改成了 NVME 的，这样一来，虚拟机内部的设备类型就不再是 `/dev/sda`，而是 `/dev/nvme0n1`，注意这个变化。

## 安装系统

启动系统之后，直接运行 `archinstall` 命令即可启动安装向导，按照提示选择即可：

- 镜像源选择中国
- 启动设备按前面说的选择
- 文件系统用 btrfs
- 区域和语言保持默认的英文
- 时区输入 `Asia/Shanghai`
- 引导器选择 grub
- 输入 root 密码

基本上就是这样了。等待安装完成之后，进入系统里面继续配置。

```sh
# 设置用户和密码
useradd -m -G wheel techstay
passwd techstay
# 安装一些必要包
pacman -S wget zsh git openssh vi nano
# 启动ssh服务
systemctl enable sshd
# ArchLinux默认没有开启wheel用户组管理员权限，需要手动开启
# 反注释 %wheel ALL=(ALL) ALL NOPASSWD: ALL
visudo
```

## 配置 SSH

重启虚拟机，再次进入系统。用 `ip a` 查看当前的 IP 地址，然后打开宿主机的 `~/.ssh/config` 文件，添加类似设置。

```txt
Host *
    ServerAliveInterval 20
    ServerAliveCountMax 10

Host arch
    Hostname 192.168.25.133
    User techstay
```

然后使用 `Git Bash` 等终端，输入 `ssh-copy-id arch` 命令将 SSH 公钥复制到虚拟机内部，这样以后就可以直接用 `ssh arch` 来登录 Arch 虚拟机了。

## 其他配置

因为现在已经可以用 SSH 登录，意味着可以直接复制粘贴命令，那么剩下的就好说了。

### 安装软件

先安装很多很多软件。

```sh
sudo pacman -S --noconfirm --needed jdk-openjdk openjdk-doc openjdk-src gradle groovy scala kotlin maven \
    python ruby nodejs ghc typescript autopep8 npm python-pip ruby-bundler \
    dotnet-sdk lua

sudo pacman -S --noconfirm --needed zsh zsh-doc \
    zshdb

sudo pacman -S --noconfirm --needed docker

sudo pacman -S --noconfirm --needed neofetch cowsay sl man-db shellcheck curl wget vim nano \
    neovim powerline-vim stow shfmt thefuck ufw nmap fd fzf exa subversion man bat
```

### 配置 docker

```sh
sudo usermod techstay -aG docker
# 设置docker镜像源
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<EOL
{
    "registry-mirrors": [
        "https://dockerhub.azk8s.cn"
    ]
}
EOL
# 开启docker服务
sudo systemctl enable docker
sudo systemctl start docker
```

### 修改 grub 等待时间

将 grub 等待时间改成 0 秒。

```sh
sudo nano /etc/default/grub
# GRUB_TIMEOUT=0
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

### 区域和 pacman 配置

配置区域和 pacman。

```sh
# pacman彩色输出
sudo sed -i 's/^#Color/Color/g' /etc/pacman.conf
# 中文区域
sudo sed -i 's/^#zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/g' /etc/locale.gen
sudo locale-gen
mkdir -p ~/.config/
echo 'LANG=zh_CN.UTF-8' |tee ~/.config/locale.conf
```

### 启用 yay

我喜欢安装完之后在用 yay 安装 yay 替换掉自己安装的版本。

```sh
pacman -S --needed git base-devel
git clone https://aur.archlinux.org/yay-bin.git
cd yay-bin
makepkg -si
```

### shell 配置

最后再克隆一下我自己的 dotfiles，把 zsh 的配置文件拷下来。

```sh
git clone https://github.com/techstay/dotfiles.git
cd dotfiles
stow zim

# 进入zsh
zsh

# 一切无误后更改默认shell
chsh -s /bin/zsh
```

这样一来，一个无界面的 ArchLinux 虚拟机就算配置完成了。
