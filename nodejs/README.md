# nodejs

我的 nodejs 学习笔记。

- [javascript-sample](./javascript-sample/README.md)，一些 JavaScript 代码例子
- [typescript-sample](./typescript-sample/README.md)，一些 typescript 代码例子
- [node-sample](./node-sample/README.md)，一些 nodejs 代码例子

编程语言永远是程序员们可以争论的话题之一。现在世界上有众多编程语言，各具特色，众口难调。我当初入门的时候，初学的还是 C、Java 这些静态语言，他们也的确很棒。除了这些静态语言之外，还有一种动态语言，典型的就是 Python、JavaScript 这些。其实动态语言写一些功能较为单一的脚本还是很舒服的，但是如果涉及到大型项目，动态语言的缺点就显现出来了。最直观的就是 IDE 没办法做非常智能的跟踪，很多错误都必须等到编译器才能知道。

这对于习惯了 IDE 提示的我来说是一个极大的挑战，如果使用 Java 这些静态语言，现代的 IDE 可以对每一个变量和函数做非常详细的类型提示，就算使用函数式链式调用，也可以非常清晰的看出每一个返回类型和输入类型，让人非常安心。但是在动态语言中就没办法做到了，只能依靠文档和人脑去确定每一个变量的类型，稍不留神就会掉到坑里。所以现在很多动态语言也开始提供类型标注等“静态功能”，目的就是让编译器和 IDE 可以更准确的推断类型，及时报告错误。但是这样一来，动态语言的一个特点就不复存在，这也算编程语言的一点曲折的发展吧。

其实说了这么多扯得有点远。我主要想表达的意思是很多静态语言当初虽然设计的时候也会有一点问题，但是因为它静态的特性，所以在 IDE 的支持下，我学习起来还凑合。但是对于 JavaScript 这个东西我实在是忍不下去了。当年 JavaScript 也只是网景公司为了给网页增加一点交互随手设计出来的东西，没想到随着万维网的迅猛发展，JavaScript 一跃成为了网页设计的基石，也变成了一种“祖宗之法不可变”的恶臭东西。虽然现代 JavaScript 增加了大量新特性，也弥补了不少当年的缺点，但是在我这个 C 和 Java 入坑的普通程序员看来，JavaScript 就如同异端一样。动态语言、历史包袱、前端混乱的生态系统再加上浏览器运行这些 debuff 加起来，让我每次想学习 JavaScript，都像浑身爬满了蚂蚁一样难受。

更加讽刺的是，整个看似现代的计算机业界，其实充满了历史包袱。所以现在其实有很多想干掉 JavaScript 的尝试，比如 wasm 等等，但是他们越是现代，越是和 JavaScript 割裂开来，反而越不可能取代这个被 JavaScript 统治的前端世界。这或许也算是一种轮回吧。

## 开发环境

### 通过 nvm 安装 nodejs

首先安装 nvm。

```powershell
scoop install nvm
```

然后使用 nvm 安装最新版的 LTS node。

```powershell
nvm install lts
```

最后应用刚刚安装的 nodejs。

```powershell
nvm use lts
```

如果遇到了`ERROR open \settings.txt: The system cannot find the file specified.`错误，记得关闭所有 windows terminal 终端，然后重新打开，这样就可以正确识别 nvm 命令了。

为了加快下载速度，推荐使用镜像。

```powershell
npm set registry https://registry.npmmirror.com
```

推荐使用 pnpm 替代 npm。

```powershell
corepack enable
corepack prepare pnpm@latest --activate
```

### IDE

使用 vscode 作为 IDE 使用，需要安装以下扩展：

- Quokka.js，交互式 js/ts 扩展，很适合新手
- eslint，代码风格检查器，帮助检测 js 代码中存在的各种问题

## 学习

- [阮一峰的 ES6 入门教程](https://es6.ruanyifeng.com/)
- [typescript 官方文档](https://www.typescriptlang.org/docs/)
- [nodejs 文档](https://nodejs.org/docs/latest-v20.x/api/documentation.html)

### eslint

在项目中初始化 eslint，命令行提供了一些初始化选项，可以使用预配置的模板或者自定义规则。

```sh
npx eslint --init
```

自动修复问题

```sh
npx eslint **/*.js --fix
```

### eslint-typescript

```sh
bun add -d eslint @eslint/js typescript typescript-eslint
```

Create `eslint.config.mjs` with the following content.

```js
// @ts-check

import eslint from "@eslint/js";
import tseslint from "typescript-eslint";

export default tseslint.config(
  eslint.configs.recommended,
  tseslint.configs.strict,
  tseslint.configs.stylistic
);
```

## node 生态

### vuepress-hope 博客

vue 是前端非常流行的一个框架，vuepress 是 vue 官方用于制作静态博客站点的框架。不过官方配置比较简洁，这里推荐 [vuepress-hope](https://vuepress-theme-hope.github.io/)，一个第三方的 vuepress 框架，专门用于制作静态博客，为官方框架添加了新的主题样式和众多功能，开箱即用。

创建新博客

```sh
pnpm create vuepress-theme-hope hope-project
```

安装插件

```sh
pnpm i -D @vuepress/plugin-google-analytics@next
pnpm i -D @vuepress/plugin-search@next
```

升级依赖

```sh
pnpm dlx vp-update
```
