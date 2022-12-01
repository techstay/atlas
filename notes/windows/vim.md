# vim 安装笔记

简单记录了一下在 windows 系统下安装 vim 的笔记。

首先需要安装 neovim。

```powershell
scoop install neovim
```

## 配置集

### SpaceVim

安装[SpaceVim](https://spacevim.org/quick-start-guide/)。

```powershell
git clone https://github.com/SpaceVim/SpaceVim.git $HOME\.SpaceVim
New-Item $env:LOCALAPPDATA\nvim -ItemType SymbolicLink -Value $HOME\.SpaceVim
```

打开 nvim 开始插件安装过程。

### NvChad

安装 [NvChad](https://nvchad.com/quickstart/install)。

```powershell
git clone https://github.com/NvChad/NvChad $HOME\AppData\Local\nvim --depth 1 && nvim
```

卸载 NvChad

```powershell
rd -r ~\AppData\Local\nvim
rd -r ~\AppData\Local\nvim-data
```

### LunarVim

安装[LunaVim](https://www.lunarvim.org/docs/installation)。

```powershell
$LV_BRANCH='release-1.2/neovim-0.8'; Invoke-WebRequest https://raw.githubusercontent.com/LunarVim/LunarVim/master/utils/installer/install.ps1 -UseBasicParsing | Invoke-Expression
```

卸载 LunarVim。

```powershell
Invoke-WebRequest https://raw.githubusercontent.com/lunarvim/lunarvim/master/utils/installer/uninstall.ps1 -UseBasicParsing | Invoke-Expression
```
