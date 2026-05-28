---
title: "疑难杂症"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
categories:
  - Windows
---

## 系统休眠恢复之后没有声音

管理员权限运行，重启声音服务。

```sh
Restart-Service Audiosrv -Force
```
