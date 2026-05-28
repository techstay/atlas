---
title: "Ssh快速入门"
date: 2022-02-04T15:11:45+08:00
tags:
  - linux
categories:
  - linux
---

Secure Shell Protocol (SSH) 是一个加密的网络协议，帮助用户安全的登录到系统。这里简单介绍一下 SSH 的使用方法。

## 安装 SSH

linux 系统直接从软件仓库中安装即可。

```sh
# Arch
sudo pacman -S openssh

# Ubuntu
sudo apt install openssh
```

windows 系统下要安装 SSH 客户端，最简单的办法就是安装 [Git for Windows](https://git-scm.com/download/win)，自带的终端包含 SSH 命令，使用起来最方便。

## 开启 SSH 服务

云服务的 Linux 主机，一般都默认开启了 SSH 服务，可以直接连接。如果是自己的 Linux 主机，那么可能需要自行开启 SSH 服务。开启方法也很简单，启用 systemd 服务即可。

```sh
sudo systemctl enable sshd
```

如果要配置 SSH 的服务器设置，编辑 `/etc/ssh/sshd_config`。

对于 windows 系统，也可以安装 SSH 服务器。

```pwsh
# 安装SSH
Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0

# 开启服务
Start-Service sshd

# 自启服务
Set-Service -Name sshd -StartupType 'Automatic'
```

## SSH 登录

接下来就可以利用 SSH 登录了。SSH 的基本登录命令为：

```sh
ssh <用户名>@<服务器IP> -p <端口号>
```

当然每次都要输入这么长的命令很麻烦，所以还可以用配置文件来简化。

### 登录配置文件

编辑 `~/.ssh/config`，添加类似下面的内容。第一段的内容针对所有连接，作用就是保证 SSH 连接存活。第二段的内容就是具体的连接配置，需要设置的就是每次要输入的用户名、服务器地址和端口号。

```txt
Host *
    ServerAliveInterval 20
    ServerAliveCountMax 10

Host manjaro
    Hostname 192.168.25.131
    User techstay
    Port 22
```

配置完成之后，SSH 连接命令就可以简化，直接输入命令就可以连接了。

```sh
ssh manjaro
```

### SSH 代理

如果你为 SSH 密钥配置了密码短语，那么每次使用 SSH 的时候都必须输入一遍，这很麻烦。如果你使用 SSH 代理的话，它会自动帮你缓存密码，后续就不用再输入一遍了。在 windows 系统上如果安装了系统版的 SSH，应该附带了对应的 SSH 代理服务，直接让它开机自启即可。

```sh
Set-Service ssh-agent -StartupType AutomaticDelayedStart
```

然后需要检查一下密钥是不是已经在代理里加载了。

```sh
# 列出当前加载的密钥
ssh-add -l

# 如果没有加载，需要手动加载
ssh-add ~/.ssh/id_ed25519
```

SSH 代理除了会帮助你记住密码之外，还能管理多个密钥。所以强烈建议你启用这个功能。

### 公钥免密码登录

就算设置了上面的方法，每次登录还是要输入密码。虽然这可以用一些带有密码保存功能的 SSH 软件来解决，不过更好的办法就是配置 SSH 公钥登录，不仅无需密码，同时也更加安全。

首先在客户端需要生成一对 SSH 密钥，`-C` 参数是注释，可以是任何字符串，不过最好设置成电邮等有意义的内容，方便确认。

```sh
ssh-keygen -t ed25519 -C "your_email@example.com"
```

设置完成后，在 `~/.ssh/` 目录下应该已经有了一对 SSH 密钥。不过这还没有完，还需要把公钥上传到服务器，才能实现免密码登录。使用下面的命令就可以完成这一工作。如果你已经在 `~/.ssh/config` 添加了登录配置，也可以直接使用名字连接。这个命令会将公钥复制到服务器的 `~/.ssh/authorized_keys` 里面，这样以后就能免密登录了，你也可以手动完成这一工作。

```sh
ssh-copy-id <用户名>@<服务器IP> -p <端口号>
```

`ssh-copy-id` 只在 Git 终端中才有，没有这个命令的话，也可以用等效的 powershell 命令代替。

```pwsh
Get-Content $env:USERPROFILE\.ssh\id_ed25519.pub | ssh {IP-ADDRESS-OR-FQDN} "cat >> .ssh/authorized_keys"
```

一切准备就绪之后，你应该可以直接用 `ssh <连接名>` 来登录 SSH 服务器了。

### Windows Terminal 配置

如果你在 Windows 上使用 Windows Terminal 作为终端软件，还可以把 SSH 配置的更简单一点。编辑 WT 的 JSON 配置文件，添加类似下面的内容，这样下次直接打开标签页的时候就会自动用 SSH 登录了。

```json
"profiles": {
    "list": [
        {
            "guid": "{ba61291b-4799-4948-9c87-05cd254a182f}",
            "name": "manjaro",
            "commandline": "ssh manjaro"
        }
    ]
},
```
