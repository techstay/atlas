---
title: "影音多媒体服务部署指南"
date: 2026-06-03T10:00:00+08:00
tags:
  - selfhosted
  - multimedia
  - jellyfin
  - qbittorrent
  - ani-rss
  - media-server
  - immich
categories:
  - 自托管
---

## Jellyfin 🎬

[Jellyfin](https://jellyfin.org/) 是一款自由开源的媒体系统，可用来集中管理个人的影视、音乐、图片等媒体库，并通过网络串流到电视、手机、浏览器等终端播放。完全免费、无广告、无追踪，支持硬件加速、电视直播与录像、丰富的插件生态（字幕、刮削、IPTV 等），是 Plex / Emby 的优秀替代品。

初始化完成后访问 <http://localhost:8096/web/index.html#!/wizardstart.html> 进行配置向导。

**中文字幕插件 📝**

推荐使用 [MeiamSubtitles](https://github.com/91270/MeiamSubtitles)，专为中文用户优化的字幕插件。更多精彩插件可以逛逛 [awesome-jellyfin](https://github.com/awesome-jellyfin/awesome-jellyfin) 合集。

**电视直播 📺**

- [iptv-api](https://github.com/Guovin/iptv-api) - 强大的 IPTV 地址聚合工具
- [iptv](https://github.com/vbskycn/iptv) - 另一个不错的 IPTV 列表源

节目单（EPG）地址：<http://epg.51zmt.top:8000/e.xml>

[这篇详细的教程](https://post.smzdm.com/p/al82804o/) 介绍了详细的图文配置方法。

**Docker 部署配置 🐳**

下面的配置文件开启了英伟达的 GPU 硬件加速功能，让转码性能起飞 ✈️。如果你使用的是 AMD 或 Intel 显卡，需要参考 [Jellyfin 官方文档](https://jellyfin.org/docs/general/post-install/transcoding/hardware-acceleration/) 调整参数。

```yaml
services:
  jellyfin:
    image: linuxserver/jellyfin
    container_name: jellyfin
    ports:
      - "28096:8096"
      - "7359:7359/udp"
      - "1900:1900/udp"
    volumes:
      - ./jellyfin/config:/config
      - ./jellyfin/cache:/cache
      - type: bind
        source: G:/
        target: /移动硬盘
      - type: bind
        source: E:/
        target: /数据盘
      - type: bind
        source: D:/
        target: /游戏盘
    restart: unless-stopped
    extra_hosts:
      - "host.docker.internal:host-gateway"
    environment:
      - DOCKER_MODS=linuxserver/mods:universal-package-install
      - INSTALL_PACKAGES=fonts-noto-cjk-extra
      - NVIDIA_VISIBLE_DEVICES=all
    deploy:
      resources:
        reservations:
          devices:
            - driver: nvidia
              count: 1
              capabilities: [gpu]
```

## Immich 📸

[Immich](https://immich.app/) 是一款高性能的自托管照片和视频备份解决方案，可作为 Google Photos 的替代品。支持自动备份、人脸识别、物体检测、时间线浏览、地图模式等功能，移动端体验流畅，是管理个人媒体库的理想选择 ✨

**主要特性 🌟**

- 📱 自动备份：移动端 App 支持后台自动备份照片和视频
- 🤖 AI 功能：人脸识别、物体检测、场景分类、智能搜索
- 🗺️ 地图模式：在地图上查看照片拍摄位置
- 🎬 视频支持：转码和流式播放视频
- 👥 多用户：支持多用户账户和共享相册
- 🔍 智能搜索：按人物、物体、地点、时间等条件搜索

**快速开始 🚀**

```sh
# 创建目录
mkdir ./immich-app
cd ./immich-app
# 下载 compose 文件
wget -O docker-compose.yml https://github.com/immich-app/immich/releases/latest/download/docker-compose.yml
# 下载.env 文件
wget -O .env https://github.com/immich-app/immich/releases/latest/download/example.env
```

编辑 `.env` 文件配置关键参数：`UPLOAD_LOCATION`（上传文件存储）、`DB_DATA_LOCATION`（数据库存储）、`TZ=Asia/Shanghai`（时区）、`DB_PASSWORD`（数据库密码，只使用 A-Za-z0-9 字符）。💡 生成随机密码可使用 `pwgen -s 32 1`。

启动服务：`docker compose up -d`，完成后访问 `http://localhost:2283`，第一个注册的用户将成为管理员。

**Docker 部署配置 🐳**

```yaml
services:
  immich-server:
    container_name: immich_server
    image: ghcr.io/immich-app/immich-server:${IMMICH_VERSION:-release}
    volumes:
      - ${UPLOAD_LOCATION}:/usr/src/app/upload
      - /etc/localtime:/etc/localtime:ro
    env_file:
      - .env
    ports:
      - "2283:3001"
    depends_on:
      - redis
      - database
    restart: unless-stopped

  immich-machine-learning:
    container_name: immich_machine_learning
    image: ghcr.io/immich-app/immich-machine-learning:${IMMICH_VERSION:-release}
    volumes:
      - model-cache:/cache
    env_file:
      - .env
    restart: unless-stopped

  redis:
    container_name: immich_redis
    image: redis:6.2-alpine
    healthcheck:
      test: redis-cli ping || exit 1
    restart: unless-stopped

  database:
    container_name: immich_postgres
    image: tensorchord/pgvecto-rs:pg14-v0.2.0@sha256:90724186f0a3517cf6914295b5ab410db9ce23190a7d235e9423708528948b1f
    env_file:
      - .env
    environment:
      POSTGRES_PASSWORD: ${DB_PASSWORD}
      POSTGRES_USER: ${DB_USERNAME}
      POSTGRES_DB: ${DB_DATABASE_NAME}
      POSTGRES_INITDB_ARGS: '--data-checksums'
    volumes:
      - ${DB_DATA_LOCATION}:/var/lib/postgresql/data
    healthcheck:
      test: pg_isready --dbname='${DB_DATABASE_NAME}' --username='${DB_USERNAME}' || exit 1
      start_period: 5m
    restart: unless-stopped

volumes:
  model-cache:
```

**GPU 硬件加速 🎮** 需要 GPU 加速 AI 模型推理时，在 `immich-machine-learning` 服务中添加：

```yaml
    deploy:
      resources:
        reservations:
          devices:
            - driver: nvidia
              count: 1
              capabilities: [gpu]
```

**移动端使用 📱** iOS 在 [App Store](https://apps.apple.com/app/immich/id1673962897) 下载，Android 在 [Google Play](https://play.google.com/store/apps/details?id=app.alextran.immich) 或 [F-Droid](https://f-droid.org/packages/app.alextran.immich) 下载。服务器地址填写 `http://<你的服务器 IP>:2283`，在 App 设置中可开启自动备份。

**数据备份 💾** 数据库备份位于 `UPLOAD_LOCATION/backups` 目录。⚠️ 注意：数据库只存储元数据和用户信息，需要单独备份 `UPLOAD_LOCATION` 目录中的照片和视频文件。

**常见问题 ⚠️** Docker 版本过旧会报 `unknown shorthand flag: 'd' in -d` 错误；健康检查报错时注释掉 `start_interval` 行；批量导入照片可使用 [immich-go](https://github.com/simulot/immich-go) 工具。

## qBittorrent 🔽

[qBittorrent](https://www.qbittorrent.org/) 是一款跨平台的开源 BitTorrent 客户端，以轻量、无广告、界面接近 µTorrent 著称，并内置了 RSS 订阅、远程管理 Web UI、BT 搜索引擎等实用功能。下载神器，你懂的 😏

**首次登录提示 ⚠️**

qBittorrent 第一次使用时会随机生成一个一次性密码，这个密码可以在容器日志中查看。需要注意的是，每次重启容器后密码都会变化。使用用户名 `admin` 和这个一次性密码登录后，记得第一时间在后台设置自己的密码。

**Docker 部署配置 🐳**

```yaml
services:
  qb:
    image: linuxserver/qbittorrent:latest
    container_name: qBittorrent
    environment:
      - TZ=Asia/Shanghai
      - WEBUI_PORT=18080
    volumes:
      - ./qbittorrent/config:/config
      - G:/:/Media
      - D:/:/Video
    ports:
      - "18080:18080" # WebUI
      - "6881:6881" # BitTorrent TCP
      - "6881:6881/udp" # BitTorrent UDP
      - "9876:9876" # Network Agent
    restart: unless-stopped
```

## qbitwebui 🎨

[qbitwebui](https://github.com/mkbula/qbitwebui) 是一个面向 qBittorrent 的现代化 Web 管理面板。相比原生的 WebUI，界面更加美观，操作也更加顺手。搭配 Network Agent 使用还能实时监控网络流量，下载控们必备工具 🛠️

**Docker 部署配置 🐳**

```yaml
services:
  qb:
    image: linuxserver/qbittorrent:latest
    container_name: qBittorrent
    environment:
      - TZ=Asia/Shanghai
      - WEBUI_PORT=18080
    volumes:
      - ./qbittorrent/config:/config
      - G:/:/Media
      - D:/:/Video
    ports:
      - "18080:18080" # WebUI
      - "6881:6881" # BitTorrent TCP
      - "6881:6881/udp" # BitTorrent UDP
      - "9876:9876" # Network Agent
    restart: unless-stopped

  net-agent:
    image: ghcr.io/mkbula/qbitwebui-agent:latest
    container_name: net-agent
    network_mode: "service:qb"
    environment:
      - QBT_URL=http://localhost:18080
    depends_on:
      qb:
        condition: service_started
    restart: unless-stopped

  qbitwebui:
    image: ghcr.io/mkbula/qbitwebui:latest
    container_name: qbitwebui
    ports:
      - "8082:3000"
    volumes:
      - ./qbitwebui:/data
      - G:/:/Media:ro
      - D:/:/Video:ro
    environment:
      - QBITTORRENT_URL=http://qb:18080
      - DISABLE_AUTH=true
      - DOWNLOADS_PATH=/Video
      - ENCRYPTION_KEY=abc # 替换为 32 位随机字符串，可使用 openssl rand -hex 32 生成
    depends_on:
      qb:
        condition: service_started
    restart: unless-stopped
```

## Ani-RSS 🎌

[Ani-RSS](https://github.com/wushuo894/ani-rss)（简称 ASS）是一个基于 RSS 的自动追番工具，可以订阅番剧更新并自动推送到 qBittorrent、Transmission、Aria2 等下载器，配合下载器完成下载、刮削、洗版。配合 Jellyfin / Plex 等媒体服务器，可以做到番剧更新即自动入库、生成元数据。二次元爱好者的福音 🎉

**连接 qBittorrent 配置 🔗**

在 ASS 中设置 qBittorrent 的连接信息，成功设置后点击「测试连接」应该就能看到成功提示了。

| 条目           | 内容               |
| -------------- | ------------------ |
| 下载工具       | qBittorrent        |
| 地址           | <http://qb:8080/>  |
| 用户名         | admin              |
| 密码           | qBittorrent 的密码 |
| 保存位置       | /Media/番剧        |
| 剧场版保存位置 | /Media/剧场版      |

**Docker 部署配置 🐳**

```yaml
services:
  ani-rss:
    image: wushuo894/ani-rss
    container_name: ani-rss
    ports:
      - 7789:7789
    environment:
      - PORT=7789
      - CONFIG=/config
      - TZ=Asia/Shanghai
    volumes:
      - ./ass:/config
      - G:/:/Media
      - D:/:/Video
    restart: unless-stopped
```
