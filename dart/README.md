# Dart

---

My Dart learning notes.

## Development Environment

Use VSCode as the IDE. You need to install the Flutter SDK, which will also install Dart.

```sh
scoop install flutter
```

After installation, run `flutter doctor` to verify the setup.

Then install the Flutter extension in VSCode.

### Command Line

```sh
# Format source code
dart format .
# Analyze and fix all source code issues
dart fix --dry-run
dart fix --apply
```

### Flutter

The VSCode Flutter extension includes many useful features. See the [official documentation](https://docs.flutter.dev/tools/vs-code) for details. To use refactoring, select the Widget with your cursor first, then press `Ctrl+,`. The most commonly used snippets are `stful` and `stless`.

## Learning Resources

- [Official Dart Documentation](https://dart.dev/guides)
- [Flutter Documentation](https://docs.flutter.dev/)
- [Flutter Material3 Widgets Online](https://flutter.github.io/samples/web/material_3_demo/)
- [Flutter Material Widgets Docs](https://docs.flutter.dev/ui/widgets/material)
- [Wonderous Demo](https://github.com/gskinnerTeam/flutter-wonderous-app)
- [Flutter 实战](https://book.flutterchina.club/) - A Chinese Flutter tutorial

## Code Projects

- **dart-sample**: Sample code organized in single-file format. Each file is a standalone example, runnable via VSCode's debug feature. The configuration files are already in version control.
- **flutterdemo**: Flutter sample application. Multiple examples combined into one Flutter project for convenience.

---

我的 Dart 学习笔记

## 开发环境

使用 VSCode 作为 IDE。需要安装 Flutter SDK，这样会同时安装 Dart。

```sh
scoop install flutter
```

安装完成后运行 `flutter doctor`，查看是否安装成功。

然后在 VSCode 中安装 Flutter 扩展。

### 命令行

```sh
# 格式化源代码
dart format .
# 分析并修复所有源代码问题
dart fix --dry-run
dart fix --apply
```

### Flutter

VSCode 的 Flutter 扩展包括了不少功能，可以参考[官方文档](https://docs.flutter.dev/tools/vs-code)。重构功能需要先用光标选中要重构的 Widget，然后点击 `Ctrl+,`。代码片段最常用的就是 `stful` 和 `stless` 两个。

## 学习资源

- [Dart 官方文档](https://dart.dev/guides)
- [Flutter 文档](https://docs.flutter.dev/)
- [Flutter Material3 Widgets Online](https://flutter.github.io/samples/web/material_3_demo/)
- [Flutter Material Widgets Docs](https://docs.flutter.dev/ui/widgets/material)
- [Wonderous Demo](https://github.com/gskinnerTeam/flutter-wonderous-app)
- [Flutter 实战](https://book.flutterchina.club/) - 一本中文 Flutter 教程

## 代码项目

- **dart-sample**：示例代码，采用单文件组织方式，每个文件都是一个单独的示例，使用 VSCode 的调试功能运行，配置文件已经加入到版本控制中，可以直接使用
- **flutterdemo**：Flutter 示例程序，为了省事将一些例子合并在一个 Flutter 项目中
