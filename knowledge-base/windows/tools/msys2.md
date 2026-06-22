---
title: "msys2"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
  - linux
categories:
  - Windows
---

msys2 是一套用于创建 Windows 应用程序的工具集，提供了类似 Linux 的命令行界面和接口。虽然 Windows 现在有了 wsl（Linux 子系统）功能，但是如果要开发 Windows 应用程序的话，还是最好装一个 msys2，而且 msys2 使用起来也很方便。

## 安装 📦

可以直接用 winget 来安装 msys2。

```powershell
winget install msys2.msys2
```

如果已经装了 scoop，也可以用它来安装。

```sh
scoop install msys2
```

安装完成后根据提示运行一次 msys2 终端，然后重启一下其他终端，初始化工作就算完成了。

### 添加清华镜像 🪞

默认的镜像源在国内访问比较慢，建议切换到清华镜像。

```sh
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686' /etc/pacman.d/mirrorlist.mingw32
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64' /etc/pacman.d/mirrorlist.mingw64
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/ucrt64' /etc/pacman.d/mirrorlist.ucrt64
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/clang64' /etc/pacman.d/mirrorlist.clang64
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch' /etc/pacman.d/mirrorlist.msys
```

然后刷新一下镜像源缓存。

```sh
pacman -Sy
```

## 环境分类 🏷️

MSYS2 提供了多个不同的环境，每个环境都基于不同的工具链和运行时：

| 环境        | 工具链           | 说明                                                                                       |
| ----------- | ---------------- | ------------------------------------------------------------------------------------------ |
| **MSYS2**   | GCC (MSYS2 原生) | 基础 POSIX 环境，用于运行 MSYS2 自身的工具和包管理器，不适合开发原生 Windows 程序          |
| **MinGW64** | MinGW-w64 GCC    | 64 位 Windows 原生开发环境，使用传统的 MSVCRT 运行时，兼容性最好                           |
| **MinGW32** | MinGW-w64 GCC    | 32 位 Windows 原生开发环境，用于需要 32 位支持的场景                                       |
| **UCRT64**  | MinGW-w64 GCC    | 64 位开发环境，使用 Universal C Runtime (UCRT)，是微软推荐的新运行时，Windows 10+ 默认自带 |
| **CLANG64** | LLVM/Clang       | 64 位开发环境，使用 LLVM/Clang 工具链，对 C++ 标准支持更好，编译速度更快                   |

> 💡 一般推荐使用 **UCRT64** 或 **MinGW64**。UCRT64 使用现代运行时，MinGW64 兼容性更好。

## 配置 Shell 🐚

msys2 默认的 bash 用起来比较朴素，可以替换成更现代的 fish 或 zsh。

### 使用 fish 🐟

先安装 fish。

```sh
pacman -S fish
```

然后安装 starship 作为提示符。

```sh
pacman -S mingw-w64-x86_64-starship
```

接着在 `~/.config/fish/config.fish` 中添加配置。

```sh
alias ip='ip -color'
alias ll='ls -l'
alias l='ll -a'

starship init fish | source
```

最后在 `~/.bashrc` 中追加 `exec fish`，这样下次打开 mingw64 终端时就会自动进入 fish。

> ⚠️ 在 msys2 终端中貌似没法直接安装 starship，如果遇到问题需要把 starship 那行配置删掉。

### 使用 zsh 💻

zsh 也是一个不错的选择。

```sh
pacman -S zsh grml-zsh-config
```

编辑 `~/.bashrc`，添加 `exec zsh` 即可让 zsh 成为默认 shell。如果弹出 zsh 的默认配置菜单，选择 0 创建一个空的 `.zshrc` 即可消除提示。

## 开发环境 🛠️

有了 msys2 之后，就可以在 Windows 下搭建各种 Linux 风格的开发环境了。

### Ruby 💎

首先用 scoop 安装 ruby。

```sh
scoop install ruby
```

然后运行 `ridk` 脚本，安装剩余的 msys2 工具链。

```sh
ridk install
```

完成后就可以在 Windows 下愉快地使用 Ruby 了。
