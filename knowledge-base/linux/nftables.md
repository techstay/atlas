---
title: "nftables"
date: 2022-02-11T22:58:55+08:00
tags:
  - linux
  - 防火墙
  - 网络
categories:
  - linux
---

参考自 [Arck Wiki Nftables](https://wiki.archlinux.org/title/Nftables)。

## 安装

首先安装 nftables：

```sh
# ubuntu
sudo apt install nftables
# Arch & Manjaro
sudo pacman -S nftables
```

## 防火墙配置

### 开启防火墙

启用并设置 nftables 防火墙开机自启。

```sh
sudo systemctl start nftables
sudo systemctl enable nftables
```

### 配置文件

nftables 默认从 `/etc/nftables.conf` 配置文件中加载规则。

将规则写入到文件中。

```sh
nft list ruleset > filename
```

手动加载文件中的规则。

```sh
nft -f filename
```

### 表管理

和 iptables 一样，nftables 也有表和链的概念。不过不同的是，nftables 默认没有加载任何表的配置，所有配置都需要用户自己创建。在创建表的时候需要指定家族，每个家族对应的 iptables 功能如下。如果没有指定家族，则默认使用 ip 家族，也就是 IPv4 的表。

| nftables family | iptables utility       |
| --------------- | ---------------------- |
| ip              | iptables               |
| ip6             | ip6tables              |
| inet            | iptables and ip6tables |
| arp             | arptables              |
| bridge          | ebtables               |

在使用 nftables 之前，自然需要先创建表。

```sh
nft add table family_type table_name
```

列出所有表。

```sh
nft list tables
```

删除表。

```sh
nft delete table family_type table_name
```

清空表。

```sh
nft flush table family_type table_name
```

列出一个表中的所有链。

```sh
nft list table family_type table_name
```

### 链管理

创建链。

```sh
nft add chain inet my_table my_tcp_chain
```

列出链。

```sh
nft list chain family_type table_name chain_name
```

编辑链。

```sh
nft chain family_type table_name chain_name '{ [ type chain_type hook hook_type device device_name priority priority_value ; policy policy_type ; ] }'
```

删除链。

```sh
nft delete chain family_type table_name chain_name
```

清空链。

```sh
nft flush chain family_type table_name chain_name
```

### 规则

向链中添加规则。

```sh
nft add rule family_type table_name chain_name handle handle_value statement
```

在 `handle_value` 处插入规则，不指定则在末尾追加。

```sh
nft insert rule family_type table_name chain_name handle handle_value statement
```

规则的语句（statement）部分由匹配的表达式和要执行的结果组成，这点和 iptables 一样。以下是匹配参数的一个不完全列表，详情参考 `nft` 命令帮助。

```txt
meta:
  oif <output interface INDEX>
  iif <input interface INDEX>
  oifname <output interface NAME>
  iifname <input interface NAME>

  (oif and iif accept string arguments and are converted to interface indexes)
  (oifname and iifname are more dynamic, but slower because of string matching)

icmp:
  type <icmp type>

icmpv6:
  type <icmpv6 type>

ip:
  protocol <protocol>
  daddr <destination address>
  saddr <source address>

ip6:
  daddr <destination address>
  saddr <source address>

tcp:
  dport <destination port>
  sport <source port>

udp:
  dport <destination port>
  sport <source port>

sctp:
  dport <destination port>
  sport <source port>

ct:
  state <new | established | related | invalid>
```

删除规则前需要知道句柄，然后才能删除。

```sh
nft --handle --numeric list chain inet my_table my_input
nft delete rule inet my_table my_input handle 10
```

也可以清空或者删除链。

```sh
nft flush table table_name
nft flush chain family_type table_name chain_name
nft delete rule family_type table_name chain_name
```

### 集合

集合以一堆花括号组成，可以容纳多个参数。匿名集合不能修改，只能整个添加和删除。

```sh
nft add rule ip6 filter input tcp dport {telnet, http, https} accept
```

命名集合可以动态修改其中的元素。例如有如下配置。

```sh
table ip sshguard {
       set attackers {
               type ipv4_addr
               flags interval
               elements = { 1.2.3.4 }
       }
```

然后就可以对 set 进行修改。

```sh
nft add element ip sshguard attackers { 5.6.7.8/32 }
nft delete element ip sshguard attackers { 1.2.3.4/32 }
```

### 原子重载

创建一个临时配置文件，在开头清空所有规则，然后将已有规则写入。这样每次用该文件导入的时候，就可以完美还原配置文件中的内容。

```sh
echo "flush ruleset" > /tmp/nftables
nft -s list ruleset >> /tmp/nftables
nft -f /tmp/nftables
```

## 示例配置

### 基本配置

通过命令行配置一个简单的防火墙。

```sh
# 清空规则
nft flush ruleset
# 创建过滤表
nft add table inet filter
# 创建链，默认状态启用
nft add chain inet filter input '{ type filter hook input priority 0; }'
nft add chain inet filter forward '{ type filter hook forward priority 0; }'
nft add chain inet filter output '{ type filter hook output priority 0; }'
# 禁用所有传入连接
nft chain inet filter input '{ policy drop ; }'
# 允许SSH连入
nft add rule inet filter input \
   tcp dport 22 \
   accept \
   comment \"Allow SSH\"
```

配置文件内容。

```conf
table inet filter {
        chain input {
                type filter hook input priority filter; policy drop;
                tcp dport 22 accept comment "Allow SSH"
        }

        chain forward {
                type filter hook forward priority filter; policy accept;
        }

        chain output {
                type filter hook output priority filter; policy accept;
        }
}
```

### 限制速率

还可以限制一些连接的速率。

```conf
table inet my_table {
 chain my_input {
  type filter hook input priority filter; policy drop;

  iif lo accept comment "Accept any localhost traffic"
  ct state invalid drop comment "Drop invalid connections"

  meta l4proto icmp icmp type echo-request limit rate over 10/second burst 4 packets drop comment "No ping floods"
  meta l4proto ipv6-icmp icmpv6 type echo-request limit rate over 10/second burst 4 packets drop comment "No ping floods"

  ct state established,related accept comment "Accept traffic originated from us"

  meta l4proto ipv6-icmp icmpv6 type { destination-unreachable, packet-too-big, time-exceeded, echo-reply, parameter-problem, mld-listener-query, mld-listener-report, mld-listener-reduction, nd-router-solicit, nd-router-advert, nd-neighbor-solicit, nd-neighbor-advert, ind-neighbor-solicit, ind-neighbor-advert, mld2-listener-report } accept comment "Accept ICMPv6"
  meta l4proto icmp icmp type { destination-unreachable, router-solicitation, router-advertisement, time-exceeded, parameter-problem } accept comment "Accept ICMP"
  ip protocol igmp accept comment "Accept IGMP"

  tcp dport ssh ct state new limit rate 15/minute accept comment "Avoid brute force on SSH"

 }

}
```

更加复杂的配置这里就不再列出了。
