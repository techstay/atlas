# 计划任务

## schtasks

Windows 命令行 schtasks，文档可参考下面链接

- <https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/schtasks-create>
- <https://www.yumefx.com/?p=2991>

### 创建计划任务

命令行：

```cmd
schtasks /create /sc <scheduletype> /tn <taskname> /tr <taskrun> [/s <computer> [/u [<domain>\]<user> [/p <password>]]] [/ru {[<domain>\]<user> | system}] [/rp <password>] [/mo <modifier>] [/d <day>[,<day>...] | *] [/m <month>[,<month>...]] [/i <idletime>] [/st <starttime>] [/ri <interval>] [/rl <level>] [{/et <endtime> | /du <duration>} [/k]] [/sd <startdate>] [/ed <enddate>] [/it] [/np] [/z] [/f]
```

举例，创建一个在用户登录时以管理员权限运行的 keepassxc 计划任务。

```cmd
schtasks /create /tn keepassxc /tr $HOME\scoop\apps\keepassxc\current\KeePassXC.exe /sc ONLOGON /rl HIGHEST
```

### 测试运行

创建以后可以立即测试一下，看看能不能运行。

```cmd
schtasks /run /tn keepassxc
```

### 静默运行

默认情况下，运行命令行程序会显示黑框界面，可以改用 SYSTEM 账户运行，这样就完全不会有提示。下面就是一个简单的例子。

```powershell
$desktop_path = [Environment]::GetFolderPath('Desktop')
$cmd = "cmd /c `"echo 666 >> $desktop_path\log.txt`""
schtasks /create /sc DAILY /mo 1 /tn 'simpletest' /tr $cmd /ru SYSTEM /f

# 测试完成后记得删除计划任务
schtasks /delete /tn 'simpletest' /f
```

## scheduledtasks

powershell 模块 scheduledtasks，用途更加通用。

<https://learn.microsoft.com/en-us/powershell/module/scheduledtasks/>

## scheduledjobs

计划任务 powershell 命令行，可以在计划任务 GUI 程序中管理，文档<https://learn.microsoft.com/en-us/powershell/module/psscheduledjob/about/about_scheduled_jobs>
