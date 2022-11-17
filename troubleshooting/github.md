# github

## 问题列表

### github 加速

参考[这里](https://zhuanlan.zhihu.com/p/75994966)，最简单有效的办法就是更改 hosts。

登录<https://www.ipaddress.com>网站，依次查询以下几个地址的 DNS：

- github.com
- assets-cdn.github.com
- github.global.ssl.fastly.net
- raw.githubusercontent.com

然后打开 hosts 文件 (windows 系统下为`C:\Windows\System32\drivers\etc\hosts`)，添加以下几行 hosts。

```txt
140.82.114.3    github.com
185.199.109.153 assets-cdn.github.com
199.232.69.194  github.global.ssl.fastly.net
185.199.110.133 raw.githubusercontent.com
```

然后输入`ipconfig /flushdns`，之后访问 github 速度应该就比较快了。
