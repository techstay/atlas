---
title: "OpenClaw"
date: 2026-05-15T01:18:06+08:00
tags:
  - oss
  - openclaw
  - ai-agent
  - local-first
  - automation
  - open-source
categories:
  - 开源工具
---

# 🦞 OpenClaw

[OpenClaw](https://github.com/openclaw/openclaw)（曾用名：Clawdbot、Moltbot，最早代号：Warelay / CLAWDIS）是一个开源的本地优先 AI Agent 框架，让大语言模型可以直接读写文件、执行命令、操作浏览器、管理邮件与日历，并通过常用的聊天应用与用户交互。它由 PSPDFKit 创始人 Peter Steinberger 发起，采用 MIT 协议发布。

## 核心特性

- 🤖 **本地优先**：Agent 运行在用户自有设备上，数据存储在本地 Markdown 文件中，无需依赖云端服务
- 💬 **多平台接入**：原生支持 WhatsApp、Telegram、Slack、Discord、Signal、iMessage 等主流聊天平台
- 🛠 **真实执行能力**：可直接执行 Shell 命令、读写文件、浏览网页、发送邮件、调用 API
- ⏰ **主动调度**：内置心跳调度器（heartbeat daemon），可按配置周期自动执行任务
- 🧩 **技能扩展**：通过 `SKILL.md` 系统支持插件式扩展，社区可自定义可复用的工作流
- 🧠 **长期记忆**：基于本地文件的持久化上下文，可随着使用不断积累用户偏好与项目信息
- 🔄 **自我增强**：Agent 可自主编写代码创建新技能，实现「自我改进」

## 典型使用场景

- **24/7 聊天机器人**：在 Slack 或 Discord 中持续响应团队问题
- **邮件收件箱管理**：自动分类、摘要重要邮件并安排会议
- **自动化工作流**：跨多个工具执行复杂的研发、营销或运营任务
- **开发辅助**：从聊天界面直接部署代码、管理服务器
- **个人助理**：处理日程安排、提醒、谈判、保险纠纷等日常事务

## 快速开始

### 安装

```bash
# 全局安装最新版
npm install -g openclaw@latest
```

### 启用插件

```bash
# 启用指定插件
openclaw plugins enable minimax-portal-auth
```

### 重启网关

```bash
# 重启 OpenClaw 网关
openclaw gateway restart
```

### 初始化引导

```bash
# 运行交互式引导配置
openclaw onboard --auth-choice minimax-portal
```

## 社区与生态

OpenClaw 拥有活跃的开发者社区，GitHub 上已积累超过 20 万星标。项目支持通过 `SKILL.md` 创建自定义技能，开发者社区也围绕 OpenClaw 构建了插件市场（Skills Marketplace）。该项目已被红帽（Red Hat）等企业用于研究企业级 Agent 部署实践，同时也有国内开发者将其适配为 DeepSeek 模型与微信等国内超级应用。

## 参考链接

- 🌐 [OpenClaw 官网](https://openclaw.ai)
- 🐙 [OpenClaw GitHub 仓库](https://github.com/openclaw/openclaw)
- 📚 [OpenClaw Wikipedia 词条](https://en.wikipedia.org/wiki/OpenClaw)
