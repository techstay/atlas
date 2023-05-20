# 青龙面板

[青龙面板](https://github.com/whyour/qinglong)是一个用来自动运行和管理定时任务的 linux 管理面板。

## 开始使用

### 安装

推荐使用 docker compose 方式运行。

```sh
ql_dir="$HOME/.config/qinglong"
mkdir -p "$ql_dir" && cd "$ql_dir"
wget https://raw.githubusercontent.com/whyour/qinglong/master/docker/docker-compose.yml

# 启动
docker-compose up -d
# 停止
docker-compose down
```

启动成功后，访问<http://server-ip:5700>运行初次配置。

### 使用

青龙面板支持 JavaScript、typescript、python 以及 shell 等脚本。如果脚本需要额外的依赖库，需要先在依赖管理面板处安装依赖项，支持 nodejs、python3、linux 三种。新建依赖项的时候选择自动拆分，然后每行一个依赖，点击确认后就可以在容器中安装了。或者也可以直接在配置文件`extra.sh`中添加安装依赖的命令。

要自动执行的脚本，可以由自己编写，也可以从 github 上订阅其他人已经写好的。不过在使用第三方脚本之前，最好确认来源是否可靠。**不要在未知的脚本中随意添加自己的 COOKIE 等信息，被盗号的话后果自负。**

然后就是设置定时任务，需要设置 crontab 语法的定时器，不过这个比较简单，网上已经有很多教程了。还有类似<https://cron.qqe2.com/>这样的工具，能够自动生成 crontab 表达式。

注意添加定时任务的时候，如果 cron 表达式中添加了可选的秒数，那么需要通过`task`内置命令运行脚本，即写成`task test.sh`这样的形式。不然的话，脚本的自动执行功能无效，只能通过手动点击方式运行。如果表达式中没有秒数参数，那么自动运行功能是没问题的，这可能是个 bug。因为我在测试`echo "Helloworld"`内容脚本每 10 秒执行一次的时候，发现了这个问题。实际使用中没人会这么运行脚本，所以问题应该不大。

青龙面板有两个[内置命令](https://github.com/whyour/qinglong#%E4%BD%BF%E7%94%A8)，可以用来管理一些功能。使用容器运行的话，需要在容器内才能执行这些命令。`ql`命令管理青龙面板自身，`task`命令用于灵活执行任务。

```sh
docker exec -it qinglong_web_1 bash
```

### 推送通知

青龙面板在文档方面做的很差，很多东西我只能在网上到处搜索去查找甚至去翻别人写好的脚本才大概搞清楚。

在系统设置中可以设置推送功能，这个是青龙面板自身的推送功能，虽然没啥用，但是有测试按钮，可以填写好信息之后来测试是否配置正确。以最简单的电报机器人为例：

1. 在电报中搜索`BotFather`，然后输入`/newbot`命令创建新机器人，根据提示设置机器人的各项信息
2. 输入`/mybot`获取`telegramBotToken`
3. 搜索`getuserid`机器人，输入`/start`命令，获取`telegramBotUserId`
4. 点击保存，成功的话，在电报上应该会收到推送测试，这样就设置成功了

然后是脚本的推送功能，这需要在青龙的配置文件`config.sh`中配置好环境变量。青龙面板内已经预先内置好`notify.py`和`sendNotify.js`推送库，会自动读取环境变量，并提供了`send`函数用于发送通知。所以接下来只需要在自己的脚本中调用这个函数即可。

```py
from notify import send

title = '测试'
text = '测试内容'
send(title, text)
```

### 代理设置

如果设备需要访问一些网站，可能需要设置代理才能正常运行。一般都会在运行青龙的设备上运行代理，所以如果使用 docker 的话，代理 host 就填写`172.18.0.1`，端口号就写自己的代理，如`7890`。
