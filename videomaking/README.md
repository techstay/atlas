# 视频制作

## 软件资源

- Adobe Premiere Pro，可参考[vposy 微博](https://weibo.com/vposy)下载
- [达芬奇](http://www.blackmagicdesign.com/products/davinciresolve)，另一个知名的视频剪辑软件
- [必剪](https://bcut.bilibili.cn)，B 站的剪辑工具，自带了 B 站的流行素材
- [剪映](https://lv.ulikecam.com/)
- [Audicity](https://www.audacityteam.org)，开源免费的音频软件
- [OBS](https://obsproject.com/download)，著名推流软件，也可以用来录屏

## 录屏

### Xbox 游戏栏

这是 Windows 系统自带的游戏捕获工具，可以用来录制游戏视频。使用 Windows 徽标键+G 打开 Xbox 游戏栏，点击录制按钮即可开始录制，或者也可以直接使用 Win+Alt+R 开始录制。

默认录制的视频是 30 帧，如果需要录制 60 帧视频，在[设置](ms-settings:gaming-gamedvr)(Windows 设置->游戏->摄像)中将录制帧数调整为 60 帧。

### OBS

OBS 是一个开源免费的视频推流软件，同时也支持录像功能。不过设置比较复杂，需要多说几句。这里就以主流的 1080p 60 帧的视频为例说明。

首先是编码器，如果使用 N 卡，那么就优先选择 NVENC 硬件编码器，效率更高一些，HEVC 编码器是 OBS 28 的新增功能，但是一些剪辑软件不支持，所以还是优先使用 H.264 编码。没有这个选项的话就选择 x264 编码器。

编码器设置这里就得看机器的配置和要录制的内容了。如果希望画质更高一些的话，那么就要调高一些参数，但是过高的参数不仅视频文件会很大，而且也会影响性能，特别是录制游戏的时候。

作为参考，如果要录制的视频不需要太高质量，可以选择 CBR，并设置 6000-30000Kbps 范围的比特率。如果想要更好的质量，可以选用 CQP，并设置合适的 CQ 级别(数值越小视频质量越好)，但是这样的话，视频的比特率就比较大，在录制游戏的时候可能达到 70000Kbps 左右的比特率。显卡不好的话也会影响到录制效果，这就需要根据自己的配置灵活选择了。

![OBS录屏设置](./img/OBS录像设置.png)

### Nvidia GeForce Experience

如果显卡是 N 卡，那么使用 GeForce Experience 也可以录制视频。使用快捷键 Alt+Z 打开 GeForce Experience 界面，选择录制即可开始视频录制，快捷键是 Alt+F9。要调整录制设置的话，点击开始录制下方的设置按钮，然后就可以修改视频质量、比特率、帧率等设置了，一般质量选择中或者高就可以了，对应的比特率是 2 万和 5 万 Kbps。

## 配音

### AI 语音

最典型的就是使用 Azure AI 的配音，典中典之云希音色，营销号都在用，用过的都说好。先安装[油猴脚本](https://greasyfork.org/zh-CN/scripts/444347-azure-speech-download?)，然后在 [Azure 文本转语音页面](https://azure.microsoft.com/zh-cn/products/cognitive-services/text-to-speech/#features)就可以看到下载按钮，输入文字即可得到 AI 配音的语音。

## 字幕

- [pyTranscriber](https://github.com/raryelcostasouza/pyTranscriber)，利用 Google AI 自动生成字幕，需要科学上网
- [Arctime Pro](https://arctime.org/download.html)，字幕打轴软件

如果经常需要给视频配音，使用语音识别还是最方便的一种。利用 pyTranscriber 可以比较轻松的创建字幕文件，并添加到已有的视频工程中去。

## 素材

视频素材。

- <https://www.vidsplay.com>
- <https://coverr.co>
- <https://mixkit.co/free-stock-video>
- <https://www.videvo.net>
- <https://www.pexels.com>
