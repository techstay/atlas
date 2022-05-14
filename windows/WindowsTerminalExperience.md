# Windows 高级终端体验

## 准备工作

首先需要配置好包管理器，方便安装一些软件。

- scoop，用于安装绿色版软件
- winget，用于安装具有额外安装配置步骤的软件

终端模拟器使用微软官方的 Windows Terminal。

```powershell
winget install Microsoft.WindowsTerminal
```

还需要安装一些 powerline 字体，支持特殊字符，这里推荐两个字体。

- `Meslo-NF-Mono`，中规中矩的字体，可读性高
- `FantasqueSansMono-NF-Mono`，更加活泼一些的字体

```powershell
scoop install FantasqueSansMono-NF-Mono Meslo-NF-Mono
```

为了方便使用管理员权限，还要安装 gsudo。

```powershell
scoop install gsudo
```

starship 是一个跨平台的终端框架，使用 rust 编写，支持多种 shell。

```powershell
scoop install starship
```

部分功能还需要通过 git 来安装。

```powershell
scoop install git-with-openssh
```

之后打开命令提示符窗口，应该就可以看到效果了。

## PowerShell

windows 自带的 powershell 版本较低，所以要先安装最新版的 powershell。

```powershell
winget install Microsoft.PowerShell
```

然后要安装一些模块。

```powershell
Install-Module posh-git -Force
Install-Module Terminal-Icons -Force
Install-Module PSReadLine -AllowPrerelease -Force
Install-Script pwshfetch-test-1 -Force
# z.lua，目录跳转插件
scoop install lua
git clone https://github.com/skywind3000/z.lua.git $HOME/z.lua
```

之后，编辑配置文件`code $PROFLIE`，添加以下内容。

```powershell
Import-Module posh-git

# terminal-icons
Import-Module -Name Terminal-Icons

# PSReadLine
Import-Module PSReadLine
Set-PSReadLineOption -EditMode Windows
Set-PSReadLineOption -PredictionSource HistoryAndPlugin
Set-PSReadLineOption -PredictionViewStyle ListView
Set-PSReadLineOption -BellStyle None
Set-PSReadLineKeyHandler -Chord 'Ctrl+d' -Function DeleteChar

Invoke-Expression (&starship init powershell)
# z.lua
Invoke-Expression (& { (lua $HOME/z.lua/z.lua --init powershell once enhanced fzf) -join "`n" })

# Alias
Set-Alias winfetch pwshfetch-test-1
```

## cmd

先安装 clink。

```powershell
winget install chrisant996.Clink
```

然后编辑 clink 的配置文件，添加 starship 的配置。

```powershell
Set-Content $env:LocalAppData\clink\starship.lua @'
load(io.popen('starship init cmd'):read("*a"))()
‘@
```

## Windows Terminal

对应的 WT 配置文件关键内容如下，使用 powershell 7 作为默认 shell，同时使用 powerline 字体使终端主题可以正常显示，并添加了一个新的管理员权限的 powershell 窗口方便执行提权操作。以下配置也可以通过图形界面来进行配置。

```json
{
  "$help": "https://aka.ms/terminal-documentation",
  "$schema": "https://aka.ms/terminal-profiles-schema",
  "copyFormatting": "none",
  "copyOnSelect": true,
  "defaultProfile": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
  "focusFollowMouse": true,
  "profiles": {
    "defaults": {
      "colorScheme": "Tango Dark",
      "font": {
        "face": "FantasqueSansMono NF",
        "size": 12,
        "weight": "normal"
      },
      "opacity": 85,
      "useAcrylic": true
    },
    "list": [
      {
        "commandline": "%SystemRoot%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe",
        "guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}",
        "hidden": false,
        "name": "Windows PowerShell"
      },
      {
        "commandline": "%SystemRoot%\\System32\\cmd.exe",
        "guid": "{0caa0dad-35be-5f56-a8ff-afceeeaa6101}",
        "hidden": false,
        "name": "\u547d\u4ee4\u63d0\u793a\u7b26"
      },
      {
        "guid": "{574e775e-4f2a-5b96-ac1e-a2962a402336}",
        "hidden": false,
        "name": "PowerShell",
        "source": "Windows.Terminal.PowershellCore"
      },
      {
        "commandline": "gsudo.exe pwsh.exe",
        "guid": "{41dd7a51-f0e1-4420-a2ec-1a7130b7e950}",
        "hidden": false,
        "icon": "https://i.imgur.com/kZeD6EN.png",
        "name": "Windows PowerShell Elevated"
      }
    ]
  },
  "trimBlockSelection": true,
  "useAcrylicInTabRow": true
}
```
