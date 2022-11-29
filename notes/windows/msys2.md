# msys2 安装笔记

## 安装

```powershell
winget install msys2.msys2
```

添加清华镜像。

```sh
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686' /etc/pacman.d/mirrorlist.mingw32
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64' /etc/pacman.d/mirrorlist.mingw64
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/ucrt64' /etc/pacman.d/mirrorlist.ucrt64
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/clang64' /etc/pacman.d/mirrorlist.clang64
sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch' /etc/pacman.d/mirrorlist.msys
```

然后刷新镜像源。

```sh
pacman -Sy
```

## 配置

### 使用 fish

先安装 fish。

```sh
pacman -S fish
```

然后安装 starship。

```sh
pacman -S mingw-w64-x86_64-starship
```

最后在`.config/fish/config.fish`中添加配置。

```sh
alias ip='ip -color'
alias ll='ls -l'
alias l='ll -a'

starship init fish | source
```

要让 fish 成为默认 shell，直接在`.bashrc`中添加`exec fish`即可。这样下次打开 ming64 msys2 的时候就生效了。

比较可惜的是在 msys2 终端中貌似没法安装 starship，要在 msys2 中使用只能删掉 starship 那行。

### 使用 zsh

安装 zsh 和配置。

```sh
pacman -S zsh grml-zsh-config
```

编辑`.bashrc`，添加`exec zsh`即可让 zsh 成为默认 shell。如果弹出 zsh 的默认配置菜单，选择 0 创建一个空的`.zshrc`即可消除提示。
