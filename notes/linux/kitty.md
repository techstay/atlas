# kitty

kitty 是一个显示效果极佳的 Linux 终端模拟器，对 powerline 字体支持很好。

安装字体

```sh
paru -S nerd-fonts-fantasque-sans-mono ttf-meslo-nerd-font-powerlevel10k
```

然后使用 kitty 扫描一下字体，只有扫描到的字体才可以应用。

```sh
kitty +list-fonts --psnames
```

最后在`kitty.conf`中指定要使用的字体名称即可。
