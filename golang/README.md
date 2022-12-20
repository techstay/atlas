# golang

我的 golang 学习笔记。

## 学习资料

- [Effictive Go](https://learnku.com/docs/effective-go/2020)
- [Go 编码指南](https://learnku.com/go/wikis/38174)

## 环境配置

### 安装 go 编译器

```sh
scoop install go
```

### 安装 go 扩展

单文件示例代码使用 vscode 编辑器编辑运行，配置[参考](https://code.visualstudio.com/docs/languages/go)，运行单文件还需要安装[Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)扩展。

首次打开 go 源代码文件时会提示安装一些额外工具，全部安装之后即可开始编写。

参考 vscode 配置：

```json
  "[go]": {
      "editor.defaultFormatter": "golang.go"
  },
  "go.formatTool": "goimports",
  "go.toolsManagement.autoUpdate": true,
  "go.useLanguageServer": true,
  "gopls": {
      "formatting.gofumpt": true,
      "ui.semanticTokens": true
  }
```

## 项目

### sample-code

golang 示例代码，全部都是单文件实例，无依赖，主要用来学习演示 golang 的基础功能。
