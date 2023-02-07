# 远程桌面

## mstsc

mstsc 是微软的官方远程桌面软件，支持 RDP 协议，主要用来远程控制 Windows 系统。被控端需要手动开启远程桌面的权限，然后控制端就能通过 mstsc 程序进行远程控制。

优点：

- 官方支持，所有 Windows 系统都能用
- 支持共享剪贴板，复制粘贴/拖动文件
- 无需注册额外账号，局域网就能连接

缺点：

- 不能同时和受控端同时控制
- 需要受控端 Windows 账号和密码
- 非局域网环境需要 VPN

## VNC

VNC 是基于 RFB(Frame Buffer protocol)协议的桌面分享软件，常用于 Linux 下的桌面分享，也可以用于 Windows。常见的 VNC 软件有[Real VNC](https://www.realvnc.com/en/connect/)、[TightVNC](https://www.tightvnc.com)等等。受控端需要安装 VNC 服务端，控制端要安装 VNC 客户端。

优点：

- 无需注册额外账号，局域网就能连接
- 系统配置要求低，大多数设备都能受控
- 支持共享剪贴板和传输文件

缺点：

- 受带宽影响大，低带宽下显示效果不好
- 非局域网环境需要 VPN

## Parsec

[Parsec](https://parsec.app)是一个远程桌面和游戏串流软件，使用自研的编解码协议进行串流功能，系统占用比较低，使用起来也很流畅。

优点：

- 使用 H265/H265 编解码，带宽占用小
- 有中转服务器，并且可以穿透简单的 NAT，打洞成功后延迟较低
- 支持游戏手柄

缺点：

- 需要注册 parsec 账号
- 需要较新的显卡，老旧显卡不支持作为受控端
- 需要开启显示器或者购买欺骗卡

## moonlight

月光是基于英伟达游戏串流协议的开源客户端软件，支持多种客户端，[配置文档](https://github.com/moonlight-stream/moonlight-docs/wiki/Setup-Guide#streaming-over-the-internet)。

受控端需要较新的英伟达显卡，安装 GeForce Experience，然后在设置中开启串流功能。控制端安装月光客户端，然后通过 IP 地址进行连接，受控端输入正确的 PIN 码即可。

要通过月光进行桌面远程控制，需要在主机端添加`mstsc`程序，路径为`C:\windows\system32\mstsc.exe`。如果要串流的游戏没有显示在程序列表中，也可以用此方法手动添加。

优点：

- 使用英伟达协议，带宽占用小
- 无需额外注册账号，局域网就能连接
- 支持的客户端种类较多，可从各种设备远程控制

缺点：

- 只支持英伟达显卡，可安装[sunshine](https://github.com/LizardByte/Sunshine)使用 AMD 显卡，但是需要较新的显卡才能支持
- 不支持共享剪贴板
- 非局域网环境需要 VPN
- 需要开启显示器或者购买欺骗卡

## mycloudgame

[mycloudgame](https://mycloudgame.com)是一个国产的远程串流软件。
