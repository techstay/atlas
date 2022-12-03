# uptime-kuma

使用 docker 部署，然后访问`3001`端口。

```sh
docker run -d --restart=always -p 3001:3001 -v uptime-kuma:/app/data -v /var/run/docker.sock:/var/run/docker.sock --name uptime-kuma louislam/uptime-kuma:1
```
