# zsh

## 开始使用

### 安装

首先要安装 zsh。

```sh
sudo pacman -S zsh
sudo apt install zsh
```

然后将其设为默认 shell。

```sh
chsh -s /bin/zsh
```

### grml-zsh-config

如果使用 ArchLinux 的话，可以直接安装`grml-zsh-config`，提供了一个用户友好的默认 zsh 配置，安装完成后会自动修改`/etc/zsh/zshrc`，无需额外配置即可应用。

```sh
sudo pacman -S grml-zsh-config
```

不是 ArchLinux 的话也可以手动下载`.zshrc`配置文件。

```sh
wget -O .zshrc https://git.grml.org/f/grml-etc-core/etc/zsh/zshrc
wget -O .zshrc.local  https://git.grml.org/f/grml-etc-core/etc/skel/.zshrc
```

### zim

zim 是一个强大的 zsh 配置工具。

```sh
curl -fsSL https://raw.githubusercontent.com/zimfw/install/master/install.zsh | zsh
```

安装完成后会创建两个配置文件`.zimrc`和`.zshrc`，前者是 zim 的配置文件，指定要 zim 的配置和要安装的插件；后者是 zsh 的配置文件，指定用户的配置。

zim 自带了一些模块，例如 git、ssh、archive 等，需要什么就可以启用什么，在这里也可以安装一些其他插件例如`z.lua`等。下面是我的`.zimrc`的部分片段，启用了几个模块，并使用特别好看的 p10k 终端主题。

```sh
zmodule archive
zmodule exa
zmodule fzf
zmodule ruby
zmodule ssh

zmodule skywind3000/z.lua --cmd 'export _ZL_HYPHEN=1' --cmd 'eval "$(lua {}/z.lua --init zsh enhanced once)"'
zmodule romkatv/powerlevel10k
```

在`.zimrc`里面配置好插件之后，需要手动调用`zimfw install`来安装才可以使用。将来如果想要更新插件的话，使用`zimfw update`就可以更新了。用户的 alias 等则要在`.zshrc`里面进行配置。

这里也顺便列举了我自己的 zim 配置文件，使用之前最好安装下面几个包。

```sh
sudo pacman -S --needed zsh lua thefuck fd fzf exa vim
```

然后将几个文件复制到自己的家目录下，然后切换到 zsh 终端，等待 zim 安装完成后就可以使用了。

```sh
wget -O .zimrc https://raw.githubusercontent.com/techstay/myNote/main/linux/zsh/.zimrc
wget -O .zshrc https://raw.githubusercontent.com/techstay/myNote/main/linux/zsh/.zshrc
wget -O .p10k.zsh https://raw.githubusercontent.com/techstay/myNote/main/linux/zsh/.p10k.zsh
```
