---
title: "Windows沙盒快速入门"
date: 2022-02-25T02:10:42+08:00
tags:
  - 沙盒
  - windows
categories:
  - windows
---

在沙盒中运行未知程序可以提高系统的安全性，而 Windows 也自带了沙盒功能。

## 启用沙盒

在管理员权限的 powershell 中运行，可能需要重启系统：

```powershell
Enable-WindowsOptionalFeature -FeatureName Containers-DisposableClientVM -Online -All
```

## 沙盒配置

如果需要还可以对沙盒进行配置，[微软官方](https://docs.microsoft.com/zh-cn/windows/security/threat-protection/windows-sandbox/windows-sandbox-configure-using-wsb-file) 对此有详细说明。

下面是一个简单的示例配置文件，文件需要使用后缀名 `.wsb` 保存。之后就可以直接双击文件按照自定义配置启动沙盒了。

```xml
<MappedFolders>
  <MappedFolder>
    <HostFolder>absolute path to the host folder</HostFolder>
    <SandboxFolder>absolute path to the sandbox folder</SandboxFolder>
    <ReadOnly>value</ReadOnly>
  </MappedFolder>
  <MappedFolder>
  </MappedFolder>
</MappedFolders>
```

## 使用 Sandboxie

如果你不喜欢 Windows 自带的沙盒，也可以使用 Windows 下知名的沙盒软件 Sandboxie，目前已经转为开源免费的软件。软件分为经典版 Classic 和加强版 Plus，经典版是老版本并且缺少维护，推荐直接下载安装加强版，下载地址<https://github.com/sandboxie-plus/Sandboxie/releases>。
