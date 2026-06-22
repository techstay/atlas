---
title: "markdown"
date: 2026-05-15T01:18:06+08:00
tags:
  - programming
  - markdown
categories:
  - 编程
---

## 文档和教程

- [Markdown 中文教程](https://markdown.com.cn) —— 一份详细的中文 Markdown 语法教程，涵盖基础语法和扩展语法，适合入门和查阅。
- [公众号排版工具](https://markdown.com.cn/editor/)

## vscode 配置

安装 prettier 和 [markdown preview enhance](https://shd101wyy.github.io/markdown-preview-enhanced/) 扩展。然后将 prettier 设置为 markdown 文件的默认格式化工具，足以应对大多数情况。

```json
{
  "markdown-preview-enhanced.automaticallyShowPreviewOfMarkdownBeingEdited": true,
  "markdown-preview-enhanced.enableExtendedTableSyntax": true,
  "markdown-preview-enhanced.enableHTML5Embed": true,
  "markdown-preview-enhanced.enableScriptExecution": true,
  "markdown-preview-enhanced.enableTypographer": true
}
```

如果有强迫症，还可以安装 `AutoCorrect` 和 `Markdown All in One` 和 `markdownlint` 扩展，并将 `markdownlint` 设置为默认 markdown 格式化程序，然后按保存快捷键，这样应该会触发 `AutoCorrect` 格式化中文段落，然后格式化文件，效果会更好一些。

---

## 目录

[TOC]

## 标题

# 一级标题

## 二级标题

### 三级标题

#### 四级标题

##### 五级标题

###### 六级标题

---

## 段落

段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落段落。

另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落另一段段落。

---

## 强调

使用两个星号或下划线**加粗字体**。

使用一个星号或者下划线*倾斜字体*。

使用三个星号或者下划线同时***加粗和倾斜字体***。

使用两个波浪号 `~` 充当删除线，~~当我没说~~。

---

## 引用

单行引用。

> 人生如戏，戏如人生。

多行引用，

> 君不见
> 黄河之水天上来
>
> 引用里也可以包含其他元素
>
> 1. 第一点
> 1. 第二点
> 1. 第三点

---

## 列表

无序列表，以减号、星号或者加号开始。

- 项目
- 项目
- 项目
- 项目

有序列表。

1. 第一项
2. 第二项
3. 第三项
4. 第四项

---

## 代码

单词 `代码`。

代码块。

```cpp
# include <iostream>

int main()
{
  return 0;
}
```

---

## 分隔线

三个及以上的星号 `*`、破折号 `-` 或者下划线 `_` 可以组成分隔线，

---

## 链接

这是一个简单的 [链接](link)。

带工具提示的 [链接](link "工具提示")。

直接显示网址的连接<https://baidu.com>。

引用链接，[百度首页][1]。

[1]: https://www.baidu.com/

图片链接，语法类似，只不过需要在最前面加个叹号 `!`。

![风景图片](https://images.pexels.com/photos/2286895/pexels-photo-2286895.jpeg)

---

## 表格

| 表格 | 居中对齐 | 左对齐 | 右对齐 |
| ---- | :------: | :----- | -----: |
| 123  |   123    | 123    |    123 |
| 123  |   123    | 123    |    123 |
| 123  |   123    | 123    |    123 |

## 定义列表

markdown

: 一种标记语言，注重内容而不是格式

## 任务列表

- [x] 已完成
- [ ] 未完成
- [ ] 等待完成

## emoji 表情

直接复制 emoij 表情 🎉。

或者使用 shortcode :clown_face: 。

## 数学公式

在一般的 markdown 解析器中不支持，但是 `markdown preview enhance` 扩展支持显示数学公式。

$$
x_{1,2}=\frac{-b\pm{\sqrt{b^2-4ac}}}{2a}
$$

$$
\sum_{i=1}^{100}i=5050
$$

$$
\int{\cos{x}}dx=\sin{x}+C
$$

## 脚注

脚注需要设置标识符 [^1] 和链接 [^2]。

[^1]: 标识符参考资料<https://markdown.com.cn/extended-syntax/footnotes.html>

[^2]: 链接参考资料<https://markdown.com.cn/extended-syntax/footnotes.html>

