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

Telegram 是一款主打速度与安全的跨平台即时通讯软件，由 Pavel Durov 于 2013 年推出，支持多端同步、端到端加密聊天、大规模群组等功能，在隐私保护和开放性上有着较高的口碑。🐱

## 📝 软件汉化

在软件中点击 [这个链接](tg://setlanguage?lang=zhcncc) 即可一键切换为简体中文界面。

## Troubleshooting

### 🖥️ 高分屏字体发虚

Telegram Windows 版默认在高分屏下字体显示发虚，可以通过以下三种办法解决。

#### 方法一：修改环境变量启用 freetype 字体引擎

临时生效（仅当前终端窗口有效）：

```powershell
$env:QT_QPA_PLATFORM="windows:fontengine=freetype"
```

永久生效需要将该环境变量添加到系统环境变量中，默认会对所有 Qt 程序生效。

#### 方法二：软件内启用 freetype 字体引擎

进入 Telegram 设置，依次点击「高级」→「实验功能」，勾选「freetype 字体引擎」即可。

#### 方法三：使用第三方客户端

也可以直接使用第三方客户端规避这个问题，详见下文 Unigram 相关介绍。

## 🛠️ Unigram 第三方客户端

Unigram 是 Telegram 在 Windows 平台上的非官方第三方客户端，基于 UWP 框架开发，完全开源免费，原生支持高分屏显示，不存在官方客户端字体发虚的问题。

### 主要特性

- 原生适配 Windows 高分屏，字体显示清晰锐利
- 支持 Telegram 全量功能，包括频道、群组、机器人、贴纸、加密聊天等
- 轻量无广告，占用系统资源远低于官方客户端
- 支持自定义主题、界面布局，可调整侧边栏、聊天列表等显示样式
- 可从 Microsoft Store 或 GitHub Releases 页面下载安装
