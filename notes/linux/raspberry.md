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
