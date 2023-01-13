# vim

## 安装

首先需要安装 neovim。

```powershell
scoop install neovim
```

## 学习资源

- vimtutor，最经典的 vim 学习教程。直接在 linux 终端里运行该命令即可，这会使用 vim 打开`vimtutor`文件，你可以一边阅读一遍熟悉 vim 操作，一般多来几遍就可以掌握最基本的 vim 知识了
- [Vim 从入门到精通](https://github.com/wsdjeg/vim-galore-zh_cn)，这是一篇 vim 资料，同样讲解了很多 vim 知识，必看
- [VimGolf](http://www.vimgolf.com)，vim 谜题挑战，包含了众多需要使用 vim 操作解决的问题，通过解决谜题你可以击败对手提升等级
- [vim-adventures](https://vim-adventures.com)，可以练习 vim 操作的冒险游戏，通过娱乐的方式掌握 vim 操作
- [space-vim](https://spacevim.org)，一套开箱即用的 vim 插件和配置，能让你迅速获得一个强大的 vim 环境

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

```sh
# windows
git clone https://github.com/NvChad/NvChad $HOME\AppData\Local\nvim --depth 1 && nvim

# linux
git clone https://github.com/NvChad/NvChad ~/.config/nvim --depth 1 && nvim
```

修改配置参考[官方文档](https://nvchad.com/config/options)，配置文件路径在`$HOME\AppData\Local\nvim\lua\custom`下，在其他位置编辑会被 NvChad 更新时覆盖。

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

## vscode 配置

安装[vscodevim](https://marketplace.visualstudio.com/items?itemName=vscodevim.vim)扩展，参考文档进行配置。

## cheetsheet

[awesome-cheatsheets](https://github.com/techstay/awesome-cheatsheets/blob/master/editors/vim.txt)

## vim 扩展

这里一些扩展可以通过 vscodevim 模拟出来，详见[vscodevim 官方文档](https://github.com/VSCodeVim/Vim)

### sneak.vim

项目地址 <https://github.com/justinmk/vim-sneak>

用法

- `sab`搜索下一个`ab`出现的位置
- `;`继续搜索下一个
- `3;`从当前位置搜索第三次出现的位置
- `ctrl+o`回到原来位置
- `s<enter>`执行上次搜索
- `S`反向搜索

### vim-commentary

项目地址 <https://github.com/tpope/vim-commentary>

用法

- `gc`行注释
- `gc2j`行注释之后的两行
- `gC`块注释
- `gC2j`块注释之后的两行

### vim-surround

项目地址 <https://github.com/tpope/vim-surround>

用法

- `yc<motion><char>`设置环绕字符
- `dc<char>`删除环绕字符
- `cs<motion><char>`更改环绕字符
-
