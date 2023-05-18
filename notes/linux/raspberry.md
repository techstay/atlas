# 树莓派

记录树莓派的一些玩法，使用的设备是树莓派 3B+。

## 准备工作

### 安装 raspberrypi os

到[官网](https://www.raspberrypi.com/software/)下载安装官方烧录工具，可选官方镜像和第三方镜像。官方镜像可预先开启 SSH 和 WIFI 进行无界面安装和配置，第三方镜像需要连接显示器和键盘进行配置。

### 系统更新

更新系统

```sh
sudo apt update && sudo apt upgrade -y
```

更新内核

```sh
sudo rpi-update
# 遇到问题时可以尝试跳过自更新，可能需要代理
sudo UPDATE_SELF=0 rpi-update
```

### nala

nala 是一个界面优雅的 apt 前端，可以替代日常 apt 使用。

```sh
echo "deb [arch=amd64,arm64,armhf] http://deb.volian.org/volian/ scar main" | sudo tee /etc/apt/sources.list.d/volian-archive-scar-unstable.list
wget -qO - https://deb.volian.org/volian/scar.key | sudo tee /etc/apt/trusted.gpg.d/volian-archive-scar-unstable.gpg > /dev/null
sudo apt update && sudo apt install nala-legacy
```

### neovim

neovim 官方没有提供 arm 的版本，而树莓派官方仓库自带的版本又太老了。最后没办法我只能尝试自己编译，好在 neovim 比我想象的小一些，编译半个小时左右就完成了。反倒是从 github 上下载依赖的时候失败了好几次，浪费了我不少时间。

```sh
make CMAKE_BUILD_TYPE=RelWithDebInfo
sudo make install
```

然后安装[lazyvim](https://www.lazyvim.org/installation)，不过 lazyvim 初始化的时候需要编译一些插件，很可能会导致树莓派卡死无法连接，遇到这种情况需要耐心等待。成功编译之后，应该就不会出现这种问题了。不过树莓派上运行 lazyvim 还是有点卡，或许我需要找一个轻量级的配置。

### docker

docker，方便容器化安装一些服务。

```sh
sudo apt install docker-compose
sudo gpasswd docker -a techstay
sudo systemctl enable -now docker
```

## 开始使用

### 各种应用

### 青龙面板

用来管理和执行各种自动任务。如果 docker-compose 启动出现问题，可以将配置文件版本号改为 3 再试试。

```sh
mkdir -p "$HOME/.config/qinglong" && cd "$HOME/.config/qinglong"
wget https://raw.githubusercontent.com/whyour/qinglong/master/docker/docker-compose.yml
docker-compose up -d
```

打开浏览器，访问<http://raspberrypi:5700>，其他命令参考[官方仓库](https://github.com/whyour/qinglong)。

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

其他配置参考[openwrt](./../network/openwrt.md)

## troubleshooting

### SSH 挂起

在`/etc/ssh/sshd_config`中添加下面一行。

```sh
IPQoS cs0 cs0
```
