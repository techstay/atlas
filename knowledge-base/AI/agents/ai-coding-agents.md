---
title: "智能体"
date: 2026-05-15T01:18:06+08:00
tags:
  - AI
categories:
  - AI
---

# 智能体

这篇笔记列出了我安装和使用过的一些智能体。

下面是我看到的一个可以让智能体工作更好的提示词，可以作为参考。

```txt
你输出的代码必须不 mock，不简化实现，考虑高效和前瞻性而不是先跑起来再说，不做假设而是积极询问用户。请先搜索互联网以获得最新 api 文档和修改。禁止 MVP 思维和简化思维。如有代码更改，必须同步更新对应目录与模块文档并保证文档与实现一致。
```

## Open Code

开源 AI 编程智能体，支持多模型后端与插件系统，灵活可定制 🛠️。

配置路径 `$HOME/.config/opencode`

## Claude Code

Anthropic 推出的命令行 AI 编程助手，深度集成 Claude 模型能力，是写代码时的得力帮手 🦾。

**配置环境变量**

```sh
CLAUDE_CODE_GIT_BASH_PATH=C:\Users\techs\scoop\apps\git-with-openssh\current\bin\bash.exe
```

**安装**

```powershell
irm https://claude.ai/install.ps1 | iex
```

**运行**

```sh
claude --dangerously-skip-permissions
```

配置路径 `$HOME/.claude/`

## Kiro

轻量级的 AI 编程 CLI 工具，安装简单、开箱即用 🚀。

**安装**

```powershell
irm 'https://cli.kiro.dev/install.ps1' | iex
```

**运行**

```sh
kiro-cli
```

## Kimi Code

月之暗面推出的 AI 编程助手，基于 Kimi 大模型，适合习惯 Kimi 生态的开发者使用 🌙。

**安装**

```sh
irm https://code.kimi.com/kimi-code/install.ps1 | iex
```

**运行**

```sh
kimi
```

配置路径 `$HOME/.kimi-code/`

## Reasonix

专为 DeepSeek 设计的智能体，能充分利用 DeepSeek 的长上下文和低价缓存，降低使用成本 💰。

[Reasonix](https://esengine.github.io/DeepSeek-Reasonix/index.html)

**安装 & 运行**

```sh
npm install -g reasonix && reasonix code
```

**桌面端下载**

[Reasonix 桌面端](https://esengine.github.io/DeepSeek-Reasonix/download.html)

配置路径 `$HOME/.reasonix`

## odysseus

自托管的 AI 工作空间，支持 Docker 一键部署，注重隐私和数据自主权 🔐。

[pewdiepie-archdaemon/odysseus: Self-hosted AI workspace.](https://github.com/pewdiepie-archdaemon/odysseus)

**安装 & 运行（Docker）**

```sh
git clone https://github.com/pewdiepie-archdaemon/odysseus.git
cd odysseus
cp .env.example .env
docker compose up -d --build
```

## AstrBot

开源的一体化 Agent 聊天机器人平台，支持对接多种即时通讯平台与 LLM，拥有 1000+ 社区插件 🚀。

[AstrBot](https://github.com/AstrBotDevs/AstrBot)

**uv 部署**

```sh
uv tool install astrbot --python 3.12
astrbot init
astrbot run
```

**Docker 部署**

参考官方文档：[AstrBot Docker 部署](https://docs.astrbot.app/deploy/astrbot/docker.html)

**桌面端**

[AstrBot-desktop](https://github.com/AstrBotDevs/AstrBot-desktop)

## Droid

Factory AI 推出的 AI 编程助手，安装便捷，配置简单 🤖。

**安装**

```powershell
irm https://app.factory.ai/cli/windows | iex
```

**运行**

```sh
droid
```

配置路径 `$HOME/.factory`

## Mimo Code

这是小米开发的基于 OpenCode 的终端智能体。

安装

```sh
npm install -g @mimo-ai/cli
```

启动

```sh
mimo
```

配置文件路径

```sh

```

## goose

AAIF 开发的开源 AI 代理，支持丰富的扩展和工具调用，灵活可定制 😤。

**安装**

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/aaif-goose/goose/main/download_cli.ps1" -OutFile "download_cli.ps1"
.\download_cli.ps1
```

**桌面版下载**

[Goose-win32-x64.zip](https://github.com/aaif-goose/goose/releases/download/stable/Goose-win32-x64.zip)

**运行**

```sh
goose
```

配置路径 `C:\Users\techs\AppData\Roaming\Block\goose\config\config.yaml`
