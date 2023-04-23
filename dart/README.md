# dart

我的 dart 学习笔记

## 开发环境

使用 vscode 作为 IDE。需要安装 flutter sdk，这样会同时安装 dart。

```sh
scoop install flutter
```

安装完成后运行`flutter doctor`，查看是否安装成功。

然后在 vscode 中安装 flutter 扩展。

### 命令行

```sh
# 格式化源代码
dart format .
# 修复所有源代码
dart fix --dry-run
dart fix --apply
```

### flutter

vscode 的 flutter 扩展包括了不少功能，可以参考[官方文档](https://docs.flutter.dev/tools/vs-code)。重构功能需要先用光标选中要重构的 Widget，然后点击`Ctrl+,`。snippets 最常用的也就`stful`和`stless`两个。

## 学习

- [官方文档](https://dart.dev/guides)
- [Flutter 文档](https://docs.flutter.dev/)
- [Flutter Material3 Widgets Online](https://flutter.github.io/samples/web/material_3_demo/)
- [Flutter Material Widgets Docs](https://docs.flutter.dev/ui/widgets/material)
- [Wonderous Demo](https://github.com/gskinnerTeam/flutter-wonderous-app)
- [Flutter 实战](https://book.flutterchina.club/)，一本中文 Flutter 教程

## 代码项目

- dart-sample，示例代码，采用单文件组织方式，每个文件都是一个单独的示例，使用 vscode 的调试功能运行，配置文件已经加入到版本控制中，可以直接使用
- flutterdemo，flutter 示例程序，为了省事将一些例子合并在一个 flutter 项目中
