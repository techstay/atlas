---
title: "tools"
date: 2026-05-15T01:18:06+08:00
tags:
  - network
categories:
  - 网络
---

## 常用工具

### ping

windows 系统默认关闭 ping，需要手动设置防火墙入站规则。

```powershell
New-NetFirewallRule -DisplayName "Allow inbound ICMPv4" -Direction Inbound -Protocol ICMPv4 -IcmpType 8 -RemoteAddress LocalSubnet -Action Allow
New-NetFirewallRule -DisplayName "Allow inbound ICMPv6" -Direction Inbound -Protocol ICMPv6 -IcmpType 8 -RemoteAddress LocalSubnet -Action Allow
```

### 端口转发

- 端口转发工具 https://portbuddy.dev

### 更改网络状态

查看网络状态

```powershell
Get-NetConnectionProfile
```

修改网络状态

```pwsh
Set-NetConnectionProfile -InterfaceIndex 42 -NetworkCategory Private
```

## 测速

### iperf3

安装

```sh
scoop install iperf3
```

电脑端使用服务器模式运行 iperf3。

```sh
iperf3 -s
```

客户端

```sh
iperf3 -c 192.168.31.100 -i 1 -n 800m -4
```

## 检查 IP

- IP 检测工具 https://ping0.cc
