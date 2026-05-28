# Java

我的 Java 学习笔记

## 开发环境

### 工具链

使用 Scoop 安装工具链，可以自动配置环境变量，非常方便。

```sh
# 启用 Java bucket
scoop bucket add java
# 安装最新版 JDK
scoop install openjdk
# 安装 LTS JDK
scoop install openjdk21
# 安装 Gradle
scoop install gradle
# 如果安装了多个 JDK，可以在 JDK 之间切换
scoop reset openjdk
```

### IDE

推荐使用 IntelliJ IDEA 进行开发，开箱即用，不管是初学者还是老手都很适合。没钱就用社区版，有钱就用旗舰版，喜欢折腾就用旗舰版 EAP，可以免费无限试用。

喜欢折腾的话，也可以试试 VSCode，这里记录一下 VSCode 下的 Java 开发环境搭建步骤。

首先安装 [Extension Pack for Java](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack)，安装完成后，使用命令 `Java: Extensions Guide` 再安装其他推荐的扩展。

然后在 Java 的扩展设置中，按自己喜欢的进行设置，以下是我的配置。如果需要代码格式化的话，需要配置 format 文件，可以直接使用官方实例的 Google Style 配置。要使用 Gradle 的话，还要设置一下 Gradle 的路径，以及是否启用 Gradle Wrapper。

```json
{
  "gradle.allowParallelRun": true,
  "gradle.reuseTerminals": "all",
  "java.codeGeneration.hashCodeEquals.useJava7Objects": true,
  "java.codeGeneration.useBlocks": true,
  "java.edit.validateAllOpenBuffersOnChanges": true,
  "java.format.settings.url": "https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-java-google-style.xml",
  "java.implementationsCodeLens.enabled": true,
  "java.import.gradle.home": "C:\\Users\\asddf\\scoop\\apps\\gradle\\current",
  "java.import.gradle.wrapper.enabled": false,
  "java.jdt.ls.java.home": "C:\\Users\\asddf\\scoop\\apps\\openjdk\\current",
  "java.referencesCodeLens.enabled": true,
  "java.saveActions.organizeImports": true,
  "java.typeHierarchy.lazyLoad": false
}
```

如果遇到问题，可以先看看 VSCode 右下角 Java 语言服务器的错误提示，看看是不是没有设置好 JDK 等等。设置完成之后，语法高亮、代码补全、提示、Lint、代码格式化等功能应该都可以使用了。如果使用的 JDK 或者 Gradle 版本比较新的话，建议安装预览版 Java 扩展，新特性会支持得比较快。

运行代码的时候，点击 VSCode 编辑器右上方的 `Run Java` 按钮即可编译并运行程序。

## 学习资源

- [On Java 8](https://zyb0408.github.io/gitbooks/onjava8/)，经典 Java 著作《Java 编程思想》的后续作品，推荐阅读
- 《Java 核心技术》，另外一本非常适合入门的 Java 技术书
- 《Effective Java》，进阶类 Java 书籍，列出了各种 Java 的高效编程范例以及分析
- [Mkyong](https://mkyong.com/)，包含了很多 Java 的特性示例，对照着查看自己不了解的特性时很方便
- [Coding Bat](https://codingbat.com/java)，包含了一些编程挑战，可以使用 Java 练习
- [Fun Programming](https://funprogramming.org/)，包含各种有趣的编程例子
- [Programming by Doing](https://programmingbydoing.com/)，一个通过编写代码来学习 Java 的教程网站
- [Program Creek](https://www.programcreek.com/)

### 设计模式

现在很多人崇尚极简开发，对设计模式嗤之以鼻，但是我觉得设计模式还是有其可取之处的。因为设计模式流行的那个年代，各种工具链和新语言并没有现在这么丰富，人们的认知也比现在落后。让一堆低端程序员胡乱设计架构，就如同让一帮原始人随地大小便一样，到最后只能喷得到处都是。与其这样还不如用设计模式将他们规范起来，虽然低端程序员还是会胡乱操作，但是至少他们懂得按套路来，这就是正面意义。

而且随着语言的发展，其实很多有益的设计模式早就被大家所接受，有的甚至直接被一些新语言作为内置特性实现。Java、C++ 等语言的迭代器，就是利用了迭代器模式；Kotlin 的 object 对象，对应于单例模式，可以轻松创建单例对象；现在很多语言都支持的 ReactiveX 类库，就是利用观察者模式来实现异步编程。像什么策略模式、适配器模式、工厂方法等等，就算你没有听说过，也绝对在很多语言和类库中默默使用过。

- [廖雪峰的网站](https://www.liaoxuefeng.com/wiki/1252599548343744/1264742167474528)
- [Refactoring Guru](https://refactoringguru.cn/design-patterns)

## 项目

- java-samples，我的 Java 学习代码，里面包含了一些 Java 语言特性的示例
- thirdparty-samples，包含了一些第三方类库的使用示例
  - JUnit5
  - Jackson
  - DataFaker
  - JDBC
  - Logging
  - OkHttp
  - Owner
- spring-samples，包含 Spring 类库的相关例子
- vertx-samples，包含 Vert.x 类库的相关例子
- javafx-samples，包含一些 JavaFX 的例子

---

My Java learning notes

## Development Environment

### Toolchain

Use Scoop to install the toolchain, which automatically configures environment variables — very convenient.

```sh
# Add Java bucket
scoop bucket add java
# Install latest JDK
scoop install openjdk
# Install LTS JDK
scoop install openjdk21
# Install Gradle
scoop install gradle
# If you have multiple JDKs installed, you can switch between them
scoop reset openjdk
```

### IDE

IntelliJ IDEA is recommended for development — it works out of the box and is suitable for both beginners and experienced developers. Use the Community Edition if you're on a budget, the Ultimate Edition if you can afford it, or the Ultimate EAP if you like to tinker (it offers free unlimited trial).

If you enjoy tinkering, you can also try VSCode. Here are the steps to set up Java development in VSCode.

First, install [Extension Pack for Java](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack). After installation, use the command `Java: Extensions Guide` to install other recommended extensions.

Then configure the Java extensions settings according to your preferences. Here's my configuration. If you need code formatting, you'll need to configure the format file — you can use the official Google Style configuration. If you want to use Gradle, you'll also need to set the Gradle path and whether to enable Gradle Wrapper.

```json
{
  "gradle.allowParallelRun": true,
  "gradle.reuseTerminals": "all",
  "java.codeGeneration.hashCodeEquals.useJava7Objects": true,
  "java.codeGeneration.useBlocks": true,
  "java.edit.validateAllOpenBuffersOnChanges": true,
  "java.format.settings.url": "https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-java-google-style.xml",
  "java.implementationsCodeLens.enabled": true,
  "java.import.gradle.home": "C:\\Users\\asddf\\scoop\\apps\\gradle\\current",
  "java.import.gradle.wrapper.enabled": false,
  "java.jdt.ls.java.home": "C:\\Users\\asddf\\scoop\\apps\\openjdk\\current",
  "java.referencesCodeLens.enabled": true,
  "java.saveActions.organizeImports": true,
  "java.typeHierarchy.lazyLoad": false
}
```

If you encounter issues, first check the error message from the Java Language Server in the bottom-right corner of VSCode to see if JDK is properly configured. After configuration is complete, features like syntax highlighting, code completion, hints, linting, and code formatting should all work. If you're using a newer version of JDK or Gradle, it's recommended to install the Java extension preview version, which supports new features more quickly.

When running code, click the `Run Java` button in the upper-right corner of the VSCode editor to compile and run the program.

## Learning Resources

- [On Java 8](https://zyb0408.github.io/gitbooks/onjava8/), the follow-up to the classic Java book "Thinking in Java" — recommended reading
- 《Java Core Technology》, another excellent introductory Java book
- 《Effective Java》, an advanced Java book that lists various efficient Java programming patterns and analyses
- [Mkyong](https://mkyong.com/), contains many Java feature examples — great for looking up features you're unfamiliar with
- [Coding Bat](https://codingbat.com/java), contains programming challenges you can practice with Java
- [Fun Programming](https://funprogramming.org/), contains various interesting programming examples
- [Programming by Doing](https://programmingbydoing.com/), a tutorial website for learning Java by writing code
- [Program Creek](https://www.programcreek.com/)

### Design Patterns

Many people advocate minimalist development nowadays and turn their noses up at design patterns, but I believe design patterns still have their merits. During the era when design patterns were popular, toolchains and new languages weren't as abundant as they are now, and people's understanding was also less advanced. Letting inexperienced programmers design architectures willy-nilly is like letting a bunch of primitive people defecate wherever they please — in the end, things get messy everywhere. It's better to use design patterns to standardize them. While inexperienced programmers may still make a mess, at least they learn to follow established patterns. That's the positive aspect.

Moreover, with the evolution of programming languages, many beneficial design patterns have been widely accepted, and some have even been implemented as built-in features in new languages. Iterators in Java, C++, and other languages use the Iterator pattern; Kotlin's object keyword corresponds to the Singleton pattern, making it easy to create singleton objects; ReactiveX libraries supported by many languages today use the Observer pattern for asynchronous programming. Patterns like Strategy, Adapter, Factory Method, and so on — even if you haven't heard of them, you've definitely used them implicitly in many languages and libraries.

- [Liao Xuefeng's Website](https://www.liaoxuefeng.com/wiki/1252599548343744/1264742167474528)
- [Refactoring Guru](https://refactoringguru.cn/design-patterns)

## Projects

- java-samples, my Java learning code containing examples of Java language features
- thirdparty-samples, contains examples of using third-party libraries
  - JUnit5
  - Jackson
  - DataFaker
  - JDBC
  - Logging
  - OkHttp
  - Owner
- spring-samples, contains examples of Spring framework
- vertx-samples, contains examples of Vert.x framework
- javafx-samples, contains examples of JavaFX
