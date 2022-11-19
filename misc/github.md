# github

记录 Github 相关的笔记。

## SSH 登录

新建 SSH 密钥。

```sh
ssh-keygen -t ed25519 -C "your_email@example.com"
```

查看公钥内容。

```sh
cat ~\.ssh\id_ed25519.pub
```

将其复制到 Github 网站上的公钥处。然后应该就可以通过 SSH 来访问 GitHub 了。

```sh
ssh -T git@github.com
```

## 命令行

### 安装

```powershell
scoop install gh
```

### 设置补全

```powershell
# powershell需要在$PROFILE中添加下面一行
Invoke-Expression -Command $(gh completion -s powershell | Out-String)
# zsh需要在$fpath中添加补全文件
gh completion -s zsh > /usr/local/share/zsh/site-functions/_gh
# fish需要创建函数
gh completion -s fish > ~/.config/fish/completions/gh.fish
```

### 登录

在浏览器中登录账号。

```powershell
gh auth login
```

### 查阅命令

直接在官方文档上查阅即可 <https://cli.github.com/manual/>。

## 徽章

- Snyk
- CodeCov
- LGTM
- Codeclimate
- Foresight
