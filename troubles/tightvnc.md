# tightvnc

## 问题列表

### Error in Tight VNC Viewer: Connection parameters (host, port, socket, gates) is empty

这个问题会在 tightvnc 文件关联错误时出现，解决办法也比较简单，打开注册表编辑器，找到`HKEY_CLASSES_ROOT\vnc_auto_file\shell\open\command`，编辑值，将第二位参数从`%1`改为`-optionsfile=%1`。
