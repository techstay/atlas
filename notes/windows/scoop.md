# scoop

一个 windows 下的包管理器。

## 安装

```powershell
# 首先设置允许运行远程脚本
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser

# 然后安装scoop
Invoke-Expression (New-Object System.Net.WebClient).DownloadString('https://get.scoop.sh')
```

如果要将 scoop 安装到其他位置，则需要先设置`SCOOP`环境变量，然后再安装。

```powershell
$env:SCOOP = 'C:\scoop'
[environment]::setEnvironmentVariable('SCOOP', $env:SCOOP, 'User')
Invoke-WebRequest -useb get.scoop.sh | Invoke-Expression
```

## 配置

### 添加 bucket

bucket 是 scoop 的软件类别仓库，可以由`scoop bucket known`查看。一般不需要全部添加，只添加几个常用的即可。

```sh
# bucket依赖git，所以需要先安装git
scoop install git-with-openssh

scoop bucket add extras
scoop bucket add nerd-fonts
scoop bucket add java
```

### 设置代理

scoop 默认下载速度比较慢，因为大部分资源都在国外，如果有代理的话，可以设置加速。

```sh
# 添加代理
scoop config proxy localhost:7890

# 删除代理
scop config rm proxy
```

### 多连接下载

安装 aria2 即可自动启用多连接下载。

```sh
scoop install aria2
```

如果下载遇到问题，可以关闭 aria2 下载。

```sh
scoop config aria2-enabled false
```

## 使用

先搜索要安装的软件名字，然后安装。

```powershell
scoop search openjdk17
scoop install openjdk17
```

更新软件包。

```powershell
# 更新 scoop 自己
scoop update scoop
# 更新所有软件
scoop update *
```

如果同时安装了一个软件的多个版本，可以设置要使用的那个。这里假设同时安装了 jdk8 和 jdk17。

```powershell
# 使用openjdk8
scoop reset openjdk8

# 使用openjdk17
scoop reset openjdk17
```

卸载和清理。

```powershell
# 卸载不需要的软件
scoop uninstall openjdk17

# 清理软件的旧版本
scoop cleanup *

# 清理软件的下载缓存
scoop cache rm *
```

要查看 scoop 命令行，直接运行`scoop`命令。

```sh
$ scoop
Usage: scoop <command> [<args>]

Some useful commands are:

alias       Manage scoop aliases
bucket      Manage Scoop buckets
cache       Show or clear the download cache
cat         Show content of specified manifest. If available, `bat` will be used to pretty-print the JSO
            N.
checkup     Check for potential problems
cleanup     Cleanup apps by removing old versions
config      Get or set configuration values
create      Create a custom app manifest
depends     List dependencies for an app
download    Download apps in the cache folder and verify hashes
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
shim        Manipulate Scoop shims
status      Show status and check for new app versions
unhold      Unhold an app to enable updates
uninstall   Uninstall an app
update      Update apps, or Scoop itself
virustotal  Look for app's hash on virustotal.com
which       Locate a shim/executable (similar to 'which' on Linux)

Type 'scoop help <command>' to get help for a specific command.
```
