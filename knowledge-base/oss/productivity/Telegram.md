---
title: "Telegram"
date: 2026-05-15T01:18:06+08:00
tags:
  - oss
  - productivity
  - telegram
  - im
categories:
  - 开源工具
---

## 软件汉化

在软件中点击 [这个链接](tg://setlanguage?lang=zhcncc) 即可。

## 高分屏字体发虚

电报 Windows 版默认字体显示有问题，可以通过两种办法解决。

第一种办法是修改环境变量，启用 freetype 字体引擎，默认会对所有 qt 程序生效。

```sh
QT_QPA_PLATFORM=windows:fontengine=freetype
```

第二种是在电报的设置中启用 freetype 字体引擎，设置 ->高级 ->实验功能 -> freetype 字体引擎。

当然还有第三种办法，就是直接使用 unigram，这是一个 telegram 的第三方客户端，没有字体的问题。
