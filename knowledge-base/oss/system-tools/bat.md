---
title: "bat"
date: 2026-05-17T01:26:40+08:00
tags:
  - oss
  - system-tools
  - bat
  - cli
categories:
  - 开源工具
---

# bat 命令使用笔记

> [!NOTE]
> **当前版本：** `0.26.1`

bat 是一个 cat(1) 的替代工具，提供语法高亮、Git 集成、自动分页等增强功能。

## 基础用法

```bash
# 查看单个文件
bat README.md

# 查看多个文件
bat file1.txt file2.txt

# 从标准输入读取
curl https://example.com | bat -l json
```

## 常用选项

| 选项                             | 作用                                                               |
| -------------------------------- | ------------------------------------------------------------------ |
| `-A, --show-all`                 | 显示所有非打印字符（空格、制表符、换行符等）                       |
| `-p, --plain`                    | 纯文本输出，无任何装饰；使用 `-pp` 同时禁用自动分页                |
| `-l, --language <lang>`          | 手动指定语法高亮的语言，例如 `-l python`                           |
| `-H, --highlight-line <range>`   | 高亮指定行/行范围                                                  |
| `-d, --diff`                     | 仅显示与 Git 索引相比有修改的行                                    |
| `--diff-context <N>`             | 配合 `--diff` 显示修改行上下 N 行上下文                            |
| `-n, --number`                   | 仅显示行号，无其他装饰                                             |
| `-S, --chop-long-lines`          | 截断超长行，不换行                                                 |
| `--wrap <mode>`                  | 换行模式：`auto`（默认）/ `never` / `character`                    |
| `--style <components>`           | 自定义显示元素，逗号分隔，如 `numbers,changes,grid`                |
| `--color <when>`                 | 颜色输出控制：`auto` / `never` / `always`                          |
| `--paging <when>`                | 控制分页器：`auto`/`never`/`always`，`-P` 是 `--paging=never` 别名 |
| `--pager <command>`              | 指定分页器命令，例如 `--pager "less -RF"`                          |
| `--theme <theme>`                | 指定语法高亮主题，`--list-themes` 查看所有可用主题                 |
| `--theme-light` / `--theme-dark` | 分别指定亮/暗色主题，配合 `--theme auto` 使用                      |
| `-r, --line-range <range>`       | 只显示指定行范围                                                   |
| `-L, --list-languages`           | 列出所有支持的语法高亮语言                                         |
| `-m, --map-syntax <glob:syntax>` | 将文件扩展名映射到语法，如 `-m '*.build:Python'`                   |
| `--file-name <name>`             | 为 STDIN 输入指定文件名（用于语法检测）                            |
| `-s, --squeeze-blank`            | 压缩连续空行为一行                                                 |
| `--tabs <T>`                     | 设置制表符宽度（空格数），设为 0 保持原样                          |

## 实用示例

### 1. 高亮显示 JSON 数据

```bash
curl https://api.github.com/users/octocat | bat -l json
```

### 2. 对比文件修改

```bash
bat --diff README.md
```

### 3. 查看文件指定范围的行

```bash
# 查看第 10 到 30 行
bat --line-range 10:30 app.py

# 高亮第 15 行
bat --highlight-line 15 app.py
```

### 4. 自定义显示样式

```bash
# 仅显示行号和网格，无文件头
bat --style=numbers,grid app.py

# 显示行号 + Git 修改标记 + 网格 + 文件头
bat --style=numbers,changes,grid,header app.py

# 完整样式（显示全部元素）
bat --style=full app.py
```

### 5. 映射自定义文件类型

```bash
# 将 .build 文件用 Python 语法高亮
bat -m '*.build:Python' project.build

# 将 .myignore 识别为 Git Ignore 语法
bat -m '.myignore:Git Ignore' .myignore
```

### 6. 从标准输入指定文件名

```bash
# 指定文件名以便 bat 自动检测语法
curl http://example.com/data | bat --file-name data.json
```

### 7. 生成 shell 补全

```bash
# Bash
bat --completion bash > ~/.bash_completion.d/bat

# Fish
bat --completion fish > ~/.config/fish/completions/bat.fish

# Zsh
bat --completion zsh > ~/.zsh/completions/_bat
```
