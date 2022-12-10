# nushell

一个数据驱动的跨平台现代 shell。

## 开始使用

### 安装

windows 安装

```sh
winget install nushell
```

### 环境

目前我使用 vscode 作为开发环境，但是 vscode 的 nushell 扩展生态还不是很完善，只有基本的高亮和补全等功能，调试、代码格式化等功能并没有跟上，只能寄希望于将来 nushell 生态继续完善了。

运行代码采用最原始的办法，终端切换进入对应目录，手动运行 shell 文件来执行。

- [nushell vscode 扩展](https://github.com/nushell/vscode-nushell-lang)

TODO: 目前所有代码均未格式化，只能等将来扩展补上这些功能了。

### 帮助

查看命令的帮助。

```nushell
help str
```

## 配置

### 默认配置文件

默认配置文件由`$nu.config-path`和`$nu.env-path`指定。

```sh
code $nu.config-path
```

修改默认编辑器`buffer_editor`

```nushell
let-env config = {
  ...

  buffer_editor: "code"
  ...
}
```

以后就可以用`config env`或`config nu`来编辑配置文件了。

### 美化

#### starship

输入`config env`，添加以下两行。

```nushell
mkdir ~/.cache/starship
starship init nu | save ~/.cache/starship/init.nu
```

输入`config nu`，在末尾添加以下一行。

```nushell
source ~/.cache/starship/init.nu
```

#### oh-my-posh

通过 scoop 安装，会同时安装 oh-my-posh 程序和主题配置文件(路径由环境变量`POSH_THEMES_PATH`指定)。

```sh
scoop install https://github.com/JanDeDobbeleer/oh-my-posh/releases/latest/download/oh-my-posh.json
```

字体安装(需要管理员权限)，也可以自己手动安装 nerdfonts。

```sh
oh-my-posh font install
```

生成默认配置

```sh
oh-my-posh init nu
```

输入`config nu`，在末尾添加以下一行。

```sh
source ~/.oh-my-posh.nu
```

主题可以在[这里](https://ohmyposh.dev/docs/themes)查看，要更换主题，重新生成一下配置文件。

```nushell
oh-my-posh init nu --config $"($env.POSH_THEMES_PATH)/M365Princess.omp.json"
```

### 自动跳转

安装

```cmd
scoop install zoxide
```

生成配置文件

```nushell
zoxide init nushell | save ~/.zoxide.nu
```

输入`config nu`，在末尾添加一行。

```nushell
source ~/.zoxide.nu
```
