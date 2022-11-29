# PM2

pm2 是一个方便好用的进程管理器。

## 开始使用

### 安装

```sh
pacman -S pm2
```

或 npm 安装

```sh
npm install pm2 -g
```

### 开启进程

每个进程建议单独放一个文件夹。

```sh
pm2 start prog
```

如果要运行的命令有额外参数，放到最后。

```sh
pm2 start prog -- --extra arguments
```

重启之后运行的程序会失效，需要持久化配置。首先让 pm2 开机自启。

```sh
pm2 startup

# 然后接着运行提示中给出的命令
sudo env PATH=$PATH:/usr/bin /usr/lib/node_modules/pm2/bin/pm2 startup systemd -u techstay --hp /home/techstay
```

然后保存当前的程序列表，这样下次重启的时候，列表中的所有配置都会跟着重新启动。

```sh
pm2 save
```

### 速查表

```sh
# 管理进程

pm2 stop <app_name|namespace|id|'all'|json_conf>
pm2 restart <app_name|namespace|id|'all'|json_conf>
pm2 delete <app_name|namespace|id|'all'|json_conf>

# 监视进程

pm2 monit

# 热重载

pm2 reload all

# 当前目录下任意文件更新时自动重启

pm2 start prog --watch --ignore-watch="node_modules"
```
