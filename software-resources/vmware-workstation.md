# Vmware Workstation 16 安装

先下载安装包 <https://www.vmware.com/products/workstation-pro/workstation-pro-evaluation.html>

然后使用序列号`ZF3R0-FHED2-M80TY-8QYGC-NPKYF`激活。

## vmware 开机启动

重装系统之后为了用安卓模拟器我只好禁用了 WSL 功能，但是后台运行一个虚拟机 linux 还是很有用的，所以这里让 vmware 开机自动启动虚拟机，达成类似的目的。

办法很简单，先创建一个批处理文件(后缀名`.bat`)，然后通过 vmware 安装目录里面的`vmrun`工具来后台启动虚拟机。命令格式如下：

```cmd
"C:\Program Files (x86)\VMware\VMware Workstation\vmrun.exe" -T ws start "C:\Users\techstay\Documents\Virtual Machines\Arch\Arch.vmx" nogui
```

如果你使用的不是 Vmware Workstation，需要把`-T`后面的参数换成`ws|fusion|player`之一。

然后按`Win+R`打开运行对话框，输入`shell:startup`打开启动文件夹，将批处理文件放进去，下次重启的时候就可以自动开启虚拟机啦。
