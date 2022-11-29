# wsl

Windows Subsystem for Linux 是 Windows 的一项功能，可以开启一个和 Windows 系统深度集成的虚拟机，方便运行各种 linux 程序。

## 安装

### 启用 wsl

使用以下命令一键开启 wsl。

```powershell
wsl --install
```

安装完成后可能需要重启电脑。

### 在线发行版

wsl 自带几个受官方支持的发行版，可以直接安装。

```powershell
wsl --list --online

以下是可安装的有效分发的列表。
请使用“wsl --install -d <分发>”安装。

NAME            FRIENDLY NAME
Ubuntu          Ubuntu
Debian          Debian GNU/Linux
kali-linux      Kali Linux Rolling
openSUSE-42     openSUSE Leap 42
SLES-12         SUSE Linux Enterprise Server v12
Ubuntu-16.04    Ubuntu 16.04 LTS
Ubuntu-18.04    Ubuntu 18.04 LTS
Ubuntu-20.04    Ubuntu 20.04 LTS
```

### 安装 archwsl

或者也可以安装自定义发行版，例如 archwsl，可以通过 scoop 安装。

```powershell
scoop install archwsl
```

安装完成后需要新建用户。

```sh
# root密码
passwd
# 新建用户
user_name=techstay
echo "$user_name ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/$user_name
useradd -m -G wheel -s /bin/bash $user_name
passwd $user_name
```

然后退出 wsl，设置 arch 的默认用户。

```powershell
Arch.exe config --default-user techstay
```

接下来进入 arch，继续配置包管理器。

```sh
sudo pacman-key --init
sudo pacman-key --populate
sudo pacman -Syy archlinux-keyring
# 直接将清华镜像添加到列表第一行
sudo sed -i '1i Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch' /etc/pacman.d/mirrorlist
# 或者使用reflector
sudo pacman -S reflector
sudo reflector --country "China" --protocol https --sort rate --save /etc/pacman.d/mirrorlist
# 更新系统
sudo pacman -Syu
```

再配置系统语言。

```sh
sudo sed -i 's/^# \?zh_CN.UTF-8 UTF-8/zh_CN.UTF-8 UTF-8/g' /etc/locale.gen
sudo locale-gen
echo 'LANG=zh_CN.UTF-8' | sudo tee /etc/locale.conf
```

## 配置 wsl

### 设置内存

wsl 默认会占用系统一半的内存，如果需要设定可以编辑`$HOME/.wslconfig`配置文件，文件内容如下。

```conf
[wsl2]
memory=4GB
nestedVirtualization=false
```

### 设定动态端口号范围

开启 wsl 之后，windows 会把默认端口号的映射起始范围降低到 1024，会导致有时候一些常用的端口号无法使用，具体表现为依赖端口号的程序会无法运行，但是通过各种程序又发现对应的端口号并没有被占用。这时候需要将端口号的起始范围重新设为一个较高的值。

查看当前动态端口号范围。

```powershell
Get-NetTCPSetting|select SettingName, DynamicPortRange*
```

如果起始范围是 1024，那么需要重新设定一次动态端口号范围。

```powershell
Set-NetTCPSetting -DynamicPortRangeStartPort 40000 -DynamicPortRangeNumberOfPorts 10000
```
