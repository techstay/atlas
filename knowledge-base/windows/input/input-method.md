---
title: "输入法"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
categories:
  - Windows
---

## AI 语音输入法

以前的语音输入法错误率比较高，但是最近随着大模型的发展，语音输入法的准确率也大幅提升，也支持通过大模型来优化语音输入和润色。就我自己的使用来看，大多数场景下已经完全可以替代键盘输入了。以前学过的双拼输入法也进入淘汰倒计时了。

### 千问

千问桌面端支持语音输入，默认右 Alt 开启，支持润色，准确率也不错。目前我正在使用。

### LazyTyper

开源的 AI 语音输入法，支持本地模型和语音识别 API。注重隐私的话可以使用本地模型，效果也不错。

### 豆包输入法

在大模型的加持下，豆包输入法的语音输入准确度也不错，不过目前还没有桌面端。

## 小狼毫

### 配置

开源免费的 rime 输入法的 windows 版。

- 下载安装 <https://rime.im/>
- 配置指南 <https://github.com/rime/home/wiki/CustomizationGuide>
- 配色工具 <https://bennyyip.github.io/Rime-See-Me/>
- 「东风破」配置管理器 <https://github.com/rime/plum>
- 词库 <https://github.com/rime-aca/dictionaries>

### 雾凇拼音

一个第三方维护的 Rime 配置和词库，支持全拼、双拼等配置。

首次使用最好备份并清空原配置文件夹，然后使用 git bash 运行东风破，安装雾凇拼音的配置。

```sh
curl -fsSL https://raw.githubusercontent.com/rime/plum/master/rime-install | bash -s -- iDvel/rime-ice:others/recipes/full
```

安装完成后在菜单中启用雾凇拼音（全拼）或者微软双拼等拼音方案，即可享受预配置好的各项功能，具体可见 [官方说明](https://dvel.me/posts/rime-ice/)。

#### 速查表

- V 模式，大写 V 开启，输入全拼首字母，表情符号等等
- 日期时间农历，双拼需要使用英文输入
- 部件反查，前缀 uU
- Unicode，前缀 U
- 数字金额大写，前缀 R，选择需要 Ctrl+ 数字键
- 农历日期，前缀 N，输入日期

## [白霜词库](https://github.com/gaboolic/rime-frost?tab=readme-ov-file)

安装

```sh
curl -fsSL https://raw.githubusercontent.com/rime/plum/master/rime-install | bash -s -- gaboolic/rime-frost:others/recipes/full
```

## [薄荷输入法](https://www.mintimate.cc/zh/)

```sh
curl -fsSL https://raw.githubusercontent.com/rime/plum/master/rime-install | bash -s -- Mintimate/oh-my-rime:plum/full
```

词库模型 https://github.com/amzxyz/RIME-LMDG

## [万象输入法](https://github.com/amzxyz/rime_wanxiang?tab=readme-ov-file)

## [雨燕输入法](https://github.com/gurecn/YuyanIme)

安卓端输入法
