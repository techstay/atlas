---
title: "adguardhome"
date: 2026-05-15T01:18:06+08:00
tags:
  - network
  - adguard
  - dns
  - adblock
categories:
  - 网络
---

## 安装

我在树莓派上试着安装了一下，顺便做个记录。

通过 docker-compose 方式安装最简单。docker-compose 文件可以在 [我的树莓派 dotfiles](https://github.com/techstay/dotfile-rasp) 中找到。

```sh
sudo apt install docker-compose
```

启动后查看一下 adguardhome 的状态。

```sh
docker ps
```

这时候还没完，如果查看日志的话，会发现提示需要通过 3000 端口号配置。所以通过浏览器访问<http://raspberrypi:3000>，进行初步的配置。配置完毕后，80 端口号就会开放，这时候就能通过 web 界面访问 adguardhome 的各项功能了。

## 配置

### 上游 DNS

需要什么的话，直接在 web 界面里配置就行了。因为我是局域网使用，所以不需要启用加密，只需要指定上游的 DNS 服务器即可。这里列出一些常用的 DNS 公共服务器。

- <https://dnsprivacy.org/public_resolvers/> 几个常用的 DNS 加密服务器
- <https://www.dnsovertor.tk> V 站老哥分享的一个基于 Tor 网络的隐私保护 DNS 服务器
- <https://github.com/dnscrypt/dnscrypt-resolvers> 另一些常用的 DNS 服务器
- <https://iqiq.io/servers.html> iqdns

### DNS 拦截

在 DNS 拦截功能里面，可以添加一些规则，以拦截广告和隐私追踪。也有一些第三方规则可供使用。

- <https://github.com/BlueSkyXN/AdGuardHomeRules>

## 使用

如果只是想在本地电脑上使用的话，可以改用<https://github.com/mili-tan/AuroraDNS.GUI>这个项目。
