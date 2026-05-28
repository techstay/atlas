---
title: "zoxide"
date: 2026-05-17T02:27:09+08:00
tags:
  - oss
  - system-tools
  - zoxide
  - cli
categories:
  - 开源工具
---

# zoxide 命令使用指南

zoxide 是一款 `cd` 的现代替代工具，通过记录访问频率实现快速目录跳转，支持模糊匹配和交互式选择，通常别名设为 `z` 使用。

> [!NOTE]
> **当前版本：** `0.9.9`

## 基本语法

```bash
zoxide <COMMAND> [OPTIONS] [ARGS]...
```

## 子命令

| 命令                  | 说明                                   |
| --------------------- | -------------------------------------- |
| `add <paths...>`      | 添加目录或增加其权重分数               |
| `edit`                | 编辑数据库                             |
| `import <path>`       | 从其他应用（z / autojump）导入历史数据 |
| `init <shell>`        | 生成 shell 配置                        |
| `query [keywords...]` | 搜索数据库中的目录                     |
| `remove [paths...]`   | 从数据库移除目录                       |

## query 选项（核心功能）

通过 `zoxide query` 或别名 `z` 使用：

| 选项                | 说明                 |
| ------------------- | -------------------- |
| `-i, --interactive` | 交互式选择匹配的目录 |
| `-l, --list`        | 列出所有匹配目录     |
| `-s, --score`       | 显示匹配分数         |
| `-a, --all`         | 显示不可用的目录     |
| `--exclude <path>`  | 排除指定路径         |
| `--base-dir <path>` | 仅在此目录内搜索     |

## init 选项

生成 shell 集成配置：

| 选项            | 说明                                                |
| --------------- | --------------------------------------------------- |
| `--no-cmd`      | 不定义 `z` / `zi` 命令                              |
| `--cmd <CMD>`   | 自定义命令前缀（默认 `z`）                          |
| `--hook <HOOK>` | 控制权重更新时机：`none` / `prompt` / `pwd`（默认） |

支持 shell：`bash`、`elvish`、`fish`、`nushell`、`posix`、`powershell`、`tcsh`、`xonsh`、`zsh`

## add 选项

| 选项                  | 说明         |
| --------------------- | ------------ |
| `-s, --score <SCORE>` | 指定权重分数 |

## import 选项

| 选项            | 说明                       |
| --------------- | -------------------------- |
| `--from <FROM>` | 来源应用：`autojump` / `z` |
| `--merge`       | 合并到现有数据库而非覆盖   |

## 环境变量

| 变量                   | 说明                            |
| ---------------------- | ------------------------------- |
| `_ZO_DATA_DIR`         | 数据库文件存储路径              |
| `_ZO_ECHO`             | 设为 `1` 时打印匹配目录后再跳转 |
| `_ZO_EXCLUDE_DIRS`     | 要排除的目录 glob 列表          |
| `_ZO_FZF_OPTS`         | 传递给 fzf 的自定义参数         |
| `_ZO_MAXAGE`           | 条目最大保留时间，超期自动删除  |
| `_ZO_RESOLVE_SYMLINKS` | 解析符号链接后存储路径          |

## 使用示例

```bash
# 跳转到匹配 "project" 的最高权重目录
z project

# 同时匹配多个关键词
z repo go

# 跳转到上一次访问的目录
z -

# 交互式选择匹配目录
z -i docs

# 列出所有匹配路径及其权重
z -l work

# 显示匹配分数
z -s download

# 手动添加路径到数据库
zoxide add ~/projects/my-app

# 从 z 导入历史数据
zoxide import --from z ~/z_history.txt

# 初始化 bash 集成（配置到 .bashrc）
zoxide init bash

# 初始化 zsh 集成（配置到 .zshrc）
zoxide init zsh

# 移除目录记录
zoxide remove ~/old-project
```
