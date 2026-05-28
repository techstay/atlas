---
title: "openwrt"
date: 2026-05-15T01:18:06+08:00
tags:
  - network
  - openwrt
  - router
categories:
  - 网络
---

## 安装和使用

### 下载

- [openwrt 官方](https://firmware-selector.openwrt.org/?target=x86%2F64&id=generic)
- [immortalwrt](https://firmware-selector.immortalwrt.org/?target=x86%2F64&id=generic)
- [lede](https://github.com/coolsnowwolf/lede/releases)
- https://openwrt.ai/?target=x86%2F64&id=generic

如果下载的官方镜像，还需要下载 [转换工具](https://www.starwindsoftware.com/tmplink/starwindconverter.exe)，将 img 格式镜像转换为 vmdk 格式的镜像。或者也可以根据 [官方文档](https://openwrt.org/docs/guide-user/virtualization/vmware) 进行转换。

```sh
scoop install busybox qemu
gunzip openwrt-x86-generic-combined-ext4.img.gz
qemu-img convert -f raw -O vmdk openwrt-x86-generic-combined-ext4.img openwrt-x86-generic-combined-ext4.vmdk
```

如遇到访问不了 web 界面的问题，检查 VMware 的桥接设置是否绑定到了正确的网络适配器上。

## 配置

### 预配置脚本

在下载 immortalwrt 之前，可以自定义组建和预配置脚本，免去系统启动之后繁复的手动配置工作。最后在电脑上设置 IPv6 DNS 地址。

```sh
uci set network.lan.ipaddr='192.168.42.2'
uci set network.lan.gateway='192.168.42.1'
uci set network.lan.dns='223.5.5.5'
uci set 'system.@system[0].zonename'='Asia/Shanghai'
uci set 'system.@system[0].timezone'='CST-8'
uci set system.ntp.enable_server='1'
uci set dhcp.lan.ra='server'
uci set dhcp.lan.ra_default='1'
uci set network.lan.delegate='0'
uci set 'dhcp.@dnsmasq[0].noresolv'='1'
uci set 'dhcp.@dnsmasq[0].server'='223.5.5.5'
uci set 'dhcp.@dnsmasq[0].filter_aaaa'='0'
uci delete network.globals.ula_prefix
uci commit
```

### 设置电脑本机 IP

配置软路由要频繁修改设备的网络配置，建议安装 NetSetMan，可以方便的切换配置。软路由默认 IP 为 `192.168.1.1`，设置电脑 IP 地址为 `192.168.1.100`，子网掩码 `255.255.255.0`，默认网关为 `192.168.1.1`。然后就可以访问路由器的 web 管理界面了。

### 设置旁路由 IP

访问 web 界面，修改*网络 ->接口 ->LAN*中的 IP 设置，或者从终端设置 IP 地址。

```sh
uci set network.lan.ipaddr='192.168.42.2'
uci set network.lan.gateway='192.168.42.1'
uci set network.lan.dns='223.5.5.5'
uci commit
reload_config
```

### 单臂主路由和旁路由切换

```sh
uci set network.wan.proto='pppoe'
uci set network.wan.device='br-lan'
uci set network.wan.username='047403103361'
uci set network.wan.password='123456'
uci set network.wan.ipv6='auto'
uci del network.lan.gateway
uci del network.wan.disabled

uci del network.wan.username
uci del network.wan.password
uci del network.wan.ipv6
uci set network.wan.device
uci set network.wan.proto='none'
uci set network.wan.disabled='1'
uci set network.lan.gateway='192.168.42.1'
```

### 系统配置

修改默认密码，复制粘贴 SSH 公钥启用 SSH 登录等等。配置完成后，还要对系统本身进行一些设置。

```sh
uci set 'system.@system[0].zonename'='Asia/Shanghai'
uci set 'system.@system[0].timezone'='CST-8'
uci set system.ntp.enable_server='1'
uci commit
```

### 扩容

openwrt 默认分区比较小，安装一些软件就满了，所以需要扩容。

```sh
opkg update
opkg install nano kmod-usb-core block-mount kmod-fs-ext4 kmod-usb-storage-extras e2fsprogs blkid cfdisk
```

然后通过 cfdisk 新建分区，再格式化。

```sh
mkfs.ext4 /dev/sda3
```

挂载，然后将 overlay 分区复制过去。

```sh
mount /dev/sda3 /mnt
tar -C /overlay -cvf - . | tar -C /mnt -xf -
```

最后在 web 界面里找到新添加的分区，选择为外部 overlay 分区，重启设备即可生效。

### 安装软件

一般的 OpenWrt 都编译了不少工具进去，只有原版的 Openwrt 什么也没有，需要手动安装工具，安装工具需要使用 opkg 工具。

安装汉化包和主题。

```sh
opkg update
opkg install luci-i18n-base-zh-cn luci-theme-argon luci-theme-design

uci set luci.main.lang='zh_cn'
uci set luci.main.mediaurlbase='/luci-static/material'
uci commit
```

### tailscale

tailscale 目前没有 luci 界面，只能通过终端配置。

```sh
opkg install tailscale
# 如果是Openwrt 22.03及以上，还要安装nft的包
opkg install iptables-nft
# 启动tailscale网络，将链接复制到浏览器中登录
tailscale up
```

如果要添加子网路由，还要添加启动参数，设置路由器所在的子网网段。

```sh
tailscale up --advertise-routes=192.168.31.0/24
```

### 启用 IPv6

首先参考 [这篇文章](https://opclash.com/luyou/216.html)，启用光猫的 IPv6 功能。

然后输入以下命令启用 IPv6 功能。

```sh
uci set dhcp.lan.ra='hybrid'
uci set dhcp.lan.ra_default='1'
uci set network.lan.delegate='0'
uci set 'dhcp.@dnsmasq[0].noresolv'='1'
uci set 'dhcp.@dnsmasq[0].server'='223.5.5.5'
uci set 'dhcp.@dnsmasq[0].filter_aaaa'='0'
uci delete network.globals.ula_prefix
uci commit
```

查看和调试可以通过下面的服务进行。

- IPv6 教程 https://post.smzdm.com/p/awzodmpp/?sort_tab=hot%25252525252F
- <https://test-ipv6.com>
- <https://ipw.cn>
- <https://ip.skk.moe>

### 终端配置

先安装 git

```sh
opkg update && opkg install git git-http gnupg2 lua shadow-chsh zsh
```

然后安装 zimfw

```sh
curl -fsSL https://raw.githubusercontent.com/zimfw/install/master/install.zsh | zsh
```

已经有 dotfiles 配置的，可以安装 yadm 并还原配置。

```sh
# 安装yadm
opkg install bash git git-http gnupg coreutils-chmod coreutils-stat
curl -fLo /usr/bin/yadm https://github.com/TheLocehiliosan/yadm/raw/master/yadm && chmod a+x /usr/bin/yadm
# 还原配置
yadm clone -b openwrt https://github.com/techstay/dotfiles
# change default sh
chsh -s $(which zsh)
```

### docker

openwrt 默认没有使用全部空间，需要先将 SD 卡扩容，参考 [官方文档 - 空间扩容](https://doc.openwrt.cc/1-General/6-Resize/)。扩容完成后，需重启 openwrt，重启之后，在*系统 ->挂载点*看到新增了 `/opt` 分区，即为扩容成功。

安装 docker，然后在 web 面板中开启。

```sh
opkg install luci-app-dockerman docker-compose
```

### openclash

一些固件已经自带了 openclash，官方镜像需要手动安装。

```sh
opkg install coreutils-nohup bash dnsmasq-full curl ca-certificates ipset ip-full libcap libcap-bin ruby ruby-yaml kmod-tun kmod-inet-diag unzip kmod-nft-tproxy luci-compat luci luci-base
# 下载openclash软件包，然后上传到软路由中去安装
# 如果使用的scp版本较新，需要添加-O参数
scp luci-app-openclash.ipk op:/tmp

# 如果安装了dnsmasq，需要先卸载，然后安装dnsmasq-full
opkg remove dnsmasq
opkg install dnsmasq-full

# 最后安装openclash
opkg install /tmp/luci-app-openclash.ipk
```
