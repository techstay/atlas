# 开启移动热点

如果有无线网卡的话，可以使用 windows 设置 WIFI 热点共享无线网络。

## 从控制面板开启

第一种方法是利用 win10 设置中的[开启热点](ms-settings:network-mobilehotspot?activationSource=SMC-IA-4027762)功能，如果点击链接无法开启，可以从`设置->网络和 Internet->移动热点`打开设置。

## 命令行开启

如果无法使用设置中的移动热点功能的话，也可以从命令行手动开启。这需要管理员权限的命令提示符或者 powershell 终端。

首先查看无线网卡支持不支持移动热点功能，如果`Hosted network supported`属性为`是`的话，说明支持 WIFI 热点功能。

```cmd
$ netsh wlan show drivers

Interface name: WLAN

    Driver                    : 802.11n USB Wireless LAN Card
    Vendor                    : Ralink Technology, Corp.
    Provider                  : Ralink
    Date                      : 2014/1/13
    Version                   : 5.1.10.0
    INF file                  : oem46.inf
    Type                      : Native Wi-Fi Driver
    Radio types supported     : 802.11b 802.11g 802.11n
    FIPS 140-2 mode supported : Yes
    802.11w Management Frame Protection supported : Yes
    Hosted network supported  : Yes
```

然后设置 WIFI 热点的属性，SSID 是热点 WIFI 的名称，key 是热点 WIFI 的密码。

```cmd
netsh wlan set hostednetwork mode=allow ssid=wifi key=pass
```

然后就可以开启热点。

```cmd
netsh wlan start hostednetwork
```

不过这时候热点还无法使用，还需要设置网络连接共享才可以使用。

从控制面板打开网络和共享中心，点击左侧的更改适配器设置，右键点击当前活动网络的属性，选择共享选项卡，然后将网络共享给刚刚创建出来的移动热点网络适配器。

这样设置之后，应该就可以正常使用移动热点 WIFI 了。如果将来不再需要热点的话，同样使用命令关闭即可。

```cmd
netsh wlan set hostednetwork mode=disallow
```
