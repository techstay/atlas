---
title: "qmd"
date: 2026-05-15T05:18:29+08:00
tags:
  - oss
  - dev-tools
  - qmd
  - search
categories:
  - 开源工具
---

# QMD 工具使用手册

## 简介

QMD（Quick Markdown Search） 是一款面向本地 Markdown/文档库的高效搜索工具，支持混合搜索、全文检索、向量相似度搜索等多种检索模式，内置 LLM 重排序能力，同时支持对接 AI 代理扩展能力。

> 当前文档基于 @tobilu/qmd **v2.1.0** 编写。当版本号发生较大变化时，建议重新生成本文档内容。

---

## 快速开始

### 安装

```bash
# 全局安装（Node 或 Bun）
npm install -g @tobilu/qmd
# 或
bun install -g @tobilu/qmd

# 或直接运行（无需安装）
npx @tobilu/qmd ...
bunx @tobilu/qmd ...
```

### 快速工作流

第一次调用部分命令的时候可能出现错误，再次调用并下载相应模型后，就可以正常使用相关功能了。

```bash
# 1. 添加文档集合
qmd collection add ~/notes --name notes
qmd collection add ~/Documents/meetings --name meetings

# 2. 添加上下文（提高 LLM 检索准确性的关键特性）
qmd context add qmd://notes "Personal notes and ideas"
qmd context add qmd://meetings "Meeting transcripts and notes"

# 3. 生成向量嵌入
qmd embed

# 4. 检索文档
qmd search "project timeline"           # 关键词全文搜索
qmd vsearch "how to deploy"             # 语义相似度搜索
qmd query "quarterly planning process"  # 混合搜索 + 重排序（质量最佳）

# 5. 按路径或 docid 获取文档
qmd get "meetings/2024-01-15.md"        # 按文件路径
qmd get "#abc123"                       # 按 docid（搜索结果中显示）
qmd multi-get "journals/2025-05*.md"    # 按 glob 模式批量获取

# 6. 按集合筛选
qmd search "API" -c notes

# 7. 为 AI 代理导出匹配结果
qmd search "API" --all --files --min-score 0.3
```

### 与 AI 代理配合使用

QMD 的 `--json` 和 `--files` 输出格式专为 AI 代理工作流设计：

```bash
# 输出结构化 JSON 供 LLM 处理
qmd search "authentication" --json -n 10

# 列出所有高于阈值的相关文件
qmd query "error handling" --all --files --min-score 0.4

# 获取完整文档内容
qmd get "docs/api-reference.md" --full
```

---

## 核心命令总览

### 1. 主要查询命令

| 命令                           | 功能说明                                                 |
| ------------------------------ | -------------------------------------------------------- |
| `qmd query <query>`            | 混合搜索模式，自动扩展查询 + LLM 重排序（日常使用推荐）  |
| `qmd query 'lex:..\nvec:...'`  | 结构化查询，支持自定义全文规则/向量规则/假设文档规则组合 |
| `qmd search <query>`           | 纯 BM25 全文关键词搜索（无 LLM 参与，速度最快）          |
| `qmd vsearch <query>`          | 仅向量相似度搜索                                         |
| `qmd get <file>[:line] [-l N]` | 查看单个文档内容，支持按行范围切片                       |
| `qmd multi-get <pattern>`      | 批量获取文件，支持 glob 匹配或逗号分隔文件列表           |
| `qmd skill show/install`       | 查看/安装 QMD 官方技能包                                 |
| `qmd mcp`                      | 启动 MCP 服务器（为 AI 代理/IDE 提供 stdio 传输接口）    |
| `qmd bench <fixture.json>`     | 基于测试集运行搜索质量基准测试                           |

### 2. 集合与上下文管理

| 命令                                         | 功能说明                               |
| -------------------------------------------- | -------------------------------------- |
| `qmd collection add/list/remove/rename/show` | 管理已索引的文件夹集合                 |
| `qmd context add/list/rm`                    | 附加人工编写的摘要上下文，优化搜索效果 |
| `qmd ls [collection[/path]]`                 | 查看指定集合下已索引的文件列表         |

### 3. 维护命令

| 命令                  | 功能说明                                         |
| --------------------- | ------------------------------------------------ |
| `qmd status`          | 查看索引状态与集合健康度                         |
| `qmd update [--pull]` | 重新索引集合，可选自动执行 git pull 拉取最新内容 |
| `qmd embed [-f]`      | 生成/刷新向量嵌入，`-f` 强制全量重建             |
| `qmd cleanup`         | 清理缓存、 vacuum 优化数据库                     |

---

## 查询语法（qmd query）

QMD 支持两种查询模式：

1. **单行扩展查询**：直接输入查询文本，系统自动进行扩展处理
2. **结构化查询文档**：每行指定查询类型，支持三种前缀：
   - `lex:` 全文检索规则，支持短语匹配、排除语法
   - `vec:` 向量相似度检索规则
   - `hyde:` 假设文档规则，输入模拟的答案片段优化召回

### 语法示例

```bash
# 单行隐式扩展查询
qmd query "how does auth work"

# 全文规则 + 向量规则组合查询
qmd query $'lex: CAP theorem\nvec: consistency'

# 短语匹配 + 排除规则查询
qmd query $'lex: "exact matches" sports -baseball'

# 纯 Hyde 假设文档查询
qmd query $'hyde: Hypothetical answer text'
```

---

## 常用选项

| 选项                              | 说明                                           |
| --------------------------------- | ---------------------------------------------- |
| `--index <name>`                  | 指定使用的索引名称（默认：index）              |
| `-n <num>`                        | 最大返回结果数（默认 5，JSON/文件模式默认 20） |
| `--min-score <num>`               | 最低相似度分数阈值，过滤低匹配结果             |
| `--full`                          | 输出完整文档内容而非片段                       |
| `--no-rerank`                     | 跳过 LLM 重排序，大幅提升 CPU 环境下查询速度   |
| `--line-numbers`                  | 输出内容包含行号                               |
| `--explain`                       | 输出检索分数追踪信息，用于调优查询效果         |
| `--files/--json/--csv/--md/--xml` | 指定输出格式                                   |
| `-c, --collection <name>`         | 仅在指定集合中搜索                             |
| `-C, --candidate-limit <num>`     | 限制送入 LLM 重排序的候选数量，默认 40         |

---

## GPU 与重排序调优

QMD 的 `query` 命令默认会执行“混合检索 + LLM 重排序”。

如果在重排序阶段遇到类似下面的 CUDA 错误：

```text
Reranking 40 chunks...
ggml-cuda.cu:98: CUDA error
```

可以禁用 llama.cpp 的 CUDA graphs 作为规避方案：

```powershell
$env:GGML_CUDA_DISABLE_GRAPHS = "1"
```

推荐组合：

```powershell
$env:QMD_LLAMA_GPU = "true"
$env:GGML_CUDA_DISABLE_GRAPHS = "1"
qmd query arch -C 20
```

说明：

- `QMD_LLAMA_GPU=true`：允许 QMD 使用 node-llama-cpp 的 GPU 自动检测，通常会选择 CUDA 后端。
- `GGML_CUDA_DISABLE_GRAPHS=1`：关闭 llama.cpp CUDA graphs，避免部分 CUDA graph/attention workload 触发底层 CUDA 错误。
- `-C 20` 或 `-C 30`：减少送入 reranker 的候选片段数量。默认值为 `40`，在泛词查询或召回结果较多时更容易触发 CUDA 后端错误。
- `--no-rerank`：完全跳过 LLM 重排序，适合只需要快速检索或临时绕过 GPU 问题的场景。

如果希望变量长期生效，可以写入用户级环境变量：

```powershell
[Environment]::SetEnvironmentVariable("QMD_LLAMA_GPU", "true", "User")
[Environment]::SetEnvironmentVariable("GGML_CUDA_DISABLE_GRAPHS", "1", "User")
```

写入后需要重新打开终端窗口，新的 PowerShell/Windows Terminal 才会继承这些变量。

---

## AI 代理集成指南

1. 运行 `qmd mcp` 启动 MCP 服务器，可直接对接 AI 代理/IDE
2. 运行 `qmd skill install` 安装 QMD 技能到当前项目 `.agents/skills/qmd`，添加 `--global` 参数可安装到用户全局目录
3. 高级用法：`qmd mcp --http --daemon` 启动 HTTP 后台服务，支持自定义传输对接

---

## 默认配置

- 默认索引存储位置：`C:/Users/techs/.cache/qmd/index.sqlite`
- 嵌入批处理可通过 `--max-docs-per-batch`/`--max-batch-mb` 调整内存占用限制
