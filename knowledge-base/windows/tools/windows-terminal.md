---
title: "WindowsTerminal"
date: 2026-05-15T01:18:06+08:00
tags:
  - windows
categories:
  - Windows
---

## 准备工作

### 包管理器

- [scoop](scoop.md)，第三方版的包管理器，主要用来安装绿色版软件
- winget，微软的包管理器，用命令行的方式安装 Store 和 Win32 程序

### 终端模拟器

```powershell
winget install Microsoft.WindowsTerminal
```

### 支持特殊字符的字体

还需要安装一些 nerd fonts，支持特殊字符。如果不知道怎么选择字体，还可以到 [codingfont](https://www.codingfont.com/) 和 [programmingfonts](https://www.programmingfonts.org) 这两个网站上选择。

```powershell
scoop install FantasqueSansMono-NF-Mono Meslo-NF-Mono Iosevka-NF-Mono
```

### 管理员权限运行

```powershell
scoop install gsudo
```

编辑配置文件所使用的的文本编辑器为 vscode，如果不想使用的话，也可以将下面所有使用 `code` 的地方改为 `notepad`，用记事本来打开，但是没有高亮和补全，并不适合编辑配置文件。

```powershell
winget install Microsoft.VisualStudioCode
```

## Windows Terminal

## 通用配置

需要编辑配置文件的话，点击设置右下角的*打开 JSON 文件*。如果没有在 vscode 中打开，需要在设置中修改默认程序。或者在终端中根据路径打开配置文件。

```powershell
code $HOME\AppData\Local\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json
```

### 管理员权限配置

#### gsudo

第一种是通过第三方 `gsudo` 来启用管理员权限。这样会添加一个管理员权限的窗格，打开的时候会弹出 UAC，打开的管理员权限终端和原本的 Windows Terminal 在一个窗口内。

需要首先安装 `gsudo` 这个包。

```powershell
scoop install gsudo
```

然后在 Windows Terminal 配置中添加下面一段。

```json
{
  "list": [
    {
      "guid": "{41dd7a51-f0e1-4420-a2ec-1a7130b7e950}",
      "name": "Windows PowerShell Elevated",
      "commandline": "gsudo.exe pwsh.exe",
      "hidden": false,
      "icon": "https://i.imgur.com/kZeD6EN.png"
    }
  ]
}
```

#### 自带配置

现在 Windows Terminal 的 shell 配置中新增了 `elevate` 属性，设为 `true` 以后，窗格就会在管理员权限的新窗口中打开。

```json
{
    "commandline": "C:\\Program Files\\PowerShell\\7\\pwsh.exe",
    "elevate": true,
    "guid": "{41dd7a51-f0e1-4420-a2ec-1a7130b7e950}",
    "hidden": false,
    "icon": "https://i.imgur.com/kZeD6EN.png",
    "name": "Windows PowerShell Elevated"
},
```

## 使用 Starship

starship 是一个跨平台的终端主题框架，使用 rust 编写，支持多种 shell。

```powershell
scoop install starship
```

### Windows Powershell

系统默认安装的 powershell 版本为 5。在 Windows Terminal 中打开 Windows PowerShell 终端，输入 `code $PROFLIE` 以打开配置文件。

然后添加下面一行。

```powershell
Invoke-Expression (&starship init powershell)
```

保存之后，重启打开 powershell 终端即可生效。

### PowerShell

要日常使用的话，建议安装最新版的 powershell。

```powershell
winget install Microsoft.PowerShell
```

安装完成后，Windows Terminal 应该会自动识别并添加 Powershell 标签页入口。打开 powershell 终端，然后安装下列模块。

```powershell
Install-Module posh-git -Force
Install-Module Terminal-Icons -Force
Install-Script pwshfetch-test-1 -Force
# z.lua，目录跳转插件
scoop install lua
git clone https://github.com/skywind3000/z.lua.git $HOME/z.lua
```

之后，编辑配置文件 `code $PROFLIE`，添加以下内容。注意，默认 powershell(WindowsPowershell，版本为 5) 和现在安装的 powershell(版本为 7) 配置文件不同，安装的包也各自独立，两者需要各自配置。

```powershell
Import-Module posh-git

# terminal-icons
Import-Module -Name Terminal-Icons

# set utf-8 encoding
$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding

Invoke-Expression (&starship init powershell)
# z.lua
Invoke-Expression (& { (lua $HOME/z.lua/z.lua --init powershell enhanced fzf) -join "`n" })

# Alias
Set-Alias winfetch pwshfetch-test-1
```

配置完成后，打开 powershell 终端，即可生效。

上面安装的 `z.lua` 是一个目录跳转插件，使用 `z` 代替 `cd` 切换目录时，会自动记录历史记录。下次切换的时候，无需输入完整路径，只输入部分目录名就能切换，可以节约不少时间，详情可以参考 [官方中文文档](https://github.com/skywind3000/z.lua/blob/master/README.cn.md)。

一些工具带有补全，可以让 powershell 更加智能。

```powershell
New-Item -Type Directory -Force -Path $PROFILE/../Completions
gh completion -s powershell | Out-File -FilePath $PROFILE/../Completions/gh.ps1
hugo completion powershell | Out-File -FilePat $PROFILE/../Completions/hugo.ps1
```

### cmd

先安装 clink。

```powershell
winget install chrisant996.Clink
```

然后在 powershell 中运行下列命令，配置 clink。

```powershell
Set-Content $env:LocalAppData\clink\starship.lua @'
load(io.popen('starship init cmd'):read("*a"))()
‘@
```

### git bash

如果使用 scoop 安装了 Git。

```json
{
  "commandline": "\"%USERPROFILE%\\scoop\\apps\\git\\current\\bin\\bash.exe\" -i -l",
  "guid": "{f2db9a16-ad00-49df-914a-8d71b94454d4}",
  "name": "Git Bash",
  "startingDirectory": "%USERPROFILE%",
  "icon": "%USERPROFILE%\\scoop\\apps\\git\\current\\mingw64\\share\\git\\git-for-windows.ico"
}
```

如果使用安装包安装了 Git。

```json
{
  "guid": "{cbcc2468-c750-459a-964f-d893042386a1}",
  "hidden": false,
  "name": "Git Bash",
  "commandline": "\"%PROGRAMFILES%\\git\\usr\\bin\\bash.exe\" -i -l",
  "startingDirectory": "%USERPROFILE%",
  "icon": "%PROGRAMFILES%\\Git\\mingw64\\share\\git\\git-for-windows.ico"
}
```

在 git bash 终端中，输入 `code ~/.bashrc`，添加下面一行，以使用 starship。

```sh
eval "$(starship init bash)"
```

### starship 主题选择

starship 自带了几套主题，可以在这里查看<https://starship.rs/presets/>。点击图片即可进入详情。

例如我这里使用的就是*pastel-powerline*主题，可以通过下面的命令直接配置。配置正确后，直接在终端中按回车即可生效。

```powershell
starship preset pastel-powerline > ~/.config/starship.toml
```

我的配置文件参考 <https://github.com/techstay/dotfiles-windows>。

## 使用 oh-my-posh

如果觉得 starship 自带的主题较少，也可以试试 [oh-my-posh](https://ohmyposh.dev/docs)，主题非常丰富。

### 安装

```sh
scoop install https://github.com/JanDeDobbeleer/oh-my-posh/releases/latest/download/oh-my-posh.json
```

### powershell

编辑配置文件 `code $PROFILE`，添加下面一行。

```sh
oh-my-posh init pwsh | Invoke-Expression
```

重新打开终端，即可看到效果。使用 powershell 的话，还可以使用 `Get-PoshThemes` 命令查看所有主题的演示效果，最好在 git 仓库中打开，可以显示较为完整的效果。

### 更换主题

在 [官网主题页](https://ohmyposh.dev/docs/themes) 挑选好主题，再修改配置文件。

```powershell
oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/montys.omp.json" | Invoke-Expression
```
