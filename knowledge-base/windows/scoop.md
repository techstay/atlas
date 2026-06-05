---
title: "scoop"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
  - scoop
  - package-manager
categories:
  - Windows
---

[scoop](https://scoop.sh) 是一个 windows 下的软件包管理器 📦，无需管理员权限，将软件全部安装到用户文件夹下，方便管理。我一直在使用这个，安装一些命令行软件非常方便。

## 安装 📥

打开 Powershell 窗口，运行下面的命令。

```powershell
# 首先设置允许运行远程脚本
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser

# 然后安装scoop
Invoke-Expression (New-Object System.Net.WebClient).DownloadString('https://get.scoop.sh')
```

如果要将 scoop 安装到其他位置 📂，则需要先设置 `SCOOP` 环境变量，然后再安装。

```powershell
$env:SCOOP = 'C:\scoop'
[environment]::setEnvironmentVariable('SCOOP', $env:SCOOP, 'User')
Invoke-WebRequest -useb get.scoop.sh | Invoke-Expression
```

## 配置 ⚙️

### 设置代理 🌐

scoop 默认下载速度比较慢，因为大部分资源都在国外，如果有代理的话，可以设置加速 🚀。

```powershell
scoop config proxy username:password@proxy.example.org:8080

# 例
scoop config proxy localhost:7890

# 删除代理
scop config rm proxy
```

### 添加 bucket 🗃️

bucket 是 scoop 的软件类别仓库，可以由 `scoop bucket known` 查看。

```powershell
scoop bucket known

main
extras
versions
nirsoft
php
nerd-fonts
nonportable
java
games
```

这些 bucket 的含义如下：

- **main** 🏠，自带的软件仓库
- **extras** 🎁，一些额外的带有图形界面软件的仓库
- **versions** 🔢，包含一些编程语言和类库的各种版本的仓库
- **nirsoft** 🛠️，包含 nirsoft 软件的仓库
- **php** 🐘，各种 php 的仓库
- **nerd-fonts** 🔤，包含各种 nerd-fonts 字体
- **nonportable** 📦，包含各种非绿色版软件的仓库
- **java** ☕，各种 java 版本都有的仓库
- **games** 🎮，一些游戏和相关工具的仓库

一般不需要全部添加，只添加几个常用的即可。我会启用 extras、nerd-fonts 和 java 这三个 bucket。

```powershell
# bucket依赖git，所以需要先安装git
scoop install git-with-openssh
git config --global http.proxy localhost:7890

scoop bucket add extras
scoop bucket add nerd-fonts
scoop bucket add java
```

### 多连接下载 ⚡

安装 aria2 即可自动启用多连接下载。

```powershell
scoop install aria2
```

如果下载遇到问题，可以关闭 aria2 下载。

```powershell
scoop config aria2-enabled false
```

关于下载的其他说明，参见 [官方文档](https://github.com/ScoopInstaller/Scoop#multi-connection-downloads-with-aria2)。

### powershell 补全 ⌨️

安装：

```powershell
# add extras bucket
scoop bucket add extras

# install
scoop install scoop-completion
```

然后在 `$PROFILE` 中添加以下一行。

```powershell
Import-Module "$($(Get-Item $(Get-Command scoop.ps1).Path).Directory.Parent.FullName)\modules\scoop-completion"
```

## 使用 🛠️

### 安装和卸载 📦

先搜索要安装的软件名字，然后安装。

```powershell
# 先搜索要安装的软件名字
scoop search openjdk17

# 然后安装
scoop install openjdk17
```

不再需要的软件包就可以卸载。

```powershell
scoop uninstall openjdk17
```

### 更新 🔄

```powershell
# 更新 scoop 自己
scoop update scoop

# 更新所有软件
scoop update *
```

### 管理多版本 🔀

比如同时安装了 openjdk8 和 openjdk17，就可以用 scoop 来轻松设置命令行，设置完成后终端的命令就会使用对应的版本。

```powershell
# 使用openjdk8
scoop reset openjdk8

# 使用openjdk17
scoop reset openjdk17
```

### 清理 🧹

scoop 更新软件的时候会保留几个旧版本，假如不再需要这些旧版本，可以把它们清理掉。顺便也可以把下载缓存清理掉。

```powershell
# 清理软件的旧版本
scoop cleanup *

# 清理软件的下载缓存
scoop cache rm *
```

## 命令行 💻

要查看 scoop 命令行，直接运行 `scoop` 命令。

```sh
$ scoop
Usage: scoop <command> [<args>]

Available commands are listed below.

Type 'scoop help <command>' to get more help for a specific command.

Command    Summary
-------    -------
alias      Manage scoop aliases
bucket     Manage Scoop buckets
cache      Show or clear the download cache
cat        Show content of specified manifest.
checkup    Check for potential problems
cleanup    Cleanup apps by removing old versions
config     Get or set configuration values
create     Create a custom app manifest
depends    List dependencies for an app, in the order they'll be installed
download   Download apps in the cache folder and verify hashes
export     Exports installed apps, buckets (and optionally configs) in JSON format
help       Show help for a command
hold       Hold an app to disable updates
home       Opens the app homepage
import     Imports apps, buckets and configs from a Scoopfile in JSON format
info       Display information about an app
install    Install apps
list       List installed apps
prefix     Returns the path to the specified app
reset      Reset an app to resolve conflicts
search     Search available apps
shim       Manipulate Scoop shims
status     Show status and check for new app versions
unhold     Unhold an app to enable updates
uninstall  Uninstall an app
update     Update apps, or Scoop itself
virustotal Look for app's hash or url on virustotal.com
which      Locate a shim/executable (similar to 'which' on Linux)
```

### 查询软件信息 🔎

```powershell
# 查看已安装的软件
scoop list

# 模糊搜索已安装的软件
scoop list git

# 查看某个软件的详细信息（版本、依赖、安装路径）
scoop info neovim

# 查看可执行文件位置，类似 Linux 的 which
scoop which python

# 打开软件主页
scoop home git

# 查看 manifest 内容
scoop cat openjdk17
```

### 安装进阶用法 🎯

```powershell
# 安装指定版本
scoop install gh@2.7.0

# 从 URL 安装 manifest
scoop install https://raw.githubusercontent.com/ScoopInstaller/Main/master/bucket/runat.json

# 全局安装（所有用户可用，需要管理员权限）
scoop install -g nodejs

# 不自动安装依赖
scoop install -i myapp

# 跳过 hash 校验（谨慎使用）
scoop install -s myapp

# 指定架构
scoop install -a 32bit myapp
```

### 更新与状态 📡

```powershell
# 查看哪些软件可以更新
scoop status

# 锁定某个软件不让它更新
scoop hold openjdk8

# 解锁，恢复更新
scoop unhold openjdk8

# 查看某个软件的依赖关系
scoop depends neovim
```

### shim 管理 🔗

scoop 通过 shim 把软件链接到 PATH 中，可以自定义 shim 来给任意命令加入 PATH。

```powershell
# 列出所有 shim
scoop shim list

# 查看某个 shim 的详情
scoop shim info python

# 添加自定义 shim
scoop shim add myapp 'D:\path\myapp.exe'

# 添加带参数的 shim
scoop shim add myapp 'D:\path\myapp.exe' '--' --verbose

# 切换 shim 指向（同名多版本时）
scoop shim alter python

# 移除 shim
scoop shim rm myapp
```

### 别名 🏷️

可以为常用命令创建别名，让 scoop 用起来更顺手。

```powershell
# 添加别名：用 scoop rm 代替 scoop uninstall
scoop alias add rm 'scoop uninstall $args[0]' 'Uninstall an app'

# 添加别名：一键更新所有软件
scoop alias add upgrade 'scoop update *' 'Update all apps'

# 列出所有别名
scoop alias list -v

# 删除别名
scoop alias rm rm
```

### 备份与迁移 💾

换机器或者重装系统的时候，可以一键导出导入所有软件列表。

```powershell
# 导出已安装的软件清单（包含 bucket）
scoop export > scoopfile.json

# 同时导出 scoop 的配置
scoop export -c > scoopfile.json

# 在新机器上导入
scoop import scoopfile.json
```

### 体检与安全 🩺

```powershell
# 检查 scoop 安装的潜在问题
scoop checkup

# 用 virustotal 检查软件 hash 是否安全
scoop virustotal firefox
```
