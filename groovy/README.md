# groovy

我的 Groovy 学习代码

## 前言

其实当初我学习 groovy 语言的主要目的还是为了掌握编写 gradle 脚本的语法，学习之后发现 groovy 这门语言确实挺有意思，用熟练以后还是挺爽的。缺点嘛和 Python 差不多，动态语言一时爽，重构代码火葬场。单纯写几十行的脚本没啥问题，但是代码量一大起来，IDE 就推断不出来类型了，然后各种自动补全也就不灵了。这时候就感觉贼他妈痛苦。

然后学完 groovy 没多长时间，我又发现了 kotlin 这门语言，同样也是一大堆语法糖用起来贼爽，最关键的是，kotlin 是 Jetbrains 的亲儿子，IDE 支持非常强大，这一点就完爆了多少没有配套环境的语言。当然后来谷歌把 kotlin 收为干儿子，在国内又火了一把这就是后话了。这次我又把 groovy 拾起来的时候，发现他和当年好像也没有多少差别。硬要说的话，好像运行起来还比当年慢一点，当年我记得是直接在 IDEA 里运行 groovy，现在改用了 gradle 来运行 groovy，每次运行文件还要等 gradle 编译好几秒，及其影响体验。

再回到当初的目的，为了学习编写 gradle 脚本。现在 gradle 已经把 kotlin 脚本作为默认支持，现在学习 groovy 语言似乎也没有什么必要性了。不过再看到`.groovy`扩展名的话，我一定会想起在 jvm 家族中，还有 groovy 这么一门语言。

## 开发环境

安装 groovy

```sh
scoop install groovy
```

IDE 使用 Jetbrains Intellij IDEA。

## 学习

- [官方文档](https://groovy-lang.org/documentation.html)
