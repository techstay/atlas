# adguardhome

一个开源免费、功能强大的 DNS 服务器。

## 安装

我在树莓派上试着安装了一下，顺便做个记录。

使用 docker 方式安装最简单，首先需要安装好 docker，然后在拉取最新 adguardhome 镜像。

```sh
sudo apt install docker.io
docker pull adguard/adguardhome
```

然后启动 adgardhome，因为 docker 是容器，所以要用`--network host`参数直接使用宿主的网络，而不是容器的网络。

```sh
docker run --name adguardhome \
  --restart unless-stopped \
  -v /my/own/workdir:/opt/adguardhome/work \
  -v /my/own/confdir:/opt/adguardhome/conf \
  --network host -d adguard/adguardhome
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

配置好了就可以开始使用，用起来很简单，在你的设备上指定 adguardhome 服务作为 DNS 服务器即可。这里我在小米路由器里面设置，需要静态 IP，所以要提前在 DHCP 设置中绑定 MAC 地址。过一段时间再看，应该就可以在 adguardhome 中看到统计数据了。

如果只是想在本地电脑上使用的话，可以改用<https://github.com/mili-tan/AuroraDNS.GUI>这个项目。
