---
title: "wsl"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
  - wsl
  - linux
categories:
  - Windows
---

Windows Subsystem for Linux 简称 WSL，是 Windows 下的 Linux 子系统，为我们提供了一个完整的 Linux 执行环境，让我们可以轻松地在 Windows 系统下使用 Linux 开发。也正因为这个功能，Windows 又被戏称为最好的 Linux 发行版。

## 启用 WSL

参考 <https://learn.microsoft.com/zh-cn/windows/wsl/install-manual>。注意，下面命令都需要在**管理员权限的 PowerShell** 中运行，安装完成后可能需要重启电脑。

### 一步启用 🚀

Windows 10 2004 以上版本或 Windows 11，可以用一条命令直接开启 WSL 并安装默认发行版。

```powershell
wsl --install
```

如果只想启用 WSL 功能而不安装发行版，可以加 `--no-distribution` 参数。

```powershell
wsl --install --no-distribution
```

如果提示需要安装 Linux 内核更新包，[点此安装](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)。

### 分步启用 🛠️

如果想一步一步开启 WSL，依次执行下面的命令。

```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

然后下载并安装 [适用于 x64 计算机的 WSL2 Linux 内核更新包](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)，再设置 WSL 版本号为 2。

```sh
wsl --set-default-version 2
```

## 安装发行版

### 在线发行版 📦

wsl 自带几个官方支持的发行版，可以直接安装。

```powershell
wsl --list --online
wsl --install -d <Distribution Name>

NAME                            FRIENDLY NAME
Ubuntu                          Ubuntu
Ubuntu-26.04                    Ubuntu 26.04 LTS
Ubuntu-24.04                    Ubuntu 24.04 LTS
Ubuntu-22.04                    Ubuntu 22.04 LTS
openSUSE-Tumbleweed             openSUSE Tumbleweed
openSUSE-Leap-16.0              openSUSE Leap 16.0
SUSE-Linux-Enterprise-15-SP7    SUSE Linux Enterprise 15 SP7
SUSE-Linux-Enterprise-16.0      SUSE Linux Enterprise 16.0
kali-linux                      Kali Linux Rolling
Debian                          Debian GNU/Linux
AlmaLinux-8                     AlmaLinux OS 8
AlmaLinux-9                     AlmaLinux OS 9
AlmaLinux-Kitten-10             AlmaLinux OS Kitten 10
AlmaLinux-10                    AlmaLinux OS 10
archlinux                       Arch Linux
FedoraLinux-44                  Fedora Linux 44
FedoraLinux-43                  Fedora Linux 43
eLxr                            eLxr 12.12.0.0 GNU/Linux
OracleLinux_7_9                 Oracle Linux 7.9
OracleLinux_8_10                Oracle Linux 8.10
OracleLinux_9_5                 Oracle Linux 9.5
SUSE-Linux-Enterprise-15-SP6    SUSE Linux Enterprise 15 SP6
```

### 安装 archlinux 🐧

配置参考 [[archlinux安装一条龙]]，配置完成后退出 wsl，设置 arch 的默认用户。

```powershell
Arch.exe config --default-user techstay
```

最后克隆 [dotfiles](https://github.com/techstay/dotfiles)。

### fedora 🟦

fedora 里面有些软件竟然比 Arch Linux 新，所以开发工具这块可以考虑切换。

```sh
wsl --update
wsl --install FedoraLinux-42
wsl -d FedoraLinux-42
```

配置 fedora。

```sh
sudo dnf install git zsh

git clone https://github.com/yadm-dev/yadm.git ~/.yadm-project
ln -s ~/.yadm-project/yadm ~/bin/yadm
```

## 命令速查 ⌨️

常用命令。

```sh
# 列出发行版
wsl --list --verbose
# 设置 WSL 版本 1/2
wsl --set-default-version 2
# 设置默认 WSL，可通过终端键入 wsl 进入
wsl --set-default <Distribution Name>
# 以指定用户登录 wsl
wsl --distribution <Distribution Name> --user <User Name>
# 更新 wsl
wsl --update
# 关闭所有 wsl 虚拟机
wsl --shutdown
# 停止指定 wsl 发行版
wsl --terminate <Distribution Name>
# 导出发行版
wsl --export <Distribution Name> <FileName>
# 导入发行版
wsl --import <Distribution Name> <InstallLocation> <FileName>
# 卸载发行版
wsl --unregister <DistributionName>
```

## 配置 WSL

### 更改语言 🌐

对于官方的 Ubuntu 发行版来说，默认应该会跟随 Windows 系统所使用的语言。如果不是的话，可以手动更改。

```sh
# 安装语言包
sudo apt install language-pack-zh-hans
# 设置语言
sudo update-locale LANG=zh_CN.UTF-8
```

命令执行完毕之后，重新打开 WSL 终端应该就能看到效果了。

### 美化终端 ✨

说到 Linux 就不得不提到以 ohmyzsh 为代表的的各种花里胡哨的终端配置，更进一步来说，应该创建自己的 dotfiles 项目来保存 Linux 下的各种配置文件。

```sh
# 安装必需程序
sudo apt install git zsh lua5.3 thefuck stow fd-find fzf
# 克隆 dotfiles
git clone https://github.com/techstay/dotfiles.git
# 复制配置文件
cd dotfiles
stow zim
# 默认启用 zsh 终端
chsh -s /bin/zsh
```

最后启动一次 zsh，等待环境配置结束，就可以获得一个包括代码补全、语法高亮、历史记录等功能的现代化终端体验了。

### 在 WSL 中使用 git 🔑

首先要配置凭据管理器，这样一来在 WSL 中即可共享凭据，直接提交代码，无需重复登录。

```sh
# 如果你的 git 是用 scoop 安装的
git config --global credential.helper "/mnt/c/Users/techstay/scoop/apps/git-with-openssh/current/mingw64/libexec/git-core/git-credential-manager-core.exe"
# 如果你的 git 是用安装包安装的
git config --global credential.helper "/mnt/c/Program\ Files/Git/mingw64/libexec/git-core/git-credential-manager-core.exe"
```

如果你使用 SSH 方式推送代码，并且使用了 GPG 密钥为代码签名，那么还需要共享 SSH 和 GPG 密钥。这里就采用最简单粗暴的直接复制文件的方式。

```sh
cp -R /mnt/c/Users/techstay/.ssh ~/.ssh
chmod 600 ~/.ssh/*
```

最后检测一下，如果出现了欢迎语就说明 SSH 密钥已经设置成功了。

```sh
ssh -T git@github.com
```

接下来需要复制 GPG 密钥。先查看要复制的密钥 keyid。

```sh
gpg --list-secret-keys --keyid-format=0xlong
```

然后导出密钥和信任信息。

```sh
gpg -o private.gpg --export-options backup --export-secret-keys <key-id>
gpg --export-ownertrust > trust.txt
```

再切换到 WSL 终端，导入密钥和信任信息。

```sh
gpg --import-options restore --import private.gpg
gpg --import-ownertrust < trust.txt
```

最后在 git 中设置签名。

```sh
git config --global commit.gpgsign true
git config --global user.signingkey <key-id>
```

### 设置内存 💾

wsl 默认会占用系统一半的内存，如果电脑内存小于 32G 的话，很有可能会被吃掉大量内存，影响正常使用。这时候就需要调整 WSL 使用的内存，编辑 `$HOME/.wslconfig` 配置文件。

```conf
[wsl2]
memory=4GB
nestedVirtualization=false
```

### 配置 docker 🐳

既然都使用了 WSL，那么也顺便安装 [Docker Desktop for Windows](https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe) 吧。

安装之后在 Docker Desktop 的设置里面找到 WSL 集成，勾选已安装的 WSL，这样一来就启用了 Docker 集成功能。无需在 WSL 中安装 docker，就可以使用 docker 命令，也能使用 Docker Desktop 这个图形化界面程序来管理 docker。

### 设定动态端口号范围 🔌

开启 wsl 之后，会同时启用 HyperV，启用 HyperV 会导致 Windows 系统将 tcp 动态端口号范围的起始端口号重置为 1024，这会导致大量常用的端口号有一定几率无法使用，表现为端口号被占用，但是在 tcpview 等网络监视工具中又找不到占用端口号的程序。

首先查看动态端口号的分配情况。

```powershell
Get-NetTCPSetting|select SettingName, DynamicPortRange*
```

如果起始端口号是 1024，那么就需要重新设定一次动态端口号范围。

```powershell
Set-NetTCPSetting -DynamicPortRangeStartPort 40000 -DynamicPortRangeNumberOfPorts 10000
```

## 互操作 🔄

### 网络交互 🌐

WSL 中的网络连接会被转发到宿主机本地回环地址，所以可以直接用 `localhost:80` 访问 WSL 开启的 80 端口标准 web 程序。

反过来则需要用宿主机的 IP 地址来访问，例如本地开启了 8080 端口号，那么在 WSL 中需要用 `192.168.1.123:8080` 来访问。

### 文件交互 📁

WSL 可以直接访问宿主机中的文件，宿主机的文件会以 `/mnt/c/XXX` 的形式挂载到 WSL 中。

反过来也可以在宿主机中访问 WSL 中的文件夹，WSL 的文件系统会被映射为网络地址的形式，访问路径为 `\\wsl$\Ubuntu`。

虽然可以比较方便地进行文件交互操作，但是仍然有不小的性能损失。如果要用 WSL 完成一些重要的任务，最好直接在 WSL 的文件系统上工作。
