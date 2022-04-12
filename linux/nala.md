# nala

[nala](https://github.com/volitank/nala)是一个高颜值的 apt 替代工具，支持平行下载。

## 开始使用

### 安装

目前只支持 64 位系统。

```sh
echo "deb [arch=amd64,arm64,armhf] http://deb.volian.org/volian/ scar main" | sudo tee /etc/apt/sources.list.d/volian-archive-scar-unstable.list
wget -qO - https://deb.volian.org/volian/scar.key | sudo tee /etc/apt/trusted.gpg.d/volian-archive-scar-unstable.gpg > /dev/null
sudo apt update && sudo apt install nala
```

### 使用

和 apt 的用法基本相同，可以当成 apt 来用。

```sh
sudo nala install neofetch
```

### 平行下载

nala 默认情况下每个镜像会同时下载两个包，理论上最高可以达到 16 倍的速度。如果某个镜像下载失败，nala 会自动切换到其他镜像。

### fetch

nala 也可以根据根据速度选择最合适的镜像。

```sh
sudo nala fetch
```

### 历史

nala 还支持历史查看功能，可以查看当前系统使用 nala 安装的用户以及安装的软件包，甚至可以撤销操作。

```sh
sudo nala history

  ID    Command                 Date and Time              Altered    Requested-By
  1     install neofetch        2022-04-12 20:40:41 CST         63    root (0)
  2     install zsh             2022-04-12 20:42:51 CST          4    root (0)
  3     install iputils-ping    2022-04-12 20:47:42 CST          3    root (0)
```

### shell 补全

nala 自带 bash 补全，同时兼容 zsh。要在 zsh 中使用，将下面几行添加到`.zshrc`中即可。

```sh
autoload bashcompinit
bashcompinit
source /usr/share/bash-completion/completions/nala
```
