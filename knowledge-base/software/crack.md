---
title: "crack"
date: 2026-05-15T01:18:06+08:00
tags:
  - software
  - crack
categories:
  - 软件
---

## Adobe

~~到微博关注 [vposy](https://weibo.com/vposy)，然后查看置顶链接，里面有网盘的下载地址，通过网盘下载即可。~~

[genp破解补丁](https://www.osssr.com/6091.html)，用 Adobe Creative Cloud 安装正版软件，然后用这个破解。

访问 [monkrus](https://w17.monkrus.ws/)，然后在网页上找到下载链接，优先选择 UNIONDHT 或 UZTRACKER，无需登录就可以下载 BT 种子。

## Mathematica

参考 [这篇文章](https://github.com/TieBaMma/InstallTutorial/blob/gh-pages/index.md)，后续有更新的话直接查看原文。

### 激活软件

安装完成后，打开软件，显示激活页面，选择手动激活，记录 ID。

然后到 [在线注册机](https://ibug.io/blog/2019/05/mathematica-keygen/) 中输入刚才的 ID，点击生成，将获取到的密钥和密码填入 Mathematica 中，即可完成激活。

## Microsoft Office

参考 [这篇文章](https://www.mdnice.com/writing/3d7c02c3ac474a25987e829ea263e6ca)

## Sublime Merge

linux 参考 <https://gist.github.com/rufoa/78e45d70f560f53678853c92dae2598a>

windows 下载文件，解压，然后使用破解版文件覆盖原程序即可。

- 下载地址 <https://downloaddevtools.com/en/product/2276/free-download-sublime-merge>
- 解压密码 `DownloadDevTools.ir`
- 使用随便一个许可证 (例如下面的) 即可激活。

```txt
----- BEGIN LICENSE -----
TEAM RUFIO
Unlimited User License
E52D-666666
487EE6F0309908F702DDD52AFCD99A6A
6EE14CF8A2D42271B4FC0991BBF93ADC
FAA9075C436B3796669194A2F36CAAEF
B251155329EC2E434FD28B4A21BE68CC
955D306EE9ED843C5E98B1577D02DEAA
1F4E872AE6495CD5E3B1DA55D5ACD2B2
2EA4110FB800F21AA3EC2E3902589BCF
7281A19C2DFF0CEE4AEA5DDD1E6DF893
----- END LICENSE -----
```

## Visual Studio 2026

企业版密钥 `VHF9H-NXBBB-638P6-6JHCY-88JWH`

## VMware Workstation

已经个人免费了，再也不用激活码了。

<https://www.vmware.com/products/workstation-pro/workstation-pro-evaluation.html>

### 开机自启

vmware workstation 17 现在新增了自动后台启动虚拟机的功能。

需要配置 Vmware 自动启动服务。默认以本地系统账户启动服务，会导致 vmware 无法正常获取虚拟机状态，需要手动在*服务*程序中将该服务的登录身份改为当前用户的账户 (需要输入用户名和密码)。

```sh
sudo Set-Service VmwareAutostartService -StartupType Automatic
```

遇到*无法更新自动启动配置，请确保存在 vmAutoStart.xml 文件，并且您有权写入此文件* 的错误时，在文件管理器找到 `%ALLUSERSPROFILE%\VMware\VMware Workstation\vmAutoStart.xml` 文件，右键选择 _属性 ->安全_，为当前用户添加此文件的完全控制权限，就能设置自启动了。

或者用命令行方式添加权限（需要管理员权限）。

```powershell
$filePath = "$env:ALLUSERSPROFILE/Vmware/Vmware Workstation/vmAutoStart.xml"
$aclObject = Get-Acl -Path $filePath -Audit:$false
$identity = [System.Security.Principal.WindowsIdentity]::GetCurrent().Name
$fileSystemRights = 'FullControl'
$type = 'Allow'
$fileSystemAccessRuleArgumentList = $identity, $fileSystemRights, $type
$fileSystemAccessRule = New-Object -TypeName System.Security.AccessControl.FileSystemAccessRule `
  -ArgumentList $fileSystemAccessRuleArgumentList
$aclObject.SetAccessRule($fileSystemAccessRule)
Set-Acl -Path $filePath -AclObject $aclObject
```

### VirtualBox 开机自启

没地方了就写到这里吧。先创建 `C:\Users\asddf\.VirtualBox\autostart.properties` 文件，最后的空行必须有：

```config
# Default policy is to deny starting a VM, the other option is "allow".
default_policy = deny

techs = {
    allow = true
    startup_delay = 5
}

```

然后添加环境变量：

```powershell
[System.Environment]::SetEnvironmentVariable("VBOXAUTOSTART_CONFIG", "C:\Users\techs\.VirtualBox\autostart.properties", [System.EnvironmentVariableTarget]::User)
```

最后运行命令：

```powershell
cd "C:\Program Files\Oracle\VirtualBox"
.\VBoxAutostartSvc.exe install --user=asddf
.\VBoxManage.exe modifyvm "OpenWrt" --autostart-enabled on
```
