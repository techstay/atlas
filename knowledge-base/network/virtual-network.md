---
title: "virtual-network"
date: 2026-05-15T01:18:06+08:00
tags:
  - network
categories:
  - 网络
---

## tailscale

### tailscale

安装

[tailescale](https://tailscale.com)

局域网路由

```sh
opkg install tailscale

tailscale up --advertise-routes=192.168.31.0/24
```

#### 一些有用的命令

[serve](https://tailscale.com/kb/1080/cli/#serve) 将网络服务暴露于 tailnet 中：

```sh
# 语法
tailscale serve http[:<port>] <mount-point> <source> [off]
# 例子 开放hugo博客端口号
tailscale serve http / http://localhost:1313
```

[funnel](https://tailscale.com/kb/1080/cli/#funnel) 命令将 serve 命令中的服务暴露于公网之中：

```sh
# 语法 限制三个端口号
tailscale funnel <443/8443/10000> [on/off]
# 查看状态
tailscale funnel status
```

### headscale

tailscale 的服务端是一个私有的服务，通过官方服务器承载。而 [headscale](https://github.com/juanfont/headscale) 是一个开源的服务端程序，兼容 tailscale，实现了 tailscale 的多数功能，可以部署在自己的服务器上。如果你有自己的服务器，那么部署一个 headscale 更加灵活方便。

调试

```sh
tailscale ping <host>
tailscale netcheck
tailscale status
```

### xedge.cc

国内版 tailscale[xEdge](https://xedge.cc)

## zerotier

安装

[zerotier](https://www.zerotier.com)

调试

```sh
zerotier-cli info
zerotier-cli peers
zerotier-cli listnetworks
```

## n2n

### n2n

[n2n](https://github.com/ntop/n2n) 是一个 P2P 的 VPN。

使用命令行连接，多个客户端英指定不同的 IP 地址，`-c` 和 `-k` 参数建议也是用不一样的名称。n2n 会尝试打洞直连，当直连失败的时候，会使用服务器进行中转。

```sh
sudo edge -c mynetwork -k mysecretpass -a 192.168.100.1 -f -l supernode.ntop.org:7777
sudo edge -c mynetwork -k mysecretpass -a 192.168.100.2 -f -l supernode.ntop.org:7777
```

## 内网穿透

### frp

[frp](https://github.com/fatedier/frp)

### 樱花 frp

国内版 [sakura frp](https://www.natfrp.com)，使用国内节点需要实名认证。

### ngrok

[ngrok](https://ngrok.com) 免费版账户只能使用给定的域名和随机分配的公网端口号访问。

安装

```sh
scoop install ngrok
```

登录网页端获取 TOKEN，然后通过命令行登录。

```sh
ngrok config add-authtoken TOKEN
```

最后通过命令行暴露内网服务。

```sh
ngrok http 8000
ngrok tcp 22
```

更多配置参考 [官方文档](https://ngrok.com/docs/)。

## 游戏组网方案

一些游戏支持局域网联机，也可以通过 VPN 的方式进行组网。一些游戏支持通过 IP 地址的方式建立主机和联机游戏。以上组网方案都应该可以正常工作。

还有一些游戏内置局域网功能，无法手动输入 IP 地址进行联机。这些游戏通过广播包的方式搜索局域网用户，需要一些奇技淫巧。

### 使用 L2 VPN

wireguard 和基于 wireguard 的 VPN(如 tailscale) 都属于 L3 VPN，而一般的游戏的局域网功能都使用 L2 广播包。所以这种情况可以改用 L2 VPN，如 n2n、zerotier、openvpn 等等。

### WinIPBroadcast

Windows 游戏默认只在局域网中进行广播，所以无法在 VPN 中进行游戏。这种时候可以使用 [WinIPBroadcast](https://github.com/dechamps/WinIPBroadcast) 在所有网络中进行广播。

软件安装即用，在后台以服务的方式运行，无配置。

软件的功能有限制，无法重放源端口和目标端口相同的包，因此一些游戏无法应用 (如 CC3)，参见 [软件限制](https://github.com/dechamps/WinIPBroadcast#caveats--limitations)。

### radmin VPN

[radmin VPN](https://www.radmin-vpn.com) 也是一个支持局域网联机的 VPN。

### UsbEAm LAN Party

[UsbEAm LAN Party](https://www.dogfight360.com/blog/1590/)，需要自建中转服务器。
