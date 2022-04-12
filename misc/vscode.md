# vscode

微软开发的一款开源跨平台编辑器，基于 Electron，拥有强大的扩展生态。

## 安装

可以直接下载安装或者通过 scoop 等包管理器安装。

- 直接下载安装<https://code.visualstudio.com>
- scoop 安装`scoop install vscode`

## 配置

### 配置文件

通过左下角的齿轮图标并选择设置，即可打开 vscode 的配置界面，在这里可以配置 vscode 编辑器以及各类扩展的功能。

当然，如果是高级用户，也可以直接按 `F1` 打开命令面板，输入`pref json`，打开 JSON 格式的配置文件直接编辑配置，要分享配置的话这种方式更加直接。

当然配置文件编辑多了就会很乱，所以我通常会同时安装`sort json object`扩展来将 JSON 配置文件排序，方便读写。

### 主题

vscode 的外观也是可以配置的，在扩展市场可以搜索安装各类颜色主题、文件图标主题和产品图标主题，颜色主题可以通过各种配色方案更改 vscode 的界面，文件图标主题则会更改文件图标，产品图标主题则会更改 vscode 最左侧的一系列产品图标。

这里有一篇颜色主题的文章可供参考[50-vs-code-themes-for-2020](https://dev.to/softwaredotcom/50-vs-code-themes-for-2020-45cc)。

### 字体

中文字体推荐思源黑体和思源等宽，英文字体推荐`Liberation Mono`，，终端字体推荐`Meslo-NF-Mono`，可以通过 scoop 来安装这些字体。这里的带`NF`的是 nerd-fonts 字体，在原版字体的基础上增加了一些特殊符号的支持。

```powershell
# 先要启用字体分类
scoop bucket add nerd-fonts
scoop install Source-Han-Mono-SC Source-Han-Mono-TC Source-Han-Sans-SC Source-Han-Sans-TC Source-Han-Sans-J
scoop install LiberationMono-NF
scoop install Meslo-NF-Mono
```

安装完成后需要在 vscode 中设置，对应的 JSON 配置如下：

```json
{
  "editor.fontFamily": "'LiterationMono NF', 'Liberation Mono', 'Jetbrains Mono', '思源黑体', Consolas, monospace",
  "editor.fontLigatures": true,
  "editor.fontSize": 18,
  "terminal.integrated.fontFamily": "MesloLGS NF",
  "terminal.integrated.fontSize": 12
}
```

### 自动保存和格式化

格式化功能是我使用编辑器的一个重要痛点，一个强大的格式化功能不仅可以让文字和代码更加美观易读，同时也可以帮助作者减少错误，在团队中也可以帮助不同的成员统一风格，具有重要的意义。

vscode 的生态十分广泛，对于很多主流语言和格式都有对应的格式化器，安装之后通过`Ctrl + Shift + F`快捷键即可启用格式化。配合编辑的自动保存和保存时格式化功能，即可享受优雅的格式化体验。

这里使用的[prettier](https://marketplace.visualstudio.com/items?itemName=esbenp.prettier-vscode)是一个极为流行的扩展，安装量将近两千万次，可以格式化多种主流语言。本项目的 MarkDown 格式文件也是有 prettier 格式化的，会自动在中英文之间加一个空格，完美符合我的要求。

```json
{
  "editor.defaultFormatter": "esbenp.prettier-vscode",
  "editor.formatOnSave": true,
  "files.autoSave": "onFocusChange"
}
```

当然，有时候自动格式化也不是万能的，这时候你可以针对单个类型的文件关闭自动保存和格式化功能，让文件内容保持原样。

## 扩展

vscode 的另一项能力就是强大的扩展生态，当初这个生态还是 Atom 编辑器领先，后来 vscode 凭借自己的实力逐渐赶上，直到远程开发这个杀手级功能出现，直接领先其他编辑器一个段位，vscode 也借此成为了江湖第一位的编辑器。

这里简单列举几个重要的 vscode 扩展。

- prettier，功能强大的格式化扩展
- remote，远程开发
- gitlens，强大的 git 管理扩展
- code runner，一键运行单个代码文件
- tabnine，强大的 AI 补全扩展
- copilot，比 tabnine 更加强大的 AI 补全扩展，甚至可以根据注释自动生成代码，无敌了
