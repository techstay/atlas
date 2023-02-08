# 资源分享

## alist

alist 是一个支持多种存储的文件列表程序，可以将百度网盘、阿里云盘等各种网盘的服务整合成一个统一的文件列表，方便进行分享。

### 安装

scoop 安装

```sh
scoop install alist
```

启动

```sh
alist start
```

查看管理员账号

```sh
alist admin
```

然后在浏览器访问<http://localhost:5244>，输入管理员账号登录。

### 挂载存储

参考[官方文档](https://alist.nn.ci/zh/guide/drivers/)进行挂载。

#### 挂载本机

- _驱动_，选择本机存储
- _挂载路径_，也就是将会在 alist 中显示的名字
- _根文件夹路径_，就是要在 alist 中显示的文件夹，如`D:\Downloads`等

#### 挂载其他 alist

- _驱动_，选择*alist v3*
- _挂载路径_，写要在 alist 中显示的名字
- _根文件夹路径_，要在 alist 中显示的文件夹，默认是`/`，如果你只需要该 alist 中的 buff 文件夹，那么就写对应的路径
- _链接_，要挂载的 alist 的网址
- _密码_，要填写的密码，通常 alist 网站都会提供密码以供访客访问

下面列出一些 WebDav 服务，可以在支持 webdav 的播放器(如 potplayer、kodi)中打开，以便在线播放。要作为 alist 挂载的话，把网址最后的`/dav`去掉就行，其他配置不变。

webdav 挂载方法可以查看[V2 版本官方文档](https://alist-doc.nn.ci/docs/webdav#%E6%94%AF%E6%8C%81%E5%BA%A6)，网页下方有图片可供参考。

| 服务名       | URL                                 | 用户名 | 密码         | 端口号 |
| ------------ | ----------------------------------- | ------ | ------------ | ------ |
| 小雅         | <http://alist.xiaoya.pro/dav>       | guest  | guest_Api789 | 80     |
| Media Center | <https://media.advanced360.top/dav> | guest  | kimiko12138  | 443    |
| 七米蓝       | <https://al.chirmyram.com/dav>      | alist  | alist        | 443    |
| 梓澪の妙妙屋 | <https://zi0.cc/dav>                | zi0    | zi0          | 443    |
| A 先生       | <https://a.a-bson.repl.co/dav>      | admin  | 1355         | 443    |
| OneList      | <https://ali.roko89.repl.co/dav>    | guest  | 123          | 443    |

### 资源站

网络上有一些现成的 alist 资源站，可以挂载到 alist 中。

- [小雅](http://alist.xiaoya.pro)(竟然没有 HTTPS)
- [梵天](https://iemo.fun)
- [imsyy](https://pan.imsyy.top)
- [谢週五の云盘](https://pan.5nav.ml)
- [姬路白雪资源站](https://pan.jlbx.xyz)，动漫分享站

其他资源站

- [随意盘](https://apps.weixinqqq.com)
- [知道创宇网络空间雷达](https://www.zoomeye.org)
- [alist 电报资源群](https://t.me/alistshare)
- [找资源](https://zhaoziyuan.la)
