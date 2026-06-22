---
title: "技能"
date: 2026-05-15T01:18:06+08:00
tags:
  - AI
categories:
  - AI
---

## 安装 skills

```sh

```

## 常用 skills

### AI 工具集成类

- **[NotebookLM Skill](https://github.com/claude-world/notebooklm-skill)** - 神级 Skill，直接让 AI 对接 NotebookLM，自动上传资料、做知识问答、生成 PPT、脑图都能搞定
- **[Rube MCP Connector](https://github.com/W3JDev/Rube-smartest-connector)** - 通过一个服务器就能把 Claude 连接到约 500 个应用（Slack、GitHub、Notion 等），不用给每个应用单独配置授权
- **[Context7 Skills](https://context7.com/)** - 为 Claude Code 提供实时文档查询能力，通过 MCP 协议动态加载最新官方文档和代码示例，有效解决 AI 编码时的幻觉问题。支持从 GitHub 仓库直接获取最新 API 文档
- [affaan-m/everything-claude-code: Complete Claude Code configuration collection - agents, skills, hooks, commands, rules, MCPs. Battle-tested configs from an Anthropic hackathon winner.](https://github.com/affaan-m/everything-claude-code)
- [thedotmack/claude-mem: A Claude Code plugin that automatically captures everything Claude does during your coding sessions, compresses it with AI (using Claude's agent-sdk), and injects relevant context back into future sessions.](https://github.com/thedotmack/claude-mem)

### 工作流与项目管理

- **[Superpowers](https://github.com/obra/superpowers)** - Obra 开发的工具包，包含 /brainstorm、/write-plan、/execute-plan 等命令。做复杂项目时讨论方案、脑暴，通过提问分析问题生成靠谱方案
- **[planning-with-files](https://github.com/OthmanAdi/planning-with-files)** - 复刻 Manus 的 Skill，可用它指导其他 Skill 的工作流程，有效解决上下文飘移问题
- **[brainstorming](https://github.com/obra/brainstorming)** - 轻量级头脑风暴工具，可将对话或灵感整理为可复用 Skill 并自动落盘

### 开发与设计

- **[Obsidian Skills](https://github.com/kepano/obsidian-skills)** - Obsidian CEO 出品的 Skill 套件，功能全面：
  - 写出 Obsidian 风格的 Markdown（内链、属性等）
  - 生成 .Obsidian 文件的过滤器和公式
  - 生成 Canvas 无限画布
- [axtonliu/axton-obsidian-visual-skills: Visual Skills Pack for Obsidian: generate Canvas, Excalidraw, and Mermaid diagrams from text with Claude Code](https://github.com/axtonliu/axton-obsidian-visual-skills)
- **[frontend-design](https://github.com/anthropics/skills/tree/main/skills/frontend-design)** - 前端设计专用，比如可以帮你去掉 AI 的渐变色
- **[anthropic/skill-creator](https://github.com/anthropics/skills/tree/main/skills/skill-creator)** - 自己做 Skill 时的首选，可直接通过它创建符合最佳实践的 Skill，也可用它来优化现有的 Skill
- **[MCP Builder](https://github.com/anthropics/skills/tree/main/skills/mcp-builder)** - 自动生成 MCP 服务器模版
- **[Systematic Debugging](https://github.com/runesleo/systematic-debugging-skill)** - 让 Claude 秒变资深架构师，根本原因分析
- **[ralph-wiggum](https://github.com/anthropics/ralph-wiggum)** - 自动迭代编码工具，反复自我 Prompt 直到代码可运行，适合循环式代码生成场景
- **[dev-agent-skills](https://github.com/fvadicamo/dev-agent-skills)** - 本地代码「后悔药」，每步自动 git-commit，AI 误删目录也能从 Git 历史全量恢复

### 内容创作与自媒体

- **[baoyu-skills](https://github.com/JimLiu/baoyu-skills)** - 宝玉老师出品的 Skill 套件，包括：
  - 写长文时自动配图
  - 自动发推、发公众号
- **自媒体 Skill 系统** - 自己开发的 Skill 套装，覆盖日常选题、写脚本、写文案、数据分析等工作

### 设计与媒体

- **[Theme Factory](https://github.com/anthropics/skills/tree/main/skills/theme-factory)** - 上传品牌规范，Claude 生成的所有素材自动对齐配色和字体
- **[Brand Guidelines](https://github.com/anthropics/skills/tree/main/skills/brand-guidelines)** - 支持多品牌管理，多项目之间一键切换
- **[Algorithmic Art](https://github.com/anthropics/skills/tree/main/skills/algorithmic-art)** - 用自然语言写 p5.js 生成艺术
- **[Slack GIF Creator](https://github.com/anthropics/skills/tree/main/skills/slack-gif-creator)** - 直接告诉 Claude 你想要啥，生成 Slack 专用动图

### 测试与文档

- **[Webapp Testing](https://github.com/anthropics/skills/tree/main/skills/webapp-testing)** - Playwright 自动化，直接跟 Claude 说测试流程
- **[Document Suite](https://github.com/anthropics/skills)** - 官方出品，让 Claude 真正精通 Office 全家桶
- **[email-best-practices](https://github.com/resend/email-best-practices)** - Resend 官方整理的邮件最佳实践指南，涵盖邮件投递率优化、SPF/DKIM/DMARC 认证配置及邮件设计规范

### 工具与实用

- **[banana-skill-finder](https://github.com/TreyDong/banana-skills)** - 原来用的 skill-lookup 不好使，自己重新做了一个。根据 skillsmp 的 api 和 vercel 的 skillsh 来查询，对话过程中如果提出有什么问题会自动寻找合适的 skill 来帮你解决

### Skills 生态与发现

- **[ComposioHQ/awesome-claude-skills](https://github.com/ComposioHQ/awesome-claude-skills)** - 官方与社区 Claude Skills 的 Awesome 列表，覆盖开发、数据分析、商业等领域
- **[travisvn/awesome-claude-skills](https://github.com/travisvn/awesome-claude-skills)** - 精选 Claude Code 工作流定制技能列表，助你快速发现和集成新技能
- **[K-Dense-AI/claude-scientific-skills](https://github.com/K-Dense-AI/claude-scientific-skills)** - 140+ 科学领域技能集合，涵盖生物、化学、数据分析与数据库整合等方向
