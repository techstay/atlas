# cpp

我的 C++ 学习笔记。

C++ 是很多计科大学生最先学习的编程语言，但是其实 C++ 并不适合作为入门编程语言来学习，因为它确实比较难学。而且，国内大学所使用的教材都很陈旧，完全跟不上现在 C++ 标准的发展和变化，所以如果有条件的话，最好直接跟着国外先进的资料走。

不过我觉得如果只是为了应付考试的话，就没必要在 C++花太多时间了，因为它实在是太难学了。这门语言的哲学就是把一切交给程序员，再加上它沉重的历史包袱，这就导致一个问题，C++语言里面的细节太多了。我记得我当初看 C++ Primer（还是 plus）的时候，看到指针那一章，作者介绍了指针的各种语法，把我看得一头雾水。我觉得光那些知识就足以单独出一本书了。

然而这只是 C++中的小小一部分而已，后面的东西还多着呢，模板、元编程、泛型、标准库等等，每个下面，都是一个深不见底的巨坑。花费同样的时间，你学 C++可能连这个类为什么编译不通过都没搞清楚，人家学 Java 都已经开始用 spring 开发 web 程序了。

所以说到最后，如果你不是执意要入坑 C++的话，为什么不学 rust 呢？人生苦短，我们有大把美好的时间，应该用在更值得的事情上面。珍爱生命，远离 C++。

不过，适当了解一下 C++的一些重要特点我觉得还是可以的。现在编程太容易了，各种高级编程语言背后隐藏了很多细节，而 C++把这些细节全部暴露出来了，某种方面也算是一个了解计算机背后运行原理的好机会。不过，记得不要掉进 C++的巨坑里了哦。

## 学习

- <https://www.learncpp.com/>，一个不错的在线学习网站，写的比较详细，很适合初学者，同时也介绍了不少现代 C++ 的特性
- [w3schools](https://www.w3schools.com/cpp/default.asp)，在线学习网站
- [cppreference](https://en.cppreference.com/w/)，C++ 标准参考
- <https://godbolt.org/>，一个在线编译和查看汇编代码的 C++网站
- 《C++ Primer》和《C++ Primer Plus》，两部非常经典的 C++ 学习大部头
- <https://github.com/applenob/Cpp_Primer_Practice>，网友整理的 C++ Primer 笔记

## 开发环境

项目使用 vscode 编辑器，通过 Dev Container 扩展在容器中运行程序，免去了复杂的开发环境配置，使用 clangd 扩展来提供语法高亮和代码补全，配置成功以后效果很好，完全不亚于 Jetbrains Clion 这样的付费专业 IDE。想当年我初学 C++ 的时候，还没有这么好用的工具，挑来挑去最后只能用 Code::Blocks。

先安装以下扩展：

- clangd，C++ 语言服务器，提供语法高亮、提示、补全、格式化等功能
- Code Runner，编译并运行单文件的 C++ 源文件，可以通过`Ctrl+Alt+N`快捷键执行
- Code LLDB，提供调试功能
- Dev Container，容器化方式运行 C++ ，提供统一的开发环境，避免各种编译和运行时问题
- Cmake Tools， C++ 的构建工具
- xmake，一个新晋的 C++构建工具，支持多平台和多种框架

这里推荐使用容器来开发和运行 C++，一来避免了复杂的开发环境配置，二来 linux 可以自动配置一些类库的头文件和库文件，在使用第三方类库的时候会方便很多，毕竟 C++没有一个官方的包管理器。当然，如果想直接在 Windows 下开发也不是不行，只是稍微麻烦一点而已。Windows 下需要安装 [gcc 编译器](https://github.com/skeeto/w64devkit)。接下来的步骤就大同小异了。

然后要配置 clangd 的功能，它需要读取`compile_commands.json`来获取项目信息，这个文件可以由 cmake 这样的构建工具自动生成。对于简单项目，比如下面的由一些互不相关的单个源文件组成的 cpp-sample 项目，可以使用`compile_flags.txt`来提供分析代码所需的信息。要学习目前最新的 C++23 标准的话，在`compile_flags.txt`配置文件中添加参数`--std=c++2b`即可。

接下来要配置如何运行项目，这取决于你的项目。如果项目使用 cmake 或者是 xmake 这样的工具的话，就使用这些工具来编译项目并生成可执行文件。

如果只是要运行单个文件的话，就使用 Code Runner 扩展来编译和运行。这里需要设置一下 Code Runner 扩展的自定义命令，让它使用最新的 C++ 23 标准来编译和运行文件。如果要将文件编译到其他位置，自行修改命令行，替换变量可以在其仓库的说明中找到<https://github.com/formulahendry/vscode-code-runner#configuration>。

```json
{
  "code-runner.executorMap": {
    "cpp": "g++ $fullFileName -o $workspaceRoot/build/$fileNameWithoutExt -g -std=c++2b -fmodules-ts && $workspaceRoot/build/$fileNameWithoutExt"
  }
}
```

最后就是调试，需要添加`.vscode/launch.json`配置文件，然后设置正确的可执行文件路径，就能利用 LLDB 来添加断点和调试了。调试单文件的时候，LLDB 在 windows 系统下有点问题，无法启动调试，所以我还是推荐在容器中开发，这些功能都是可以正常使用的。

因为是使用容器开发，所以本机无需安装 C++编译器等工具，容器会自动帮你处理好一切。其实微软官方提供的基于 Debian 的 C++容器就不错，但是我需要学习最新的 C++标准，所以得通过 Dockerfile 创建自己的容器。在下面的 cpp-sample 项目中，我使用了基于 fedora 的容器，安装了最新的 gcc 13 和 clangd 16 编译器来编译和执行最新 C++标准的代码，具体细节和配置在项目中都有，自行参考。

这里还要吐槽一下，其实本来我用的是 archlinux，但是我发现一直以更新速度快著称的 archlinux，在 clang 编译器上竟然落后了。我想学习使用一些最新的 C++23 标准，但是 archlinux 的 clang 仍然只有 15，不仅导致 clangd 的提示功能出现错误，而且也没办法用 clang-format 正确格式化代码了。所以最后我只能切换为 fedora，它的更新还是很及时的。

## 代码

- cpp-sample，一些单文件小例子，可以直接使用 Code Runner 扩展运行，演示了 C++ 的一些基本功能
- xmake-sample，xmake 构建工具的小例子
