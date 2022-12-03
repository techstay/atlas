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

## all-contributors

首先安装 bot，<https://github.com/apps/allcontributors/installations/new>。

之后新开一个 issue，在里面输入以下指令就可以让 bot 自动创建 PR，将贡献者添加进来了。默认会在项目`README.md`文件中添加贡献者，所以需要该文件存在（内容可以为空）。或者如果贡献者太多的话，可以考虑将贡献者放到`CONTRIBUTORS.md`中，而在项目 README 醒目位置添加该文件的链接。

其中`<contributions>`是贡献类别，这里有详细说明<https://allcontributors.org/docs/en/emoji-key>。

```sh
@all-contributors please add @<username> for <contributions>
# 例
@all-contributors please add @techstay for example
```

推荐同时在项目中添加`CONTRIBUTING.md`或类似文件，里面介绍向项目发起贡献的方法，甚至可以将 all-contributors 的文档链接也带上。

如果需要修改 bot 配置的话，编辑 bot 添加的`.all-contributorsrc`文件即可，可以参考<https://allcontributors.org/docs/zh-cn/overview>。
