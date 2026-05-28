---
title: "jellyfin"
date: 2026-05-15T01:18:06+08:00
tags:
  - selfhosted
  - jellyfin
  - media-server
categories:
  - 自托管
---

## ANI-RSS

docker 部署，需修改 volume 路径：

```docker
version: "3"
services:
  qb:
    image: linuxserver/qbittorrent
    container_name: qBittorrent
    ports:
      - 8080:8080 #qb端口
    environment:
      - PUID=0
      - PGID=0
      - WEBUIPORT=8080
      - TZ=Asia/Shanghai
    volumes:
      - /volume1/docker/qbittorrent/config:/config
      - /volume2/downloads:/downloads
      - /volume2/Media:/Media #番剧挂载路径两侧须一致
    restart: always
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
      - /volume1/docker/ani-rss/config:/config
      - /volume2/Media:/Media #番剧挂载路径两侧须一致
    restart: always

```

然后查看日志，用临时密码（用户 admin）登录 qbittorrent<http://localhost:8080>，然后设置永久密码。

然后在 ASS 中设置 qBittorrent 的用户名和密码。

| 条目           | 内容              |
| -------------- | ----------------- |
| 下载工具       | qBittorrent       |
| 地址           | <http://qb:8080/> |
| 用户名         | admin             |
| 密码           | 自己设置的密码    |
| 保存位置       | /Media/番剧       |
| 剧场版保存位置 | /Media/剧场版     |

## jellyfin

初始化完成后访问<http://localhost:8096/web/index.html#!/wizardstart.html>进行配置。

字幕插件 https://github.com/91270/MeiamSubtitles

https://github.com/awesome-jellyfin/awesome-jellyfin

### 电视直播

IPTV 列表

- https://github.com/Guovin/iptv-api
- https://github.com/vbskycn/iptv

节目列表 http://epg.51zmt.top:8000/e.xml

参考 https://post.smzdm.com/p/al82804o/
