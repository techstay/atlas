---
title: "BIOS"
date: 2026-06-03T00:00:00+08:00
tags:
  - windows
  - bios
  - hardware
categories:
  - Windows
aliases:
  - 主板 BIOS 设置
  - BIOS 设置
---

# 🧬 BIOS

这里记录我电脑上比较关键的一些 BIOS 设置，方便以后重装、更新或排查问题时快速恢复配置。

## 🚀 系统启动与唤醒设置

- ⚡ **由 PCI-E 设备唤醒**：[关闭] → [开启]
- 🐢 **快速启动**：[开启] → [关闭]
- 🧭 **设置模式**：[EZ 模式] → [高级模式]
- 🧹 **下载并安装 ARMOURY CRATE 应用程序**：[开启] → [关闭]

## 🧠 内存超频与频率设置

我的处理器体质比较一般，内存频率暂时稳在 6000MHz。

- 🎛️ **Ai Overclock Tuner**：[Auto] → [EXPO I]
- 📉 **EXPO 配置文件**：[DDR5-6400 32-38-38-90-1.35V-1.35V] → [DDR5-6000 32-38-38-90-1.35V-1.35V]
- 🚦 **Memory Frequency**：[Auto] → [DDR5-6000MHz]
- 🔁 **FCLK Frequency**：[Auto] → [2000 MHz]
- 🔗 **UCLK DIV1 MODE**：[Auto] → [UCLK=MEMCLK]

## ⚙️ 高级电源与上下文恢复

让主板自动沿用上次训练好的内存配置，减少开机等待时间。

- 🧩 **Memory Context Restore**：[Auto] → [Enabled]
- 🔋 **Power Down Enable**：[Auto] → [Enabled]

## 🛠️ 更新 BIOS

我目前使用的主板是 **TUF GAMING B650M-PLUS WIFI 重炮手**，对应的 [驱动下载页面](https://www.asus.com.cn/motherboards-components/motherboards/tuf-gaming/tuf-gaming-b650m-plus-wifi/helpdesk_bios?model2Name=TUF-GAMING-B650M-PLUS-WIFI) 在这里。

更新流程：

1. 📦 下载 BIOS 文件并解压。
2. 💾 将解压出来的 BIOS 更新文件放到 **FAT32 格式的 U 盘** 中。
3. 🔌 把 U 盘插到电脑上，然后重启进入 BIOS。
4. 🧰 在 BIOS 中选择华硕 BIOS 更新程序，按提示执行更新。
5. ☕ 稍等片刻，更新完成后再检查关键设置是否被重置。

> [!warning]
> BIOS 文件不要直接放到本地硬盘里，华硕 BIOS 更新程序可能无法正常识别。乖乖放到 U 盘里，少给自己找麻烦。
