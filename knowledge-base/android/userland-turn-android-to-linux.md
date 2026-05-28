---
title: "用UserLAnd将安卓手机变成Linux服务器"
date: 2022-02-05T00:12:27+08:00
tags:
  - linux
  - android
categories:
  - linux
---

UserLAnd 是一个可以将安卓手机变成 Linux 服务器的 APP，可以在谷歌 Play 上下载。下载完成后选择一个发行版安装，我这里选择的是 Arch，等待安装完毕之后，输入 SSH 密码就可以连接到 Linux 服务了。不过手机输入命令还是太慢了，所以我们还可以使用电脑远程连接。

连接方式很简单，UserLAnd 会在 2022 端口号开放 SSH 连接，所以只要用 SSH 登录即可。

```sh
ssh yourusername@192.168.31.103 -p 2022
```

当然，每次输入这个命令还是很麻烦，所以可以把下面的配置放到 `~/.ssh/config` 中，这样以后只需要用 `ssh mi8` 即可访问。

```txt
Host *
    ServerAliveInterval 20
    ServerAliveCountMax 10

Host mi8
    Hostname 192.168.31.103
    User tech
    Port 2022
```

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
     /ossssssss/        +ssssooo/-
   `/ossssso+/:-        -:/+osssso+-
  `+sso+:-`                 `.-/+oso:
 `++:.                           `-/+/
 .`                                 `/
`````
