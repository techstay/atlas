# github 官方命令行

## 开始使用

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

## 查阅命令

直接在官方文档上查阅即可 <https://cli.github.com/manual/>。
