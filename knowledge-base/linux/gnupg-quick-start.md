---
title: "Gnu隐私卫士（gpg)快速入门"
date: 2022-01-19T04:55:23+08:00
tags:
  - gpg
  - linux
categories:
  - linux
---

Gnu Privacy Guard（缩写 GnuPG 或者 gpg） 是一个著名的加密和签名工具，广泛应用于各种场合。很多工具也对 gpg 提供了支持，所以如果你对数据的保密和安全有一定要求，那么学会使用 GnuPG（以下简称 gpg） 可以说是一项必备技能。

## 安装 gpg

大部分 linux 发行版自带 gpg，无需安装即可使用。如果你使用 windows 系统的话，就需要自己安装 gpg 了。安装方法也很简单，下载安装 [gpg4win](https://www.gpg4win.org) 安装包即可，安装包同时包含了 [Kleopatra](https://apps.kde.org/kleopatra/) 这个界面美观的 gpg 图形界面程序，方便 windows 用户使用。

gpg4win 的配置文件遵循 windows 风格，位于 `$home\AppData\Roaming\gnupg` 下，如果你已经用 Git Bash 等方式创建了 gpg 密钥，那么在 `~/.gnupg` 下已经有配置文件了，要让 Kleopatra 能够找到密钥，还需要使用符号链接的方式共享配置文件。

```powershell
New-Item -path $home\AppData\Roaming\gnupg -ItemType SymbolicLink -Value $home\.gnupg\
```

我个人是两种方式都有使用，所以把两个路径链接起来了。后面不在区分配置文件的路径，你在编辑的时候应该注意一下。

为了更好的保护 gpg 密钥，你还可以使用火绒或者类似工具对 gpg 配置目录设置访问权限，防止未经授权的访问。

## 密钥管理

### 创建密钥

现在推荐创建 ED25519 格式的密钥，更加安全而且计算速度更快。ED25519 的格式不在默认的 gpg 选项中，需要添加 `--expert` 参数才能选择。我在每个部分都做了注释说明，你应该很容易就能看明白。

```sh
# 输入下面一行命令开始创建密钥
$ gpg --full-generate-key --expert
gpg (GnuPG) 2.2.32-unknown; Copyright (C) 2021 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

# 因为我们要使用ED25519算法，所以要先选择ECC也就是椭圆加密算法
请选择您要使用的密钥类型：
   (1) RSA 和 RSA （默认）
   (2) DSA 和 Elgamal
   (3) DSA（仅用于签名）
   (4) RSA（仅用于签名）
   (7) DSA（自定义用途）
   (8) RSA（自定义用途）
   (9) ECC 和 ECC
  (10) ECC（仅用于签名）
  (11) ECC（自定义用途）
  (13) 现存的密钥
 （14）卡中现有密钥
您的选择是？ 9

# 然后选择ED25519算法
请选择您想要使用的椭圆曲线：
   (1) Curve 25519
   (3) NIST P-256
   (4) NIST P-384
   (5) NIST P-521
   (6) Brainpool P-256
   (7) Brainpool P-384
   (8) Brainpool P-512
   (9) secp256k1
您的选择是？ 1

# 这里设定密钥的有效期，例如2w就是两周，4m就是4个月，3y就是3年
# 你在私人电脑上使用的话，就算设定永不过期也没关系
# 对安全性有要求的话，可以设定1年有效期，然后到期重新续签，不过我觉得大部分人都用不着
请设定这个密钥的有效期限。
         0 = 密钥永不过期
      <n>  = 密钥在 n 天后过期
      <n>w = 密钥在 n 周后过期
      <n>m = 密钥在 n 月后过期
      <n>y = 密钥在 n 年后过期

密钥的有效期限是？(0) 0
密钥永远不会过期
这些内容正确吗？ (y/N) y

# 下面需要输入个人信息，名字和电邮是公开可见的，为了保护隐私，你完全不用输入真实姓名和私人电邮
# 但是因为一些服务要求验证电邮，所以电邮还是要输入你自己的电邮
GnuPG 需要构建用户标识以辨认您的密钥。

真实姓名： techstay
电子邮件地址： lovery521@gmail.com
注释：
您选定了此用户标识：
    “techstay <lovery521@gmail.com>”

更改姓名（N）、注释（C）、电子邮件地址（E）或确定（O）/退出（Q）？ o

# 密钥创建完成后还需要输入密码来保护
# 私人电脑的话，不用密码保护也没关系
我们需要生成大量的随机字节。在质数生成期间做些其他操作（敲打键盘
、移动鼠标、读写硬盘之类的）将会是一个不错的主意；这会让随机数
发生器有更好的机会获得足够的熵。
我们需要生成大量的随机字节。在质数生成期间做些其他操作（敲打键盘
、移动鼠标、读写硬盘之类的）将会是一个不错的主意；这会让随机数
发生器有更好的机会获得足够的熵。
gpg: 密钥 0xE4414A4C6D777E2F 被标记为绝对信任
gpg: 吊销证书已被存储为‘/home/techstay/.gnupg/openpgp-revocs.d/CEF918120220D7C28991F7F3E4414A4C6D777E2F.rev’
公钥和私钥已经生成并被签名。

pub   ed25519/0xE4414A4C6D777E2F 2022-01-31 [SC]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                              techstay <lovery521@gmail.com>
sub   cv25519/0xF0C1DEE0526760E3 2022-01-31 [E]
```

这样，一个 gpg 密钥就创建成功了。这里还有几点需要说明一下。上面输出中的 `0xE4414A4C6D777E2F` 是密钥的哈希值，可以用来区分不同的密钥，称作 keyid。密钥也可以用 uid 也就是创建密钥时输入的名字和电邮来指定。

你应该注意到这里同时创建了一个吊销证书，这其实和 gpg 的工作机制有关。gpg 允许你将公钥上传到公钥服务器以供大家互相交换公钥，但是公钥服务器上的公钥只能修改不能删除，所以假如你的密钥遗失或者被盗导致公钥不再使用的话，就需要吊销证书来让公钥失效。特别地，如果你使用密码来保护密钥的话，那么一定要妥善保存吊销证书，因为一旦忘记密码你甚至无法为加密的密钥生成吊销证书。

### 查看密钥

刚刚创建好的密钥其实是一对公钥和私钥，要查看它们，使用以下的命令。

```sh
gpg --list-secret-keys
gpg --list-keys
```

为了显示 keyid 以及指纹，需要添加下面两个参数。

```sh
gpg --list-secret-keys --keyid-format=0xlong --with-fingerprint
gpg --list-keys --keyid-format=0xlong --with-fingerprint
```

每次查看都要输入一遍参数实在是很烦，这时候可以编辑 `~/.gnupg/gpg.conf` 配置文件来更改 gpg 的默认行为。

```sh
keyid-format 0xlong
with-fingerprint
```

[Github](https://github.com/ioerror/duraconf/blob/master/configs/gnupg/gpg.conf) 上也有一个最佳实践的配置文件可供参考，建议直接下载使用这个配置文件，其中有一行 gpg 无法识别，会显示警告信息，删除或者注释这一行都可以。

配置完成之后的密钥应该会以下面的形式显示。你应该会注意到这里其实有两个密钥，后面还跟了不同的大写字母以表示不同的用途。其中 sec 和 pub 代表私钥和公钥，ssb 和 sub 代表子私钥和子公钥，S 代表签名，C 代表验证，E 代表加密。这也正是 gpg 推荐的最佳实践，主密钥用来签名和验证，而加密解密通过子密钥来进行。当你创建密钥的时候，gpg 会自动为你创建好主密钥和一个用于加密解密的子密钥。

```sh
$ gpg --list-secret-keys
gpg: 正在检查信任度数据库
gpg: marginals needed: 3  completes needed: 1  trust model: pgp
gpg: 深度：0  有效性：  1  已签名：  0  信任度：0-，0q，0n，0m，0f，1u
/home/techstay/.gnupg/pubring.kbx
---------------------------------
sec   ed25519/0xE4414A4C6D777E2F 2022-01-31 [SC]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                     [ 绝对 ] techstay <lovery521@gmail.com>
ssb   cv25519/0xF0C1DEE0526760E3 2022-01-31 [E]

$ gpg --list-keys
/home/techstay/.gnupg/pubring.kbx
---------------------------------
pub   ed25519/0xE4414A4C6D777E2F 2022-01-31 [SC]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                     [ 绝对 ] techstay <lovery521@gmail.com>
sub   cv25519/0xF0C1DEE0526760E3 2022-01-31 [E]
```

### 备份密钥

备份密钥前，首先需要查看一下密钥，确定要备份的密钥。

```sh
gpg --list-secret-keys
```

然后使用下面的命令备份密钥，该命令导出的时候会同时导出公钥和私钥，所以不用分别导出一次。

```sh
gpg -o private.gpg --export-options backup --export-secret-keys <key-id>
```

之后就可以重新导入密钥了。

```sh
gpg --import-options restore --import private.gpg
```

这样导入的密钥会丢失信任信息，所以备份的时候可以同时备份信任信息。有两种方式可以备份信任信息，第一种是直接复制 `~/.gnupg/trustdb.gpg`，第二种是将信任信息导出为文本。

```sh
# 导出信任信息
gpg --export-ownertrust > trust.txt

# 导入信任信息
gpg --import-ownertrust < trust.txt
```

### 吊销密钥

当密钥不再使用的时候，就需要吊销密钥，防止被他人滥用。你可能发现了，在创建密钥的时候，会同时在 `~/.gnupg/openpgp-revocs.d` 下创建一个吊销证书。

```txt
gpg: 吊销证书已被存储为‘/home/techstay/.gnupg/openpgp-revocs.d/CEF918120220D7C28991F7F3E4414A4C6D777E2F.rev’
```

该文件用于在紧急状况下吊销密钥，文件内容如下。

```txt
这是一份针对此 OpenPGP 密钥的吊销证书：

pub   ed25519/0xE4414A4C6D777E2F 2022-01-31 [S]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                            techstay <lovery521@gmail.com>

吊销证书就像是一种“紧急按钮”，用来公开地
声明一个密钥将不再被使用。 一旦一个这样的
吊销证书被发布之后，就不可能撤回。

使用它来吊销这个密钥是一种折衷的方法，或者在私钥丢失的
时候使用。然而只要私钥仍然可被访问，更好的做法是生成一
个新的吊销证书并给定一个吊销理由。更多的细节请参阅
 GnuPG 手册中关于 gpg 命令“--generate-revocation”的描述。

为了避免意外使用了此文件，一个冒号已经被插入到了下面的
5 个短横线之前。在导入和发布此吊销证书之前，请使用一个
文本编辑器来移除此冒号。

:-----BEGIN PGP PUBLIC KEY BLOCK-----
Comment: This is a revocation certificate

iHgEIBYKACAWIQTO+RgSAiDXwomR9/PkQUpMbXd+LwUCYfemaAIdAAAKCRDkQUpM
bXd+L6rnAP9TI/6vtOBQWofGXJEa1YfnrV6c0yLUrKWzqq4bdVHaMgEAmYClVGHY
D1NTnTjzktwmleji/2dVy1ItUbr7SeTFpQ0=
=mf7G
-----END PGP PUBLIC KEY BLOCK-----
```

如果我们按照文件内容的说明将 `BEGIN PGP PUBLIC KEY BLOCK` 前面的冒号删除的话，就可以使用该证书来吊销密钥了。

```sh
gpg --import .gnupg/openpgp-revocs.d/CEF918120220D7C28991F7F3E4414A4C6D777E2F.rev
```

这时候再查看密钥，就会发现密钥已经变成吊销状态了。

```sh
$ gpg --list-secret-keys

/home/techstay/.gnupg/pubring.kbx
---------------------------------
sec   ed25519/0xE4414A4C6D777E2F 2022-01-31 [SC] [吊销于：2022-01-31]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                     [ 吊销 ] techstay <lovery521@gmail.com>

```

假如私钥还能用的话，更好的办法就是自己生成一个吊销证书，并在生成的时候指定吊销理由。

```sh
gpg --output revoke.asc --gen-revoke <key-id>
```

然后将吊销证书导入，即可将密钥吊销。这时候再查看密钥状态就会显示已吊销。

```sh
gpg --import revoke.asc
```

如果你将公钥发布到了公共服务器上，这时候也需要将已吊销的公钥重新发布一次，这样服务器上的公钥状态就会更新为已吊销。

```sh
gpg --keyserver subkeys.pgp.net --send <key-id>
```

### 删除密钥

在吊销证书并发布到公钥服务器上之后，本地的密钥就没用了，可以删除了。

```sh
# 删除私钥
gpg --delete-secret-keys <key-id>

# 删除公钥
gpg --delete-keys <key-id>

# 同时删除公钥和私钥
gpg --delete-secret-and-public-keys <key-id>
```

### 子密钥

如果你需要一个新的密钥来进行验证或者加密操作，可以不创建一个新的密钥，而是直接创建一个子密钥。创建子密钥需要进入 gpg 交互模式编辑当前密钥，如果你要创建的是 ED25519 算法的子密钥的话，同样需要加上专家参数。交互界面和创建密钥时差不多，所以就不完整展示了。

```sh
$ gpg --edit-key --expert techstay

# addkey子命令来创建密钥，根据提示操作
gpg> addkey

# 创建完毕之后需要保存才能生效
gpg> save
```

这时候再次查看，就会发现多出来一个新的子密钥。

```sh
$ gpg --list-secret-keys

/home/techstay/.gnupg/pubring.kbx
---------------------------------
sec   ed25519/0xE4414A4C6D777E2F 2022-01-31 [SC]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                     [ 绝对 ] techstay <lovery521@gmail.com>
ssb   cv25519/0xF0C1DEE0526760E3 2022-01-31 [E]
ssb   ed25519/0x4B2C453C8527C457 2022-01-31 [SA]
```

在编辑模式中可以对子密钥进行操作，子密钥可以单独吊销或者删除。

```sh
gpg --edit-key --expert techstay

# 查看密钥和子密钥
gpg> list

# 选中子密钥，编号从1开始
gpg> key 2

# 吊销子密钥，没有选中子密钥会询问是否吊销整个密钥
gpg> revkey

# 删除子密钥
gpg> delkey

# 最后别忘了保存
gpg> save
```

### 交换公钥

gpg 的很多功能需要双方都持有对方的公钥，所以第一步自然就是交换公钥了。

最直接的办法就是直接交换公钥了，把双方的公钥导出为文件，然后通过线下交流、即时通讯软件、电子邮件等方式交换。导入公钥的时候最好和别人通过另一种可靠的方式确认指纹，公钥和指纹都对应上，我们才能确信导入的公钥就是别人的公钥而不是伪造的。

```sh
# 导出自己的公钥
gpg --armor --output public.key --export <key-id>

# 导入别人的公钥
gpg --import some-public.key
```

为了方便大家交换密钥，就产生了公钥服务器这种集中式的管理方式。你可以将自己的公钥上传到公钥服务器上，这样别人就可以通过公钥服务器搜索和下载。以前的公钥服务器被设计为只能上传公钥而不能删除，这造成了很多问题。所以现在你如果要使用公钥服务器的话，最好使用 `keys.openpgp.org` 这种允许删除公钥的服务器。

首先需要在 `gpg.conf` 中设置为 `keys.openpgp.org` 公钥服务器。

```txt
keyserver hkps://keys.openpgp.org/
```

先查看一下自己的公钥的 keyid。

```sh
$ gpg --list-keys
/home/techstay/.gnupg/pubring.kbx
---------------------------------
pub   ed25519/0xE4414A4C6D777E2F 2022-01-31 [SC]
      密钥指纹 = CEF9 1812 0220 D7C2 8991  F7F3 E441 4A4C 6D77 7E2F
uid                     [ 绝对 ] techstay <lovery521@gmail.com>
sub   cv25519/0xF0C1DEE0526760E3 2022-01-31 [E]
```

然后就可以上传了，openpgp 服务器需要验证电邮，所以需要通过下面的命令来上传。上传完成后会返回一个验证链接，在浏览器中访问，并验证电邮之后，上传的公钥就可以正常访问了，将来也可以通过电邮的方式删除公钥。注意下面这条命令需要在 Git Bash 等兼容 linux 的终端中运行，在 powershell 中运行会失败。

```sh
gpg --export your_address@example.net | curl -T - https://keys.openpgp.org
```

如果无法通过命令行上传，也可以手动上传。先生成公钥文件，然后将文件通过 [网页上传](https://keys.openpgp.org/upload) 的方式上传到服务器上。

```sh
# 生成公钥文件
gpg --export your_address@example.net > my_key.pub
```

搜索别人的公钥就简单多了，通过电邮、keyid 和指纹都可以搜索公钥，推荐使用指纹方式搜索，结果唯一，搜索到以后选择编号就可以下载了。注意只有经过验证的公钥才能以电邮的方式下载，直接上传的公钥是不包含用户信息的。

```sh
gpg --search-key <key-id> [ <fingerprint> ]
```

你可以将自己的公钥和指纹放在自己公开的博客或者网站上，方便其他人下载公钥。

## 加密和解密

gpg 的第一个用法就是加密和解密了，这可以保证文件只有发送方和接收方可以解密，就算密文被第三方截获也无法获得有效信息。

首先是加密，你需要拥有接收方的公钥，接下来就可以加密文件了，默认输出的文件名是 `<原文件名>.gpg`。

```sh
gpg --recipient <keyid> --encrypt <file> [--output <outfile>]
```

解密的时候很简单，指定加密文件即可，不指定输出文件即可在当前路径下解密文件。

```sh
gpg --decrypt <file.gpg> [ --output <file> ]
```

在加密的时候还有几个有用的参数可以指定：

- `--armor, -a`，使用 ASCII 字符加密文件
- `--hidden-recipient <user-id>, -R <user-id>`，隐藏接收方的 ID，不会被追踪

## 签名和验证签名

gpg 的第二个用法就是签名和验证签名，这可以保证一个文件是由原作者发布的，而且没有被第三方篡改。

首先是签名，下面的命令会将文件签名为一个新文件。

```sh
# 签名一个文件，文件被压缩为二进制形式
gpg --sign <file> [ --output <file.gpg> ]
# 明文签名一个文件，文件内容原样保存在签名文件中
gpg --clearsign <file> [ --output <file.asc> ]
```

如果你希望签名文件是一个单独的文件，那么使用下面的命令。很多软件的下载包就是通过这种方式提供验证的，你需要同时下载源文件以及校验文件才能验证。

```sh
# 使用文本文件签名
gpg --armor [ --output <file.sig> ] --detach-sign <file>
# 使用二进制文件签名
gpg [ --output <file.sig> ] --detach-sign <file>
```

验证签名之前，首先要导入签名方的公钥，导入成功之后，验证签名的命令就很简单。如果签名无误，gpg 就会显示“良好的签名”，否则就会产生错误信息。如果签名文件是随源文件同时提供的，你需要将两者放到一起，这样 gpg 才能识别。

```sh
gpg --verify <pgp-file/sig-file>
```

## 为 git 提交签名

git 是一个非常流行的版本控制软件，它使用用户名和电邮来确定提交者，但是却未对提交做验证。这也意味着你可以将用户名和电邮修改成任意一个人来伪造提交。为了解决这个问题，git 提供了使用 gpg 签名提交的功能。像 github 这样的网站也支持验证提交，甚至你还可以启用严格模式，这样的话，所有签名不符合的提交都会被显示为未验证状态。当然，因为签名提交也算提交历史的一部分，所以一旦签名提交，你应该好好保管自己的密钥，不然将来更换密钥的话，历史记录就会全变成未验证，这简直就是一个灾难。

### 上传公钥

首先先查看一下密钥的 keyid。

```sh
gpg --list-keys

pub   ed25519/0x7CDDF9CBDDF9BF2E 2022-02-01 [SC]
      Key fingerprint = 3E00 2217 712E BA30 A53D  485F 7CDD F9CB DDF9 BF2E
uid                   [ultimate] techstay <lovery521@gmail.com>
sub   cv25519/0xD79DC3086AB52118 2022-02-01 [E]
```

然后以文本方式将公钥导出到终端中，这样会显示一段以 `-----BEGIN PGP PUBLIC KEY BLOCK-----` 和 `-----END PGP PUBLIC KEY BLOCK-----` 包裹的公钥段，将公钥整个（包含起始和结束的横线行）复制到剪贴板中。

```sh
gpg --armor --export 0x7CDDF9CBDDF9BF2E
```

或者你使用 powershell 的话，也可以直接用管道的方式复制到剪贴板中。

```powershell
gpg --armor --export 0x7CDDF9CBDDF9BF2E | Set-Clipboard
```

然后在 Github 的 `SSH and GPG keys` 中，将公钥粘贴进去。

### 修改 git 设置

接下来还需要让 git 知道如何签名提交。

```sh
git config --global user.signingkey 0x7CDDF9CBDDF9BF2E
git config --global commit.gpgsign true
```

这样以后使用 git 提交的时候，都会使用我们设置的密钥签名，在上一步也告知了 Github 我们的公钥。这样签名以后 github 就可以验证我们的提交是否为本人了。

### 重新签名个人项目

如果你更换了密钥，之前的所有提交都会变为失效，所以你应该妥善保存自己的密钥。不过假如你的项目属于个人项目，没有多人协作的话，那么就算重新为整个项目签名一次也没有关系。当然，这个操作十分危险，使用之前请确认没有其他人使用你的项目。

然后用下面的命令就可以重新签名整个项目的提交。

```sh
git filter-branch --commit-filter 'git commit-tree -S "$@";' -- --all
```

签名完成后整个项目的历史记录全部变了，所以推送的时候只能强制推送。

```sh
git push --force
```

### 信任 github 公钥

你可能会发现，从 github 网页端编辑的提交虽然在网页上显示为已验证状态，但是在本地查看的时候并没有验证。这是因为 github 网页端的提交使用了 github 自己的密钥，如果你想让本地也接受 github 的提交，那就需要信任 github 的公钥。

首先导入 github 的公钥。

```sh
curl https://github.com/web-flow.gpg | gpg --import
```

然后信任 github 的公钥。

```sh
gpg --edit-key noreply@github.com
gpg> trust
gpg> save
```

## 命令行概览

gpg 命令行帮助。

```sh
$ gpg --help
gpg (GnuPG) 2.2.32-unknown
libgcrypt 1.9.4-unknown
Copyright (C) 2021 Free Software Foundation, Inc.
License GNU GPL-3.0-or-later <https://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Home: /home/techstay/.gnupg
支持的算法：
公钥： RSA, ELG, DSA, ECDH, ECDSA, EDDSA
密文： IDEA, 3DES, CAST5, BLOWFISH, AES, AES192, AES256, TWOFISH,
    CAMELLIA128, CAMELLIA192, CAMELLIA256
散列： SHA1, RIPEMD160, SHA256, SHA384, SHA512, SHA224
压缩：  不压缩, ZIP, ZLIB, BZIP2

语法：gpg [选项] [文件]
签名、检查、加密或解密
默认的操作依输入数据而定

命令：

 -s, --sign                  生成一份签名
     --clear-sign            生成一份明文签名
 -b, --detach-sign           生成一份分离的签名
 -e, --encrypt               加密数据
 -c, --symmetric             仅使用对称密文加密
 -d, --decrypt               解密数据（默认）
     --verify                验证签名
 -k, --list-keys             列出密钥
     --list-signatures       列出密钥和签名
     --check-signatures      列出并检查密钥签名
     --fingerprint           列出密钥和指纹
 -K, --list-secret-keys      列出私钥
     --generate-key          生成一个新的密钥对
     --quick-generate-key    快速生成一个新的密钥对
     --quick-add-uid         快速添加一个新的用户标识
     --quick-revoke-uid      快速吊销一个用户标识
     --quick-set-expire      快速设置一个过期日期
     --full-generate-key     完整功能的密钥对生成
     --generate-revocation   生成一份吊销证书
     --delete-keys           从公钥钥匙环里删除密钥
     --delete-secret-keys    从私钥钥匙环里删除密钥
     --quick-sign-key        快速签名一个密钥
     --quick-lsign-key       快速本地签名一个密钥
     --quick-revoke-sig      快速吊销一个密钥签名
     --sign-key              签名一个密钥
     --lsign-key             本地签名一个密钥
     --edit-key              签名或编辑一个密钥
     --change-passphrase     更改密码
     --export                导出密钥
     --send-keys             将密钥导出到一个公钥服务器上
     --receive-keys          从公钥服务器上导入密钥
     --search-keys           在公钥服务器上搜索密钥
     --refresh-keys          从公钥服务器更新所有密钥
     --import                导入/合并密钥
     --card-status           打印卡片状态
     --edit-card             更改卡片上的数据
     --change-pin            更改卡片的 PIN
     --update-trustdb        更新信任数据库
     --print-md              打印消息摘要
     --server                以服务器模式运行
     --tofu-policy VALUE     设置一个密钥的 TOFU 政策

选项：

 -a, --armor                 创建 ASCII 字符封装的输出
 -r, --recipient USER-ID     为 USER-ID 加密
 -u, --local-user USER-ID    使用 USER-ID 来签名或者解密
 -z N                        设置压缩等级为 N （0 为禁用）
     --textmode              使用规范的文本模式
 -o, --output FILE           写输出到 FILE
 -v, --verbose               详细模式
 -n, --dry-run               不做任何更改
 -i, --interactive           覆盖前提示
     --openpgp               使用严格的 OpenPGP 行为

（请参考手册页以获得所有命令和选项的完整列表）

例子：

 -se -r Bob [文件]          为用户 Bob 签名和加密
 --clear-sign [文件]        创建一个明文签名
 --detach-sign [文件]       创建一个分离签名
 --list-keys [名字]        列出密钥
 --fingerprint [名字]      显示指纹
```

gpg 交互界面帮助。

```sh
gpg> help
quit        退出此菜单
save        保存并退出
help        显示此帮助
fpr         显示密钥指纹
grip        显示 keygrip
list        列出密钥和用户标识
uid         选择用户标识 N
key         选择子密钥 N
check       检查签名
sign        为所选用户标识添加签名 [* 参见下面的相关命令]
lsign       为所选用户标识添加本地签名
tsign       为所选用户标识添加信任签名
nrsign      为所选用户标识添加不可吊销签名
adduid      增加一个用户标识
addphoto    增加一个照片标识
deluid      删除选定的用户标识
addkey      增加一个子密钥
addcardkey  增加一个密钥到智能卡
keytocard   移动一个密钥到智能卡
bkuptocard  移动一个备份密钥到智能卡上
delkey      删除选定的子密钥
addrevoker  增加一个吊销用密钥
delsig      从所选用户标识上删除签名
expire      变更密钥或所选子密钥的使用期限
primary     标记所选的用户标识为主要
pref        列出偏好设置（专家模式）
showpref    列出偏好设置（详细模式）
setpref     为所选用户标识设定偏好设置列表
keyserver   为所选用户标识设定首选公钥服务器 URL
notation    为所选用户标识的设定注记
passwd      变更密码
trust       变更信任度
revsig      吊销所选用户标识上的签名
revuid      吊销选定的用户标识
revkey      吊销密钥或选定的子密钥
enable      启用密钥
disable     禁用密钥
showphoto   显示选定的照片标识
clean       压缩不可用的用户标识并从密钥上移除不可用的签名
minimize    压缩不可用的用户标识并从密钥上移除所有签名

* ‘sign’命令可以通过‘l’前缀（lsign）进行本地签名，‘t’前缀（tsign）进行
  信任签名，‘nr’前缀（nrsign）进行不可吊销签名，
  或者上述三种前缀的任意组合（ltsign、tnrsign 等）。
```
