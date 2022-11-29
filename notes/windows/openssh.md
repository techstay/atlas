# openssh

## 安装

windows 系统下，在管理员权限的 powershell 终端中运行以下命令来安装。

```powershell
Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0
Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
```

### 启动服务端

使用上面方法安装的 openssh，可以直接通过服务启动服务端。

```powershell
# 需要管理员权限
Set-Service -Name sshd -StartupType 'Automatic'
Start-Service sshd
```

### 启动 ssh-agent

ssh 代理也使用类似的方法启动。

```powershell
Set-Service -Name ssh-agent -StartupType 'Automatic'
Start-Service ssh-agent
```

## 开始使用

### 命令行连接

使用 ssh 登录到远程服务器，然后按照提示输入密码。

```sh
ssh <用户名>@<服务器IP> -p <端口号>
```

退出连接可以使用`Ctrl+D`，或者使用`~.`也可以强制 ssh 客户端断开连接。

### 配置文件

通过配置文件可以简化命令。编辑`~/.ssh/config`文件，添加类似下面的内容。配置文件第一段让客户端定时发送保活信号防止连接断开，第二段配置连接信息，之后即可使用`ssh arch`来快捷登录。

```conf
Host *
    ServerAliveInterval 20
    ServerAliveCountMax 10

Host arch
    Hostname 192.168.25.133
    User techstay
    Port 22
```

### 免密码登录

通过密钥的方式来登录，无需输入密码。首先需要创建一对密钥，默认会创建到`~/.ssh/`下。

```sh
ssh-keygen -t ed25519 -C "your_email@example.com"
```

然后将公钥复制到服务器对应用户的`~/.ssh/authorized_keys`配置文件中即可。这可以通过 openssh 附带的`ssh-copy-id`命令来完成。没有`ssh-copy-id`的话，可以通过 scoop 安装带 ssh 的 git 来实现`scoop install git-with-openssh`。

```sh
ssh-copy-id arch
# 完整命令
ssh-copy-id techstay@192.168.25.133 -p 22
```

对于 windows 下的 openssh，没有`ssh-copy-id`命令，可以改用 powershell 完成同样的功能。

```powershell
Get-Content $env:USERPROFILE\.ssh\id_ed25519.pub | ssh arch "cat >> .ssh/authorized_keys"
```

配置完成后就不再需要密码了。
