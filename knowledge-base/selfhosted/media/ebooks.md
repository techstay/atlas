---
title: 图书与数字阅读服务部署
date: 2026-06-03T10:00:00+08:00
tags:
  - selfhosted
  - ebooks
  - reading
  - komga
  - kavita
  - comic
categories:
  - 自托管
---

## Komga

[Komga](https://komga.org/) 是一款免费开源的漫画/书籍媒体服务器，专为漫画、杂志、电子书等设计。支持多种格式（CBZ、CBR、PDF、EPUB 等），提供 Web 阅读器和 OPDS 支持，可与其他阅读应用（如 Tachiyomi、Panels 等）配合使用。具有元数据刮削、阅读进度同步、用户管理等功能。

```yaml
services:
  komga:
    image: gotson/komga
    container_name: komga
    volumes:
      - type: bind
        source: ./komga
        target: /config
      - type: bind
        source: G:/
        target: /data
    ports:
      - 25600:25600
    restart: unless-stopped
```

## Kavita

[Kavita](https://www.kavitareader.com/) 是一款快速、功能丰富的跨平台阅读服务器，支持漫画、漫画书、PDF 和电子书。具有响应式 Web 阅读器、个性化推荐、智能过滤、OPDS 支持、阅读进度同步等功能。界面现代化，性能优秀，是多格式数字阅读的理想选择。

```yaml
services:
  kavita:
    image: lscr.io/linuxserver/kavita:latest
    container_name: kavita
    environment:
      - PUID=1000
      - PGID=1000
      - TZ=Asia/Shanghai
    volumes:
      - ./kavita-config:/config
      - C:/Users/techs/Desktop/电子书:/books
      - G:/漫画:/manga
    ports:
      - 5000:5000
    restart: unless-stopped
```
