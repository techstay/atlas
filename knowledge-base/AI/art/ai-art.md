---
title: "绘画"
date: 2023-05-01T15:37:52+08:00
tags:
  - AI
categories:
  - AI
---

## Stable Diffusion

Stable Diffusion 是一类开源扩散模型，用于根据文本提示生成图片，也支持图生图、局部重绘、放大修复和风格迁移等创作流程。它的生态包含模型权重、LoRA、ControlNet、采样器和多种 WebUI 工具，适合在本地或云端搭建可控性较高的 AI 绘画工作流。

### [Stable Diffusion WebUI](https://github.com/AUTOMATIC1111/stable-diffusion-webui)

stable-diffusion-webui 是 AUTOMATIC1111 维护的 Stable Diffusion Web UI 项目，提供本地化的文生图、图生图、局部重绘、模型管理和插件扩展能力，适合在个人电脑上搭建可视化的 Stable Diffusion 创作环境。

```cmd
scoop install miniconda3
conda create -n pyai python=3.10.6
conda activate pyai

cd stable-diffusion-webui
.\webui.bat
```

### SD 教程

[Stable Diffusion Art](https://stable-diffusion-art.com/) 是一个面向本地 AI 绘画的英文教程站，内容覆盖 Stable Diffusion 和 Flux 的入门指南、提示词写法、模型选择、ControlNet、ComfyUI、AUTOMATIC1111 WebUI、修复放大和常见工作流，适合作为系统学习 SD 生态和排查具体问题的参考资料。

## [Nano Banana](https://blog.google/products/gemini/updated-image-editing-model/)

nano banana 是 Google Gemini 中的图像生成与编辑模型，官方名称对应 Gemini 2.5 Flash Image，侧重自然语言改图、角色一致性、多图融合和快速视觉创作。它适合用来做图像局部调整、风格迁移、产品图生成、素材扩展和多轮迭代式图片编辑。

### [awesome-nano-banana-pro-prompts](https://github.com/YouMind-OpenLab/awesome-nano-banana-pro-prompts)

awesome-nano-banana-pro-prompts 是 YouMind-OpenLab 整理的 Nano Banana Pro 提示词资源库，收集了大量带预览图的 Gemini 图像生成提示词，适合用于学习提示词结构、快速查找创意模板和复用不同风格的图像生成方案。

## [Seedream](https://console.volcengine.com/ark/region:cn-beijing/docs/82379/1829186?lang=zh)

Seedream 是火山方舟推出的图像生成模型系列（包括 4.0、4.5、5.0 lite 版本），具备强大的自然语言理解能力和高质量图像生成能力，适用于文生图、图生图、参考图生图、多图输入输出等多种创作场景。

### 通用规则

- 🖼️ **自然语言描述**：使用简洁连贯的语言，遵循「主体 + 行为 + 环境」结构，可补充风格、色彩、光影等美学元素
- 🎯 **明确用途**：在提示词中直接说明图像最终用途（如「设计一个游戏公司的 logo」）
- 🎨 **提升风格渲染**：使用精准的风格词（如「莫奈油画风格」「儿童绘本风」）或上传风格参考图
- 📝 **文本渲染准确度**：需要生成具体文字时，将文字内容放在**双引号**内
- ✏️ **明确编辑目标**：局部修改时，说明修改对象和操作，并指出保持不变的部分

### 核心应用场景

#### 文生图

- 简洁精确优于复杂堆砌，清晰的描述即可生成细节丰富的图像
- 支持知识可视化，可生成公式、图表、教学插图等
- 使用准确的**专业术语**，明确图像版式、风格等要求

#### 图生图（图像编辑）

- 支持对原图进行**增加、删除、替换、修改**
- 复杂编辑可配合**箭头、线框、涂鸦**等视觉信号精确控制编辑区域

#### 参考图生图

- 用于从参考图中提取并保持特定元素，生成新场景
- 提示词需包含两部分：指明参考对象 + 描述生成画面
- 设计草图转效果图时，注明「遵循图中文字内容进行生成」

#### 多图输入与输出

- **多图输入**：支持多张图片复合操作，需清楚指明每张图的用途
- **多图输出**：适用于生成漫画分镜、成套设计等，通过「一系列」「一套」或指定数量触发

### 💡 关键思维转变

使用 Seedream 时，应从「堆砌关键词」转向「进行清晰的自然语言沟通」。模型具备强大的理解和推理能力，提供明确的目标、上下文和参考依据是获得理想结果的关键。
