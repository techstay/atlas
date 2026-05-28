---
title: "eza"
date: 2026-05-17T01:33:22+08:00
tags:
  - oss
  - system-tools
  - eza
  - cli
categories:
  - 开源工具
---

# eza 命令使用笔记

eza 是 ls(1) 的现代替代品，提供彩色输出、图标支持、Git 集成、树状视图等增强功能。

> [!NOTE]
> **当前版本：** `0.23.4`

## 基础用法

```bash
# 基础列表（默认网格视图）
eza

# 详细列表视图
eza -l

# 显示所有文件（包含隐藏文件）
eza -a

# 树状视图显示目录结构
eza -T
```

## 常用选项

### 显示选项

| 选项                  | 作用                                        |
| --------------------- | ------------------------------------------- |
| `-1, --oneline`       | 每行显示一个条目                            |
| `-l, --long`          | 显示扩展文件元数据表格                      |
| `-G, --grid`          | 网格视图（默认）                            |
| `-x, --across`        | 网格按横向排序                              |
| `-R, --recurse`       | 递归显示子目录内容                          |
| `-T, --tree`          | 以树状结构递归显示目录                      |
| `-F, --classify=WHEN` | 文件名后显示类型指示符（always/auto/never） |
| `--colo[u]r=WHEN`     | 终端颜色输出控制（always/auto/never）       |
| `--colo[u]r-scale`    | 按字段值使用不同颜色高亮（all/age/size）    |
| `--icons=WHEN`        | 显示图标（always/auto/never）               |
| `--hyperlink`         | 将文件显示为超链接                          |
| `--absolute`          | 显示绝对路径（on/follow/off）               |
| `--follow-symlinks`   | 跟踪符号链接指向的目录                      |
| `-w, --width COLS`    | 设置屏幕宽度（列数）                        |

### 过滤和排序选项

| 选项                                                     | 作用                                       |
| -------------------------------------------------------- | ------------------------------------------ |
| `-a, --all`                                              | 显示隐藏和点文件，使用两次显示 `.` 和 `..` |
| `-A, --almost-all`                                       | 同 `-a`，兼容 `ls -A`                      |
| `-d, --treat-dirs-as-files`                              | 将目录作为文件列出，不展开内容             |
| `-D, --only-dirs`                                        | 仅显示目录                                 |
| `-f, --only-files`                                       | 仅显示文件                                 |
| `--show-symlinks` / `--no-symlinks`                      | 显式显示/隐藏符号链接                      |
| `-L, --level DEPTH`                                      | 限制递归/树状视图的深度                    |
| `-r, --reverse`                                          | 反向排序                                   |
| `-s, --sort FIELD`                                       | 按指定字段排序                             |
| `--group-directories-first` / `--group-directories-last` | 目录排在文件前/后                          |
| `-I, --ignore-glob GLOBS`                                | 忽略匹配 glob 模式的文件                   |
| `--git-ignore`                                           | 忽略 `.gitignore` 中指定的文件             |

**`--sort` 可用字段：**

`name` / `Name`（大小写敏感）/ `extension` / `Extension` / `size` / `type` / `created` / `modified` / `accessed` / `changed` / `inode` / `none`

> `date`、`time`、`old`、`new` 均为 `modified` 的别名。

### 长视图选项（搭配 `-l` 使用）

| 选项                      | 作用                                                                              |
| ------------------------- | --------------------------------------------------------------------------------- |
| `-h, --header`            | 显示表头                                                                          |
| `-g, --group`             | 显示文件所属组                                                                    |
| `--smart-group`           | 仅当组名与所有者不同时显示                                                        |
| `-H, --links`             | 显示硬链接数量                                                                    |
| `-i, --inode`             | 显示 inode 号                                                                     |
| `-b, --binary`            | 文件大小使用二进制前缀                                                            |
| `-B, --bytes`             | 文件大小直接显示字节数                                                            |
| `-n, --numeric`           | 显示数字 UID/GID                                                                  |
| `-S, --blocksize`         | 显示文件系统块大小                                                                |
| `-t, --time FIELD`        | 指定时间字段：`modified` / `accessed` / `created`                                 |
| `--time-style STYLE`      | 时间格式：`default` / `iso` / `long-iso` / `full-iso` / `relative` 或 `+<FORMAT>` |
| `--total-size`            | 显示目录总大小（递归计算）                                                        |
| `-o, --octal-permissions` | 以八进制格式显示权限                                                              |
| `--no-permissions`        | 隐藏权限列                                                                        |
| `--no-filesize`           | 隐藏文件大小列                                                                    |
| `--no-user`               | 隐藏用户列                                                                        |
| `--no-time`               | 隐藏时间列                                                                        |
| `--git`                   | 显示文件 Git 状态                                                                 |
| `--git-repos`             | 显示 Git 仓库根目录状态                                                           |
| `--no-git`                | 隐藏 Git 状态（覆盖 `--git`）                                                     |
| `-@, --extended`          | 显示扩展属性及大小                                                                |
| `-Z, --context`           | 显示安全上下文                                                                    |

## 实用示例

```bash
# 显示所有文件的详细信息，包含Git状态，目录优先
eza -al --git --group-directories-first

# 树状视图显示3级目录结构，包含图标
eza -T --icons -L 3

# 仅显示目录，详细列表视图
eza -lD

# 按修改时间排序，最新的排在最后
eza -l --sort modified -r

# 显示文件的八进制权限和inode号
eza -l --octal-permissions -i

# 忽略 node_modules 目录
eza -I "node_modules"

# 显示目录总大小及头部信息
eza -lh --total-size

# 自定义时间格式
eza -l --time-style '+%Y-%m-%d %H:%M'
```
