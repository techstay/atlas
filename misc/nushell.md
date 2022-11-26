# nushell

## 安装

安装后，自动在 Windows Terminal 中创建配置文件，可从标签页直接启动。

```cmd
winget install nushell
```

## 主题配置

先安装 starship。

```sh
scoop install starship
```

创建 starship 的配置文件。

```sh
mkdir ~/.cache/starship
starship init nu | save ~/.cache/starship/init.nu
```

最后在 nushell 配置文件末尾添加(使用`code $nu-config-path`打开配置文件)。

```nu
source ~/.cache/starship/init.nu
```

如果遇到下列错误，打开`~/.cache/starship/init.nu`文件，找到`let width = (term size | get columns | into string)`一行，删除`term size`后面的`-c`参数。该命令不支持`-c`参数，不清楚为什么生成的配置会添加该参数。

```txt
Error: nu::parser::unknown_flag (link)

  × The `term size` command doesn't have flag `-c`.
   ╭─[entry #7:1:1]
 1 │ term size -c
   ·            ┬
   ·            ╰── unknown flag
   ╰────
  help: use term size --help for a list of flags
```
