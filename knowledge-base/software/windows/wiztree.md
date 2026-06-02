---
title: "WizTree"
date: 2026-06-01T13:24:00+08:00
tags:
  - software
  - windows
  - wiztree
  - disk-analyzer
categories:
  - 软件
  - Windows
---

## 概述

WizTree 是一款 Windows 下的磁盘空间分析工具，通过直接读取 NTFS 的 MFT（Master File Table）实现极速扫描。相比同类工具动辄几分钟的扫描速度，WizTree 通常在数秒内即可完成全盘分析。

- 官网: <https://diskanalyzer.com/>
- 免费用于个人使用，商业用途需购买
- 有便携版（Portable），无需安装

![[wiztree.avif]]

## 安装

用 winget 命令行安装。

```sh
winget install --id "AntibodySoftware.WizTree" --exact --source winget --accept-source-agreements --disable-interactivity --silent --accept-package-agreements --force
```

或者在 [官网下载安装](https://diskanalyzer.com/download)，有安装版和便携版两种可以选择。

## 核心功能

⚡ **极速扫描** — 直接读取 NTFS 的 MFT，无需遍历文件系统，扫描 1TB 硬盘通常只需几秒钟。

🗺️ **树状图可视化** — 以 Treemap 颜色方块展示文件占用比例，直观定位大文件和占用异常的目录。

📊 **文件扩展名统计** — 按文件类型汇总，快速了解哪类文件占用最多空间。

📤 **导出功能** — 支持导出扫描结果为 CSV、将文件列表复制到剪贴板，以及导出 MFT 文件备份。
