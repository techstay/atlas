# linux 常见命令

## 用户管理

### 修改用户

查看用户信息。

```sh
id techstay
```

修改登录名称。

```sh
usermod -l techstay2 techstay
```

修改组名。

```sh
groupmod -n techstay2 techstay
```

修改用户目录。

```sh
usermod -d /home/techstay2 -m techstay2
```

最后再查看一次，这时候 techstay 用户的所有信息包括主目录应该都已经更改为了 techstay2 了。

```sh
id techstay2
```
