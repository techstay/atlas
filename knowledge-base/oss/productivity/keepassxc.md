---
title: "keepassxc"
date: 2026-05-15T01:18:06+08:00
tags:
  - oss
  - productivity
  - keepass
  - password-manager
categories:
  - 开源工具
---

## 安装

- <https://keepassxc.org/download/>
- `scoop install keepassxc`

## 开始使用

### 新建数据库

首先需要新建一个数据库，设置密码或密钥文件。创建数据库之后，可以将数据库和密钥文件放到 Onedrive 等网盘中同步，这样既可以随时备份，同时将来也同步到其他设备上使用。

### 添加条目

将要保存的账号和密码添加到数据库中。要启用自动填写的话，需要标题和程序的标题相对应。

如果要保存浏览器密码的话，需要启用浏览器集成功能并安装相应的浏览器扩展。

### 自动填充

右击最上级群组并选择设置，找到自动填充设置，设置如下的序列，这在中文输入法环境中比较适用，默认你当前是中文输入状态。

实际执行的操作如下：先按 shift 键切换成英文输入状态，等待 100 毫秒，清空账户框的输入，输入用户名，TAB 切换到密码框，输入密码。

```txt
+{DELAY 100}{CLEARFIELD}{USERNAME}{TAB}{PASSWORD}
```

如果想让自动完成后直接登录，可以在最后面再加上一个 `{ENTER}`。

### 浏览器集成

在程序设置中启用浏览器集成，然后安装 [浏览器扩展](https://chrome.google.com/webstore/detail/keepassxc-browser/oboonakemofpalcgghocfoadofidjkkk)，配对之后即可将浏览器中填写的密码保存到 keepass 数据库中。

### TOTP

在 keepassxc 的账号设置中右击选择 TOTP 并添加密钥。需要使用时可以从 keepass 直接复制 TOTP 密码，也可以将其应用在自动填充功能里面，代码是 `{TOTP}`。
