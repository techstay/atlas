# Vmware Workstation 安装

先下载安装包，然后用下面的序列号激活。

<https://www.vmware.com/products/workstation-pro/workstation-pro-evaluation.html>

| 版本 | 序列号                        |
| ---- | ----------------------------- |
| 16   | ZF3R0-FHED2-M80TY-8QYGC-NPKYF |
| 17   | MC60H-DWHD5-H80U9-6V85M-8280D |

## vmware 开机启动

vmware workstation 17 现在新增了自动后台启动虚拟机的功能，无需自己创建计划任务或者使用其他方法，直接在菜单栏中点击*文件->配置自动启动虚拟机*即可。

还需要启动 Vmware 自动启动服务。默认以本地系统账上启动服务，会导致 vmware 无法正常获取虚拟机状态，需要手动在*服务*程序中将该服务的登录身份改为当前用户的账户(需要输入用户名和密码)。

```sh
sudo Set-Service VmwareAutostartService -StartupType Automatic
```

::: warning
遇到*无法更新自动启动配置，请确保存在 vmAutoStart.xml 文件，并且您有权写入此文件。*的错误时，在文件管理器找到`%ALLUSERSPROFILE%\VMware\VMware Workstation\vmAutoStart.xml`文件，右键选择*属性->安全*，为当前用户添加此文件的完全控制权限，就能设置自启动了。

或者也可以在管理员权限的 powershell 中执行以下命令。

```powershell
$filePath = "$env:ALLUSERSPROFILE/Vmware/Vmware Workstation/vmAutoStart.xml"
$aclObject = Get-Acl -Path $filePath
$identity = [System.Security.Principal.WindowsIdentity]::GetCurrent().Name
$fileSystemRights = 'FullControl'
$type = 'Allow'
$fileSystemAccessRuleArgumentList = $identity, $fileSystemRights, $type
$fileSystemAccessRule = New-Object -TypeName System.Security.AccessControl.FileSystemAccessRule `
  -ArgumentList $fileSystemAccessRuleArgumentList
$aclObject.SetAccessRule($fileSystemAccessRule)
Set-Acl -Path $filePath -AclObject $aclObject
```

:::
