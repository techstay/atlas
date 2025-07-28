---
id: tr73z1bdtubcx2qyr54jvti
title: Elvish
desc: ""
updated: 1753733125660
created: 1753733123910
---

## 开始使用

### 安装

scoop 安装

```sh
scoop install elvish
```

### 编辑器

目前 vscode 的 elvish 扩展支持很不完善，同样没有格式化等基本功能，只能等以后 elvish 生态继续发展了。

### 美化

先安装 starship

```sh
scoop install starship
```

编辑配置文件`code ~/.elvish/rc.elv`，添加下面一行。

```elvish
eval (starship init elvish)
```
