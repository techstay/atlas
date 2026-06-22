---
title: "Ponytail"
date: 2026-06-18T04:10:00+08:00
tags:
  - programming
  - ai
  - agent
  - tool
categories:
  - AI
---

# Ponytail

> 「他什么都不说，写一行代码，就能跑。」

[GitHub](https://github.com/DietrichGebert/ponytail) · MIT 协议 · v4.7.0

---

## 是什么

Ponytail 是一套面向 AI 编程智能体的规则配置集，核心理念是让 AI 学会「资深懒开发者」的编码思路——**只写必要的代码，避免冗余实现**。

口号：「最好的代码是你没写的代码。」

---

## 核心机制：决策阶梯

AI 在写代码前，按优先级依次判断，满足前序条件就直接跳过冗余实现：

```
1. 这个需求真的需要存在吗？     → 不需要就跳过（YAGNI 原则）
2. 标准库已经实现了吗？         → 直接用
3. 平台原生特性支持吗？         → 直接用
4. 项目已经安装了对应的依赖吗？ → 直接用
5. 一行代码能解决吗？           → 一行搞定
6. 以上都不满足，再写最小可用实现
```

**安全兜底**：信任边界的输入校验、数据丢失防护、安全逻辑、无障碍支持这四个部分**绝对不裁剪**。

---

## 效果

在 Claude 系列模型上的基准测试结果（单轮测试）：

| 指标     | 效果        |
| -------- | ----------- |
| 代码量   | 减少 80-94% |
| 调用成本 | 降低 42-75% |
| 响应速度 | 快 3-6 倍   |

> ⚠️ 注意：效果因模型而异。GPT 系列推理模型可能出现成本上升；基准测试为单轮，多轮会话效果会有差异。

---

## 支持的平台

原生支持几乎所有主流 AI 编程工具：

| 平台                      | 安装方式                                                                                   |
| ------------------------- | ------------------------------------------------------------------------------------------ |
| Claude Code               | `/plugin marketplace add DietrichGebert/ponytail` 然后 `/plugin install ponytail@ponytail` |
| Codex                     | `codex plugin marketplace add DietrichGebert/ponytail` 然后按提示安装                      |
| GitHub Copilot CLI        | `copilot plugin marketplace add DietrichGebert/ponytail`                                   |
| OpenCode                  | 在 `opencode.json` 中添加插件路径                                                          |
| Gemini CLI                | `gemini extensions install https://github.com/DietrichGebert/ponytail`                     |
| Cursor / Windsurf / Cline | 复制对应的 rules 文件到项目目录                                                            |
| VS Code + Codex 扩展      | 自动读取 `AGENTS.md`，无需额外配置                                                         |

仅支持指令的平台（Cursor、Windsurf、Cline 等）只能加载 always-on 规则集，不支持 `/ponytail` 命令切换模式。

---

## 快捷命令

| 命令                                 | 功能                                                |
| ------------------------------------ | --------------------------------------------------- |
| `/ponytail [lite\|full\|ultra\|off]` | 切换规则强度 / 关闭规则，无参数时返回当前模式       |
| `/ponytail-review`                   | 审查当前 diff，返回可删除的冗余代码清单             |
| `/ponytail-audit`                    | 审计整个仓库的过度工程问题                          |
| `/ponytail-debt`                     | 收集 `ponytail:` 注释标记的临时简化项，生成待办清单 |
| `/ponytail-help`                     | 以上命令的快速参考                                  |

---

## 默认等级设置

可通过以下方式设置默认等级（`lite` / `full` / `ultra` / `off`）：

- 环境变量 `PONYTAIL_DEFAULT_MODE`
- 配置文件 `~/.config/ponytail/config.json`（Windows: `%APPDATA%\ponytail\config.json`）

默认等级为 `full`。

---

## 相关链接

- 仓库地址：<https://github.com/DietrichGebert/ponytail>
- 基准测试：仓库内 `benchmarks/` 目录，可用 `npx promptfoo eval -c benchmarks/promptfooconfig.yaml` 自行复现
- 优化前后代码对比示例：`examples/` 目录
