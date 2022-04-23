# garuda

我的 garuda linux 笔记。

## 使用 wayland

我试图在 garuda 上使用 wayland，虽然最后没有成功，但是也算有一点经验，所以趁着还没忘记记录一下。参考了[这篇帖子](https://forum.garudalinux.org/t/sddm-in-wayland/12568)。

首先要编辑`/etc/sddm.conf`配置文件，在对应的小节添加新的配置。

```conf
[General]
DisplayServer=wayland
GreeterEnvironment=QT_WAYLAND_SHELL_INTEGRATION=layer-shell

[Wayland]
CompositorCommand=kwin_wayland --no-lockscreen --inputmethod maliit-keyboard --width 1920 --height 1080
```

配置完成后注销用户，返回到显示管理器界面，选择 wayland 然后重新登录，看看能不能正常进入桌面，比较可惜的是我卡在了这里无限黑屏，无奈之下只好返回到 x11。

通过查看环境变量的方式就可以了解当前使用的是 wayland 还是 x11。

```sh
echo $XDG_SESSION_TYPE
```

开源运动是一项伟大的创举，但是也不得不承认很多开源项目的进展确实没有一些大企业主导的项目快。也希望 wayland 早日成熟，彻底取代 x11 吧。
