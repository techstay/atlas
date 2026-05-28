---
title: "Windows Subsystem for Linux快速入门"
date: 2022-02-20T01:05:40+08:00
tags:
  - wsl
  - linux
  - windows
categories:
  - windows
---

Windows Subsystem for Linux 简称 WSL，也即 Windows 下的 Linux 子系统，这个功能为我们提供了一个完整的 Linux 执行环境，让我们可以轻松的在 Windows 系统下使用 Linux 开发。也正因为这个功能，Windows 又被戏称为最好的 Linux 发行版。

## 启用 WSL

注意，下面这些命令都需要在管理员权限的 powershell 中运行。

### 开启 WSL

如果你的系统是 Windows 10 2004 以上版本或者 Windows 11，那么就可以用下面一条命令直接开启 WSL 功能并安装默认的 Ubuntu 发行版。命令运行完毕之后需要重启计算机。

```powershell
wsl --install
```

如果你想一步一步开启 WSL 的话，那么就依次执行下面的命令。首先要启用几个 Windows 的功能。

```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

然后下载并安装 [适用于 x64 计算机的 WSL2 Linux 内核更新包](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)。

然后设置 WSL 的版本号为 2。

```sh
wsl --set-default-version 2
```

### 安装 WSL 发行版

接下来就可以在 [应用商店](https://aka.ms/wslstore) 中搜索和安装 WSL 发行版了。或者如果你不想用应用商店，也可以通过命令行的方式来安装 WSL 发行版。

首先搜索可以在线下载的发行版。

```sh
$ wsl --list --online
以下是可安装的有效分发的列表。
请使用“wsl --install -d <分发>”安装。

NAME            FRIENDLY NAME
Ubuntu          Ubuntu
Debian          Debian GNU/Linux
kali-linux      Kali Linux Rolling
openSUSE-42     openSUSE Leap 42
SLES-12         SUSE Linux Enterprise Server v12
Ubuntu-16.04    Ubuntu 16.04 LTS
Ubuntu-18.04    Ubuntu 18.04 LTS
Ubuntu-20.04    Ubuntu 20.04 LTS
```

之后就可以通过名字安装了。

```sh
wsl --install -d Ubuntu
```

如果这些发行版仍然不能满足你的话，也可以自己手动安装其他发行版。

## 配置 WSL

### 更改语言

对于官方的 Ubuntu 发行版来说，默认应该会跟随 Windows 系统所使用的语言。如果不是的话，你可以手动更改系统语言。命令执行完毕之后，重新打开 WSL 终端应该就能看到效果了。

```sh
# 安装语言包
sudo apt install language-pack-zh-hans
# 设置语言
sudo update-locale LANG=zh_CN.UTF-8
```

### 美化终端

说到 Linux 就不得不提到以 ohmyzsh 为代表的的各种花里胡哨的终端配置，更进一步来说，你应该创建自己的 dotfiles 项目来保存 Linux 下的各种配置文件。以我自己的 dotfiles 为例：

```sh
# 安装必需程序
sudo apt install git zsh lua5.3 thefuck stow fd-find fzf
# 克隆dotfiles
git clone https://github.com/techstay/dotfiles.git
# 复制配置文件
cd dotfiles
stow zim
# 默认启用zsh终端
chsh -s /bin/zsh
```

最后启动一次 zsh，等待环境配置结束，就可以获得一个包括代码补全、语法高亮、历史记录等多种多样功能的现代化终端体验了。

### 调整 WSL 内存

默认情况下 WSL 会使用最多一半的系统内存，假如你的电脑内存小于 32G 的话，很有可能会被吃掉大量内存，影响正常使用。所以这时候就需要调整 WSL 使用的内存了。

```powershell
code $HOME/.wslconfig
```

编辑文件内容，设置内存上限。

```conf
[wsl2]
memory=4GB
nestedVirtualization=false
```

### 在 WSL 中使用 git

首先要配置凭据管理器，这样一来在 WSL 中即可共享凭据，直接提交代码，无需重复登录。

```sh
# 如果你的git是用scoop安装的
git config --global credential.helper "/mnt/c/Users/techstay/scoop/apps/git-with-openssh/current/mingw64/libexec/git-core/git-credential-manager-core.exe"
# 如果你的git是用安装包安装的
git config --global credential.helper "/mnt/c/Program\ Files/Git/mingw64/libexec/git-core/git-credential-manager-core.exe"
```

如果你使用 SSH 方式推送代码，并且使用了 GPG 密钥为代码签名，那么还需要共享 SSH 和 GPG 密钥。这里就采用最简单粗暴的直接复制文件的方式。

```sh
cp -R /mnt/c/Users/techstay/.ssh ~/.ssh
chmod 600 ~/.ssh/*
```

最后检测一下，如果出现了那么就说明 SSH 密钥已经设置成功了。

```sh
ssh -T git@github.com
```

接下来需要复制 GPG 密钥。首先先查看要复制的密钥 keyid。

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

### 配置 docker

既然都使用了 WSL，那么也顺便安装 [Docker Desktop for Windows](https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe) 吧。

安装之后在 Docker Desktop 的设置里面找到 WSL 集成，找到安装好的 WSL 打上勾，这样一来就启用了 Docker 集成功能。无需在 WSL 中安装 docker，就可以使用 docker 命令，也能使用 Docker Desktop 这个图形化界面程序来管理 docker，可以说是两全其美。

### 重新设定动态端口号范围

启用 WSL 以后，会同时启用 HyperV，而启用 HyperV 会导致 Windows 系统将 tcp 动态端口号范围的起始端口号重置为 1024，这会导致大量常用的端口号有一定几率无法使用，表现为端口号被占用，但是在 tcpview 等网络监视工具中又找不到占用端口号的程序，简直像见了鬼一样。

首先需要打开管理员权限的 powershell 窗口，查看动态端口号的分配情况。

```powershell
Get-NetTCPSetting|select SettingName, DynamicPortRange*
```

如果起始端口号是 1024，那么就需要修改起始范围。

```powershell
Set-NetTCPSetting -DynamicPortRangeStartPort 40000 -DynamicPortRangeNumberOfPorts 10000
```

## 互操作

### 网络交互

WSL 中的网络连接会被转发到宿主机本地会换地址，所以可以直接用 `localhost:80` 访问 WSL 开启的 80 端口标准 web 程序。

反过来则需要用宿主机的 IP 地址来访问，例如本地开启了 8080 端口号，那么在 WSL 中需要用 `192.168.1.123:8080` 来访问。

### 文件交互

WSL 可以直接访问宿主机中的文件，宿主机的文件会以 `/mnt/c/XXXx` 的形式挂载到 WSL 中。

反过来也可以在宿主机中访问 WSL 中的文件夹，WSL 的文件系统会被映射为网络地址的形式，访问路径为 `\\wsl$\Ubuntu`。

当然，虽然可以比较方便的进行文件交互操作，但是仍然有不小的性能损失。如果如果要用 WSL 完成一些重要的任务，最好直接在 WSL 的文件系统上工作。
