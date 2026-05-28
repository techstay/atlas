---
title: "wsl"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
  - wsl
categories:
  - Windows
---

## 安装

参考 <https://learn.microsoft.com/zh-cn/windows/wsl/install-manual>

### 启用 wsl

```powershell
wsl --install --no-distribution
```

安装完成后可能需要重启电脑。如果提示需要安装 Linux 内核更新包，[点此安装](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)。

### 在线发行版

wsl 自带几个受官方支持的发行版，可以直接安装。

```powershell
wsl --list --online
```

### 安装 archwsl

或者也可以安装自定义发行版，例如 archwsl，可以通过 scoop 安装。

```powershell
scoop install archwsl
```

安装完成后需要先更新密钥。

```sh
pacman-key --init
pacman-key --populate
pacman -Syy archlinux-keyring
```

配置参考 [[archlinux安装一条龙]]，配置完成后退出 wsl，设置 arch 的默认用户。

```powershell
Arch.exe config --default-user techstay
```

最后克隆 [dotfiles](https://github.com/techstay/dotfiles)。

### fedora

fedora 里面有些软件竟然比 Arch Linux 新，所以开发工具这块我还是切换了。

```sh
wsl --update
wsl --install FedoraLinux-42
wsl -d FedoraLinux-42
```

配置 fedora

```
sudo dnf install git zsh

git clone https://github.com/yadm-dev/yadm.git ~/.yadm-project
ln -s ~/.yadm-project/yadm ~/bin/yadm


```

## 命令

常用命令

```sh
# 列出发行版
wsl --list --verbose
# 设置WSL版本 1/2
wsl --set-default-version 2
# 设置默认WSL，可通过终端键入wsl进入
wsl --set-default <Distribution Name>
# 以指定用户登录wsl
wsl --distribution <Distribution Name> --user <User Name>
# 更新wsl
wsl --update
# 关闭所有wsl虚拟机
wsl --shutdown
# 停止指定wsl发行版
wsl --terminate <Distribution Name>
# 导出发行版
wsl --export <Distribution Name> <FileName>
# 导入发行版
wsl --import <Distribution Name> <InstallLocation> <FileName>
# 卸载发行版
wsl --unregister <DistributionName>
```

## 配置 wsl

### 设置内存

wsl 默认会占用系统一半的内存，如果需要设定可以编辑 `$HOME/.wslconfig` 配置文件，文件内容如下。

```conf
[wsl2]
memory=4GB
```

### 设定动态端口号范围

开启 wsl 之后，windows 会把默认端口号的映射起始范围降低到 1024，会导致有时候一些常用的端口号无法使用，具体表现为依赖端口号的程序会无法运行，但是通过各种程序又发现对应的端口号并没有被占用。这时候需要将端口号的起始范围重新设为一个较高的值。

查看当前动态端口号范围。

```powershell
Get-NetTCPSetting|select SettingName, DynamicPortRange*
```

如果起始范围是 1024，那么需要重新设定一次动态端口号范围。

```powershell
Set-NetTCPSetting -DynamicPortRangeStartPort 40000 -DynamicPortRangeNumberOfPorts 10000
```
