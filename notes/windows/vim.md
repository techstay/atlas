# vim 安装笔记

简单记录了一下在 windows 系统下安装 vim 的笔记。

首先需要安装 vim 或者 neovim。

```powershell
scoop install vim
```

然后克隆 spacevim 的仓库。

```powershell
git clone https://github.com/SpaceVim/SpaceVim.git $HOME\.SpaceVim
```

并为 vim 创建符号链接，指向 spacevim 的仓库。

```powershell
# vim
New-Item $HOME\vimfiles -ItemType SymbolicLink -Value $HOME\.SpaceVim
# neovim
New-Item $env:LOCALAPPDATA\nvim -ItemType SymbolicLink -Value $HOME\.SpaceVim
```

最后打开 vim，即可开始安装 spacevim 插件，等安装完成再次打开 vim 即可享受 spacevim 的体验了。
