---
title: "OpenViking"
date: 2026-06-21T00:00:00+08:00
tags:
  - AI
  - Agent
  - Context-Database
  - RAG
  - Memory
categories:
  - AI
---

# OpenViking

OpenViking 是字节跳动（Volcengine）开源的专为 AI Agent 设计的「上下文数据库」（Context Database）。它抛弃了传统 RAG 分散的向量存储模式，创新性地采用「文件系统范式」来统一管理 Agent 所需的记忆、资源和技能。

[Website](https://openviking.ai) · [GitHub](https://github.com/volcengine/OpenViking) · [Docs](https://www.openviking.ai/docs)

## 核心理念

在 AI 时代，数据丰富但高质量的上下文稀缺。开发 AI Agent 时面临五大挑战：

|        挑战        | 说明                                                     |
| :----------------: | :------------------------------------------------------- |
|  **上下文碎片化**  | 记忆在代码里、资源在向量数据库、技能分散在各处           |
| **上下文需求激增** | 长期运行的任务每次执行都产生上下文，简单截断导致信息丢失 |
|   **检索效果差**   | 传统 RAG 使用扁平存储，缺乏全局视角                      |
| **上下文不可观测** | 隐式检索链像黑盒，出错时难以调试                         |
|  **记忆迭代有限**  | 当前记忆只是用户交互记录，缺少 Agent 任务记忆            |

OpenViking 通过五个核心概念逐一解决这些问题：

### 1. 文件系统管理范式

所有上下文映射为 `viking://` 协议下的虚拟目录，每个条目有唯一 URI。Agent 可以像开发者操作本地文件一样，使用 `ls`、`find` 等标准命令精确管理上下文。

### 2. 分层上下文加载（L0/L1/L2）

- **L0（Abstract）**：一句话摘要，快速检索和识别
- **L1（Overview）**：核心信息和使用场景，供规划阶段决策
- **L2（Details）**：完整原始数据，必要时深度读取

### 3. 目录递归检索

通过「意向分析 → 向量初定位 → 目录内精炼 → 递归下钻 → 结果聚合」的策略，兼顾语义匹配的精确度和全局上下文理解。

### 4. 可视化检索轨迹

检索过程中目录浏览和文件定位的轨迹完整保留，用户可清晰观察问题根因并优化检索逻辑。

### 5. 自动会话管理（上下文自迭代）

会话结束时自动分析任务执行结果和用户反馈，更新用户记忆和 Agent 经验记忆，实现「越用越聪明」的自我进化。

## 快速开始

### 安装

```bash
pip install openviking --upgrade --force-reinstall
```

Rust CLI（可选）：

```bash
npm i -g @openviking/cli
```

### 模型准备

OpenViking 需要两种模型能力：

- **VLM 模型**：图像和内容理解
- **Embedding 模型**：向量化和语义检索

支持的 VLM 提供商：

|     提供商     | 说明             |
| :------------: | :--------------- |
|  `volcengine`  | 火山引擎豆包模型 |
|    `openai`    | OpenAI 官方 API  |
| `openai-codex` | Codex VLM        |
|     `kimi`     | Kimi Code 会员   |
|     `glm`      | GLM Coding Plan  |

### 环境配置

推荐使用交互式向导完成配置：

```bash
openviking-server init
openviking-server doctor
```

手动配置示例（`~/.openviking/ov.conf`）：

```json
{
  "storage": {
    "workspace": "/home/your-name/openviking_workspace"
  },
  "embedding": {
    "dense": {
      "api_base": "https://api.openai.com/v1",
      "api_key": "your-api-key",
      "provider": "openai",
      "dimension": 3072,
      "model": "text-embedding-3-large"
    }
  },
  "vlm": {
    "api_base": "https://api.openai.com/v1",
    "api_key": "your-api-key",
    "provider": "openai",
    "model": "gpt-4o",
    "max_concurrent": 64
  }
}
```

### 运行

```bash
openviking-server
```

CLI 操作：

```bash
ov status
ov add-resource https://github.com/volcengine/OpenViking
ov ls viking://resources/
ov find "what is openviking"
```

## VikingBot

VikingBot 是基于 OpenViking 构建的 AI Agent 框架：

```bash
pip install "openviking[bot]"
openviking-server --with-bot
ov chat
```

## 基准测试

### 用户记忆（LoCoMo）

|         集成方案          |     准确率 | 平均查询时间 | 总输入 Token |
| :-----------------------: | ---------: | -----------: | -----------: |
|    OpenClaw + 原生记忆    |     24.20% |       95.14s |         392M |
|   OpenClaw + OpenViking   | **82.08%** |        38.8s |          37M |
| Claude Code + auto-memory |     57.21% |        49.1s |         353M |
| Claude Code + OpenViking  | **80.32%** |    **20.4s** |         130M |

### 知识库 QA（HotpotQA）

|        方法         |   检索模式    |     准确率 | Token/QA | 延迟/QA |
| :-----------------: | :-----------: | ---------: | -------: | ------: |
|      Naive RAG      |   向量检索    |     62.50% |    1,290 |   0.11s |
|      LightRAG       | 向量 + 知识图谱 |     89.00% |   28,443 |     75s |
| OpenViking (top-20) |   向量检索    | **91.00%** |   12,533 |   0.23s |

OpenViking 以极低的检索延迟（0.23s）达到了最高准确率，索引成本仅为 LightRAG 的 13.8%。

## 学术背景

OpenViking 开源了 VikingMem 论文的核心能力子集：

> **VikingMem: A Memory Base Management System for Stateful LLM-based Applications**
> Jiajie Fu, Junwen Chen, Mengzhao Wang, et al. arXiv:2605.29640, 2026. Accepted by VLDB 2026.
> 📄 [Read the paper on arXiv](https://arxiv.org/abs/2605.29640)

## 项目信息

- **许可证**：主项目 AGPLv3，CLI (Apache 2.0)，examples (Apache 2.0)
- **主要语言**：Python、Rust、C++、TypeScript
- **Star 数**：25k+
- **创建时间**：2026-01-05
