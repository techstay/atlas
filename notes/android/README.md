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
