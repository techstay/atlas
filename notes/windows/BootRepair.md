# windows 系统引导修复

这里介绍 bcdboot、bcdedit 等几个工具，协助配置 windows 的引导项。

## 开始使用

### 查询 bcd

在管理 bcd 之前，需要先了解一下 bcd（Boot Configuration Data） 里面有什么。通过下面的命令可以查询所有 bcd：

```powershell
bcdedit /enum ALL
```

可以看到系统中有很多引导项目。当然，一般情况下只需要会在启动菜单里显示的那几个。

```powershell
bcdedit /enum ACTIVE
```

### 访问 ESP

要管理 ESP 需要指定 EFI 文件的路径，然而在 Windows 系统中不能直接查看 ESP，需要一点技巧。接下来需要在管理员权限的 powershell 终端中执行一些命令。

```powershell
# 查看所有分区
Get-Partition
# 找到ESP
Get-Partition | Where-Object -Property Type -eq system | Select-Object -Property DiskNumber, PartitionNumber, DriveLetter, Size, Type
# 为ESP分配一个未使用的盘符
Add-PartitionAccessPath -DiskNumber 3 -PartitionNumber 1 -AccessPath k:
# 如果只有一个ESP的话还可以把这些命令连接起来
Get-Partition | Where-Object -Property Type -eq system | Add-PartitionAccessPath -AccessPath k:
# 最后别忘了清除盘符，恢复ESP的状态
Remove-PartitionAccessPath -DiskNumber 3 -PartitionNumber 1 -AccessPath k:
```

不过由于微软限制，就算分配了盘符也无法使用文件资源管理器来访问，只能使用第三方的文件管理器并用管理员权限打开来实现。这里推荐使用 onecommander。

```powershell
scoop install onecommander
```

或者也可以直接在管理员权限的 powershell 中使用 tree 命令查看目录内容。

```powershell
tree /f k:

K:\
└─EFI
    ├─boot
    │      bootx64.efi
    │
    ├─Microsoft
    │  ├─Boot
    │  │  │  winsipolicy.p7b
    │  │  │  bootmgfw.efi
    │  │  │  bootmgr.efi
    │  │  │
    │  │  └─CIPolicies
    │  │      └─Active
    │  │
    │  └─Recovery
    │          BCD
    │
    └─Garuda
            grubx64.efi
```

### 修复 bcd

如果现在的系统启动项有问题，可以使用 bcdboot 工具来修复。

```powershell
bcdboot C:\Windows\ /l zh-CN /s K: /f ALL
```

修复完成之后再次查看 bcd，应该就能看到正常的 bcd 了。

```powershell
bcdedit /enum ACTIVE
```

### 修复 grub 引导

更新 bios 之后，不知道什么原因我双系统的 grub 引导消失不见，只剩下了 windows boot manager 的引导项。以往遇到这种情况只需要用 live usb 系统 chroot 进 linux，然后更新一下 grub 就可以了，但是这次居然没有生效。

所以无奈之下只好采用另外一种曲线救国的方式，直接在 windows 引导项里指定 grub 引导。例如我使用的 garuda 的引导文件路径为`\EFI\Garuda\grubx64.efi`，那么就这样修改 bootmgr 的配置。

```powershell
# 在cmd中
bcdedit /set {bootmgr} description 'grub bootloader'
bcdedit /set {bootmgr} path \EFI\Garuda\grubx64.efi
# 在powershell中需要引号
bcdedit /set "{bootmgr}" description 'grub bootloader'
bcdedit /set "{bootmgr}" path \EFI\Garuda\grubx64.efi
```

如果要恢复 windows boot manager 的默认配置，只需要还原一下即可。

```powershell
bcdedit /set "{bootmgr}" description 'Windows Boot Manager'
bcdedit /set "{bootmgr}" path \EFI\Microsoft\Boot\bootmgfw.efi
```
