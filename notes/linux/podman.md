# podman

## 开始使用

### 安装

- [windows 安装](https://github.com/containers/podman/blob/main/docs/tutorials/podman-for-windows.md)
- [podman desktop](https://podman-desktop.io)

### 拉取镜像

拉取 docker 镜像要添加`docker.io/`前缀。

```sh
podman run --rm docker.io/hello-world
```

拉取 podman 镜像

```sh
podman run --rm quay.io/podman/hello
```

拉取 github 镜像

```sh
podman pull ghcr.io/dreamacro/clash-premium
```

### root 方式启动

```sh
podman machine stop
podman set --rootful
podman machine start
```

### 自动启动

```sh
mkdir -p ~/.config/systemd/user/
podman generate systemd --new --name <name-of-your-container> -f \
  ~/.config/systemd/user/<name-of-your-container>.service
systemctl --user daemon-reload
systemctl --user enable <name-of-your-container>.service
```
