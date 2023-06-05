# java

我的 java 学习笔记

## 开发环境

### 工具链

使用 scoop 安装工具链，可以自动配置环境变量，很方便。

```sh
# 启用java bucket
scoop bucket add java
# 安装最新版JDK
scoop install openjdk
# 安装LTS JDK
scoop install openjdk17
# 安装gradle
scoop install gradle
# 如果安装了多个JDK，可以在JDK之间切换
scoop reset openjdk
```

### IDE

推荐使用 Intellij IDEA 进行开发，开箱即用，不管是初学者还是老手都很适合。

喜欢折腾的话，也可以试试 vscode，这里记录一下 vscode 下的 Java 开发环境搭建步骤。

首先安装[Extension Pack for Java](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack)，安装完成后，使用命令`Java: Extensions Guide`再安装其他推荐的扩展。

然后在 java 的扩展设置中，按自己喜欢的进行设置，以下是我的配置。如果需要代码格式化的话，需要配置 format 文件，可以简单的从 github 上指定一个 URL。要使用 gradle 的话，还要设置一下 gradle 的路径，以及是否启用 gradle wrapper。

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

如果遇到问题，可以先看看 vscode 右下角 java 语言服务器的错误提示，看看是不是没有设置好 JDK 等等。设置完成之后，语法高亮、代码补全、提示、lint、代码格式化等功能应该都可以使用了。如果使用的 JDK 或者 gradle 版本比较新的话，建议安装预览版 Java 扩展，新特性会支持的比较快。

运行代码的时候，点击 vscode 编辑器右上方的`Run Java`按钮即可编译并运行程序。

## 学习资源

- [On Java 8](https://zyb0408.github.io/gitbooks/onjava8/)，经典 Java 著作《Java 编程思想》的后续作品，推荐阅读
- 《java 核心技术》,另外一本非常适合入门的 java 技术书
- effective java,进阶类 java 书籍,列出了各种 java 的高效编程范例以及分析
- [mkyong](https://mkyong.com/)，包含了很多 Java 的特性示例，对照着查看自己不了解的特性时很方便
- <https://codingbat.com/java>，包含了一些编程挑战，可以使用 java
- <https://funprogramming.org/>，包含了各种有趣的编程例子
- <https://programmingbydoing.com/>，一个通过编写代码来学习 Java 的教程网站
- <https://www.programcreek.com/>

## 项目

- java-samples，我的 java 学习代码，里面包含了一些 java 语言特性的示例
- thirdparty-samples，包含了一些第三方类库的使用示例
