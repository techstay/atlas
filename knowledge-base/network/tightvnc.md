---
title: "tightvnc"
date: 2026-05-15T01:18:06+08:00
tags:
  - troubleshooting
  - tightvnc
  - vnc
categories:
  - 故障排查
---

## 问题列表

### Error in Tight VNC Viewer: Connection parameters (host, port, socket, gates) is empty

这个问题会在 tightvnc 文件关联错误时出现，解决办法也比较简单，打开注册表编辑器，找到 `HKEY_CLASSES_ROOT\vnc_auto_file\shell\open\command`，编辑值，将第二位参数从 `%1` 改为 `-optionsfile=%1`。
