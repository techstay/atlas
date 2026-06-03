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
