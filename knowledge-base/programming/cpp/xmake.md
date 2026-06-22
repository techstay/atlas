---
title: "xmake"
date: 2026-06-12T00:00:00+08:00
tags:
  - cpp
  - build-tool
  - xmake
categories:
  - C++
---

[xmake](https://xmake.io/) 是一款基于 Lua 的轻量级跨平台 C/C++ 构建工具 ⚙️，使用 `xmake.lua` 描述项目，语法简洁且开箱即用，支持 Windows、Linux、macOS 等主流平台。

- 官网：[https://xmake.io](https://xmake.io)
- GitHub：[https://github.com/xmake-io/xmake](https://github.com/xmake-io/xmake)
- LLM 参考文档：[https://xmake.io/llms-full.txt](https://xmake.io/llms-full.txt)

---

## 安装 📥

### Windows (PowerShell)

```powershell
Invoke-Expression (Invoke-Webrequest 'https://xmake.io/psget.text' -UseBasicParsing).Content
```

### macOS / Linux

```sh
curl -fsSL https://xmake.io/shget.text | bash
```

---

## 基本使用 🛠️

### 创建项目

```sh
xmake create -l c -P my-project
```

### 配置工具链

```sh
xmake f -p mingw --sdk=C:\Qt\Tools\mingw900_64
```

### 编译与运行

```sh
xmake
xmake run
```

---

## vscode 图形化调试 🐞

安装好 `tboox.xmake-vscode` 扩展后，点击状态栏上的调试图标就能直接拉起调试器。
