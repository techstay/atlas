# archlinux

ArchLinux 系发行版的安装和配置。

## 最小化安装

个人使用 archlinux 的方式是在虚拟机里使用官方镜像执行最小化安装，然后将虚拟机设置为开机自启。这样可以得到类似 WSL 的效果，占用的系统资源比较低，同时也没有 WSL 的问题，最重要的是可以和一些常见的模拟器共存，而不是只能使用 HyperV。

### 下载镜像

- [阿里云镜像](http://mirrors.aliyun.com/archlinux/iso/latest/)
- [清华大学镜像](https://mirrors.tuna.tsinghua.edu.cn/archlinux/iso/latest/)

下载的时候最好同时下载校验文件，方便确认文件的完整性。

```sh
# 几种校验方式选择一种
md5sum -c md5sums.txt
gpg --keyserver-options auto-key-retrieve --verify archlinux.iso.sig
```

### 安装

archwiki 有官方安装指导，可以一步一步跟着安装，实际操作起来也不难。不过现在有了更简单的安装方式，那就是使用 archinstall 安装脚本，这是 Python 写成的库，专门用来管理 archlinux 的安装。启动安装镜像，直接执行`archinstall`，然后按照提示选择即可。现在 archinstall 采用菜单式操作，更加容易安装了。

## Arch 衍生版

### ArchLinuxGUI

这个项目简称[ALG](https://archlinuxgui.in)，是向那些不喜欢命令行界面安装的用户提供的图形化界面安装方式，拥有 Plasma、Gnome、Xfce、窗口管理器等多种风味，可以满足不同用户的需求。

安装这个版本和其他那些拥有图形界面的版本类似，按照提示进行就可以，这里不再做更多介绍。

### archcraft

archcraft 是一个基于 arch 的衍生版，它对 arch 的修改较小，主要进行了一些主题方面的定制，适合像我这样想要酷一点界面但是又不喜欢自己折腾的人。官网还提供了大量截图可以查看 <https://archcraft.io/gallery.html>

缺点就是社区力量比较小，支持较慢，XFCE 桌面版每半年更新一次，这对于一个滚动发行版来说有点慢了。下载地址： <https://github.com/archcraft-os/archcraft-xfce/releases>。

安装的时候需要注意一下，安装镜像默认不包含中文字体，如果在安装界面选择中文的话，只能显示成方块。所以需要在安装之前，现在终端里执行下面两条命令把中文字体先安装好，然后就可以正常显示中文了。

```sh
sudo pacman -Sy
sudo pacman -S noto-fonts-cjk
```

### Manjaro

Manjaro 是比较流行的 arch 衍生版，可以作为想要体验 arch 系又不想通过命令行安装的用户的首选。在虚拟机里面使用的话推荐 xfce 桌面环境，更加节省资源。下载地址： <https://manjaro.org/downloads/official/xfce/>。

### garuda

garuda 是我目前在真机上安装的 arch 衍生版，优点是默认的桌面很好看，同时内置了一套功能丰富的配置工具。下载地址： <https://garudalinux.org/downloads.html>。

### endeavouros

endeavouros 是另外一个很流行的 arch 衍生版，在安装的时候几乎可以选择所有的桌面环境。下载地址：<https://endeavouros.com> 。

## 系统配置

ArchLinux 作为一个定制性极强的系统，系统的大部分配置都可以根据自身情况修改。但是 arch 系发行版的配置并不完全一样，所以这里的配置可能并不适用于所有 arch 系发行版，这一点需要注意。

### 无界面 arch 配置

这里假设从 archinstall 安装的系统还没有创建自定义用户，直接通过 root 用户登录操作。

创建用户。

```sh
newuser=techstay
useradd $newuser -m -G wheel -s /bin/zsh
passwd $newuser
```

然后启用用户的免密码 sudo 权限，方便后面执行命令。

```sh
newuser=techstay
echo "$newuser ALL=(ALL:ALL) NOPASSWD: ALL" | sudo tee "/etc/sudoers.d/$newuser"
```

后面的配置比较通用，不同的 arch 衍生版也可以作为参考。

### 代理配置

有代理的话，推荐自己设置一个代理脚本，方便在网络不通的时候使用。

#### zsh

创建`~/.proxy.sh`文件，内容如下。

```sh
proxy_host="THISPC"
proxy_port="7890"

function setproxy() {
  export all_proxy="http://$proxy_host:$proxy_port"
  export http_proxy="http://$proxy_host:$proxy_port"
  export https_proxy="http://$proxy_host:$proxy_port"
  export NO_PROXY=localhost,::1,.example.com
}

function unsetproxy() {
  export all_proxy=""
  export http_proxy=""
  export https_proxy=""
}
```

然后在`.zprofile`中 source 该文件。

```sh
tee -a .zprofile <<'EOF'
source ~/.proxy.sh
EOF
```

重新登录以后就可以用这两个函数开关代理了。

#### fish

fish 有自己的自动加载目录，需要将两个函数创建到对应的目录中，文件名也要匹配。

```sh
# ~/.config/fish/functions/setproxy.fish
function setproxy
    set proxy_host THISPC
    set proxy_port 7890
    set -gx all_proxy "http://$proxy_host:$proxy_port"
    set -gx http_proxy "http://$proxy_host:$proxy_port"
    set -gx https_proxy "http://$proxy_host:$proxy_port"
    set -gx NO_PROXY 'localhost,::1,.example.com'
end

# ~/.config/fish/functions/unsetproxy.fish
function unsetproxy
    set -gx all_proxy ''
    set -gx http_proxy ''
    set -gx https_proxy ''
end
```

设置好代理之后，下面的克隆工作就会比较方便的运行了。

### 必备包

先安装一些必备的包。

```sh
sudo pacman -S --needed openssh zsh git yadm fish starship reflector \
  inetutils \
  exa base-devel ntp iptables-nft wget curl nano vim grml-zsh-config
```

这时候就可以进入 zsh 或者 fish 来执行命令，比默认的 bash 方便不少。

### 远程登录

```sh
systemctl enable sshd
systemctl start sshd
```

### pacman 配置

我这里清华镜像源的速度最快，所以直接将清华镜像源添加到`/etc/pacman.d/mirrorlist`最前面。

```sh
sudo sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch' /etc/pacman.d/mirrorlist
sudo pacman -Syy
```

也可以通过`reflector`来测速并设置镜像源。注意并不是所有的 arch 衍生版都带有`reflector`这个包，manjaro 就没有，不过 manjaro 有自己的`pacman-mirrors`命令。

```sh
sudo pacman -S reflector
sudo reflector -c China -n 5 --sort rate --save /etc/pacman.d/mirrorlist
# manjaro
sudo pacman-mirrors -c China
```

启用 pacman 彩色输出。

```sh
sudo sed -i 's/^#Color/Color/g' /etc/pacman.conf
```

一些衍生版使用自己的镜像文件来安装，当衍生版镜像过期的时候，用户自己更新系统可能会出现问题。如果打包软件包的密钥过期，就会导致安装失败，这时候可以编辑`/etc/pacman.conf`文件，临时在配置文件前面添加一行全局配置，信任所有包，让更新过程顺利进行。在系统成功更新之后，应当及时删除这行配置。

```ini
SigLevel = TrustAll
```

有时候个别软件源无法访问，可以刷新一下 DNS 缓存。

```sh
sudo systemd-resolve --flush-caches

sudo resolvectl flush-caches
```

### sudo 免密码

```sh
echo "$(whoami) ALL=(ALL:ALL) NOPASSWD: ALL"|sudo tee /etc/sudoers.d/"$(whoami)"
```

### 第三方仓库

除了直接使用 AUR 的软件之外，还可以添加一些第三方仓库。

```sh
# 添加chaotic-aur的软件源
sudo pacman-key --recv-key FBA220DFC880C036 --keyserver keyserver.ubuntu.com
sudo pacman-key --lsign-key FBA220DFC880C036
sudo pacman -U 'https://cdn-mirror.chaotic.cx/chaotic-aur/chaotic-keyring.pkg.tar.zst' 'https://cdn-mirror.chaotic.cx/chaotic-aur/chaotic-mirrorlist.pkg.tar.zst'

# 配置pacman.conf文件
sudo tee -a /etc/pacman.conf <<'EOL'
[chaotic-aur]
Include = /etc/pacman.d/chaotic-mirrorlist

[archlinuxcn]
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
EOL

# 安装密钥环
sudo pacman -Sy && sudo pacman -S archlinuxcn-keyring
```

之后就可以安装这些仓库里面的软件了。

### paru

paru 是一个使用 rust 编写的 AUR 安装程序，在启用了 chaotic-aur 后可以直接从仓库中安装。

```sh
sudo pacman -S paru
```

### 配置区域和语言

因为我主要使用 SSH 连接，所以将系统全局语言设置为中文是没有问题的。但是这样做会导致 tty 界面乱码。遇到此类问题时可以将全局语言设为英文，然后将用户语言设为中文。

```sh
sudo sed -i 's/^# \?zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/g' /etc/locale.gen
sudo locale-gen

sudo localectl set-locale LANG=zh_CN.UTF-8
echo 'LANG=zh_CN.UTF-8' | sudo tee /etc/locale.conf
echo 'LANG=zh_CN.UTF-8' | tee ~/.config/locale.conf

sudo timedatectl set-timezone Asia/Shanghai
sudo timedatectl set-ntp 1
sudo ntpdate ntp.ntsc.ac.cn
```

### 微码

微码包含了处理器厂商的修复和优化，建议安装。根据处理器的不同，安装下列之一。

```sh
sudo pacman -S intel-ucode
sudo pacman -S amd-ucode
```

### grub 配置

将 grub 超时时间设置为 1 秒。

```sh
sudo nano /etc/default/grub

# 修改这一行
GRUB_TIMEOUT=1
```

然后生成新的 grub 配置。

```sh
sudo update-grub
# 一些发行版没有这个命令，只能使用原始命令
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

### 安装其他软件

如果有其他要安装的软件，别忘了安装。

```sh
#! /bin/bash

# 一些语言和类库
sudo pacman -S --noconfirm --needed jdk-openjdk openjdk-doc \
  openjdk-src gradle groovy scala kotlin maven \
  python ruby nodejs ghc typescript autopep8 npm python-pip ruby-bundler \
  dotnet-sdk lua go

# zsh相关
sudo pacman -S --noconfirm --needed zsh \
  zsh-doc zshdb grml-zsh-config

# 杂项
sudo pacman -S --noconfirm --needed neofetch \
  cowsay sl man-db shellcheck curl wget vim nano \
  powerline-vim yadm shfmt thefuck ufw nmap \
  iptables-nft fd fzf ntp exa subversion man bat bottom asciiquarium
```

## 系统美化

### 启用虚拟机功能

如果在 vmware 虚拟机中安装 arch，那么需要需要安装对应的虚拟机工具才能启用剪贴板复制等高级功能。

```sh
sudo pacman -S open-vm-tools
sudo systemctl enable vmtoolsd.service vmware-vmblock-fuse.service
sudo systemctl start vmtoolsd.service vmware-vmblock-fuse.service
```

一些衍生版增强了对虚拟机的支持，直接安装即可启用，无需额外配置。

```sh
# 软件包名可能是open-vm-tools-desktop
sudo pacman -S open-vm-tools
```

### 字体美化

首先要安装几个常用的字体。

```sh
sudo pacman -S --needed adobe-source-han-sans-cn-fonts \
  adobe-source-han-sans-jp-fonts adobe-source-han-sans-tw-fonts \
  noto-fonts noto-fonts-cjk noto-fonts-emoji ttf-sarasa-gothic
```

默认情况下的字体显示一般般，参考 <https://szclsya.me/zh-cn/posts/fonts/linux-config-guide/> 进行字体配置。

```sh
mkdir -p ~/.config/fontconfig && cd ~/.config/fontconfig
wget https://raw.githubusercontent.com/szclsya/dotfiles/master/fontconfig/fonts.conf
```

### shell 美化

推荐使用 dotfiles 方式管理配置文件，以后就可以随时随地同步配置了。

```sh
yadm clone https://github.com/techstay/dotfiles-public.git
```

然后选择 zsh 或者 fish 作为默认 shell。

```sh
chsh -s /usr/bin/fish
chsh -s /bin/zsh
```

powerline 主题的一些字符可能不会正常显示，这时候需要安装支持 powerline 的字体。

```sh
paru -S nerd-fonts-fantasque-sans-mono ttf-meslo-nerd-font-powerlevel10k
```

默认的终端程序也可能无法正常显示 powerline 字体，可以安装 kitty，能完美显示 powerline 字符。

在配置 kitty 的时候，可以通过以下命令查看 kitty 找到的字体。

```sh
kitty +list-fonts --psnames
```
