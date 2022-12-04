# Windows 高级终端体验

## 准备工作

首先需要配置好包管理器，方便安装一些软件。

- [scoop](./scoop.md)，第三方版的包管理器，主要用来安装绿色版软件
- winget，微软的包管理器，用命令行的方式安装 Store 和 Win32 程序

终端模拟器使用微软官方的 Windows Terminal。

```powershell
winget install Microsoft.WindowsTerminal
```

还需要安装一些 nerd fonts，支持特殊字符。

```powershell
scoop install FantasqueSansMono-NF-Mono Meslo-NF-Mono Iosevka-NF-Mono
```

:::warning
在 Windows 11 22H2 系统上，可能会出现提示，表示使用普通方式安装的用户字体可能无法生效。遇到这种情况，可以按照提示，改用管理员权限将字体安装为系统字体。

```powershell
scoop install sudo
sudo scoop install -g Iosevka-NF-Mono
```

:::

为了方便使用管理员权限，还要安装 gsudo。

```powershell
scoop install gsudo
```

starship 是一个跨平台的终端主题框架，使用 rust 编写，支持多种 shell。

```powershell
scoop install starship
```

编辑配置文件所使用的的文本编辑器为 vscode，如果不想使用的话，也可以将下面所有使用`code`的地方改为`notepad`，用记事本来打开，但是没有高亮和补全，并不适合编辑配置文件。

```powershell
winget install Microsoft.VisualStudioCode
```

## Windows Terminal

Windows Terminal 是现在 Windows 11 默认终端软件，相当好用。

## 通用配置

打开设置，进行以下配置，部分选项只在 Windows 11 中可用。

- _启动->默认配置文件_，改为 Powershell，使用最新版的 powershell 作为默认 shell。
- _启动->默认终端应用程序_，改为 Windows Terminal，这样以后就见不到讨厌的 cmd 窗口了。
- _外观->在选项卡行中使用亚力克材料_，启用。
- _配置文件->默认值->外观->字体_，采用刚刚安装的几个 nerdfonts 字体，按个人喜好选择一个。
- _配置文件->默认值->外观->字号_，如果对字体大小不满意，也可以调整有一下字号
- _配置文件->默认值->外观->透明度->启用亚力克材料_，启用，然后设置不透明度，个人感觉 80%以上为好，太透明了看不清终端
  如果安装了 Git 的话，可以将 Git Bash 添加到 Windows Terminal 中。

需要编辑配置文件的话，点击设置右下角的*打开 JSON 文件*。如果没有在 vscode 中打开，需要在设置中修改默认程序。或者在终端中根据路径打开配置文件。

```powershell
code $HOME\AppData\Local\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json
```

### 使用管理员权限打开 Windows Terminal

#### gsudo

第一种是通过第三方`gsudo`来启用管理员权限。这样会添加一个管理员权限的窗格，打开的时候会弹出 UAC，打开的管理员权限终端和原本的 Windows Terminal 在一个窗口内。

需要首先安装`gsudo`这个包。

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

现在 Windows Terminal 的 shell 配置中新增了`elevate`属性，设为`true`以后，窗格就会在管理员权限的新窗口中打开。

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

## 各 Shell 配置

### Windows Powershell

系统默认安装的 powershell 版本为 5。在 Windows Terminal 中打开 Windows PowerShell 终端，输入`code $PROFLIE`以打开配置文件。

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

之后，编辑配置文件`code $PROFLIE`，添加以下内容。注意，默认 powershell(WindowsPowershell，版本为 5)和现在安装的 powershell(版本为 7)配置文件不同，安装的包也各自独立，两者需要各自配置。

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

上面安装的`z.lua`是一个目录跳转插件，使用`z`代替`cd`切换目录时，会自动记录历史记录。下次切换的时候，无需输入完整路径，只输入部分目录名就能切换，可以节约不少时间，详情可以参考[官方中文文档](https://github.com/skywind3000/z.lua/blob/master/README.cn.md)。

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

在 git bash 终端中，输入`code ~/.bashrc`，添加下面一行，以使用 starship。

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
