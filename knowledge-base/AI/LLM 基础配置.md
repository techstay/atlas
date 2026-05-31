---
title: "LLM 基础配置"
date: 2026-05-31T00:22:00+08:00
tags:
  - AI
categories:
  - AI
---

# LLM 基础配置

各 AI 提供商的 API 配置汇总。各厂商模型更新比较频繁，这里的模型只作为示例参考。API Key 建议作为环境变量设置，避免明文保存，也不用在每个智能体中重新设置一遍。

- **[Gemini](https://ai.google.dev/gemini-api/docs)** — 谷歌旗下大模型系列，以多模态能力（文本、图像、音频、视频）为核心特色。API 支持 OpenAI 兼容模式，生态与 Google 深度集成。模型迭代速度快，在推理效率和多语言任务上持续领先。
  - **Base URL**: `https://generativelanguage.googleapis.com/v1beta/openai/`
  - **API Key**: `GEMINI_API_KEY`
  - **Model**: `gemini-2.5-flash`

- **[OpenAI](https://platform.openai.com)** — 全球闭源大模型标杆，GPT 系列是业界事实标准。API 生态最成熟，几乎所有第三方工具和框架都优先支持 OpenAI 兼容接口。在代码生成、指令遵循、长文本理解等方面表现均衡领先。
  - **Base URL**: `https://api.openai.com/v1`
  - **API Key**: `OPENAI_API_KEY`
  - **Model**: `gpt-5.4-mini`, `gpt-5.4`

- **[NVIDIA](https://build.nvidia.com/models)** — 英伟达提供的推理微服务（NIM）平台，托管 100+ 主流开源/商业模型，可以免费试用一些模型，不过延迟会大一些。
  - **Base URL**: `https://integrate.api.nvidia.com/`
  - **API Key**: `NVIDIA_API_KEY`
  - **Model**: 参考 <https://build.nvidia.com/models>

- **[OpenRouter](https://openrouter.ai)** — 统一 API 网关，单接口接入数百个模型、数十家提供商。支持自动路由（按延迟/价格/可用性择优）、用量追踪、失败回退和 BYO Key。聚合免费模型多，适合多模型对比和冗余备份场景。
  - **Base URL**: `https://openrouter.ai/api/v1`
  - **API Key**: `OPENROUTER_API_KEY`
  - **Model**: 参考 <https://openrouter.ai/models>，其中带有 `free` 后缀的是免费模型

- **[DeepSeek](https://platform.deepseek.com)** — 国产开源大模型标杆，MoE 架构，以极高性价比和开源开放著称。在编程、数学等推理任务上比肩 GPT 级别模型，但 API 价格低得多。输出速度快，开源社区活跃，适合大批量推理和成本敏感场景。
  - **Base URL**: `https://api.deepseek.com`, `https://api.deepseek.com/anthropic`
  - **API Key**: `DEEPSEEK_API_KEY`
  - **Model**: `deepseek-v4-flash`, `deepseek-v4-pro`

- **[火山引擎](https://www.volcengine.com/product/ark)** — 字节跳动旗下云平台，提供豆包系列及第三方模型托管。功能覆盖模型推理、精调、评测、插件、知识库等，是国内 MaaS 平台生态最完善的选择之一。
  - **Base URL**: `https://ark.cn-beijing.volces.com/api/v3`
  - **API Key**: `ARK_API_KEY`
  - **Model**: `deepseek-v4-flash-260425`, `deepseek-v4-pro-260425`, `doubao-seed-2-0-mini-260428`, `doubao-seed-2-0-pro-260215`

- **[阿里云](https://bailian.console.aliyun.com/)** — 阿里云大模型服务平台，通义千问（Qwen）系列模型在开源和商业两端均有深厚积累。Qwen 系列在中文理解、多语言、代码生成等领域表现突出。平台同时托管 DeepSeek、GLM 等多款第三方模型，型号覆盖全面。
  - **Base URL**: `https://dashscope.aliyuncs.com/compatible-mode/v1`
  - **API Key**: `ALIYUN_API_KEY`
  - **Model**: 参考 <https://bailian.console.aliyun.com/cn-beijing?tab=model#/model-usage>

- **[腾讯云](https://cloud.tencent.com/product/tokenhub)** — 腾讯云大模型服务平台，提供自研混元（Hunyuan）及多家第三方模型托管。
  - **Base URL**: `https://tokenhub.tencentmaas.com/v1`
  - **API Key**: `TENCENT_API_KEY`
  - **Model**: `deepseek-v4-flash`, `deepseek-v4-pro`, `glm-5.1`, `kimi-k2.6`, `minimax-m2.7`, `hy3-preview`

- **[智谱](https://open.bigmodel.cn)** — 清华系 AI 公司，国产原创 GLM 架构。GLM 系列在中文理解、数学推理和代码生成上处于国内第一梯队。平台提供从开源到商业的完整模型矩阵，在智能体（Agent）和编程任务上投入较大，已有 AutoGLM 等产品。
  - **Base URL**: `https://open.bigmodel.cn/api/paas/v4`
  - **API Key**: `BIGMODEL_API_KEY`
  - **Model**: `glm-5.1`

- **[月之暗面](https://platform.moonshot.cn)** — 清华系创业公司，以超长上下文技术起家（200 万字符）。Kimi 系列模型在长文档处理、深度推理和 Agent 能力上表现突出。
  - **Base URL**: `https://api.moonshot.cn/v1`
  - **API Key**: `MOONSHOT_API_KEY`
  - **Model**: `kimi-k2.6`

- **[MiniMax](https://platform.minimaxi.com)** — 国产大模型厂商，在编程 Agent 和成本效率上极具竞争力。模型推理速度快（100+ tokens/s），定价远低于同级竞品。已开源多个模型，在 SWE-Bench 等编程基准上表现突出，适合追求性价比的编程和 Agent 场景。
  - **Base URL**: `https://api.minimaxi.com/v1`, `https://api.minimaxi.com/anthropic`
  - **API Key**: `MINIMAX_API_KEY`
  - **Model**: `MiniMax-M2.7`

- **[GPTDOS](https://gptdos.com)** — 第三方聚合 API 代理服务，提供多个主流模型的代理接入。适合作为直连不可用时的备用通道，或需要 OpenAI 兼容接口的场景。配置简单，开箱即用。
  - **Base URL**: `https://api.gptdos.com/v1`
  - **API Key**: `GPTDOS_API_KEY`
  - **Model**: `gpt-4o-mini`

- **[硅基流动](https://cloud.siliconflow.cn)** — 国产 MaaS 推理平台，小模型永久免费。集成 DeepSeek、Qwen、GLM、Kimi、MiniMax 等上百款模型，OpenAI 兼容接口，国内延迟低，是个人和中小团队性价比首选。
  - **Base URL**: `https://api.siliconflow.cn`
  - **API Key**: `SILICONFLOW_API_KEY`
  - **Model**: `deepseek-ai/DeepSeek-V4-Flash`, `deepseek-ai/DeepSeek-V4-Pro`
