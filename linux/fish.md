# fish 配置

首先安装 fish。

```sh
sudo pacman -S fish
```

然后安装 starship，需要 sudo 权限将其安装到系统目录。如果你使用 arch 等发行版，软件仓库里有 starship，推荐直接从软件仓库安装。

```sh
curl -sS https://starship.rs/install.sh | sh
```

安装完成后编辑`.config/fish/config.fish`配置文件，添加以下内容。

```sh
alias ip='ip -color'
alias ll='ls -l'
alias l='ll -a'
alias ls='exa --icons --group-directories-first'
alias lzd='docker run --rm -it -v /var/run/docker.sock:/var/run/docker.sock -v ~/.config/lazydocker:/.config/jesseduffield/lazydocker lazyteam/lazydocker'

starship init fish | source
```

这样就完成了 fish 的配置，最后将 fish 设为默认 shell 即可。starship 主题会使用一些 powerline 字体，推荐安装`Meslo NF`或者`FantasqueSansMono NF`这样的字体。

```sh
chsh -s /usr/bin/fish
```
