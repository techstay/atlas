---
title: "配置Linux Samba服务器"
date: 2022-02-09T16:56:55+08:00
tags:
  - linux
  - samba
categories:
  - linux
---

samba 协议是 windows 下的一个文件分享协议，使用也非常广泛。就算是使用 linux 服务器，很多人也会使用 samba 来分享文件，特别是在你有一个树莓派的情况下。所以这里就简单介绍一下，如何在 linux 下配置 samba 服务器。

## 安装 samba

samba 一般都已经包含在了系统的软件仓库之中，直接安装即可。

```sh
# Ubuntu
sudo apt install samba
# Arch & Manjaro
sudo pacman -S samba
#  RaspberryPiOS
sudo apt install samba samba-common-bin
```

## 配置 samba

对于 Arch 系的发行版来说，需要自己创建一个配置文件，可以从 [这里](https://git.samba.org/samba.git/?p=samba.git;a=blob_plain;f=examples/smb.conf.default;hb=HEAD) 找到。而其他发行版就可以直接编辑 `/etc/samba/smb.conf` 配置文件。之后在文件最后面添加类似下面的一段内容。

```conf
[sambashare]
    comment = Samba
    path = /home/username/sambashare
    read only = no
    browsable = yes
```

这里的 `path` 参数所指的共享目录也需要创建。

```sh
mkdir ~/sambashare
```

配置完成之后就可以开启 samba 服务了。

```sh
sudo systemctl start smbd
# Arch系
sudo systemctl start smb
```

## 配置用户

到这里还没有配置结束，因为上面的配置并没有指定匿名用户，所以需要我们再添加 samba 用户才能连接。

```sh
# 添加用户，用户名必须是系统中已经存在的用户
sudo smbpasswd -a username
# 修改smb密码
sudo smbpasswd username
```

## 测试连接

到这里 samba 服务器的配置就算基本完成了，下面就需要看看能不能连接得上。

在 Windows 资源管理器此电脑界面，邮寄空白处选择新建一个网络位置，然后在网络地址处填写 `\\IP地址或主机名\共享文件夹`，然后按照提示进行，初次设置可能需要一段时间来搜索网络。

![samba连接](/img/samba连接.png)

一切顺利的话，应该会弹出密码对话框提示输入用户名和密码，输入前面设置的 samba 用户名和密码之后，应该就能看到设置的 samba 共享文件夹了。这样就说明连接成功了。
