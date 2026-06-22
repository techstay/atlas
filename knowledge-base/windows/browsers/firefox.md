---
title: "Firefox浏览器"
date: 2026-06-19T00:00:00+08:00
tags:
  - windows
  - firefox
categories:
  - Windows
---

## Firefox Developer Edition 切换中文界面

由于 Firefox 开发者版（Firefox Developer Edition）的官方策略与正式版不同，它**默认不支持直接在高级设置（Settings）中通过点击下拉菜单添加和切换界面语言**。

要将其改为中文，目前最有效、最彻底的方法有两种：

---

### 方法一：直接下载官方简中安装包（最推荐）

这是最省时、最不容易出错的方法。你不需要卸载当前的浏览器，直接覆盖安装即可，你的所有浏览记录、插件和配置都会完好保留。

1. 访问 [Firefox 官方所有版本下载页面](https://www.mozilla.org/firefox/all/)。
2. 在列表中找到 **Firefox Developer Edition**。
3. 将 **Platform（平台）** 选择为你的操作系统（如 Windows 64-bit、macOS 或 Linux）。
4. 将 **Language（语言）** 明确选择为 **Chinese (Simplified)（中文简体）**。
5. 下载对应的安装包并直接运行安装，覆盖原有程序。

---

### 方法二：通过高级配置（about:config）强制修改

如果你不想重新下载完整的安装包，可以通过修改底层参数来强制加载中文语言包。

#### 第一步：下载并启用中文语言包

1. 打开你的 Firefox 开发者版，在地址栏输入 `about:addons` 并回车，进入插件管理页面。
2. 点击左侧的 **Languages（语言）** 标签页。
3. 如果列表中没有中文，点击右上角的齿轮图标，选择 **Find updates（寻找更新）**，或者直接前往 Mozilla 官方语言包商店搜索 **Chinese (Simplified) Language Pack** 并点击 **Add to Firefox** 进行安装。
4. 安装完成后，确保该语言包处于 **Enabled（已启用）** 状态。

#### 第二步：修改底层语言请求参数

1. 在地址栏输入 `about:config` 并回车。
2. 页面会弹出警告提示（Accept the Risk and Continue），点击蓝色按钮接受风险并继续。
3. 在顶部的搜索框中，输入专名词：**`intl.locale.requested`**。
4. **修改或创建该参数**：
   - 如果该参数已存在：点击右侧的铅笔图标（Edit），将它的值修改为 **`zh-CN`**，然后点击对勾保存。
   - 如果该参数不存在：选择类型为 **String（字符串）**，点击 `+` 号添加，名称填入 `intl.locale.requested`，值填入 `zh-CN`。
5. 完全关闭 Firefox 开发者版并重新打开，整个界面即会切换为中文。
