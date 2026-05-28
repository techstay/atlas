# xmake-sample

使用 xmake 构建的示例程序程序。

## 开始使用

### 开发环境

安装`tboox.xmake-vscode`扩展，然后在状态栏上就可以编译和运行项目了。

### xmake 命令行

创建项目

```sh
xmake create -l c -P xmake-sample
```

生成项目

```sh
xmake
```

运行项目

```sh
xmake run xmake-sample
```

调试项目

```sh
xmake run -d xmake-sample
```

自动生成 IDE 项目

```sh
xmake project -k vs2022 -m "debug,release"
```
