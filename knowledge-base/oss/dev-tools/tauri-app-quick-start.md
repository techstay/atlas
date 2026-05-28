---
title: "Tauri App快速上手"
date: 2022-02-20T17:22:56+08:00
tags:
  - tauri
  - windows
categories:
  - dev
---

Tauri 是一个基于前端的开发图形化界面程序的技术，和 Electron 相比体积更小。这也是一个很有潜力的项目，不过目前使用的人数不是很多。这里简单介绍一下如何在 Windows 上配置 Tauri 开发环境。

## 配置环境

### 安装 MSVC 编译器

首先下载安装 MSVC 编译器工具，如果你没有安装 Visual Studio 的话，需要从下面的网址手动下载安装编译器。如果你已经安装了最新的 Visual Studio 2022 的话，那么在 Visual Studio Installer 中安装 C++ 工作负载。

编译器下载地址： <https://visualstudio.microsoft.com/zh-hans/visual-cpp-build-tools/>

### Node.js 运行时

推荐使用 nvm 管理多版本的 Node.js。这里使用 scoop 来安装。

```sh
scoop install nvm
```

安装完毕之后，用 nvm 安装最新的长期支持版 Node.js。

```sh
nvm install lts
# 在管理员权限的powershell中运行
nvm use lts
```

最后用下面的命令来确认安装，如果出现了前面带星号的版本号就说明成功的安装和启用 Node.js 了。

```sh
$ nvm list

  * 16.14.0 (Currently using 64-bit executable)
```

默认的 npm 包管理器不太好用，所以这里改用 pnpm 工具。下面的命令在 Node 16.13 之后的版本中都可用。

```sh
corepack enable
```

如果需要更新 pnpm，那么就可以用下面的命令。

```sh
pnpm add -g pnpm
```

### 安装 Rust 编译器

Rust 官方推荐使用 Rustup 来安装 Rust，这里同样通过 scoop 来安装 rustup。安装完毕后，rustup-init 命令应该会自动执行并开始安装 rust 开发环境。

```sh
scoop install rustup
```

最后检测一下 Rust 编译器是否安装成功。

```sh
$ rustup show

Default host: x86_64-pc-windows-gnu
rustup home:  C:\Users\techstay\scoop\persist\rustup\.rustup
```

Rust 的包管理器 Cargo 默认速度很慢，所以如果你有代理的话，最好配置一下。方法很简单，在 powershell 终端中运行下面的命令即可。

```powershell
[Environment]::SetEnvironmentVariable("CARGO_HTTP_PROXY", "localhost:8083", "User")
```

### 安装 WebView2

访问<https://developer.microsoft.com/en-us/microsoft-edge/webview2/#download-section>，下载和安装 WebView2。

## 创建项目

### 使用模板创建项目

用 npx 命令创建模板项目，然后按照提示进行选择。

```sh
npx create-tauri-app
```

等待运行完毕之后，切换进入项目，检测一下项目所需的工具是否安装完全。

```sh
cd tauri-app
npm run tauri info
```

### 预览项目

如果需要的话，也可以在浏览器中实时预览项目效果。

```sh
npm run tauri dev
```

### 生成项目

项目开发完毕之后，就可以开始构建了。

```sh
npm run tauri build
```
