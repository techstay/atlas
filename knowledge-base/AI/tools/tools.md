---
title: "工具"
date: 2026-05-15T01:18:06+08:00
tags:
  - AI
categories:
  - AI
---

## 文本

### [Chatbox](https://chatboxai.app/)

Chatbox 是一个跨平台的 AI 桌面客户端，适合把 ChatGPT、Claude、Gemini、Ollama 等不同模型服务统一放到一个界面里使用。它支持 Windows、macOS 和 Linux，可以接入官方 API、自定义 API 或本地模型，界面简洁，配置灵活，适合日常问答、写作、翻译、代码辅助和轻量知识整理。

它的局限也很明显：核心形态仍然是文字聊天，主要负责回答和生成内容，而现在的 AI 已经进入 Agent 时代，越来越多工具可以自主规划、调用工具并执行任务。因此 Chatbox 更适合作为传统聊天客户端使用，作为主力 AI 工作台会显得逐渐过时。

![](https://raw.githubusercontent.com/chatboxai/chatbox/main/doc/statics/snapshot_light.png)

![](https://raw.githubusercontent.com/chatboxai/chatbox/main/doc/statics/snapshot_dark.png)

### [Cherry Studio](https://cherry-ai.com/)

Cherry Studio 是一个开源、跨平台的 AI 桌面客户端，核心定位是“多服务商统一管理平台”。它不生产模型，而是把 OpenAI、Gemini、Anthropic、DeepSeek、Qwen 等云端模型，以及 Ollama、LM Studio 这类本地模型统一接入一个界面里，适合开发者和 AI 重度用户集中管理模型、API Key、助手、会话、文档和工具链。

模型聚合是 Cherry Studio 最核心的能力。同一个问题可以同时发给多个模型，快速比较不同模型的回答质量；同一个服务商也可以配置多个 API Key，并按顺序轮询使用，缓解单个 Key 的速率限制问题。对于经常在 Claude、Gemini、DeepSeek、本地模型之间切换的人，它可以把分散的模型能力收束到一个统一工作台里。

本地知识库是它的另一项重点功能。Cherry Studio 可以导入 PDF、DOCX、PPTX、XLSX、TXT、Markdown、文件夹目录、网页 URL 和 Sitemap 等数据源，再通过 Embedding 模型向量化后在对话中引用。配合本地 Embedding 和 Ollama 之类的本地大模型，可以搭建偏私密的个人 RAG 流程，用来检索自己的文档、项目资料、网页资料和长期沉淀的笔记。

MCP 集成让 Cherry Studio 不只是一个聊天窗口。它支持接入 MCP Server，让模型可以通过工具读取文件、访问外部服务、检索网页或扩展长期记忆，相当于给大模型接上可调用的外部能力。对开发者来说，这类工具调用能力适合和 GitHub、搜索、文件系统、数据库、自动化脚本等场景组合使用。

它还提供了比较丰富的生产力功能：300+ 预设助手、多模型会话、AI 翻译、绘图相关入口、全局搜索、主题管理、小程序、Mermaid 图表、LaTeX、完整 Markdown 渲染和自定义 CSS。数据层面支持本地备份、WebDAV 备份和自动备份，适合把云端模型、本地模型、知识库、MCP 工具和同步备份组合成一个长期使用的个人 AI 工作流。

![](https://github.com/user-attachments/assets/36dddb2c-e0fb-4a5f-9411-91447bab6e18)

![](https://github.com/user-attachments/assets/f549e8a0-2385-40b4-b52b-2039e39f2930)

![](https://github.com/user-attachments/assets/58e0237c-4d36-40de-b428-53051d982026)

## 语音

### [Qwen3-TTS](https://github.com/QwenLM/Qwen3-TTS)

通义千问团队开发的开源语音合成模型，支持中英日韩等 10 种语言，提供多音色、多语种与多方言的流式语音生成能力。

没有官方 Windows Wheel 包，所以推荐直接在 WSL 里面安装。

```sh
conda create -n qwen3 python=3.12 -y
conda activate qwen3
pip install -U qwen-tts -i https://pypi.tuna.tsinghua.edu.cn/simple
pip install -U flash-attn --no-build-isolation
# 或者直接依赖版本
pip install torch==2.8.0 torchvision torchaudio --index-url https://download.pytorch.org/whl/cu128
pip install flash-attn --no-build-isolation
pip install "https://github.com/Dao-AILab/flash-attention/releases/download/v2.8.3/flash_attn-2.8.3+cu12torch2.9cxx11abiTRUE-cp312-cp312-linux_x86_64.whl"

```

运行

```sh
qwen-tts-demo Qwen/Qwen3-TTS-12Hz-1.7B-CustomVoice --ip 0.0.0.0 --port 8000
qwen-tts-demo Qwen/Qwen3-TTS-12Hz-0.6B-CustomVoice --ip 0.0.0.0 --port 8000
```

## 数据采集/爬虫

### [Firecrawl](https://www.firecrawl.dev/)

Firecrawl 是一款专为 AI 场景设计的智能网页数据采集工具，能够自动抓取静态/动态网页内容，自动清洗去重，并直接输出 Markdown、JSON 等 LLM 友好的结构化格式，无需额外处理即可直接用于大模型训练、RAG 知识库构建、AI 代理信息获取等场景。

#### 核心特性 ✨

- 🕷️ 全场景爬取支持：无需 sitemap 即可递归抓取整站所有可访问子页面，完美支持 JavaScript 渲染的动态页面、SPA 应用、瀑布流内容
- 🧹 智能内容清洗：内置 LLM 净化能力，自动过滤广告、导航栏、版权信息等无关内容，直接输出纯净正文
- 📊 结构化提取：支持通过 JSON Schema 或自然语言提示词，从页面中提取自定义结构的业务数据
- 🤖 AI 代理模式：仅需自然语言描述需求（如「帮我找到 Notion 的所有定价方案」），即可自动完成搜索、页面导航、数据提取全流程
- 🔌 生态适配：提供 Python/Node.js/Rust 多语言 SDK，无缝对接 LangChain、Dify、LlamaIndex 等 AI 开发框架，支持 MCP 协议接入

#### 典型适用场景

- RAG 系统的实时网页知识采集与更新
- 大模型训练数据集的规模化生产与清洗
- 竞品分析、市场调研、内容监控等自动化业务流程
- AI 智能体的网页信息获取能力扩展

#### 快速使用

```python
# 安装SDK
pip install firecrawl-py

# 单页面抓取
from firecrawl import Firecrawl
firecrawl = Firecrawl(api_key="你的API_KEY")
doc = firecrawl.scrape("https://example.com", formats=["markdown"])
print(doc.markdown)

# AI 代理自动采集
result = firecrawl.agent("帮我提取这三款手机的参数和价格对比")
print(result.data)
```

## 命令行工具

### [Ark CLI](https://github.com/volcengine/ark-cli)

Ark CLI 是火山方舟（Volcengine Ark）官方命令行工具，支持在终端中一句话完成对话、生图、生视频、多模态理解和模型部署等操作，还能一键将这些能力注入 AI Agent。

```sh
npm i -g @volcengine/ark-cli
```

#### 核心能力

| 能力             | 命令                 | 说明                                                        |
| ---------------- | -------------------- | ----------------------------------------------------------- |
| 💬 对话推理      | `arkcli +chat`       | 多模态对话（文本 / 图片 / 视频 / 音频），流式输出、多轮接续 |
| 🎨 生图生视频    | `arkcli +gen`        | Seedream 文生图 / 图生图、Seedance 文生视频 / 图生视频      |
| 🔍 多模态理解    | `arkcli +understand` | OCR、视觉定位、文档抽取、视频总结、语音转写 / 翻译          |
| 🚀 部署模型      | `arkcli +deploy`     | 一键把模型部署成在线推理接入点                              |
| 📋 模型 / 用量   | `arkcli models`      | 查公共基础模型、推理用量、结算账单                          |
| 🤖 注入 AI Agent | `arkcli +connect`    | 把能力作为 Skill 装进 Claude Code / OpenCode                |

#### 快速开始

```sh
# 1. 安装
npm config set registry https://registry.npmjs.org/
npm i -g @volcengine/ark-cli@latest
arkcli --version

# 2. 登录（火山引擎 SSO）
arkcli auth login volc-sso
arkcli auth status

# 3. 上手
arkcli +chat "你好，介绍下你自己"
```

#### Agent 集成

运行 `arkcli +connect` 可自动检测本机的 AI Agent（Claude Code / OpenCode 等）并安装 Ark Skills。装好后可用自然语言驱动所有能力，如「帮我生成一张图」「把这段录音转写成文字」「把某个模型部署成 Endpoint」。

### [QMD](https://github.com/tobi/qmd)

QMD 是一个迷你命令行搜索引擎，专为文档、知识库和会议笔记的快速检索设计，可在本地目录中快速定位相关内容。
