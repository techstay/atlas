---
title: "ufw"
date: 2022-03-02T18:32:10+08:00
tags:
  - linux
  - 防火墙
  - 网络
categories:
  - linux
---

ufw 全名 Uncomplicated Firewall，和名字一样，这是一个使用非常简单的防火墙。

## 安装

```sh
sudo pacman -S ufw
sudo systemctl enable ufw
sudo systemctl start ufw
```

ufw 默认使用 iptables 后端，如果需要使用 nftables 后端，安装 `iptables-nft`。

## 配置

### 简易配置

默认禁用所有连接，然后启用本地局域网段并限制 SSH 连接。这里限制的标准是，每 30 秒超过 6 次连接。

```sh
ufw default deny
ufw allow from 192.168.0.0/24
ufw limit ssh
```

然后启用 ufw。

```sh
ufw enable
```

这时候就可以查看 ufw 状态了。

```sh
ufw status
ufw status verbose
```

如果不仅仅想查看用户定义的规则，而是整个系统的规则。

```sh
ufw show raw
```

要删除规则的话。

```sh
ufw delete limit ssh
```

### 自定义规则

ufw 自带了一组程序规则。

```sh
ufw app list
ufw app info SSH
```

需要自定义规则的话，推荐在 `/etc/ufw/applications.d/custom` 下创建自己的规则。

```conf
[myhugo]
title=hugo server
description=hugo local dev server
ports=1313/tcp
```

如果需要多个端口号可以这样指定。

```conf
ports=10000:10002/tcp|10003,10009/udp
```

以上就是 ufw 的使用方法，确实很简单。如果需要图形化客户端的话，安装 `gufw`，桌面环境可用。
