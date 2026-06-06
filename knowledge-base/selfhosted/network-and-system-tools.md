---
title: 网络与系统工具部署
date: 2026-06-03T10:00:00+08:00
tags:
  - selfhosted
  - network
  - tools
  - heimdall
  - dashboard
categories:
  - 自托管
---

## Heimdall

[Heimdall](https://heimdall.site/) 是一款优雅的导航页应用，用于集中管理和访问所有自托管服务。支持多种应用程序类型的自动识别和图标显示，可以自定义背景、搜索栏、用户认证等。作为自托管服务的统一入口，让访问和管理多个服务变得更加便捷。

```yaml
services:
  heimdall:
    image: lscr.io/linuxserver/heimdall:latest
    container_name: heimdall
    environment:
      - PUID=1000
      - PGID=1000
      - TZ=Asia/Shanghai
    volumes:
      - ./heimdall:/config
    ports:
      - 20000:80
    restart: unless-stopped
```

## AList

[AList](https://alist.nn.ci/) 是一款支持多种存储的文件列表程序，可以聚合管理阿里云盘、百度网盘、OneDrive、Google Drive、本地存储等多种云存储服务。提供 WebDAV 支持、视频在线播放、图片预览、文件上传下载等功能，是统一管理多网盘资源的利器。

```yaml
services:
  alist:
    image: xhofe/alist:latest
    container_name: alist
    volumes:
      - ./alist:/opt/alist/data
      - E:/:/data
    ports:
      - "5244:5244"
    environment:
      - PUID=0
      - PGID=0
      - UMASK=022
    restart: unless-stopped
```

## Neko Master

[Neko Master](https://github.com/foru17/neko-master) 是一款网络工具，用于管理和监控网络相关服务。提供简洁的 Web 界面，支持多用户管理、数据统计等功能。

```yaml
services:
  neko-master:
    image: foru17/neko-master:latest
    container_name: neko-master
    restart: unless-stopped
    ports:
      - "23132:3000"
    volumes:
      - ./neko-master-data:/app/data
    environment:
      - NODE_ENV=production
      - DB_PATH=/app/data/stats.db
      - COOKIE_SECRET=${COOKIE_SECRET}
```
