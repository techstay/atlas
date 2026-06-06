---
title: Docker 容器化部署指南
date: 2026-05-15T01:18:06+08:00
tags:
  - selfhosted
  - docker
  - container
  - dev-tools
  - compose
categories:
  - 自托管
---

## 📚 教程

- 🧭 [官方入门教程（英文）](https://docs.docker.com/get-started/overview/)：适合从 Docker 基础概念开始系统了解。
- 📖 [Docker 从入门到实践](https://yeasy.gitbook.io/docker_practice/)：中文教程，适合边查边练。

## 🚀 开始使用

### 📦 安装

#### 🐧 Linux 安装

在 Arch Linux 上安装：

```sh
sudo pacman -S docker
```

在 Ubuntu 上安装：

```sh
sudo apt install docker.io
```

将当前用户添加到 `docker` 用户组中，避免每次执行命令都需要 `sudo`：

```sh
sudo usermod -aG docker "$USER"
```

启动 Docker 服务，并设置为开机自启：

```sh
sudo systemctl start docker
sudo systemctl enable docker
```

#### 🪟 Windows 安装

先参考 [[wsl]] 笔记开启 WSL 功能，再到 [Docker 官网](https://docs.docker.com/desktop/setup/install/windows-install/) 下载并安装 Docker Desktop。

### ⚡ 镜像加速

国内云厂商由于合规和成本原因，基本上都停止了公开的镜像加速服务。拉取 Docker 镜像时如果遇到网络问题，通常需要通过更稳定的网络环境解决。

### ▶️ 运行

```sh
docker run [OPTIONS] IMAGE[:TAG|@DIGEST] [COMMAND] [ARG...]
```

常用参数：

- `-d`：后台运行；未指定时以前台方式运行。
- `--name`：指定容器名称；未指定时会随机生成。
- `--rm`：容器停止后自动删除容器；命名卷会保留。
- `-p 80:80`：绑定端口，前者是宿主机端口，后者是容器内端口。
- `IMAGE[:tag]`：指定镜像标签，通常是版本号；未指定时默认为 `latest`。
- `--network=host`：指定网络类型，默认为 `bridge`；使用 `host` 时会直接使用宿主机网络，通常不需要再用 `-p` 绑定端口。
- `--restart=always`：指定重启策略；设置为 `always` 后，无论容器以什么状态结束，都会自动重启。

### 💾 数据卷

管理数据卷：

```sh
docker volume create <volume>
docker volume ls
docker volume inspect
docker volume rm
```

常见挂载方式：

- 数据卷挂载：`-v volume_name:/app`，数据卷不存在时会自动创建。
- 主机目录挂载：`-v $HOME/html:/usr/share/nginx/html`。
- 只读挂载：`-v volume_name:/app:ro`。

### 🛠️ 管理

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

### 🧹 清理

```sh
docker image prune
docker volume prune
docker container prune
# 全部清理
docker system prune --volumes
```

## 🏗️ 构建容器

### 📄 Dockerfile 文件

Dockerfile 是用来描述镜像构建过程的文件。它把基础镜像、依赖安装、文件复制、启动命令等步骤写成可重复执行的构建脚本。

[官方文档](https://docs.docker.com/engine/reference/builder/) 介绍了更多 Dockerfile 文件的知识。

一个简单示例：

```Dockerfile
FROM node:22-alpine

WORKDIR /app

COPY package.json package-lock.json ./
RUN npm ci --omit=dev

COPY . .

EXPOSE 3000

CMD ["node", "server.js"]
```

### 🧱 常见指令

- `FROM`：指定基础镜像，通常是 Dockerfile 的第一条有效指令。
- `WORKDIR`：设置工作目录，后续的 `RUN`、`COPY`、`CMD` 等指令都会基于这个目录执行。
- `COPY`：把本地文件复制到镜像中，常用于复制源码、配置文件和依赖清单。
- `ADD`：功能比 `COPY` 多，可以自动解压压缩包，也能读取 URL；普通文件复制优先使用 `COPY`。
- `RUN`：在构建镜像时执行命令，常用于安装依赖、编译项目、清理缓存。
- `ENV`：设置环境变量，会保存在最终镜像中。
- `ARG`：设置构建参数，只在构建阶段可用，适合传入版本号、构建开关等信息。
- `EXPOSE`：声明容器内部监听的端口，只是文档说明，不会自动发布端口。
- `VOLUME`：声明数据卷挂载点，适合持久化数据目录。
- `USER`：指定运行容器时使用的用户，生产环境中尽量避免直接使用 `root`。
- `CMD`：容器启动时默认执行的命令，可以被 `docker run` 后面的命令覆盖。
- `ENTRYPOINT`：容器启动时固定执行的入口命令，通常用于把镜像做成一个固定工具或服务。
- `LABEL`：给镜像添加元数据，例如维护者、源码地址、版本说明。
- `HEALTHCHECK`：定义健康检查命令，让 Docker 判断容器服务是否正常。

### 🔨 构建镜像

在 Dockerfile 所在目录执行：

```sh
docker build -t my-app:latest .
```

常用参数：

- `-t my-app:latest`：指定镜像名称和标签。
- `-f Dockerfile.prod`：指定 Dockerfile 文件名。
- `--build-arg VERSION=1.0.0`：传入构建参数，对应 Dockerfile 中的 `ARG`。
- `--no-cache`：不使用缓存，重新执行所有构建步骤。

构建完成后可以直接运行：

```sh
docker run --rm -p 3000:3000 my-app:latest
```

### 🪜 多阶段构建

多阶段构建可以把“编译环境”和“运行环境”分开，减少最终镜像体积，也能避免把源码、构建工具、临时文件一起打进生产镜像。

```Dockerfile
FROM node:22-alpine AS builder

WORKDIR /app
COPY package.json package-lock.json ./
RUN npm ci
COPY . .
RUN npm run build

FROM nginx:alpine

COPY --from=builder /app/dist /usr/share/nginx/html
EXPOSE 80
```

### 🧹 .dockerignore

`.dockerignore` 用来排除不需要发送给 Docker 构建上下文的文件。它的作用类似 `.gitignore`，可以减少构建时间，也能避免把敏感文件打进镜像。

常见内容：

```gitignore
.git
node_modules
dist
.env
*.log
```

### ⚠️ 注意事项

- 优先选择体积较小、来源可信的基础镜像，例如 `alpine`、`slim` 或官方镜像。
- 尽量固定镜像版本，例如 `node:22-alpine`，不要在生产环境中依赖 `latest`。
- 把变化少的步骤放前面，例如先复制依赖清单并安装依赖，再复制源码，这样可以更好地利用构建缓存。
- 不要把密码、Token、私钥写进 Dockerfile，也不要把 `.env` 打进镜像。
- 尽量将安装、清理等步骤合并到同一条 `RUN` 命令中，因为 Dockerfile 会按层构建；层数过多会增加镜像体积，也可能拖慢构建和分发速度。
- 容器内只运行一个主要进程，日志优先输出到标准输出和标准错误，方便 Docker 收集。
- 生产镜像中尽量使用非 `root` 用户运行服务，降低容器被攻击后的影响。
- `EXPOSE` 只是声明端口，真正发布端口仍然需要在 `docker run` 或 compose 中配置。

## 🧩 Compose

Compose 用来管理一组相关容器，适合把应用、数据库、缓存、反向代理等服务写进同一个配置文件中统一启动。相比一条条执行 `docker run`，Compose 更适合长期维护和重复部署。

### 📄 配置文件

默认配置文件名为 `compose.yml` 或 `docker-compose.yml`，使用 YAML 格式。官方文档：<https://docs.docker.com/compose/compose-file/>

一个简单示例：

```yaml
services:
  app:
    image: nginx:alpine
    container_name: demo-nginx
    ports:
      - "8080:80"
    volumes:
      - ./html:/usr/share/nginx/html:ro
    restart: unless-stopped
```

常见字段：

- `services`：定义服务列表，每个服务通常对应一个容器。
- `image`：指定使用的镜像。
- `build`：指定构建配置，用本地 Dockerfile 构建镜像。
- `container_name`：指定容器名称；不是必须配置，Compose 默认会自动生成。
- `ports`：端口映射，格式通常是 `宿主机端口:容器端口`。
- `volumes`：挂载目录或数据卷，用于保存数据或挂载配置文件。
- `environment`：设置环境变量。
- `depends_on`：声明服务启动顺序，例如应用依赖数据库。
- `restart`：设置重启策略，常用 `unless-stopped`。
- `networks`：配置服务使用的网络。

### ▶️ 常用命令

```sh
# 启动服务
docker compose up
# 后台启动服务
docker compose up -d
# 停止并移除服务
docker compose down
# 停止并移除服务，同时删除匿名卷
docker compose down -v
# 查看服务状态
docker compose ps
# 查看日志
docker compose logs -f
# 重新构建镜像
docker compose build
# 拉取配置文件中使用的镜像
docker compose pull
```

如果配置文件不是默认名称，可以使用 `-f` 指定：

```sh
docker compose -f compose.prod.yml up -d
```

维护 Compose 项目时，如果只修改某个服务的配置，或者只需要更新部分镜像，可以直接修改配置文件，或先拉取镜像后重新启动：

```sh
docker compose pull
docker compose up -d
```

未受影响的容器通常会保持不变，只有配置或镜像发生变化的服务会被重新创建。

### ⚠️ 注意事项

- Compose 适合描述“服务组合”，单个一次性命令仍然可以直接使用 `docker run`。
- `depends_on` 只保证启动顺序，不保证数据库等服务已经完全可用；应用本身仍然需要重试连接。
- 配置文件中的相对路径以 Compose 文件所在目录为基准。
- 不要把密码直接写进公开的 Compose 文件，可以使用 `.env` 文件或外部密钥管理。
- `docker compose down -v` 会删除匿名卷，执行前要确认不会误删重要数据。

## 🛠️ 第三方管理工具

除了命令行之外，还有不少优秀的 Web 管理面板，可以让日常的容器维护工作更加直观 👀。

### Dockhand

[Dockhand](https://github.com/jhuckaby/dockhand) 是一个轻量的 Docker 容器管理面板，提供可视化的容器管理界面。可以方便地查看容器状态、日志、资源使用情况，执行容器操作（启动、停止、重启等），简化 Docker 容器的日常管理工作。

```yaml
services:
  dockhand:
    image: fnsys/dockhand:latest
    container_name: dockhand
    restart: unless-stopped
    ports:
      - 23000:3000
    volumes:
      - /var/run/docker.sock:/var/run/docker.sock
      - ./dockhand-data:/app/data
```

### Portainer

[Portainer](https://github.com/portainer/portainer) 是非常流行的 Docker 可视化管理面板，几乎是自托管玩家装机必备。功能非常全面：容器、镜像、网络、卷、Swarm 集群、Compose 一键部署都能在 Web 界面完成。

```yaml
services:
  portainer:
    image: portainer/portainer-ce:lts
    container_name: portainer
    restart: always
    ports:
      - "8000:8000"
      - "9443:9443"
    volumes:
      - /var/run/docker.sock:/var/run/docker.sock
      - portainer_data:/data

volumes:
  portainer_data:
```

部署完成后访问 <https://localhost:9443>，首次进入会引导创建管理员账户。

### Dockge

[Dockge](https://github.com/louislam/dockge) 是一款主打「以 Compose 文件为中心」的轻量管理面板。配合自带的 stacks 目录，编辑 `compose.yaml` 就能实时同步启动状态，特别适合习惯直接写 compose 配置而不是点鼠标的用户。

![](https://github.com/louislam/dockge/assets/1336778/e7ff0222-af2e-405c-b533-4eab04791b40)

```yaml
services:
  dockge:
    image: louislam/dockge:1
    restart: unless-stopped
    ports:
      # Host Port : Container Port
      - 5001:5001
    volumes:
      - /var/run/docker.sock:/var/run/docker.sock
      - ./data:/app/data

      # If you want to use private registries, you need to share the auth file with Dockge:
      # - /root/.docker/:/root/.docker

      # Stacks Directory
      # ⚠️ READ IT CAREFULLY. If you did it wrong, your data could end up writing into a WRONG PATH.
      # ⚠️ 1. FULL path only. No relative path (MUST)
      # ⚠️ 2. Left Stacks Path === Right Stacks Path (MUST)
      - C:\Users\techs\Desktop\docker:/opt/stacks
    environment:
      # Tell Dockge where is your stacks directory
      - DOCKGE_STACKS_DIR=/opt/stacks
      - DOCKGE_ENABLE_CONSOLE=true
```
