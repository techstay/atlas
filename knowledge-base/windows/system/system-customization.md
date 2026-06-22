---
title: "🖥️ Windows 系统美化指南"
description: "Windows 系统美化和个性化配置推荐，包括启动器、字体、鼠标指针、窗口美化等"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
  - 美化
  - 个性化
  - 效率
categories:
  - Windows
icon: 🎨
cover: null
---

## 🔍 搜索 & 启动器

- [Raycast](https://www.raycast.com/windows) - 强大的 Mac 风格启动器，现已支持 Windows 公开测试版，支持系统级搜索、剪贴板历史等
- [Listary](https://www.listary.com) - Windows 文件搜索与应用启动器，可快速定位文件和程序

## 🔤 字体

- 修改系统字体 [no MeiryoUI](https://github.com/Tatsu-syo/noMeiryoUI) - Windows 8.1/10/11 系统字体修改工具，可自定义 UI 字体

## 🖱️ 鼠标指针

- BlackMamba
- CDot
- Dimato2
- Elegant rose
- gami
- layan-white
- Oreo
- oreo
- TinyHand
- [Bibata_Cursor](https://github.com/ful1e5/Bibata_Cursor)
- [BlueArchive-Cursors](https://github.com/makipom/BlueArchive-Cursors)
- [macOS-cursors-for-Windows](https://github.com/antiden/macOS-cursors-for-Windows)
- [catppuccin/cursors](https://github.com/catppuccin/cursors) 这个是linux下专用，需要用 [ani2xcur-cli](https://github.com/licyk/ani2xcur-cli) 工具转换为windows格式，先下载并解压，然后用命令行指定解压目录，即可转换

## 🪟 窗口美化

Windows 11 自带的 Mica / Acrylic 材质偏向扁平，缺少 Win7 Aero Glass 那种磨砂玻璃的厚重感和高光。以下工具可以恢复经典的毛玻璃窗口边框效果：

- [DWMBlurGlass](https://github.com/Maplespe/DWMBlurGlass) - 通过注入 DWM 在窗口标题栏生成真正的毛玻璃和高光模糊效果，支持全局模糊、自定义透明度和反射强度，还原 Win7/Vista 窗口玻璃质感。由于权限问题，软件需要放到 C 盘，不能直接放到用户目录下。
- [Explorer Tab Utility](https://github.com/w4po/ExplorerTabUtility) - Windows 11 文件资源管理器标签页增强工具，自动将新窗口转换为标签页，支持复制标签页、重新打开已关闭标签、快捷键导航等功能，告别多个资源管理器窗口的混乱局面。安装命令：`winget install w4po.ExplorerTabUtility`
- [Windhawk](https://windhawk.net) - Windows 系统底层微调平台，推荐安装的社区模组：
  - **Bring Back the Borders!** - 找回 Win7 式粗边框和窗口边缘
  - **Taskbar Show Desktop Button Aero Peek** - 恢复鼠标悬停任务栏右下角时所有窗口变透明的 Aero Peek 功能
  - **Windows 11 Taskbar/Start Menu Styler** - 为任务栏和开始菜单注入玻璃磨砂材质
- [MicaForEveryone](https://github.com/MicaForEveryone/MicaForEveryone) - 为 Win32 应用窗口标题栏启用云母/亚克力等背景材质效果，自定义全局窗口渲染样式
- [Stardock WindowFX](https://www.stardock.com/products/windowfx) - 商业窗口效果增强工具，支持自定义窗口动画、阴影、透明度、过渡效果等高级视觉特性

> [!warning] 安全提示
> 这些工具需要深入系统底层或内存注入，Windows 重大版本更新（如 24H2、25H2）后可能失效甚至导致黑屏。折腾前务必**创建系统还原点**，并记住如何进入**安全模式**卸载美化软件。

### Windhawk

安装

```sh
winget.exe install --id "RamenSoftware.Windhawk" --exact --source winget --accept-source-agreements --disable-interactivity --silent --accept-package-agreements --force
```

## 🖼️ 桌面壁纸 & 微件

- [Wallpaper Engine](https://www.wallpaperengine.io)（小红车） - Steam 动态壁纸工具，依托创意工坊拥有海量社区壁纸，支持鼠标交互、音频响应等全交互效果，全屏时自动暂停几乎不影响性能，19 元买断
- [Rainmeter](https://www.rainmeter.net)（雨滴） - 开源免费的桌面微件引擎，可在桌面上放置时钟、天气、硬件监控、音乐频谱等各种皮肤（Skins），自由度极高但需要从社区获取皮肤包并手动配置
