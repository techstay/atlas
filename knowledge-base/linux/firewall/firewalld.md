---
title: "firewalld"
date: 2022-03-02T18:00:06+08:00
tags:
  - linux
  - 防火墙
  - 网络
categories:
  - linux
---

iptables 和 nftables 都比较底层，用于精细控制 Linux 的网络层，而不仅仅是作为防火墙使用。如果只是想要使用防火墙的保护功能，可以使用 firewalld 和 ufw 这样的高级防火墙，它们都是基于 `*tables` 的。

## 安装和启用

```sh
sudo pacman -S firewalld
sudo systemctl start firewalld
sudo systemctl enable firewalld
```

## 配置

### 区域

列出所有或者单个区域。

```sh
firewall-cmd --list-all-zones
firewall-cmd --info-zone=zone_name
```

改变区域。

```sh
firewall-cmd --zone=zone --change-interface=interface_name
```

获取当前区域。

```sh
firewall-cmd --get-active-zones
```

当新的接口连接上的时候，会自动应用默认区域。要改变默认区域：

```sh
firewall-cmd --get-default-zone
firewall-cmd --set-default-zone=zone
```

使用 NetworkManager 可以在特定接口上设定区域。

```sh
# 列出所有接口
nmcli connection show
# 在接口上设定区域
nmcli connection modify myssid connection.zone home
```

### 服务

服务即是预定义的规则。

列出服务的信息。

```sh
firewall-cmd --get-services
firewall-cmd --info-service service_name
```

向区域添加或者删除服务。

```sh
firewall-cmd --zone=zone_name --add-service service_name
firewall-cmd --zone=zone_name --remove-service service_name
```

如果这些服务仍然不能满足需求，也可以自行设定端口号。

```sh
firewall-cmd --zone=zone_name --add-port port_num/protocol
firewall-cmd --zone=zone_name --remove-port port_num/protocol
```

### 运行时配置和永久配置

命令行配置的默认都是运行时配置，需要永久生效的话。

```sh
firewall-cmd --runtime-to-permanent
```

### 超时设置

可以暂时让一个服务或者端口号生效，这仅适用于运行时配置。

```sh
firewall-cmd --add-service ssh --timeout=3h
```

### 图形化界面

`firewalld` 包自带了名为 `firewall-config` 的图形界面配置程序，可以在桌面环境下使用。

如果在服务器环境下的话可以安装 `cockpit`，附带了一个 web 配置界面，端口号默认为 `9090`。
