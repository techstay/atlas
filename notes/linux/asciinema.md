# asciinema

asciinema 是一个基于文本的 linux 终端录屏工具，开源免费。

## 开始使用

### 安装

各大 linux 发行版仓库中都有收录，直接安装即可。

```sh
sudo pacman -S asciinema
```

### 录屏

开始录屏很简单，使用命令行启用即可。

```sh
asciinema rec
```

这样会启动一个新的 shell，在这里面就可以执行各种要想的录制的操作。录制完成后输入`exit`或者`Ctrl + D`即可结束录制。结束录制时还会询问你是上传到`asciinema.org`还是只保存在本地。

### 播放

录制完成后就可以重放了，支持本地文件或者网页。

```sh
asciinema play <path-or-url>
```

### 分享

想要分享终端录屏也十分简单，参考[官方文档](https://asciinema.org/docs/embedding)即可。

asciinema 也并非完全没有缺点，目前字体貌似还无法自定义设置，这就导致如果使用了带有特殊字符的 shell 主题（如 powerlevel10k），一些特殊字符在网页端显示的时候会显示为乱码，这一点比较可惜。不过既然这个工具名字叫做 asciinema，看来使用它进行录屏的时候只能换回那些传统的主题。
