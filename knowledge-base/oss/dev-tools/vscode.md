---
title: "vscode"
date: 2026-05-15T01:18:06+08:00
tags:
  - oss
  - dev-tools
  - vscode
  - editor
categories:
  - 开源工具
---

## 安装

- 直接下载安装<https://code.visualstudio.com>
- scoop 安装 `scoop install vscode`

## 配置

### 主题

这里有一篇颜色主题的文章可供参考 [50-vs-code-themes-for-2020](https://dev.to/softwaredotcom/50-vs-code-themes-for-2020-45cc)。

### 字体

```powershell
# 先要启用字体分类
scoop bucket add nerd-fonts
scoop install Source-Han-Mono-SC Source-Han-Mono-TC Source-Han-Sans-SC Source-Han-Sans-TC Source-Han-Sans-J
scoop install LiberationMono-NF
scoop install Meslo-NF-Mono
```

安装完成后需要在 vscode 中设置，对应的 JSON 配置如下：

```json
{
  "editor.fontFamily": "'LiterationMono NF', 'Liberation Mono', 'Jetbrains Mono', '思源黑体', Consolas, monospace",
  "editor.fontLigatures": true,
  "editor.fontSize": 18,
  "terminal.integrated.fontFamily": "MesloLGS NF",
  "terminal.integrated.fontSize": 12
}
```

### 自动保存和格式化

```json
{
  "editor.defaultFormatter": "esbenp.prettier-vscode",
  "editor.formatOnSave": true,
  "files.autoSave": "onFocusChange"
}
```
