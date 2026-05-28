---
title: "asciinema"
date: 2026-05-15T01:18:06+08:00
tags:
  - oss
  - productivity
  - asciinema
  - terminal
  - recording
categories:
  - 开源工具
---

asciinema 是一个基于文本的 linux 终端录屏工具，开源免费。

## 开始使用

### 安装

```sh
sudo pacman -S asciinema
```

### 录屏

开始录屏。

```sh
asciinema rec
```

这样会启动一个新的 shell，在这里面就可以执行各种要想的录制的操作。录制完成后输入 `exit` 或者 `Ctrl + D` 即可结束录制。结束录制时还会询问你是上传到 `asciinema.org` 还是只保存在本地。

### 播放

录制完成后就可以重放了，支持本地文件或者网页。

```sh
asciinema play <path-or-url>
```

### 分享

参考 [官方文档](https://asciinema.org/docs/embedding)。
