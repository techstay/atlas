---
title: "dolphin"
date: 2026-05-15T01:32:24+08:00
tags:
  - gaming
  - emulators
  - dolphin
  - emulator
  - wii
categories:
  - 游戏
---

# dolphin

Dolphin 是一款对应任天堂游戏主机 GameCube 和 Wii 的模拟器。它可以让电脑玩家以全高清 (1080p) 画质体验这两款主机的游戏，还具有兼容电脑手柄、加速、多人联网等增强功能。

## 下载和安装

到 [官网下载页面](https://cn.dolphin-emu.org/download/) 下载模拟器，推荐下载 beta 版。可能还需要同时安装 [Visual C++ redistributable](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)。

下载完成后打开软件，应该会看到类似下图的界面。

![主界面](./attachments/dolphin-mainui.avif)

## 常见设置

### 游戏路径

软件主界面会显示出一大片空白，这是因为还没有设置游戏 ROM 的路径。双击空白处，就会弹出对话框，询问要从哪里查找游戏，选择一个文件夹，然后 dolphin 就会从这个文件夹中查找并列出所有的游戏 ROM。

之后要重新设置的话，可以从*设置 ->路径*中找到。

![游戏路径](./attachments/dolphin-config-path.avif)

### 语言设置

有时候默认打开是英文界面，可以改为中文。点击菜单栏*Options->Configuration*，打开设置对话框，然后在*Interface*下找到*Language*下拉菜单，在最下面找到简体中文。更改语言需要重启模拟器才能生效。

![更改语言](./attachments/dolphin-change-language.avif)

### 图形设置

在工具栏点击*图形*工具，就能打开图形设置对话框。

在**常规**配置中，选择一个合适的后端，并选择显卡设备，显卡通常选择独立显卡。后端的稳定性与设备和驱动等有关系，如果出现渲染问题的话，可以换一个后端试试。

在**增强**配置中，根据自己的显示器选择合适的内部分辨率和抗锯齿设置，可以有效的增强画面质量。

其余设置项基本不用更改。

![图形设置](./attachments/dolphin-graphics.avif)

### 键位设置

设置键位时通常需要设置两种键位，第一种是 GAME CUBE 手柄键位，这种游戏手柄类似 XBOX360 手柄，主要用来游玩各种传统游戏。

![GAME CUBE](https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/Gamecube-controller-breakdown.jpg/1024px-Gamecube-controller-breakdown.jpg)

点击工具栏的*控制器*图标，就可以打开控制器设置，选择 GAME CUBE 控制器右边的配置，即可配置键位。

![控制器](./attachments/dolphin-controller-gamecube.avif)

如果有游戏手柄的话，推荐使用游戏手柄进行键位配置。如果点击手柄按键没有反映，可能是没有正确选择手柄设备，在**设备**那一栏点击*刷新*，然后在下拉菜单中看看有没有识别到手柄设备，选择正确以后，键位设置的时候就能正确记录手柄按键输入。当一套键位全部设置完成后，可以在**预设**那一栏输入名称并保存。这样以后有多套键位设置的时候方便切换。

![GAME CUBE键位配置](./attachments/dolphin-controller-gamecube-config.avif)

像超级马里奥兄弟这类游戏，需要使用 WII 遥控器，这是一种长条状的控制器。

![WII遥控器](https://m.media-amazon.com/images/I/61QSQlmEvgL.jpg)

在控制器设置对话框，找到 WII 遥控器配置，点击右边的配置按钮，即可配置键位。

![控制器](./attachments/dolphin-controller-wii-remote.avif)

WII 遥控器配置起来要稍微复杂一些，因为除了标准键位以外，一些游戏还用到了体感功能，同样需要在键位中进行设置。

以下是我的键位，大家可以作为参考。

![键位设置1](./attachments/dolphin-controller-wii-remote-config1.avif)

![键位设置2](./attachments/dolphin-controller-wii-remote-config2.avif)

## 多人联机

### 主机设置

dolphin 模拟器也支持多人联机功能，可以让朋友们在一起玩游戏。点击*菜单栏 ->工具 ->开始联机*，即可打开联机对话框。需要注意所有联机的玩家的模拟器版本和游戏 ROM 都必须一致才可以联机。

先来讲讲局域网联机，需要所有联机玩家都在同一个局域网之中。推荐使用 xedge.cc 或者 tailscale 等虚拟组网工具，支持 P2P 直连，让分隔两地的朋友也能加入同一个虚拟局域网。主机玩家选择好要游玩的游戏之后，点击右下角的*主机*按钮，就能成功建立游戏主机，等待其他玩家的加入。

![主机建房](./attachments/dolphin-multiplayer-host.avif)

### 公开主机

如果主机玩家在建立主机的时候，打上了*服务器浏览器*的对勾，并设置了房间名字和密码。那么在建立主机之后，主机就会出现在公开的服务器浏览器列表中，其他玩家可以查看和加入。

因为一般情况下家用网络都没有公网 IP 地址，所以公开服务器的时候显示的 IP 地址无法用于联机游戏，其他人点击联机也会失败。这时候可以将*联机设定*对话框中的连接类型改为**穿透服务器**，这样通常可以连接成功。

![公开主机](./attachments/dolphin-multiplayer-host-public.avif)

### 客户端连接

主机玩家建立好主机之后，其他玩家就可以连接了。连接方式很简单，同样在联机对话框中，客户端玩家需要点击连接选项卡，然后输入主机玩家的局域网 IP 地址或者虚拟局域网 IP 地址就可以连接了。

![连接主机](./attachments/dolphin-multiplayer-client.avif)

要连接公开主机的话，需要点击*菜单栏 ->工具 ->浏览联机会话*打开联机会话对话框。在这里应该就能看到公开的服务器主机了。选择要加入的主机，点击确定即可。如果主机列表很多，还可以利用下面的过滤条件进行筛选。

![连接公开主机](./attachments/dolphin-multiplayer-client-public.avif)

### 房间设置

等所有玩家都连进房间以后，主机玩家先别急着开游戏，因为还有一些东西需要设置。

- 菜单栏 ->数据 ->加载和写入主机的存档数据，启用该项可以将联机游玩时的存档保存到主机的存档中，以便下次继续游玩
- 菜单栏 ->数据 ->使用所有 WII 存档数据，启用该项以后，切换游戏的时候同样会使用主机的联机存档，该选项要和上面的选项配合使用
- 菜单栏 ->网络 ->公平输入延迟/主机输入优先权，选择哪个需要看玩的什么游戏，网络连接顺畅或者高技术游戏选择前者，网络差或者休闲游戏可以选择后者
- 菜单栏 ->校验 ->当前游戏，会计算所有玩家的游戏文件校验码，可以用来确认联机玩家使用的是不是相同的游戏文件

![房间设置](./attachments/dolphin-multiplayer-host-room-config.avif)

默认情况下联机游戏只会映射 GAME CUBE 控制器，在游玩马里奥兄弟等游戏的时候，需要使用 WII 遥控器，所以在游玩之前，还需要手动添加控制器，否则进游戏以后无法操控。

![指定控制器端口](./attachments/dolphin-multiplayer-controller1.avif)

![添加遥控器](./attachments/dolphin-multiplayer-controller2.avif)

添加成功之后，映射一栏就会出现 WII 字样，这样进入游戏以后就能使用 WII 遥控器游玩游戏了。多人联机的时候主机玩家要注意，不要将 WII 遥控器设置错位张冠李戴，遥控器的编号要和玩家的编号一致。

![添加成功](./attachments/dolphin-multiplayer-controller3.avif)

设置成功以后，就可以和朋友一起畅快的联机游戏了！
