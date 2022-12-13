---
icon: linux
---

# linux

我的 linux 学习笔记，包含了一些常用在 Linux 下的工具的经验和记录。

## 发行版

简单列举一下我尝试过的一些发行版，推荐和现在正在用的会放到最上面。

- Arch，高度可定制化的滚动发行版，适合定制强迫症和追求最新版的人
- Manjaro，基于 Arch，提供了不错的图形界面支持，更适合一般用户
- Garuda，另一个基于 Arch 的发行版，界面很酷，值得尝试
- Mint，基于 Ubuntu，使用体验也不错，在各类排名中不断提升
- Ubuntu，广泛使用的一个发行版，作为很多软件的编译环境
- Fedora，红帽系的系统，也是 Linux 的半壁江山
- Deepin，我觉得目前做的最好的国产发行版

有些发行版的界面做的也不错。

- CuteFish，界面挺好看的
- Zorin OS，
- Nitrux OS，基于 Debian 和 KDE 桌面环境的发行版

## 导入导出密钥

为了方便多设备 git 协作，一个简单办法就是将 SSH 和 GPG 密钥导出到其他系统上。这个工作可以用脚本来完成。

导出密钥的脚本，需在用户主目录执行。

```sh
#!/usr/bin/bash
gpg -o ~/.gnupg/private.gpg --export-options backup --export-secret-keys techstay
gpg --export-ownertrust >~/.gnupg/trust.txt
tar -cvf keys.tar .ssh/id_ed25519{,.pub} .gnupg/{private.gpg,trust.txt}
```

将密钥文件复制到目标机器上。

```sh
# 复制到用户的主文件夹中
scp keys.tar -P 8080 techstay@192.168.25.129:.
scp keys.tar rasp:.
```

导入密钥的脚本。归档文件会自动保存文件权限属性，无需额外操作。

```sh
#!/usr/bin/bash
tar -xvf keys.tar
gpg --import-options restore --import ~/.gnupg/private.gpg
gpg --import-ownertrust <~/.gnupg/trust.txt
```
