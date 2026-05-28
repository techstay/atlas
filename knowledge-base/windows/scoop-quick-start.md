---
title: "Scoop快速入门"
date: 2022-02-06T18:08:14+08:00
tags:
  - scoop
  - windows
categories:
  - dev
---

[scoop](https://scoop.sh) 是一个 windows 下的软件包管理器，无需管理员权限，将软件全部安装到用户文件夹下，方便管理。我一直在使用这个，安装一些命令行软件非常方便。

## 安装 scoop

打开 Powershell 窗口，运行下面的命令。

```powershell
# 首先设置允许运行远程脚本
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser

# 然后安装scoop
Invoke-Expression (New-Object System.Net.WebClient).DownloadString('https://get.scoop.sh')

# 如果要将scoop安装到其他位置
$env:SCOOP = 'C:\scoop'
[environment]::setEnvironmentVariable('SCOOP', $env:SCOOP, 'User')
Invoke-WebRequest -useb get.scoop.sh | Invoke-Expression
```

## 配置 scoop

### 添加 bucket

自带下面几个 bucket。

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

- main，自带的软件仓库
- extras，一些额外的带有图形界面软件的仓库
- versions，包含一些编程语言和类库的各种版本的仓库
- nirsoft，包含 nirsoft 软件的仓库
- php，各种 php 的仓库
- nerd-fonts，包含各种 nerd-fonts 字体
- nonportable，包含各种非绿色版软件的仓库
- java，各种 java 版本都有的仓库
- games，一些游戏和相关工具的仓库

我会启用 extra、nerd-fonts 和 java 这三个 bucket。

```powershell
scoop bucket add extra
scoop bucket add nerd-fonts
scoop bucket add java
```

### 使用代理

scoop 默认下载比较慢，如果你有代理的话，可以为 scoop 设置代理，加速软件的下载。

```powershell
scoop config proxy username:password@proxy.example.org:8080

# 例
scoop config proxy localhost:8080

# 删除代理配置
scop config rm proxy
```

### 多连接下载

scoop 也支持多连接下载，只需要安装 aria2，scoop 就会自动利用 aria2 来进行多连接下载。

```powershell
scoop install aria2
```

关于下载的其他说明，参见 [官方文档](https://github.com/ScoopInstaller/Scoop#multi-connection-downloads-with-aria2)。

## 使用 scoop

### 安装和卸载

首先需要搜索软件包的名称，然后就可以安装。

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

### 更新

更新 scoop 自己。

```powershell
scoop update scoop
```

更新所有软件。

```powershell
scoop update *
```

### 管理多版本

比如我现在已经安装了 openjdk8 和 openjdk17，就可以用 scoop 来轻松设置命令行，设置完成后终端的命令就会使用对应的版本。

```powershell
# 使用openjdk8
scoop reset openjdk8

# 使用openjdk17
scoop reset openjdk17
```

### 清理

scoop 更新软件的时候会保留几个旧版本，假如你不再需要这些旧版本，可以把他们清理掉。顺便也可以把下载缓存清理掉。

```powershell
# 清理软件的旧版本
scoop cleanup *

# 清理软件的下载缓存
scoop cache rm *
```

## scoop 命令行

```powershell
$ scoop
Usage: scoop <command> [<args>]

Some useful commands are:

alias       Manage scoop aliases
bucket      Manage Scoop buckets
cache       Show or clear the download cache
cat         Show content of specified manifest.
checkup     Check for potential problems
cleanup     Cleanup apps by removing old versions
config      Get or set configuration values
create      Create a custom app manifest
depends     List dependencies for an app
export      Exports (an importable) list of installed apps
help        Show help for a command
hold        Hold an app to disable updates
home        Opens the app homepage
info        Display information about an app
install     Install apps
list        List installed apps
prefix      Returns the path to the specified app
reset       Reset an app to resolve conflicts
search      Search available apps
status      Show status and check for new app versions
unhold      Unhold an app to enable updates
uninstall   Uninstall an app
update      Update apps, or Scoop itself
virustotal  Look for app's hash on virustotal.com
which       Locate a shim/executable (similar to 'which' on Linux)

Type 'scoop help <command>' to get help for a specific command.
```
