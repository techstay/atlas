# cloudflare

## 问题列表

### 网站内容出现重复现象

参考[该链接](https://vuepress-theme-hope.github.io/v2/faq/common-error.html#hydration-completed-but-contains-mismatches)，如果使用 cloudflare 部署网站，检查是否开启了静态资源压缩，寻找*网站->速度->优化->Auto Minify*，如果开启了的话就关闭。Cloudflare 的最小化可能会错误优化一些标签和空格，如果 vue 开启了 SSR 优化的话，就可能出现显示错误的问题。

### 网站无限重定向

打开*网站->SSL/TLS*，将加密模式改为*完全(严格)*，应该就不会出现这种问题了。
