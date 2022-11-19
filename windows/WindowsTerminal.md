# Windows Terminal

## 安装

- [应用商店](https://www.microsoft.com/en-us/p/windows-terminal/9n0dx20hk701?activetab=pivot:overviewtab)安装
- winget 包管理器安装`winget install Microsoft.WindowsTerminal`

## 配置

现在有了图形化界面的配置，不再需要手动编辑配置文件了。不过有时候还是编辑配置文件更加高效一点，配置文件路径为`'~\AppData\Local\Packages\Microsoft.WindowsTerminal_8wekyb3d8bbwe\LocalState\settings.json'`。

### 终端美化

参考[powershell 美化](../pwsh/pwsh-beautify/README.md)。

### 添加 Git Bash

如果安装了 Git 的话，可以将 Git Bash 添加到 Windows Terminal 中。

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

### 添加远程 SSH

参考[openssh](../linux/openssh.md)先配置好 ssh，然后添加类似下面这样的配置。

```json
{
  "commandline": "ssh arch",
  "guid": "{1e014656-8b46-4a79-aeaf-106f0b989e2d}",
  "name": "arch"
}
```

### 添加管理员权限的标签

虽然 Windows Terminal 官方没有添加这个功能的支持，不过我们也可以利用一些第三方工具自行实现这个功能，参考[这里](https://blog.poychang.net/run-windows-terminal-as-administrator-with-elevated-admin-permissions/)。

需要首先安装`gsudo`这个包。

```powershell
scoop install gsudo
```

然后在 Windows Terminal 配置中添加下面一段。配置之后，对于同一个 Windows Terminal 窗口，只会弹出一次管理员权限认证对话框。

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
