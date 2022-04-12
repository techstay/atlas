# ventoy

[ventoy](https://www.ventoy.net/cn/index.html) 是一个同时支持 windows 和 linux 的启动盘制作工具，无需重复格式化，复制 ISO 即可使用。

## 下载

到[ventoy 官网](https://www.ventoy.net/cn/download.html)即可查看下载链接，然后根据系统下载对应版本。

## 安装

准备一个 8G 以上的空 U 盘，连接到电脑上，然后打开`Ventoy2Disk`，点击安装即可。如果需要安全启动支持，记得在菜单栏上打勾。

![ventoy](img/ventoy.png)

安装完成后，ventoy 会创建两个分区，一个是隐藏的启动分区，我们不用管它。另一个是占据 U 盘绝大多数空间的数据分区，我们可以像平时那样使用 U 盘。要启动一个 windows 或者 linux 系统的话，只需要将它的 ISO 文件复制到数据分区中即可，无需使用 rufus 之类的工具格式化，就是这么简单！

## 配置

ventoy 支持大量配置，不过一般情况下不需要修改。要修改配置，需要在数据分区（不是启动分区）创建`ventoy/ventoy.json`配置文件，配置项需要参考官方文档。

下面是一个简单的配置文件，设置 ventoy 默认 ISO 搜索文件夹和搜索深度，加快搜索速度，同时将 ventoy 启动界面等待时间设置为 30 秒。

```json
{
  "control": [
    { "VTOY_MAX_SEARCH_LEVEL": "2" },
    { "VTOY_MENU_TIMEOUT": "30" },
    { "VTOY_DEFAULT_SEARCH_ROOT": "/ISO" }
  ]
}
```

当然，其实还有一种更简单的方式，就是使用 ventoy 自带的 VentoyPlugson 工具，它会开启一个 web 图形界面来帮助我们修改配置，更加方便。
