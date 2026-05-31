---
title: 将安卓手机变成Linux服务器
date: 2026-05-31T11:47:00+08:00
tags:
  - linux
  - termux
categories:
  - Android
---

## Termux

不要从 Google Play 下载（版本已停更），请前往 [F-Droid](https://f-droid.org/packages/com.termux/) 或 [GitHub](https://github.com/termux/termux-app/releases) 下载最新版 Termux。

### 安装与基础更新

```sh
# 更新软件源
pkg update && pkg upgrade

# 申请存储权限（方便访问手机文件）
termux-setup-storage
```

### 安装常用工具

```sh
pkg install vim git openssh curl wget -y
```

### 配置 SSH 远程连接

由于手机打字不便，配置好 SSH 后可以用电脑操作。

设置 Termux 密码：

```sh
passwd
```

查看用户名和 IP：

```sh
whoami      # 通常会输出类似 u0_a123 的用户名
ifconfig    # 找到 wlan0 的 IP 地址（例如 192.168.1.5）
```

启动 SSH 服务（Termux 的 SSH 默认端口是 8022）：

```sh
sshd
```

电脑端连接：

```sh
ssh u0_a123@192.168.1.5 -p 8022
```

### 安装完整的 Linux 发行版（可选）

如果你需要标准的 Linux 目录结构或某些 Termux 原生不支持的包，可以使用 proot-distro：

```sh
pkg install proot-distro
proot-distro install ubuntu
proot-distro login ubuntu
```

## UserLAnd

[UserLAnd](https://play.google.com/store/apps/details?id=tech.ula) 是一个可以将安卓手机变成 Linux 服务器的 APP，可以在谷歌 Play 上下载。下载完成后选择一个发行版安装，我这里选择的是 Arch，等待安装完毕之后，输入 SSH 密码就可以连接到 Linux 服务了。不过手机输入命令还是太慢了，所以我们还可以使用电脑远程连接。

### SSH 连接

连接方式很简单，UserLAnd 会在 2022 端口号开放 SSH 连接，所以只要用 SSH 登录即可。

```sh
ssh yourusername@192.168.31.103 -p 2022
```

当然，每次输入这个命令还是很麻烦的，所以可以把下面的配置放到 `~/.ssh/config` 中，这样以后只需要用 `ssh mi8` 即可访问。

```txt
Host *
    ServerAliveInterval 20
    ServerAliveCountMax 10

Host mi8
    Hostname 192.168.31.103
    User tech
    Port 2022
```

### Arch Linux 镜像配置

新安装好的 Arch 默认镜像速度比较慢，所以这里改用阿里云的镜像服务。

```sh
# 添加阿里云镜像，然后更新系统
sudo sed -i '1i Server = https://mirrors.aliyun.com/archlinuxarm/$arch/$repo' /etc/pacman.d/mirrorlist
sudo pacman -Syu

# 如果上面的方法不行，需要手动编辑
# 刷新仓库
sudo pacman -Syy
# 安装编辑器
sudo pacman -S nano
# 编辑配置文件
sudo nano /etc/pacman.d/mirrorlist
# 添加下面一行
# Server = https://mirrors.aliyun.com/archlinuxarm/$arch/$repo
# 更新系统
sudo pacman -Syu
```

然后就可以像一个正常的 linux 发行版一样安装软件了。最后让我们来检验一下成果吧。

`````txt
[tech@localhost ~]$ neofetch
                   -`                    tech@localhost
                  .o+`                   --------------
                 `ooo/                   OS: Arch Linux ARM aarch64
                `+oooo:                  Kernel: 4.9.297-Etude-Op.12-No.2-ge0d8a216
               `+oooooo:                 Uptime: 21 hours, 22 mins
               -+oooooo+:                Packages: 204 (pacman)
             `/:-:++oooo+:               Shell: bash 5.1.16
            `/++++/+++++++:              Terminal: /dev/pts/0
           `/++++++++++++++:             CPU: Qualcomm SDM845 (8) @ 1.766GHz
          `/+++ooooooooooooo/`           Memory: 3651MiB / 5627MiB
         ./ooosssso++osssssso+`
        .oossssso-````/ossssss+`
       -osssssso.      :ssssssso.
      :osssssss/        osssso+++.
     /ossssssss/        +ssssooo/-`
   `/ossssso+/:-        -:/+osssso+-`
  `+sso+:-`                 `.-/+oso:
 `++:.                           `-/+/
 .`                                 `/
`````

## Linux Deploy

### 下载资源

- [BusyBox](https://github.com/SmartPack/BusyBox-Installer/releases) — 为 Android 提供完整的 Unix 命令行工具
- [Linux Deploy](https://github.com/meefik/linuxdeploy) — 在 Android 上部署完整 Linux 系统

### 配置步骤

安装以下软件：

- BusyBox — 在 app 里安装 busybox，路径 `/system/xbin`
- Linux Deploy

在 Linux Deploy 中，将路径设置为 `/system/xbin/`，系统选择 debian，用户选择 root 用户，其他按需配置。
