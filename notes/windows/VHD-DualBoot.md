# VHD 双系统安装笔记

之前写过利用 dism++和 easybcd 工具的 VHD 双系统安装教程，不过利用了第三方工具，比较麻烦。这次返璞归真，直接使用 windows 自带的工具完成同样的功能。

## 准备工作

准备一个全新的 win10 或 win11 镜像。

## 配置 VHD

打开磁盘管理，在里面创建一块新的 VHD 磁盘，创建完成后进行初始化和格式化操作，并为其分配一个盘符。

## 安装镜像

双击下载好的 ISO 文件，系统会自动挂载镜像。然后在镜像里面找到`X:\sources\install.wim`文件，查看其中的安装镜像，记好这里的编号。

```powershell
Get-WindowsImage -ImagePath I:\sources\install.wim

ImageIndex       : 1
ImageName        : Windows 11 教育版
ImageDescription : Windows 11 教育版
ImageSize        : 16,882,042,626 bytes

ImageIndex       : 2
ImageName        : Windows 11 企业版
ImageDescription : Windows 11 企业版
ImageSize        : 16,882,164,641 bytes

ImageIndex       : 3
ImageName        : Windows 11 专业版
ImageDescription : Windows 11 专业版
ImageSize        : 16,878,635,478 bytes

ImageIndex       : 4
ImageName        : Windows 11 专业教育版
ImageDescription : Windows 11 专业教育版
ImageSize        : 16,881,993,836 bytes

ImageIndex       : 5
ImageName        : Windows 11 专业工作站版
ImageDescription : Windows 11 专业工作站版
ImageSize        : 16,882,018,231 bytes
```

然后将其释放到刚刚创建好的 VHD 分区中，`ImagePath`参数指定`install.wim`的位置，`ApplyPath`指定要安装的分区路径，`Index`是要安装的系统版本编号。

```powershell
Expand-WindowsImage -ImagePath H:\sources\install.wim -ApplyPath K: -Index 1
```

## 添加引导

这时候系统还无法启动，需要添加引导项，`/p`表示保留`windows boot manager`引导项在 EFI 菜单里的位置，`/d`参数指定保留当前默认的引导项，否则会将添加的作为新的默认项使用。

```powershell
bcdboot K:\Windows\ /l zh-CN /p /d
```

然后再次查看就可以发现新增了一个引导项。

```powershell
bcdedit /enum ACTIVE
```

有需要的话，还可以设置引导项的属性，在 powershell 中记得使用双引号包裹括号防止转义。

```powershell
# 指定新名字
bcdedit /set "{f7fba89a-c43d-11ec-929b-1c1b0de18031}" description "Windows 10 Alter"
# 指定超时值
bcdedit /set "{bootmgr}" timeout 5
```

这样就完成了双系统的安装。将来不想要 VHD 系统的时候，只需要先移除引导项，然后就可以安全的删除 VHD 文件了。

```powershell
bcdedit /delete "{f7fba89a-c43d-11ec-929b-1c1b0de18031}"
```
