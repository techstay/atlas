---
id: pebzqykyiug59k1x2b01t7p
title: Go
desc: ""
updated: 1753733176634
created: 1753733174711
---

go 这门语言设计的比较独特，设计者在参考了 C、Java 等语言后，决定做减法，最后出来这么一门语言。喜欢的人，自然推崇 go 的精简哲学。抛弃了那些繁杂的设计模式之后，go 体现出了一种大道至简的美。而且 go 语言的 goroutine 实现的非常成功，对很多编程语言产生了深远的影响。比如我很喜欢的 kotlin 语言的协程，就在很多方面参考了 goroutine，如果之前了解了其中一个，那么学起另外一个来真的是非常轻松。

不过呢，我当初入门编程语言的时候被 Java 语言注入了思维钢印，所以我觉得 go 的很多特点都是邪道，像数据与实现分离的结构体、隐式实现借口、函数返回错误码等等，真的让我觉得超级别扭。所以虽然 go 的各方面性能都还不错，甚至现在在很多领域也非常流行，但是我还是没办法将他作为一门主力语言来使用。

当然，这也只是我的个人口味问题。毕竟 go 语言这么多年的成就毋庸置疑，而他在语言特性方面的取舍也不能简单的从单一方面评价，毕竟 go 语言的编译速度是真的快，运行起来完全给我一种无需编译的脚本语言的感觉。可以说 go 语言很好的在几个方面做了取舍，或许这也是一门成功的语言落地的必要的代价吧。

总的来说，如果你喜欢 C 语言的那一套东西，而不是 Java 那样的面向对象编程的话，那么你应该也会喜欢 go 语言的。

## 学习资料

有条件的话，强烈建议直接看英文官方文档。很多中文资料更新缓慢、可能存在翻译错误，让人看得一头雾水。

- [Official Documentation](https://go.dev/doc/)
- [A tour of Go](https://go.dev/tour/list)，跟着例子学 go
- [Go 入门指南](https://learnku.com/docs/the-way-to-go)
- [Go Web 编程](https://learnku.com/docs/build-web-application-with-golang)
- [Go 编码指南](https://learnku.com/go/wikis/38174)
- [Effictive Go](https://learnku.com/docs/effective-go/2020)

## 开发环境

安装 go 工具

```sh
scoop install go
```

安装 go 扩展

- go 扩展，参考<https://code.visualstudio.com/docs/languages/go>
- [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)扩展，用于运行单文件 go 源代码

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

或者也可以使用 vscode 的 Dev Container 功能在容器里进行开发。一般情况下其实本地开发就够了，不过因为我用的 Avast 杀毒软件会对生成的 exe 文件进行杀毒，影响效率，所以干脆放到容器里面。

## 项目

### go-demo

golang 示例代码，全部都是单文件实例，无依赖，主要用来学习演示 golang 的基础功能。

### gomod-demo

go mod 项目小例子。
