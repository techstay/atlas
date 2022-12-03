---
icon: network
---

# 网络

一些网络相关的知识和工具笔记。

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
