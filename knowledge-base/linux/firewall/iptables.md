---
title: "iptables"
date: 2022-02-09T17:54:05+08:00
tags:
  - linux
  - 防火墙
  - 网络
categories:
  - linux
---

要学习 linux 防火墙的使用，首先要学的自然就是 iptables，这是最经典的 linux 防火墙工具。

## 安装

iptables 默认包含在大多数 linux 发行版中，无需额外安装即可使用。

## 基本概念

### 表

iptables 包含 5 张表，raw、filter、nat、mangle、security，其中最常用的就是 filter 和 nat 了，其他表的配置复杂，用途也比较专业，这里就不介绍了。

### 链

表由链组成，而链则是由按一定顺序排列的防火墙规则组成。默认的 filter 表就是由 INPUT、OUTPUT、FORWARD 三个链组成，而 nat 表则是由 PREROUTING、POSTROUTING 和 OUTPUT 链组成。

### 规则

防火墙规则是由匹配条件和目标组成，匹配条件可以是数据包的来源、类型、目标端口号等等；而目标则是对数据包要采取的动作，例如 ACCEPT、DROP、REJECT 等等。

## 防火墙配置

### 启用

iptables 是一个 systemd 服务，所以启用它的办法就是用 systemctl 命令来启用。

```sh
# 开启服务
sudo systemctl start iptables
# 让服务自启
sudo systemctl enable iptables
# 开启IPV6控制
sudo systemctl start ip6tables
```

### 配置文件

iptables 的配置文件是 `/etc/iptables/iptables.rule` 和 `/etc/iptables/ip6tables.rule`，会在服务启动的时候自动读取。不过，在使用命令行添加了一些防火墙规则之后，并不会自动同步到配置文件中，而是需要我们手动保存规则。

```sh
iptables-save -f /etc/iptables/iptables.rules
```

而在修改了配置文件之后，同样需要重载服务才能生效。

```sh
# 重载服务
sudo systemctl reload iptables
# 或者另一种方式
iptables-restore /etc/iptables/iptables.rules
```

以上命令均需要 root 权限，所以可能需要在命令前添加 `sudo` 或者直接在 root 用户下执行，后面的命令同理。

### 查看当前配置

首先先来查看一下当前的防火墙规则，如果你没有添加任何规则，那么这里应该是空的。

```sh
iptables -nvL
# 如果要查看其他表的规则，使用-t参数
iptables -nvL -t nat
# 查看规则时最好同时显示行号，方便后续编辑
iptables -nvL --line-numbers
```

### 重置防火墙规则

如果需要重置防火墙规则，可以使用下面的命令。

```sh
iptables -F
iptables -X
iptables -t nat -F
iptables -t nat -X
iptables -t mangle -F
iptables -t mangle -X
iptables -t raw -F
iptables -t raw -X
iptables -t security -F
iptables -t security -X
iptables -P INPUT ACCEPT
iptables -P FORWARD ACCEPT
iptables -P OUTPUT ACCEPT
```

iptables 默认也安装了一个空的配置文件，可以用来重置规则。

```sh
iptables-restore < /etc/iptables/empty.rules
```

## 编辑规则

### 参数说明

iptables 的命令行参数比较多，所以先来看看各个参数的说明吧。

- `-p` 代表协议，例如 tcp、udp 等等，如果不指定则默认为 all 也就是所有协议。协议可以用编号或者名称来指定，所有可用的协议在 `/etc/protocols` 文件中列出
- `-s` 代表来源，可以是一个 IP 地址或者主机名。例如 `192.168.31.1` 代表单个 IP 地址，`192.168.31.0/24` 代表一个子网。
- `-d` 代表目的地，和 `-s` 参数类似
- `-j` 代表目标，也就是要采用的行为，常用的有 ACCEPT、DROP、REJECT 等
- `-i` 代表输入接口，也就是入站规则使用的网络接口
- `-o` 代表输出接口，也就是出站规则使用的网络接口
- `--sport` 代表来源端口号，可以用端口号或者名称来指定，名称在 `/etc/services` 中列出，也可以用 `20:100` 来指定一个端口号范围
- `--dport` 代表目的地端口号，和 `--sport` 类似，要注意当你使用这两个参数的时候必须用 `-p` 指定具体的协议

### 添加规则

filter 表的 INPUT 和 OUTPUT 链代表入站规则和出站规则，入站规则就是外来链接访问本地主机的规则，而出站规则就是本地主机访问外部网络的规则。

我们首先设置一组简单粗暴的规则，阻止所有试图访问本地主机的外部连接，同时允许所有访问外部网络的请求。需要注意这些命令你应该在虚拟机里直接执行而非使用 SSH 远程连接，因为这个入站规则会同时禁用 SSH 连接，导致永远无法使用 SSH。

```sh
# 使用-P参数设置策略
iptables -P INPUT DROP
iptables -P OUTPUT ACCEPT
```

上面的入站策略会禁止所有对本地主机的访问，所以你甚至不能通过本地回环对称访问自己。因此有必要解禁一些连接，例如对本地回环地址的访问，这在大多数情况下都是安全的。如果你在本地运行了 nginx 服务器，现在就可以使用 `localhost` 访问了。如果要查看其他网络接口，使用 `ip a` 命令。

```sh
iptables -A INPUT -i lo -j ACCEPT
iptables -A OUTPUT -o lo -j ACCEPT
```

如果要允许外部连接访问一些本地服务，使用端口号放行即可。

```sh
# 允许SSH连接
iptables -A INPUT -p tcp --dport 22 -j ACCEPT
# 允许HTTP连接
iptables -A INPUT -p tcp --dport 80 -j ACCEPT
```

如果发现来自某个 IP 的攻击，可以简单的禁止所有来自该 IP 的访问。

```sh
iptables -A INPUT -s 1.2.3.4 -j DROP
```

如果不想上班摸鱼的话，可以禁止访问外网 80 和 443 端口号，这样就没办法上网了。

```sh
iptables -A OUTPUT -p tcp --dport 80 -j REJECT
iptables -A OUTPUT -p tcp --dport 443 -j REJECT
```

### 修改规则

如果要修改规则，可以使用 `-I`、`-R` 和 `-D` 参数，它们的作用分别是插入、替换和删除规则，在使用这几个参数的时候，需要额外指定要修改的规则的编号。例如，我不小心多输入了一次命令，导致出现了两条相同的规则，这时候就可以指定编号来删除了。

```txt
# 编号12都是重复的规则
Chain OUTPUT (policy ACCEPT 0 packets, 0 bytes)
num   pkts bytes target     prot opt in     out     source               destination
1        0     0 ACCEPT     tcp  --  *      lo      0.0.0.0/0            0.0.0.0/0            tcp dpt:80
2       12   720 ACCEPT     tcp  --  *      lo      0.0.0.0/0            0.0.0.0/0            tcp dpt:80
3      172 12728 REJECT     all  --  *      lo      0.0.0.0/0            0.0.0.0/0            reject-with icmp-port-unreachable

# 删除编号为1的规则
iptables -D OUTPUT 1
```

### 保存规则

使用命令行设置的规则只在当前生效，一旦重启就会恢复为原来的样子。要永久保存到配置文件中需要用前面介绍过的命令。

```sh
iptables-save -f /etc/iptables/iptables.rules
```

然后再查看配置文件也会发现规则已经保存了。

## 日志

有时候需要对网络访问情况进行记录，这时候就可以使用 iptables 的日志功能了。

### 日志目标

除了常见的 ACCEPT、REJECT 等目标之外，iptables 还包含了一个叫做 LOG 的目标，可以用来记录日志。不过和前几个不同的是，数据包在遇到 LOG 目标之后，不会停止，而是会被发送到下一个规则继续处理。因此最简单的一种日志记录方式就是在每一个要记录的目标之前插入一个 LOG 目标。

例如，我先添加了一条入站规则禁止所有 80 端口的连接。

```sh
iptables -A INPUT -p tcp --dport 80 -j REJECT
```

然后在这条规则（假设编号为 1）之前插入日志规则，就可以实现日志记录了。

```sh
iptables -I INPUT 1 -p tcp --dport 80 -j LOG
```

### 日志链

如果你要对多个规则设置日志记录，那么就需要在每一个要记录的规则前添加一条日志规则。其实还有更加简便的办法，那就是自定义一条日志链。首先新建一条名为 logdrop 的链，这个链将用于记录所有被丢弃的数据包记录。

```sh
iptables -N logdrop
```

然后为 logdrop 链设置规则。第一条规则是为了防止日志太多挤满磁盘空间，只有最开始的 10 个数据包和后续每分钟 5 个数据包会被记录。第二条就是对数据包实施丢弃处理。

```sh
iptables -A logdrop -m limit --limit 5/m --limit-burst 10 -j LOG
iptables -A logdrop -j DROP
```

然后就可以设置规则，将目标设为 logdrop 链，这样即可实现对不同的规则实施统一的日志处理。

```sh
iptables -A INPUT -p tcp --dport 80 -j logdrop
```

### 查看日志

日志会被记录到 systemd 的日志系统中。

```sh
sudo journalctl -k --grep="IN=.*OUT=.*"
```

## 参考资料

- <https://wiki.archlinux.org/title/Iptables>
- <https://www.thegeekstuff.com/2011/02/iptables-add-rule/>
- <https://www.thegeekstuff.com/2011/06/iptables-rules-examples/>
