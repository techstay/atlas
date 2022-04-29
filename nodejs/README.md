# nodejs

## 开发环境

首先安装 nvm。

```powershell
scoop install nvm
```

然后使用 nvm 安装最新版的 LTS node。

```powershell
nvm install lts
```

最后应用刚刚安装的 nodejs。

```powershell
nvm use lts
```

如果遇到了`ERROR open \settings.txt: The system cannot find the file specified.`错误，记得关闭所有 windows terminal 终端，然后重新打开，这样就可以正确识别 nvm 命令了。

为了加快下载速度，推荐使用镜像。

```powershell
npm set registry https://registry.npmmirror.com
```

推荐使用 pnpm 替代 npm。

```powershell
corepack enable
corepack prepare pnpm@latest --activate
```
