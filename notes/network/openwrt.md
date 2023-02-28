# openwrt

## 安装和使用

### 虚拟机旁路由

之前因为树莓派旁路由设置错误，导致再也连接不上。然后我尝试在内存卡上重做系统，但是不知道为何还保留着原来的数据，偏偏另外几张内存卡也不能使用。所以最后树莓派作为旁路由的功能也没办法继续使用了。不过旁路由的体验确实比 cfw 好，所以我准备用虚拟机旁路由来折腾一下。基本上 1G 内存完全够用，也不会太占用电脑资源。

### 下载

我用的 vmware 虚拟机软件，就下载 vmdk 格式的包，文件系统格式选择 squashfs，方便备份和升级。下载完成后创建虚拟机，设置好之后启动。没什么特殊需求的话，就不用专门下载官方原版，官方版干净纯洁，但是什么插件都没有，都要自己安装，不如直接使用第三方版本，自带大量插件，开箱即用。

我这里主要使用 openwrt-rpi，它的固件每日自动根据源码构建最新版，自带 oh-my-zsh，使用起来比较方便。

- [openwrt 官方](https://firmware-selector.openwrt.org/?target=x86%2F64&id=generic)
- [immortalwrt](https://firmware-selector.immortalwrt.org/?target=x86%2F64&id=generic)
- [lede](https://github.com/coolsnowwolf/lede/releases)
- [openwrt-rpi](https://github.com/SuLingGG/OpenWrt-Rpi/releases/tag/x86-64)

如果下载的官方镜像，还需要下载[转换工具](https://www.starwindsoftware.com/tmplink/starwindconverter.exe)，将 img 格式镜像转换为 vmdk 格式的镜像。或者也可以根据[官方文档](https://openwrt.org/docs/guide-user/virtualization/vmware)进行转换。

```sh
scoop install busybox qemu
gunzip openwrt-x86-generic-combined-ext4.img.gz
qemu-img convert -f raw -O vmdk openwrt-x86-generic-combined-ext4.img openwrt-x86-generic-combined-ext4.vmdk
```

## 配置

### 设置电脑本机 IP

配置软路由要频繁修改设备的网络配置，建议安装 NetSetMan，可以方便的切换配置。软路由默认 IP 为`192.168.1.1`，设置电脑 IP 地址为`192.168.1.100`，子网掩码`255.255.255.0`，默认网关为`192.168.1.1`。然后就可以访问路由器的 web 管理界面了。

### 设置旁路由 IP

访问 web 界面，修改*网络->接口->LAN*中的 IP 设置，或者从终端设置 IP 地址。

```sh
uci set network.lan.ipaddr='192.168.31.2'
uci set network.lan.gateway='192.168.31.1'
uci set network.lan.dns='223.5.5.5'
uci commit
reload_config
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

安装汉化包和 material 主题。

```sh
opkg update
opkg install luci-i18n-base-zh-cn luci-theme-material

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

首先参考[这篇文章](https://opclash.com/luyou/216.html)，启用光猫的 IPv6 功能。

然后输入以下命令启用 IPv6 功能。

```sh
uci set dhcp.lan.ra='hybrid'
uci set dhcp.lan.ra_default='1'
uci set network.lan.delegate='0'
uci set 'dhcp.@dnsmasq[0].noresolv'='1'
uci set 'dhcp.@dnsmasq[0].server'='223.6.6.6'
uci set 'dhcp.@dnsmasq[0].filter_aaaa'='0'
uci delete network.globals.ula_prefix
uci commit
```

查看和调试可以通过下面的服务进行。

- <https://test-ipv6.com>
- <https://ipw.cn>
- <https://ip.skk.moe>

### 终端配置

先安装 git

```sh
opkg update && opkg install git git-http gnupg2 lua
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
```

### docker

openwrt 默认没有使用全部空间，需要先将 SD 卡扩容，参考[官方文档 - 空间扩容](https://doc.openwrt.cc/1-General/6-Resize/)。扩容完成后，需重启 openwrt，重启之后，在*系统->挂载点*看到新增了`/opt`分区，即为扩容成功。

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

<details>
    <summary>个人配置</summary>

```sh
uci set openclash.config.disable_udp_quic='1'
uci set openclash.config.filter_aaaa_dns='0'
uci set openclash.config.router_self_proxy='1'
uci set openclash.config.operation_mode='fake-ip'
uci set openclash.config.ipv6_enable='1'
uci set openclash.config.ipv6_dns='1'
uci set openclash.config.disable_masq_cache='1'
uci set openclash.config.dnsmasq_noresolv='1'
uci set openclash.config.geo_auto_update='1'
uci set openclash.config.geo_update_day_time='14'
uci set openclash.config.chnr_auto_update='1'
uci set openclash.config.chnr_update_day_time='14'
uci set openclash.config.china_ip6_route='1'
uci set openclash.config.china_ip_route='1'
uci set openclash.config.store_fakeip='1'
uci set openclash.config.custom_china_domain_dns_server='119.29.29.29'
uci set openclash.config.dnsmasq_server='119.29.29.29'
uci set openclash.config.append_wan_dns='1'
uci set openclash.config.append_default_dns='1'

uci batch <<'EOI'
add openclash rule_providers
set 'openclash.@rule_providers[0]'=rule_providers
set 'openclash.@rule_providers[0]'.enabled='1'
set 'openclash.@rule_providers[0]'.config='all'
set 'openclash.@rule_providers[0]'.type='http'
set 'openclash.@rule_providers[0]'.behavior='domain'
set 'openclash.@rule_providers[0]'.url='https://cdn.jsdelivr.net/gh/Loyalsoldier/clash-rules@release/reject.txt'
set 'openclash.@rule_providers[0]'.interval='86400'
set 'openclash.@rule_providers[0]'.position='0'
set 'openclash.@rule_providers[0]'.group='REJECT'
set 'openclash.@rule_providers[0]'.name='Rule-provider-reject'
add openclash rule_providers
set 'openclash.@rule_providers[1]'=rule_providers
set 'openclash.@rule_providers[1]'.enabled='1'
set 'openclash.@rule_providers[1]'.config='all'
set 'openclash.@rule_providers[1]'.type='http'
set 'openclash.@rule_providers[1]'.behavior='domain'
set 'openclash.@rule_providers[1]'.url='https://cdn.jsdelivr.net/gh/Loyalsoldier/clash-rules@release/proxy.txt'
set 'openclash.@rule_providers[1]'.interval='86400'
set 'openclash.@rule_providers[1]'.position='0'
set 'openclash.@rule_providers[1]'.group='Proxy'
set 'openclash.@rule_providers[1]'.name='Rule-provider-proxy'
add openclash rule_providers
set 'openclash.@rule_providers[2]'=rule_providers
set 'openclash.@rule_providers[2]'.enabled='1'
set 'openclash.@rule_providers[2]'.config='all'
set 'openclash.@rule_providers[2]'.type='http'
set 'openclash.@rule_providers[2]'.behavior='domain'
set 'openclash.@rule_providers[2]'.url='https://cdn.jsdelivr.net/gh/Loyalsoldier/clash-rules@release/gfw.txt'
set 'openclash.@rule_providers[2]'.interval='86400'
set 'openclash.@rule_providers[2]'.position='0'
set 'openclash.@rule_providers[2]'.group='Proxy'
set 'openclash.@rule_providers[2]'.name='Rule-provider-gfw'
add openclash rule_providers
set 'openclash.@rule_providers[3]'=rule_providers
set 'openclash.@rule_providers[3]'.enabled='1'
set 'openclash.@rule_providers[3]'.config='all'
set 'openclash.@rule_providers[3]'.type='http'
set 'openclash.@rule_providers[3]'.behavior='domain'
set 'openclash.@rule_providers[3]'.url='https://cdn.jsdelivr.net/gh/Loyalsoldier/clash-rules@release/tld-not-cn.txt'
set 'openclash.@rule_providers[3]'.interval='86400'
set 'openclash.@rule_providers[3]'.position='0'
set 'openclash.@rule_providers[3]'.group='Proxy'
set 'openclash.@rule_providers[3]'.name='Rule-provider-notcn'
add openclash rule_providers
set 'openclash.@rule_providers[4]'=rule_providers
set 'openclash.@rule_providers[4]'.enabled='1'
set 'openclash.@rule_providers[4]'.config='all'
set 'openclash.@rule_providers[4]'.type='http'
set 'openclash.@rule_providers[4]'.behavior='domain'
set 'openclash.@rule_providers[4]'.url='https://cdn.jsdelivr.net/gh/Loyalsoldier/clash-rules@release/applications.txt'
set 'openclash.@rule_providers[4]'.interval='86400'
set 'openclash.@rule_providers[4]'.position='0'
set 'openclash.@rule_providers[4]'.group='DIRECT'
set 'openclash.@rule_providers[4]'.name='Rule-provider-applications'
EOI
uci commit
```

</details>
