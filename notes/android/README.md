---
icon: android
---

# 安卓

安卓开发和日常使用的一些笔记。

## 技巧

### 修改 ntp 服务器

```sh
adb shell "settings put global ntp_server ntp.ntsc.ac.cn"
```

### 消除 WIFI 叉号

打开 ADB 调试功能，在电脑上操作。最后手机开关飞行模式即可。

```shell
# 进入shell模式
adb shell
# 在shell中输入以下命令
settings delete global captive_portal_http_url
settings delete global captive_portal_https_url
settings put global captive_portal_http_url http://developers.google.cn/generate_204
settings put global captive_portal_https_url https://developers.google.cn/generate_204
```

### 作为 linux 服务器使用

首先需要安装 magisk 获取 root 权限，然后安装以下软件。

- [busybox](https://github.com/SmartPack/BusyBox-Installer/releases)，在 app 里安装 busybox，路径`/system/xbin`
- [linux deploy](https://github.com/meefik/linuxdeploy/releases)

在 linux deploy 中，做以下配置

1. 设置 PATH 路径为`/system/xbin`，点击应用配置
2. 点击主界面右下角，选择 debian 系统，镜像文件大小设置 8G 左右
3. 用户直接使用 root 用户，普通用户可能出现 DNS 问题
4. 其它选项按需设置

配置完成后点击右上角选择安装，稍等片刻就能安装完成。安装完成后点击启动即可启动 linux 系统。

之后通过 SSH 就能访问系统，并安装所需软件了。
