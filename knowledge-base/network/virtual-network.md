---
title: "虚拟组网与内网穿透"
date: 2026-05-15T01:18:06+08:00
tags:
  - VPN
  - 虚拟组网
  - 内网穿透
  - Tailscale
  - ZeroTier
categories:
  - 网络
---

# 🌐 虚拟组网与内网穿透

无需公网 IP，即可将分散的设备连入同一个虚拟局域网——这就是虚拟组网的魅力 🏠 无论是远程办公、游戏联机还是内网服务暴露，都能轻松搞定。

## 组网工具列表

一些主流的虚拟组网方案。

- [Tailscale](https://tailscale.com/)，基于 WireGuard 协议，配置简单、开箱即用，适合快速搭建私有网络 ✨
- [ZeroTier](https://www.zerotier.com/)，工作在 Layer 2 的虚拟以太网交换机，可模拟完整局域网，支持游戏联机和远程桌面串流 🎮
- [n2n](https://github.com/ntop/n2n)，轻量级 P2P VPN，支持直连打洞，直连失败时自动回退到服务器中转

两者的核心区别：ZeroTier 层级更低（Layer 2），甚至可以用于需要广播包的游戏联机；Tailscale 基于 WireGuard，配置更简单，生态更完善。

## Tailscale

[Tailscale](https://tailscale.com/) 是基于 [WireGuard](https://www.wireguard.com/) 协议的虚拟组网方案，由 Tailscale Inc. 维护，提供零配置的安全点对点连接。

### 安装 📦

**Windows**

```sh
winget.exe install --id "Tailscale.Tailscale" --exact --source winget --accept-source-agreements --disable-interactivity --silent --accept-package-agreements --force
```

**OpenWrt**

```sh
opkg install tailscale
```

### 局域网路由 🛣️

通告本地子网路由，让 tailnet 中的其他设备也能访问你的局域网设备：

```sh
tailscale up --advertise-routes=192.168.31.0/24
```

### Serve 与 Funnel 🔓

**暴露到 tailnet 内部** 🏠

[serve](https://tailscale.com/kb/1080/cli/#serve) 可以将本地服务暴露给 tailnet 中的其他设备访问：

```sh
# 语法
tailscale serve http[:<port>] <mount-point> <source> [off]
# 例子：开放 Hugo 博客
tailscale serve http / http://localhost:1313
```

**暴露到公网** 🌍

[funnel](https://tailscale.com/kb/1080/cli/#funnel) 将 serve 中的服务进一步暴露到公网，仅支持 443、8443、10000 三个端口：

```sh
tailscale funnel 443 on
tailscale funnel status
```

### Headscale 🏗️

Tailscale 的官方服务端由 Tailscale Inc. 托管。如果你希望完全掌控控制服务器，可以部署 [Headscale](https://github.com/juanfont/headscale)——一个开源的自托管替代方案，兼容 Tailscale 客户端。

### xEdge 🇨🇳

[xEdge](https://xedge.cc) 是国内版 Tailscale，使用国内中继节点，延迟更低，适合国内用户。

### 调试 🔍

```sh
tailscale ping <host>       # 测试连通性（含 DERP 中继检测）
tailscale netcheck          # 检查 NAT 类型与中继延迟
tailscale status            # 查看 tailnet 节点状态
```

### 命令行速查 ⚡

```sh
# --- 状态与诊断 ---
tailscale status                  # 查看 tailnet 中所有节点状态
tailscale ip                      # 查看当前节点的 Tailscale IP
tailscale ping <host>             # 测试到目标节点的连通性（含 DERP 中继检测）
tailscale netcheck                # 检查 NAT 类型与 DERP 中继延迟
tailscale debug doctor            # 综合诊断连接问题

# --- 连接管理 ---
tailscale up                      # 连接 / 重新连接
tailscale up --accept-routes      # 接受其他节点通告的子网路由
tailscale up --advertise-routes=192.168.1.0/24  # 向 tailnet 通告本地子网
tailscale up --exit-node=<ip>     # 通过指定节点路由全部流量
tailscale up --exit-node=         # 清除 exit node
tailscale down                    # 断开连接

# --- 节点控制 ---
tailscale logout                  # 注销当前节点
tailscale reset                   # 重置所有 Tailscale 网络设置

# --- Serve / Funnel ---
tailscale serve http / http://localhost:8080   # 在 tailnet 内暴露本地服务
tailscale serve status                         # 查看 serve 配置
tailscale serve --reset                        # 清除所有 serve 配置
tailscale funnel 443 on                        # 将 serve 的服务暴露到公网
tailscale funnel status                        # 查看 funnel 状态

# --- ACL 与密钥 ---
tailscale login                                 # 交互式登录（获取 auth URL）
tailscale up --authkey=<key>                    # 使用 auth key 免交互登录
```

## ZeroTier

[ZeroTier](https://www.zerotier.com/) 是一个开源的虚拟以太网交换机，工作在 Layer 2，可以模拟完整的局域网环境。相比 Tailscale，它层级更低，支持广播包，适合游戏联机和 Parsec 远程桌面等低延迟场景 🎮

### 安装 📦

**Windows**

```sh
winget.exe install --id "ZeroTier.ZeroTierOne" --exact --source winget --accept-source-agreements --disable-interactivity --silent --accept-package-agreements --force
```

### 调试 🔍

```sh
zerotier-cli info           # 查看节点信息
zerotier-cli peers          # 查看已连接的节点
zerotier-cli listnetworks   # 查看已加入的网络
```

## n2n

[n2n](https://github.com/ntop/n2n) 是一个轻量级 P2P VPN，会尝试打洞直连，直连失败时自动使用服务器中转。

使用时需指定网络名称（`-c`）和密钥（`-k`），多个客户端应使用不同的虚拟 IP 地址：

```sh
sudo edge -c mynetwork -k mysecretpass -a 192.168.100.1 -f -l supernode.ntop.org:7777
sudo edge -c mynetwork -k mysecretpass -a 192.168.100.2 -f -l supernode.ntop.org:7777
```

## 内网穿透

当虚拟组网无法满足需求时，还可以通过内网穿透工具将本地服务暴露到公网。

### frp 🔧

[frp](https://github.com/fatedier/frp) 是一个高性能的反向代理工具，支持 TCP、UDP、HTTP、HTTPS 等多种协议，需要自备公网服务器。

### Sakura Frp 🌸

[Sakura Frp](https://www.natfrp.com) 是国内的免费内网穿透服务，使用国内节点需要实名认证，开箱即用，适合不想自建服务器的场景。

### ngrok 🚀

[ngrok](https://ngrok.com) 是一款流行的内网穿透工具，免费版只能使用给定域名和随机分配的公网端口。

```sh
# 安装
scoop install ngrok

# 登录（TOKEN 从网页端获取）
ngrok config add-authtoken TOKEN

# 暴露服务
ngrok http 8000
ngrok tcp 22
```

更多配置参考 [官方文档](https://ngrok.com/docs/)。

## 游戏组网 🎮

许多游戏支持通过 IP 地址建立局域网联机，上述组网方案均可使用。但部分游戏内置局域网发现功能，依赖 L2 广播包搜索玩家，需要额外处理。

### 使用 L2 VPN 🔗

Tailscale 等基于 WireGuard 的 VPN 属于 L3 VPN，无法转发广播包。对于需要广播发现的游戏，可改用 L2 VPN，如 ZeroTier、n2n、OpenVPN 等。

### WinIPBroadcast 📡

[WinIPBroadcast](https://github.com/dechamps/WinIPBroadcast) 让 Windows 游戏在所有网络接口中发送广播包，安装即用，无需配置。

⚠️ 软件限制：无法重放源端口和目标端口相同的包，部分游戏可能无法使用，参见 [Caveats & Limitations](https://github.com/dechamps/WinIPBroadcast#caveats--limitations)。

### Radmin VPN 🎯

[Radmin VPN](https://www.radmin-vpn.com) 是一款免费的虚拟局域网工具，专为游戏联机设计。

### UsbEAm LAN Party 🎲

[UsbEAm LAN Party](https://www.dogfight360.com/blog/1590/) 是一款游戏联机工具，需要自建中转服务器。
