# gpg

## 安装

windows 系统需要下载安装[gpg4win](https://www.gpg4win.org/)，同时附带了 Kleopatra 这个图形界面程序，可以非常方便的使用 gpg 的各项功能。

## 开始使用

### 创建密钥

推荐使用 ED25519 算法创建密钥，方法如下：

1. 使用专家模式生成密钥`gpg --full-generate-key --expert`
1. 选择`(9) ECC 和 ECC`
1. 选择`(1) Curve 25519`椭圆曲线

之后按提示操作即可。

### 查看密钥

生成的是一对公钥和私钥，可以由以下命令查看。

```sh
gpg --list-secret-keys
gpg --list-keys
```

类似结果如下。公钥下面一长串哈希值称作指纹，指纹的后 16 位叫做 keyid，都可以用来区分密钥。日期后面的大写字母表示密钥的作用，`S`是签名、`C`是验证、`E`是加密。

```sh
$ gpg --list-keys
/home/techstay/.gnupg/pubring.kbx
---------------------------------
pub   ed25519 2022-02-01 [SC]
      3E002217712EBA30A53D485F7CDDF9CBDDF9BF2E
uid             [ 绝对 ] techstay <lovery521@gmail.com>
sub   cv25519 2022-02-01 [E]
```

### 交换公钥

传统办法就是将公钥导出为文件，然后通过聊天软件或者电子邮件等方式交换。

```sh
# 导出自己的公钥
gpg --armor --output public.key --export <key-id>

# 导入别人的公钥
gpg --import some-public.key
```

另一种方式是使用公钥服务器。首先在`~/.gnupg/gpg.conf`中添加 openpgp 公钥服务器的地址，没有则可以先创建这个文件。

```sh
echo 'keyserver hkps://keys.openpgp.org' > ~/.gnupg/gpg.conf
```

openpgp 服务器支持通过电子邮件的方式删除公钥，不过需要先验证电邮地址。

```sh
gpg --export <key-id> | curl -T - https://keys.openpgp.org
```

之后会往公钥对应的电邮地址发送一封电子邮件，验证过之后即可从公钥服务器上查找公钥。

```sh
gpg --search-key <key-id> [ <fingerprint> ]
```

将来要随时更新公钥信息的话，只需要运行以下命令。

```sh
gpg --refresh-keys
```

### 加密和解密

gpg 一大功能是加密文件，可以保证文件内容不被第三方读取。加密的时候需要接收方的公钥，不指定输出文件名的话会使用原文件名加上`.gpg`后缀。

如果将以下命令的`--recipient`参数改为`--hidden-recipient`参数，那么加密文件将不包含任何接收方信息，可以更好的保护隐私。`--recipient`和`--hidden-recipient`各有缩写参数`-r`和`-R`。

```sh
gpg --recipient <keyid> --encrypt <file> [--output <outfile>]
```

接收方无需额外操作即可解密文件。

```sh
gpg --decrypt <file.gpg> [ --output <file> ]
```

### 签名和验证

gpg 另一大功能是签名，可以确保文件完整性，不被第三方篡改。不指定输出文件名的话，生成的签名文件就是原文件名加上`.sig`后缀。

```sh
gpg [ --output <file.sig> ] --detach-sign <file>
```

如果希望将签名文件和原文件合二为一的话，改用`--sign`参数。

```sh
gpg --sign <file> [ --output <file.gpg> ]
```

验证之前需要先导入签名方的公钥，并将原文件和签名文件放到一起。这样如果验证通过，gpg 就会显示“良好的签名”，否则就会产生错误信息。

```sh
gpg --verify <pgp-file/sig-file>
```

签名和验证也可以放到一起，命令如下：

```sh
gpg --sign --encrypt --hidden-recipient <key-id> <filename>
```

解密时无需参数，直接指定文件名即可同时解密和验证。

```sh
gpg <filename.gpg>
```

## 密钥操作

### 导入导出密钥

导入导出公钥和私钥。

```sh
# 导出
gpg -o private.gpg --export-options backup --export-secret-keys <key-id>
# 导入
gpg --import-options restore --import private.gpg
```

以上的方法不会保留信任信息，导入密钥后需要重新信任一次密钥。如果要保留信任信息，需要单独备份。或者也可以直接复制`~/.gnupg/trustdb.gpg`文件。

```sh
# 导出信任信息
gpg --export-ownertrust > trust.txt

# 导入信任信息
gpg --import-ownertrust < trust.txt
```

### 吊销密钥

如果 gpg 密钥因为各种原因不再使用，最好将其吊销并上传到公钥服务器上。这样其他人就可以及时收到吊销信息，取消对密钥的信任。

生成吊销证书。

```sh
gpg --output revoke.asc --gen-revoke <key-id>
```

有了吊销证书，将其导入即可吊销密钥。

```sh
gpg --import revoke.asc
```

### 删除密钥

```sh
# 删除私钥
gpg --delete-secret-keys <key-id>

# 删除公钥
gpg --delete-keys <key-id>

# 同时删除公钥和私钥
gpg --delete-secret-and-public-keys <key-id>
```
