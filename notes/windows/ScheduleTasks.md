# 计划任务

## schtasks

Windows 命令行 schtasks，文档<https://learn.microsoft.com/zh-cn/windows-server/administration/windows-commands/schtasks>

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

## scheduledtasks

powershell 模块 scheduledtasks，用途更加通用。

<https://learn.microsoft.com/en-us/powershell/module/scheduledtasks/>

## scheduledjobs

计划任务 powershell 命令行，可以在计划任务 GUI 程序中管理，文档<https://learn.microsoft.com/en-us/powershell/module/psscheduledjob/about/about_scheduled_jobs>
