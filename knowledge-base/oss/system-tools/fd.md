---
title: "fd"
date: 2026-05-17T02:25:53+08:00
tags:
  - oss
  - system-tools
  - fd
  - cli
categories:
  - 开源工具
---

# fd 命令使用指南

fd 是一款简单、快速且用户友好的 `find` 替代工具，使用 Rust 编写，支持彩色输出、正则匹配、自动忽略 `.gitignore` 规则等特性。

> [!NOTE]
> **当前版本：** `10.4.2`

## 基本语法

```bash
fd [选项] [搜索模式] [路径...]
```

- `[pattern]`：搜索模式，默认为正则表达式（`--glob` 后为 glob 模式）。省略则匹配所有条目。
- `[path]`：搜索的根目录，省略则为当前目录。

## 核心特性

- 默认忽略 `.gitignore`/`.fdignore` 中定义的隐藏文件和目录
- 内置正则表达式和 glob 模式匹配
- 原生支持彩色终端输出
- 智能大小写：模式含大写字母时自动大小写敏感
- 搜索速度远快于传统 `find` 命令
- 跨平台支持（Linux/macOS/Windows）

## 常用选项

| 选项                           | 说明                                  |
| ------------------------------ | ------------------------------------- |
| `-H, --hidden`                 | 搜索隐藏文件和目录                    |
| `-I, --no-ignore`              | 不忽略 `.gitignore`/`.fdignore` 规则  |
| `-s, --case-sensitive`         | 强制大小写敏感                        |
| `-i, --ignore-case`            | 强制大小写不敏感                      |
| `-g, --glob`                   | glob 模式匹配（默认正则）             |
| `-a, --absolute-path`          | 显示绝对路径                          |
| `-l, --list-details`           | 类似 `ls -l` 的详细列表格式           |
| `-L, --follow`                 | 跟随符号链接                          |
| `-p, --full-path`              | 针对完整路径匹配（默认仅匹配文件名）  |
| `-d, --max-depth <depth>`      | 限制最大搜索深度                      |
| `-E, --exclude <pattern>`      | 排除匹配 glob 模式的文件/目录         |
| `-t, --type <type>`            | 按类型筛选                            |
| `-e, --extension <ext>`        | 按文件后缀筛选                        |
| `-S, --size <size>`            | 按文件大小筛选                        |
| `--changed-within <date\|dur>` | 筛选修改时间在指定时间/时长内的文件   |
| `--changed-before <date\|dur>` | 筛选修改时间在指定时间/时长之前的文件 |
| `-o, --owner <user:group>`     | 按文件所有者筛选                      |
| `--format <fmt>`               | 自定义输出格式模板                    |
| `-x, --exec <cmd>`             | 对每个结果并行执行命令                |
| `-X, --exec-batch <cmd>`       | 将所有结果一次性传给命令执行          |
| `-c, --color <when>`           | 颜色输出控制：`auto`/`always`/`never` |
| `--hyperlink[=<when>]`         | 输出路径添加终端超链接                |

## `-t, --type` 文件类型说明

| 值                        | 含义                             |
| ------------------------- | -------------------------------- |
| `f` / `file`              | 普通文件                         |
| `d` / `dir` / `directory` | 目录                             |
| `l` / `symlink`           | 符号链接                         |
| `x` / `executable`        | 可执行文件（隐含 `--type file`） |
| `e` / `empty`             | 空文件或空目录                   |
| `s` / `socket`            | socket                           |
| `p` / `pipe`              | 命名管道（FIFO）                 |
| `b` / `block-device`      | 块设备                           |
| `c` / `char-device`       | 字符设备                         |

可多次指定以包含多种类型，如 `-tf -tl` 同时搜索文件和符号链接。

## `-S, --size` 大小筛选格式

格式：`<+-><NUM><UNIT>`

- `+`：文件大小大于等于该值
- `-`：文件大小小于等于该值
- 无符号：文件大小精确等于该值

**单位**（不区分大小写）：`b`(字节), `k`(KB), `m`(MB), `g`(GB), `t`(TB), `ki`(KiB), `mi`(MiB), `gi`(GiB), `ti`(TiB)

## 高频使用示例

1. 搜索当前目录下所有包含 "test" 关键词的文件：

   ```bash
   fd test
   ```

2. 搜索所有 Markdown 文件：

   ```bash
   fd -e md
   ```

3. 搜索名称包含 "src" 的目录：

   ```bash
   fd -t d src
   ```

4. 搜索所有 JS 文件并自动执行 prettier 格式化：

   ```bash
   fd -e js -x prettier --write {}
   ```

5. 搜索包含 "config" 关键词的隐藏文件：

   ```bash
   fd -H config
   ```

6. 搜索大于 100MB 的压缩包文件：

   ```bash
   fd -e zip -S +100M
   ```

7. 搜索最近 7 天内修改过的文件：

   ```bash
   fd --changed-within 7d
   ```

8. 排除 node_modules 搜索 "utils"：
   ```bash
   fd -E node_modules utils
   ```

## `-x` / `-X` 占位符

| 占位符 | 说明               |
| ------ | ------------------ |
| `{}`   | 完整路径           |
| `{/}`  | 文件名（basename） |
| `{//}` | 父目录路径         |
| `{.}`  | 去掉扩展名的路径   |
| `{/.}` | 去掉扩展名的文件名 |
