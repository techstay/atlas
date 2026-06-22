---
title: "虚拟机"
date: 2026-05-15T01:18:06+08:00
tags:
  - software
  - virtual-machine
categories:
  - 软件
---

# 🖥️ 虚拟机

## VMware Workstation

VMware Workstation Pro 已对个人用户免费，无需激活码即可使用 🎉

[VMware Workstation Pro 官方下载](https://www.vmware.com/products/workstation-pro/workstation-pro-evaluation.html)

### 开机自启 🚀

VMware Workstation 17 新增了自动后台启动虚拟机的功能。

需要配置 VMware 自动启动服务。默认以本地系统账户启动服务，会导致 VMware 无法正常获取虚拟机状态，需要手动在*服务*程序中将该服务的登录身份改为当前用户的账户（需要输入用户名和密码）。

```sh
sudo Set-Service VmwareAutostartService -StartupType Automatic
```

遇到*无法更新自动启动配置，请确保存在 vmAutoStart.xml 文件，并且您有权写入此文件*的错误时，在文件管理器找到 `%ALLUSERSPROFILE%\VMware\VMware Workstation\vmAutoStart.xml` 文件，右键选择*属性 -> 安全*，为当前用户添加此文件的完全控制权限，就能设置自启动了。

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

### 故障排查 🔧

VMware 下桥接的虚拟机（如 OpenWrt）偶尔无法连接网络，这是由于桥接模式设置为「自动」，导致 VMware Workstation 可能桥接到错误的网络适配器上。解决方法如下：打开网络编辑器，找到桥接网络，在右侧下拉菜单中选择合适的网络适配器（如以太网）。设置完成后，网络即可恢复正常。

## VirtualBox

### 开机自启 🚀

先创建 `C:\Users\asddf\.VirtualBox\autostart.properties` 文件，最后的空行必须有：

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
