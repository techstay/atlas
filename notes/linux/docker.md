# docker

推荐阅读

- [官方入门教程(英文)](https://docs.docker.com/get-started/overview/)
- [docker 从入门到实践](https://yeasy.gitbook.io/docker_practice/)

## 开始使用

### 安装

archlinux 安装

```sh
sudo pacman -S docker
```

ubuntu 安装

```sh
sudo apt install docker.io
```

将当前用户添加到 docker 用户组中。

```sh
sudo usermod -aG docker "$USER"
```

让 docke 服务开机自启。

```sh
sudo systemctl start docker
sudo systemctl enable docker
```

windows 可以通过只安装 docker-cli，链接远程 docker-daemon 的方式来使用。

```sh
scoop install docker docker-compose
docker context create remote --docker "host=ssh://techstay@192.168.149.129:22"
docker context use remote
```

### 镜像加速

各加速器状态可以通过[这个仓库](https://github.com/docker-practice/docker-registry-cn-mirror-test/actions)的 Action 查看。

- [阿里云镜像加速](https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors)，需要登录自己的账号，获取专属加速器地址
- [网易云加速](https://sf.163.com/help/documents/56918246390157312)
- [百度云加速](https://cloud.baidu.com/doc/CCE/s/Yjxppt74z#%E4%BD%BF%E7%94%A8dockerhub%E5%8A%A0%E9%80%9F%E5%99%A8)

添加加速器配置

```sh
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<-'EOF'
{
    "registry-mirrors": [
        "https://68vapi3g.mirror.aliyuncs.com",
        "https://hub-mirror.c.163.com",
        "https://mirror.baidubce.com"
    ]
}
EOF

sudo systemctl daemon-reload
sudo systemctl restart docker
```

运行`docker info`，看到*Registry Mirrors*则说明成功。

```sh
 Registry Mirrors:
  https://68vapi3g.mirror.aliyuncs.com/
  https://hub-mirror.c.163.com/
  https://mirror.baidubce.com/
 Live Restore Enabled: false
```

测试

```sh
docker run --rm hello-world
```

### 运行

```sh
docker run [OPTIONS] IMAGE[:TAG|@DIGEST] [COMMAND] [ARG...]
```

参数

- `-d`，后台运行，未指定则为前台运行
- `--name`，名字，未指定则随机生成一个
- `--rm`，容器停止时删除所有数据卷，命名卷会保留
- `-p 80:80`，绑定端口号，前者是宿主机端口号，后者是容器内端口号
- `Image[:tag]`，指定镜像标签，通常是版本号，未指定则为`latest`
- `--network=host`，指定网络类型，默认为`bridge`，若指定为`host`则直接使用宿主机网络，也就无需使用`-p`绑定端口号
- `-restart=always`，指定重启策略，默认不重启，指定为`always`时，不论容器结束状态如何，总会自动重启

### 数据卷

管理

```sh
docker volume create <volume>
docker volume ls
docker volume inspect
docker volume rm
```

挂载

- 数据卷挂载`-v volume_name:/app`，没有数据卷时会自动创建
- 主机目录挂载`-v $HOME/html:/usr/share/nginx/html`
- 只读挂载`-v volume_name:/app:ro`

### 管理

```sh
# 启动容器
docker start <container>
# 停止容器
docker stop <container>
# 暂停容器
docker pause <container>
# 恢复容器
docker unpause <container>
# 更新配置，即通过run命令行指定的参数
docker update <container>
# 查看docker信息
docker info
# 检查docker详细信息
docker inspect
# 查看docker版本
docker version
```

### 清理

```sh
docker image prune
docker volume prune
docker container prune
# 全部清理
docker system prune --volumes
```

### Dockerfile 文件

官方文档 <https://docs.docker.com/engine/reference/builder/>

下载速度慢时可以在 Dockerfile 中使用镜像。

```Dockerfile
# alpine
RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.tuna.tsinghua.edu.cn/g' /etc/apk/repositories && \
  apk add --no-cache gcc musl-dev linux-headers

# python
RUN pip install -i https://pypi.tuna.tsinghua.edu.cn/simple some-package

# npm
RUN npm install -g cnpm --registry=https://registry.npmmirror.com
```

## compose

### 配置文件

默认配置文件名为`docker-compose.yml`，是 YAML 格式配置文件。官方文档 <https://docs.docker.com/compose/compose-file/>

### 命令

```sh
# 使用当前目录下的docker-compose.yml文件启动
docker compose up
# 停止compose[，移除所有卷]
docker compose down [-v]
```

## 速查表

记录一些常用的 docker 命令和配置文件。

```sh
# nginx
docker run --name some-nginx \
  -v /some/content:/usr/share/nginx/html:ro \
  -d -p 80:80 --rm nginx

# mysql
docker run --name some-mysql \
  -e MYSQL_ROOT_PASSWORD=mysecretpassword
  -d -p 3306:3306 --rm mysql

# mongo
docker run --name mongo \
  -p 27017:27017 -d --rm mongo

# postgres
docker run --name some-postgres \
  -e POSTGRES_PASSWORD=mysecretpassword \
  -d --rm -p 5432:5432 postgres:alpine
```

```yaml
# teamcity
version: "3"

services:
  teamcity-server:
    image: jetbrains/teamcity-server
    ports:
      - 80:8111
    volumes:
      - teamcity-data:/data/teamcity_server/datadir
      - teamcity-log:/opt/teamcity/logs
    depends_on:
      - postgres
  postgres:
    image: postgres:alpine
    environment:
      POSTGRES_PASSWORD: 12345678

volumes:
  teamcity-data:
  teamcity-log:
```
