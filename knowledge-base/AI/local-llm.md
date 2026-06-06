---
title: "本地 LLM"
date: 2026-06-06T12:00:00+08:00
tags:
  - AI
  - LLM
  - 本地模型
  - 工具
categories:
  - AI
---

## LM Studio 🎛️

LM Studio 是另一款常用的本地大语言模型运行工具，主打图形界面，同时附带 `lms` 命令行工具方便脚本化操作。`lms` 涵盖本地模型管理、对话、加载与服务暴露等大部分日常场景。

### 常用命令 📦

> 日常用得最多的部分，覆盖 80% 的场景。

**搜索与下载** ⬇️

- `lms get <name>` - 搜索并下载模型（如 `openai/gpt-oss-20b`）
- `lms get <name>@<quant>` - 下载指定量化版本（如 `qwen/qwen3.5-9b@q8_0`）
- `lms get <hf-url>` - 从 Hugging Face 直接下载（传入完整 URL）
- `lms get --mlx` / `--gguf` - 限定下载格式（MLX 适用于 Apple Silicon，GGUF 通用）
- `lms get --select` - 下载前手动选择变体
- `lms get -y` - 自动确认所有提示，适合脚本

**对话** 💬

- `lms chat [model]` - 启动与模型的交互式对话
- `lms chat -p "<prompt>"` - 单次提问后退出，脚本场景特别顺手
- `lms chat -s "<system>"` - 指定系统提示词
- `lms chat --stats` - 显示每次回复的详细预测统计（token 数、耗时等）
- `lms chat --ttl <seconds>` - 对话结束后模型在显存中的保留时长

**查看模型** 🔍

- `lms ls` - 列出本地所有模型
- `lms ls --llm` / `--embedding` - 只看 LLM / 嵌入模型
- `lms ls --variants` - 列出所有变体
- `lms ls <modelKey>` - 查看指定模型的变体
- `lms ls --json` - 以 JSON 格式输出
- `lms ps` - 列出当前已加载到内存中的模型

**加载与卸载** ⚙️

- `lms load [model-key]` - 加载模型到显存（不传 model-key 进入交互式选择）
- `lms load --gpu off` - 禁用 GPU 卸载，纯 CPU 推理
- `lms load --gpu max` - 最大化 GPU 卸载
- `lms load --gpu 0.5` - 指定 GPU 卸载比例
- `lms load -c <length>` - 指定上下文长度
- `lms load --parallel <count>` - 最大并发预测数
- `lms load --ttl <seconds>` - 模型空闲多久后自动卸载
- `lms load --identifier <id>` - 给加载的模型起个标识符，方便 API 调用
- `lms load --estimate-only` - 只估算资源占用，不实际加载
- `lms load -y` - 自动确认所有提示
- `lms unload` - 卸载模型，释放显存

### 进阶命令 🔌

> 偶尔用到的部分，了解有这些即可。

**本地服务** 🚀

- `lms server start` - 启动 LM Studio 内置的 OpenAI 兼容 API 服务
- `lms server stop` - 停止本地服务
- `lms server status` - 查看本地服务状态
- `lms log` - 查看服务的请求/响应日志

**导入模型** 📥

- `lms import` - 把外部模型文件导入到 LM Studio

**LM Link（远程实例）** 🌐

- `lms link` - 管理 LM Link，可在多台机器间共享模型

**运行时** 🧠

- `lms runtime` - 管理并更新推理运行时（llama.cpp、MLX 等）

**开发与发布（Beta）** 🛠️

- `lms clone` - 从 LM Studio Hub 克隆 artifact 到本地
- `lms push` - 把当前目录的 artifact 上传到 LM Studio Hub
- `lms dev` - 在当前目录启动插件开发服务器
- `lms login` / `lms logout` / `lms whoami` - 认证相关

### 小贴士 ✨

> 几个容易踩坑的小细节。

- `lms chat` 不带 model 参数时会从已加载的模型中选一个；不指定 `-p` 默认进入 REPL。
- `lms get` 默认会先根据你的硬件自动挑选合适的量化版本，不想自动选可以加 `--select`。
- 在 Apple Silicon 上 `lms get --mlx` 通常比 GGUF 跑得更快。
- `lms load --estimate-only` 可以用来在加载前预估显存占用，避免 OOM。
- LM Studio 内置的服务兼容 OpenAI API，可以直接接入 `opencode` 等工具。
- 更多信息：<https://lmstudio.ai/docs/developer>，Discord：<https://discord.gg/lmstudio>。

## Ollama 🦙

Ollama 是本地运行大语言模型的工具，封装了模型下载、推理和服务暴露的全套流程；常用命令其实不多，下面按使用频率排好。除此以外，Olama 还支持图形界面客户端。如果对使用命令行不熟悉的话，也可以直接使用图形客户端。

### 常用命令 📦

> 日常用得最多的部分，覆盖 80% 的场景。

**拉取与运行** ⬇️

模型可以从 [官方仓库](https://ollama.com/search) 上查找。

- `ollama pull <model>` - 从仓库拉取模型（如 `llama3:8b`、`qwen2.5:14b`、`deepseek-r1:7b`）
- `ollama run <model>` - 进入交互式对话模式
- `ollama run <model> "PROMPT"` - 一次性提问后退出，脚本场景特别顺手

**查看模型** 🔍

- `ollama list`（别名 `ls`） - 列出本地所有模型
- `ollama ps` - 列出当前已加载到显存中的模型
- `ollama show <model>` - 查看模型信息（Modelfile、参数、许可证等）
- `ollama show --modelfile` / `--parameters` / `--system` / `--template` / `--license` - 只看其中一项
- `ollama show -v` - 看更详细的元信息（量化方式、上下文长度、tool use 支持等）

**停止、删除与复制** 🗂️

- `ollama stop <model>` - 手动卸载模型，立刻释放显存
- `ollama rm <model>` - 删除本地模型文件
- `ollama cp <src> <dst>` - 复制一份并打新 tag，相当于 " 另存为 "

**自定义模型** 🛠️

- `ollama create <name>` - 从当前目录的 `Modelfile` 创建自定义模型
- `ollama create <name> -f <path>` - 指定 Modelfile 路径
- `ollama create <name> -q q4_K_M` - 创建时直接量化到指定精度，省盘又省显存
- `ollama create <name> --draft-quantize <level>` - 量化草稿模型（用于 speculative decoding）
- `ollama create <name> --experimental` - 启用实验性 safetensors 创建流程

### 进阶命令 🔌

> 偶尔用到的部分，了解有这些即可。

**服务** 🚀

- `ollama serve` - 手动启动 Ollama 服务，默认监听 `127.0.0.1:11434`

**推送模型** 📤

- `ollama push <model>` - 把本地模型推送到仓库

**集成启动** 🔌

- `ollama launch` - 不带参数时进入交互菜单
- `ollama launch <integration>` - 启动指定集成，目前支持 `claude` / `codex` / `codex-app` / `opencode` / `copilot` / `cline` / `droid` / `hermes` / `qwen` / `kimi` / `pi` / `pool` / `vscode` / `openclaw`
- `--model <model>` - 指定使用的模型
- `--config` - 只生成/写入配置，不实际启动
- `--restore` - 把某个集成恢复到默认配置
- `-y, --yes` - 自动确认所有提示

**账户** 🔑

- `ollama signin` - 登录 ollama.com
- `ollama signout` - 登出 ollama.com

### `run` 常用参数 🎛️

> 给经常跑模型的人备查。

- `--format <json>` - 强制按 JSON 输出
- `--think` / `--hidethinking` - 控制是否显示思考过程（DeepSeek R1、QwQ 等推理模型）
- `--keepalive <duration>` - 临时延长模型常驻时间（如 `30m`）
- `--verbose` - 显示 token 耗时与上下文用量
- `--insecure` - 允许不安全仓库
- `--nowordwrap` - 不自动折行
- `--experimental` / `--experimental-websearch` / `--experimental-yolo` - 实验性 agent 模式（`yolo` 会跳过所有工具审批）

### 环境变量 ⚙️

> 调优和特殊配置时再翻这里。

**服务** 🛠️

- `OLLAMA_HOST` - 监听地址，默认 `127.0.0.1:11434`
- `OLLAMA_MODELS` - 模型存储目录
- `OLLAMA_KEEP_ALIVE` - 模型在显存中保留时长，默认 `5m`
- `OLLAMA_CONTEXT_LENGTH` - 上下文长度（根据显存自动选 4k / 32k / 256k）
- `OLLAMA_NUM_PARALLEL` - 最大并行推理请求数
- `OLLAMA_MAX_LOADED_MODELS` - 每 GPU 最多加载模型数
- `OLLAMA_MAX_QUEUE` - 最大排队请求数
- `OLLAMA_LOAD_TIMEOUT` - 加载模型超时，默认 `5m`
- `OLLAMA_DEBUG=1` - 输出调试日志

**性能** ⚡

- `OLLAMA_FLASH_ATTENTION=1` - 启用 flash attention
- `OLLAMA_KV_CACHE_TYPE` - K/V cache 量化类型，默认 `f16`
- `OLLAMA_SCHED_SPREAD=1` - 强制把模型分片到所有 GPU
- `OLLAMA_GPU_OVERHEAD` - 每张 GPU 预留 VRAM（字节）
- `OLLAMA_IGPU_ENABLE=1` - 启用核显辅助
- `OLLAMA_LLM_LIBRARY` - 手动指定 LLM 后端库，绕过自动检测
- `OLLAMA_MAX_TRANSFER_STREAMS` - 拉取/推送时的并行流数，默认 `4`

**杂项** 📡

- `OLLAMA_NOPRUNE=1` - 启动时不清理孤立 blobs
- `OLLAMA_NO_CLOUD=1` - 禁用云端功能（远程推理、Web 搜索）
- `OLLAMA_ORIGINS` - 允许的跨域来源（逗号分隔）
- `OLLAMA_EDITOR` - 交互模式 `Ctrl+G` 调起的编辑器
- `OLLAMA_NOHISTORY` - 不保存 readline 历史
- `LLAMA_ARG_FIT` / `LLAMA_ARG_FIT_TARGET` - llama.cpp 自动适配内存的相关开关

### 小贴士 ✨

> 几个容易踩坑的小细节。

- 第一次 `ollama run` 一个新模型时会先自动 `pull` 再加载，不用单独 `pull`。
- 模型在显存里会保留 5 分钟（`OLLAMA_KEEP_ALIVE`），过时被自动卸载。
- `curl http://127.0.0.1:11434/api/chat -d '{...}'` 可以直接调 REST API，所有 CLI 本质上都走这个接口。
- 排查 " 模型行为不对 " 时先 `ollama show --modelfile`，看实际加载的配置。
