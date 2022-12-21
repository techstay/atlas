# 树莓派

记录树莓派的一些玩法，使用的设备是树莓派 3B+。

## 开始使用

### 安装

到[官网](https://www.raspberrypi.com/software/)下载安装官方烧录工具，可选官方镜像和第三方镜像。官方镜像可预先开启 SSH 和 WIFI 进行无界面安装和配置，第三方镜像需要连接显示器和键盘进行配置。

开启 docker，方便容器化安装一些服务。

```sh
sudo apt install docker.io
sudo gpasswd docker -a techstay
sudo systemctl enable -now docker
```

### cockpit

开源的系统管理网页工具。

```sh
sudo apt cockpit install cockpit-system cockpit-networkmanager cockpit-packagekit
sudo systemctl enable --now cockpit
```

### adguardhome

开源的 DNS 服务器，支持去广告和自定义拦截。开启之后先访问 3000 端口号初始化，然后访问配置好的端口号初始化。

```sh
mkdir ~/.config/adguardhome -p && cd ~/.config/adguardhome
tee docker-compose.yml <<'EOL'
version: "3"
services:
  adguardhome:
    image: adguard/adguardhome:latest
    container_name: adguardhome
    ports:
      - 53:53/tcp
      - 53:53/udp
      - 67:67/udp
      - 68:68/tcp
      - 68:68/udp
      - 80:80/tcp
      - 443:443/tcp
      - 443:443/udp
      - 3000:3000/tcp
      - 784:784/udp
      - 853:853/tcp
      - 853:853/udp
      - 8853:8853/udp
      - 5443:5443/tcp
      - 5443:5443/udp
    network_mode: host
    volumes:
      - ./data:/opt/adguardhome/work
      - ./config:/opt/adguardhome/conf
    restart: always
EOL
docker compose up -d
```

### update-kuma

开源的服务监控程序，启动后访问 3001 端口号。

```sh
mkdir ~/.config/uptime-kuma -p && cd ~/.config/uptime-kuma
tee docker-compose.yml <<'EOL'
version: "3"
services:
  uptime-kuma:
    image: louislam/uptime-kuma:1
    container_name: uptime-kuma
    ports:
      - 3001:3001
    volumes:
      - ./data:/data
      - /var/run/docker.sock:/var/run/docker.sock
    restart: always
EOL
docker compose up -d
```

### portainer

一个开源的 docker 网页管理工具，开启后通过 HTTPS 协议下的 9443 端口号访问。

```sh
mkdir ~/.config/portainer -p && cd ~/.config/portainer
tee docker-compose.yml <<'EOL'
version: "3"
services:
  portainer:
    image: portainer/portainer-ce:latest
    container_name: portainer
    ports:
      - 8000:8000
      - 9443:9443
    volumes:
      - ./config:/data
      - /var/run/docker.sock:/var/run/docker.sock
    restart: always
EOL
docker compose up -d
```

然后访问 9443 端口号。

### heimdall

一个开源的程序仪表盘和启动器，可以用来管理树莓派运行的众多服务。启动后通过 80 端口号访问。

```sh
mkdir ~/.config/heimdall -p && cd ~/.config/heimdall
tee docker-compose.yml <<'EOL'
version: "3"
services:
  heimdall:
    image: lscr.io/linuxserver/heimdall:latest
    container_name: heimdall
    environment:
      - PUID=1000
      - PGID=1000
      - TZ=Asia/Shanghai
    volumes:
      - ./config:/config
    ports:
      - 80:80
    restart: unless-stopped
EOL
docker compose up -d
```

### clash

梯子

```sh
mkdir ~/.config/clash -p && cd ~/.config/clash
echo 'wget <your-subscription-url> -O config.yaml' > update-clash.sh
bash update-clash.sh
tee docker-compose.yml <<'EOL'
version: "3"
services:
  clash:
    image: dreamacro/clash-premium
    container_name: clash
    volumes:
      - ./config.yaml:/root/.config/clash/config.yaml
      - ./ui:/ui # dashboard volume
    ports:
      - 7890:7890
      - 7891:7891
      - 8080:8080 # external controller (Restful API)
    network_mode: host
    # TUN
    # cap_add:
    #   - NET_ADMIN
    # devices:
    #   - /dev/net/tun
    restart: unless-stopped
EOL
docker compose up -d
```

### stashapp

管理本地小黄片的程序，启动后通过 9999 端口号访问。

```sh
mkdir ~/.config/stashapp -p && cd ~/.config/stashapp
tee docker-compose.yml <<'EOL'
version: '3'
services:
  stash:
    image: stashapp/stash:latest
    container_name: stash
    restart: unless-stopped
    ## the container's port must be the same with the STASH_PORT in the environment section
    ports:
      - "9999:9999"
    ## If you intend to use stash's DLNA functionality uncomment the below network mode and comment out the above ports section
    # network_mode: host
    logging:
      driver: "json-file"
      options:
        max-file: "10"
        max-size: "2m"
    environment:
      - STASH_STASH=/data/
      - STASH_GENERATED=/generated/
      - STASH_METADATA=/metadata/
      - STASH_CACHE=/cache/
      ## Adjust below to change default port (9999)
      - STASH_PORT=9999
    volumes:
      - /etc/localtime:/etc/localtime:ro
      ## Adjust below paths (the left part) to your liking.
      ## E.g. you can change ./config:/root/.stash to ./stash:/root/.stash

      ## Keep configs, scrapers, and plugins here.
      - ./config:/root/.stash
      ## Point this at your collection.
      - ./data:/data
      ## This is where your stash's metadata lives
      - ./metadata:/metadata
      ## Any other cache content.
      - ./cache:/cache
      ## Where to store generated content (screenshots,previews,transcodes,sprites)
      - ./generated:/generated
EOL
docker compose up -d
```

## 旁路由

### 下载安装固件

树莓派 3B+对应的型号是`openwrt-bcm27xx-bcm2710`。

- [openwrt rpi](https://github.com/SuLingGG/OpenWrt-Rpi/releases)，集成了一些常用功能
- [openwrt](https://openwrt.org/toh/raspberry_pi_foundation/raspberry_pi#installation)，纯净版 openwrt

最好同时下载*sha256sum*文件进行校验。

```sh
sha256sum -c sh256sum
```

下载完成后，使用 etcher 或者其他软件写入内存卡，注意内存卡需 4G 以上。镜像制作需 1 分钟左右，制作完成后，取下来插入树莓派中。

### IP 配置

打开电脑的网络设置，将以太网卡 IP 设置为静态`192.168.1.2`，子网掩码`255.255.255.0`，默认 DNS 服务器为`114.114.114.114`，然后确认。

将电脑网线与树莓派直接相连，浏览器访问<https://192.168.1.1>，此时应该可以成功访问，默认用户名和密码为 root 和 password。如果成功启动的话，树莓派应当同时开启一个公开的 WIFI，用手机连接也可以进行配置。

找到接口设置，将树莓派静态端口号设置为主路由器同一网段，如我使用的是小米路由器，默认网关是`192.168.31.1`，就把树莓派 IP 设置为`192.168.31.2`。

设置完成后保存，然后恢复电脑的网络设置为默认，并将树莓派用网线连接到路由器的 LAN 口。这时候用电脑访问<https://192.168.31.2>应当也可以访问。

这时候配置就基本上算完成了，OpenWrt 提供了很多玩法，自己开发研究吧。

### 旁路由配置

这时候树莓派路由虽然已经生效，但是默认还是走主路由，如果主路由支持的话，就可以在主路由里面将默认网关设置为树莓派的 IP 地址。这样所有使用主路由上网的设备，就会自动使用旁路由。

如果主路由没有这样的设置，可以手动将设备上的网关地址和 DNS 地址设置为旁路由的地址。也可以考虑使用折中办法，[参考这里](https://www.right.com.cn/forum/thread-3615208-1-1.html)。

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

### adguardhome

为保证性能，最好将 adguardhome 设置为主 DNS 服务器，如有需求，可以将 openclash 设为 adguardhome 的上游服务器。配置较复杂，没有把握可先备份配置，把网络搞没了也能迅速还原。

第一步首先要拉取 adguardhome 镜像，防止一会没有网络的时候抓瞎。

```sh
docker pull adguard/adguardhome
```

1. 访问*网络->接口->LAN->DHCP*，勾选*忽略此接口*以关闭 DHCP 服务，防止出现冲突。
2. 访问*网络->DHCP/DNS->高级设置*，为默认的 dnsmasq 服务器指定一个不冲突的端口号(如 5335)。
3. 运行以下命令，启动 adguardhome 容器，然后访问 3000 端口号继续进行配置。
4. adguardhome*设置->DNS 设置->上游服务器*，添加要使用的 DNS 服务器，如 IQDNS(`quic://cn-east.ovo.glass`)，或者 openclash 为唯一节点(`127.0.0.1:7874`)，测试 DNS 时可能会失败，但是重启 docker 后不影响使用，过段时间就会正常`。

```sh
mkdir /opt/config/adguardhome -p && cd /opt/config/adguardhome
tee docker-compose.yml <<'EOL'
version: "3"
services:
  adguardhome:
    image: adguard/adguardhome:latest
    container_name: adguardhome
    network_mode: host
    volumes:
      - ./data:/opt/adguardhome/work
      - ./config:/opt/adguardhome/conf
    restart: always
EOL
docker compose up -d
```

如果一切配置正常，但是 adguardhome 未正常工作，可重启 docker，在不行重启系统试试。

```sh
service dockerd restart
```
