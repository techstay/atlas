# Ruby Study

我的 ruby 学习笔记

## 学习资源

- [官方文档](https://www.ruby-lang.org/zh_cn/documentation/)
- [Ruby 标准库](https://docs.ruby-lang.org/en/master/standard_library_rdoc.html)
- [风格规范](https://github.com/1c7/ruby-airbnb)
- [techotopia 教程](https://www.techotopia.com/index.php/Ruby_Essentials)
- [zetcode 教程](https://zetcode.com/lang/rubytutorial/)
- [ruby koans](https://github.com/edgecase/ruby_koans)

## 开发环境

Windows 下 ruby 性能貌似不太行，开发的时候贼慢，毫无体验。测试了几种方案以后，我发现使用 vscode 配合 devcontainer 扩展体验最佳。使用之前需要开启 windows 系统的 WSL2 等功能，再安装 docker，可以参考[这篇官方教程](https://code.visualstudio.com/docs/devcontainers/tutorial)。配置完成以后，开发环境完全以容器化方式管理，本地电脑无需安装 ruby 环境，也不会被各种乱七八糟的工具搞乱。

vscode 需要安装`Shopify.ruby-extensions-pack`扩展包，扩展写到了`devcontainer.json`配置文件中，使用容器打开的时候会自动将扩展安装到容器中。如果 sorbet 扩展打不开，参考[官方文档](https://sorbet.org/docs/adopting)配置一下环境应该就没有问题了。第一次使用的时候，sorbet 需要重新编译一遍项目以生成 rbi 文件，会耗费比较长的时候，后面速度就快了。根据项目说明，这些文件也需要添加到版本控制中。

sorbet 需要安装 watchman 才能正常使用。微软官方的开发容器基于 debian 11，可以直接安装，这一点很赞。

```sh
sudo apt install watchman
```

这个基于 vscode 的开发环境配置成功之后，开启 sorbet 和 ruby-lsp 功能，开发体验不输收费的 RubyMine，代码提示等功能也不会少。

## 代码项目

### ruby-sample

这是我根据上面教程学习写的练习代码，代码试了好几种方案，最后形成了这种。每个文件都比较小，单独演示一些功能，这样写起来方便，运行查看结果也比较方便。

其实对于这种脚本语言来说，最好的方式是使用 jupyter 那样的交互式终端练习，体验应该是最好的，其实很多 ruby 教程就是这么做的。但是系统自带的交互式终端 irb 功能比较简陋，而且编辑器也没有提供很好的支持。直接使用 jupyter 运行 ruby 代码倒也不是不可以，但是缺了一项我认为很重要的功能，那就是代码格式化。这一点 Python 就很好，可能是用的人比较多吧，生态问题是最难解决的问题。

不过 ruby 语言其实也不错了，虽然生态没有 Python 那么完善，但是差不多也该有的都有了。开发环境配置完成后，代码编写体验还是很优雅的。果然在现在这个时候当程序员是真的很爽，有很多强大的代码插件可以使用，比我大学时候爽多了，更难让人想象更早的程序员们是怎么度过的。
