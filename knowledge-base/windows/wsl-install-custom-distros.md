---
title: "WSL安装自定义发行版"
date: 2021-12-11T23:31:25+08:00
tags:
  - linux
  - windows
  - wsl
categories:
  - windows
---

WSL（全名 Windows Subsystem for Linux，即 Linux 子系统）是一个非常好用的功能，它本质上是一个虚拟机，但是和 Windows 有着很高的集成度，能让我们像运行本地命令一样执行 Linux 程序，可以说是极为方便，用过的都说好。不过比较可惜的是，这个功能支持的 Linux 发行版有限，只能应用商店里的 Ubuntu、OpenSUSE 等几个，实在是不能满足广大开发者的需求。不过没有关系，虽然商店里的发行版有限，但是我们也可以自己安装发行版，这也就是本文要介绍的内容。

注意，这里介绍的 WSL 指的是 WSL 2，在运行后面的命令之前请确保你正确的启用了 WSL 2。

## Fedora

Fedora 不久之前发布了最新的 Fedora 35，我也试了一下感觉还不错。如果能够将 Fedora 和 Windows 结合起来那应该也蛮有意思的。

### 下载 rootfs

首先我们需要 fedora 的 rootfs，这个可以在<https://github.com/fedora-cloud/docker-brew-fedora/tree/35/x86_64>下载。下载完成后我们就得到了一个后缀名 `tar.xz` 的文件，使用压缩软件解压后得到后缀名 `tar` 的归档文件。为了执行命令方便，我将归档文件放在了 `C:\wsl` 目录下，这个目录也将会是后面 wsl 的安装目录。

### 安装 Fedora

有了 rootfs 文件，就可以安装 Fedora 了。切换到 `C:\wsl` 目录下，执行下面的命令，即可将 Fedora 安装为 WSL 发行版。下面的命令第一个参数是 WSL 发行版的名字，第二个参数是要安装的文件夹的名字（没有会创建），第三个参数就是刚刚得到的 rootfs 归档文件。

```powershell
wsl --import Fedora fedora .\fedora-35.20211125-x86_64.tar
```

安装完成后，会看到多出来一个文件夹，里面还有一个 vhdx 虚拟文件，这样一来 Fedora 发行版就算安装好了。我们也可以在 WSL 命令行中看到刚刚安装的发行版了。而刚刚使用的归档文件也可以安全的删除了。

```powershell
wsl --list
```

### 配置 Fedora

安装完了的 Fedora 子系统还不能马上使用，如果你留意刚刚生成的 vhdx 文件的大小，可以注意到它只有二三十兆。这么一点点大小怎么可能包含完整的功能呢？没错，这时候的 Fedora 可以说是一个空壳子，几乎啥也没有，所以下面需要安装和配置很多东西，让这个 Fedora 变成一个真正可用的系统。

首先需要更新系统，然后安装一些必要的软件包。

```sh
dnf update
dnf install wget curl sudo ncurses dnf-plugins-core dnf-utils passwd findutils util-linux-user
```

然后创建新用户，并为用户设置密码。

```sh
useradd -G wheel yourusername
passwd yourusername
```

退出终端，并用 `wsl --terminate Fedora` 结束 Fedora 虚拟机。然后使用新账户启动 Feodra 子系统。为了查看新账户和 sudo 的运行状况，你应该试着运行一些命令。

```sh
wsl -d fedora -u myusername

# 在WSL里面
whoami
sudo cat /etc/shadow
id -u
```

为了将新账户设置成默认账户，需要在管理员权限的 Powershell 中运行下面的命令。这里的要点是，刚才我们创建的新用户对应的 ID 应该是 1000，然后就可以在注册表里将默认用户设置为 ID 为 1000 的账户。假如你的新用户 ID 不是 1000，那么也应该跟着改，查看用户 ID 可以用 `id -u` 命令。

```powershell
$distroName = 'Fedora'
Get-ItemProperty Registry::HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Lxss\*\ DistributionName | Where-Object -Property DistributionName -eq $distroName | Set-ItemProperty -Name DefaultUid -Value 1000
```

### 导入和导出

安装好的 WSL 还可以方便的导入和导出。

```sh
# 首先清除安装产生的缓存
sudo dnf clean all

# 然后退出wsl，在Powershell中执行
wsl --export fedora fedora-wsl.tar
```

要将导出的归档包再导入 WSL，运行前面介绍过的命令即可。因为这次使用的是已经配置过的归档包，所以导入以后可以直接使用。这是一个很方便的备份和还原的功能。

当然，为了让 Fedora 更加好用，你可能还要继续安装和配置一些工具，不过这就不是本文的内容了。

## Arch

接下来介绍如何安装 Arch，其实过程基本上大同小异。这里只在使用不同的方法时着重说明一下，安装的路径默认和前面一样。

其实现在已经有一个 ArchWSL 的项目了，不过这里为了演示还是手动安装一次 Arch。

### 获取 rootfs

下载 rootfs 其实还有一种方法就是通过 docker，这里假定你已经安装了 docker for windows。

```powershell
# 获取ArchLinux docker镜像
docker run --name arch archlinux:latest
# 在wsl安装目录下，刚才的C:\wsl
docker export -o arch.tar arch
```

完成之后，在相关目录下就得到了新的 ArchLinux 归档文件。

### 安装 Arch

切换到 wsl 安装目录下，运行下面的命令。

```powershell
wsl --import Arch arch .\arch.tar
```

### 配置 Arch

进入 Arch 环境，安装一些必备软件。

```sh
pacman -Syu
pacman -S --needed wget curl git zsh man sudo
```

创建新用户。

```sh
useradd -G wheel -m yourusername
passwd yourusername
```

将新用户设置为默认用户。如果没有设置成功，先用 `wsl --terminate Arch` 将 Arch 关机，然后运行该命令，再试一次。

```powershell
$distroName = 'Arch'
Get-ItemProperty Registry::HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Lxss\*\ DistributionName | Where-Object -Property DistributionName -eq $distroName | Set-ItemProperty -Name DefaultUid -Value 1000
```

剩下的安装软件包的工作就不在介绍了。这样一来，我们就获得了两个不在应用商店的全新 WSL 发行版。其他发行版的设置也基本上大同小异，这里就不在重复了。
