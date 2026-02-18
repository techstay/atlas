# powershell

## 环境配置

### 开发环境

首先要安装最新版的 powershell，推荐使用 winget 安装，虽然也可以通过 scoop 下载安装，不过 vscode 和 windows terminal 等程序不会识别，需要自己手动配置 powershell 的位置，反而麻烦一些。

- winget `winget install microsoft.powershell`

vscode 需要安装以下扩展，并按照下面进行配置。

- powershell
- Code Runner

```json
{
  "[powershell]": {
    "editor.defaultFormatter": "ms-vscode.powershell"
  },
  "editor.formatOnSave": true,
  "editor.renderControlCharacters": true,
  "editor.renderWhitespace": "all",
  "files.autoGuessEncoding": true,
  "files.autoSave": "onFocusChange",
  "powershell.buttons.showPanelMovementButtons": true,
  "powershell.codeFormatting.autoCorrectAliases": true,
  "powershell.codeFormatting.avoidSemicolonsAsLineTerminators": true,
  "powershell.codeFormatting.pipelineIndentationStyle": "IncreaseIndentationAfterEveryPipeline",
  "powershell.codeFormatting.preset": "OTBS",
  "powershell.codeFormatting.trimWhitespaceAroundPipe": true,
  "powershell.codeFormatting.useConstantStrings": true,
  "powershell.codeFormatting.useCorrectCasing": true,
  "powershell.codeFormatting.whitespaceBetweenParameters": true,
  "powershell.integratedConsole.forceClearScrollbackBuffer": true,
  "powershell.integratedConsole.suppressStartupBanner": true,
  "powershell.powerShellDefaultVersion": "PowerShell Core 7(x64)",
  "powershell.promptToUpdatePowerShell": false,
  "code-runner.executorMap": {
    "powershell": "pwsh -ExecutionPolicy ByPass -NoProfile -File"
  }
}
```

运行代码直接使用右上角的运行按钮，或者从菜单栏选择*运行->以非调试模式运行*或者按*Ctrl+F5*。

还可以额外安装几个 powershell 模块,增加额外的功能.

```powershell
Install-Module -Name PSScriptAnalyzer -Force
Install-Module -Name Pester -Force -SkipPublisherCheck
Install-Module Microsoft.PowerShell.Crescendo -Force
Install-Module Microsoft.PowerShell.SecretManagement
Install-Module Microsoft.PowerShell.SecretStore
```

### 终端美化

美化方法参考我的[笔记](https://studynotes.techstay.tech/notes/windows/WindowsTerminalExperience.html)，配置文件参考我的[dotfiles](https://github.com/techstay/dotfiles-windows/blob/main/Documents/PowerShell/Microsoft.PowerShell_profile.ps1)

## 学习

### 官方文档

官方文档目录 <https://docs.microsoft.com/en-us/powershell/scripting/how-to-use-docs>

关于主题包含了 powershell 的语法知识，如果需要了解基本的语法，就可以查阅这里。

<https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about>

powershell 的常用命令，如果需要了解 powershell 的命令就查看这里。

<https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core>

要将 powershell 命令组合成实用的脚本，还需要一些辅助命令，可以在这里查看。

- [microsoft.powershell.management](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/)
- [Microsoft.powershell.utility](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/)

想要深入了解 powershell 的话，继续阅读文档。

<https://docs.microsoft.com/en-us/powershell/scripting/learn/deep-dives/overview>

### Powershell 101

官方文档还有一本电子书[Powershell 101](https://docs.microsoft.com/en-us/powershell/scripting/learn/ps101/00-introduction)，也是一本很好的 powershell 学习材料。

## 代码

- [pwsh-samples](./pwsh-samples/README.md)，powershell 示例代码
- [techstay-util](./techstay-utils/README.md)，我的 pwsh 工具库
