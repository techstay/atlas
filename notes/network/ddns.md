# ddns

## 准备工作

参考以下几篇文章，测试运营商和路由器防火墙是否禁止 IPv6 访问。

- [正确地配置 IPv6 防火墙和 DDNS 以在公网访问设备](https://rongrongbq.moe/2021/08/firewall-and-DDNS-settings-for-IPv6/)
- <https://ccie.lol/knowledge-base/ipv6-use-eui-64-convert-link-local-address/>

## ddns 客户端

之前用的几个 ddns 服务的客户端，要么好久不更新，要么不支持 IPv6。不如自己直接写脚本或者使用开源的 ddns 客户端<https://github.com/NewFuture/DDNS>。

安装

```sh
pip install ddns
```

示例配置文件

```json
{
  "$schema": "https://ddns.newfuture.cc/schema/v2.8.json",
  "debug": false,
  "dns": "cloudflare",
  "id": "",
  "index4": "",
  "index6": "default",
  "ipv4": [],
  "ipv6": ["your-hostname"],
  "proxy": null,
  "token": "token",
  "ttl": null
}
```

设置计划任务(管理员权限)，计划任务会每隔五分钟更新一次 IP 地址。在配置文件所在的目录中打开管理员权限的 powershell 窗口，然后运行一下代码，就能创建计划任务了。成功执行以后，看看`run.log`日志文件中的记录，就可以知道任务是否能够正常运行。

```powershell
$cmd = "cmd /c `"`"$((Get-Command ddns.exe).Source)`" -c `"$pwd\config.json`" >> `"$pwd\run.log`"`""
schtasks /Create /SC MINUTE /MO 5 `
    /TR $cmd `
    /TN 'DDNS' /F /RU SYSTEM
```
