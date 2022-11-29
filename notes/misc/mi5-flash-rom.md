# 小米 5 刷机记录

手里的老小米 5，没事干就拿出来刷个机，记录一下步骤，下次照做就行。

首先需要安装驱动，不然识别不到手机。<https://www.miui.com/shuaji-393.html> 或者 <https://xiaomirom.com/download-xiaomi-flash-tool-miflash/> 链接下载小米刷机工具，一方面可以从里面安装驱动，另一方面万一刷坏了还可以直接用这个救砖。

先刷最新版的 twrp，在这里下载<https://dl.twrp.me/gemini/>。记得同时下载 asc 密钥方便校验。

```powershell
gpg --verify .\twrp-3.6.0_9-0-dipper.img.asc .\twrp-3.6.0_9-0-dipper.img
```

如果安装了 Kleopatra 的话，直接双击就可以校验。然后按电源+音量减键或者`adb reboot bootloader`进入 fastboot 模式，就可以刷机了。

```powershell
fastboot flash recovery .\twrp-3.7.0_9-0-gemini.img
```

然后下载最新版的 lineageos <https://download.lineageos.org/gemini>， 顺便校验一下，看看 sha256 对不对。

```powershell
sha256sum .\lineage-19.1-20221016-nightly-gemini-signed.zip
```

然后按电源+音量加键进入 twrp recovery，然后选择 sideload，就能安装刷机包了。

```powershell
adb sideload .\lineage-19.1-20221016-nightly-gemini-signed.zip
```

不过现在安装最新的 lineage 19 的话，用 twrp 可能遇到刷机失败的问题。这时候最好改用 lineageos 自己的 recovery，在 lineageos 的刷机包下载页面就能找到，同样地，最好先校验一下。之后，用同样的方式，让手机进入 fastboot 模式，再刷入。

```powershell
fastboot flash recovery .\lineage-19.1-20221016-recovery-gemini.img
```

再次重启进入 recovery，选择 Enable ADB，然后进入旁加载模式。

```powershell
adb reboot sideload
```

这时候就能成功刷入系统了。

```powershell
adb sideload .\lineage-19.1-20221016-nightly-gemini-signed.zip
```

别忘了刷 GAPPS，这里我选用 [NikGapps](https://nikgapps.com)。lineageos 19.1 的安卓版本号为 12.1，对应的字母是 SL，这卡了我一段时间。下载完成后，在 lineageos recovery 中选择`Apply update`，然后选择`Apply from ADB`，刷入 gapps。

```powershell
adb sideload .\NikGapps-basic-arm64-12.1-20220908-signed.zip
```

最后双清一下，就可以进入系统了。

emmm，后续的工作还是很麻烦的。要登录谷歌账号，先得设置代理，只能通过连接 WIFI 的时候先用 PC 的本地代理过渡一下。之后在 Google Play 里安装 Clash 软件，还要输入订阅地址，为了防止泄露还不能使用社交软件传递，最后只能用 scrcpy 通过 PC 复制过去。之后的设置基本上就能在手机上独立完成了。甚至时间同步都可能出问题，还需要手动设置为国内的 ntp 服务器。这一套下来还是挺麻烦的，所以有时候我在想，假如没有墙，是不是生活一下子就完美了呢？

```sh
adb shell "settings put global ntp_server ntp.ntsc.ac.cn"
```
