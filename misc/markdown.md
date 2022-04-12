# markdown

markdown 是一种方便编写和阅读的格式，关注内容而不是排版格式。

- [markdown 练习](https://www.markdowntutorial.com/zh-cn/)
- [公众号排版工具](https://markdown.com.cn/editor/)

## vscode 配置

安装 prettier 和[markdown preview enhance](https://markdown.com.cn/editor/)扩展。然后添加下面的 vscode 配置。

```json
{
  "markdown-preview-enhanced.automaticallyShowPreviewOfMarkdownBeingEdited": true,
  "markdown-preview-enhanced.enableExtendedTableSyntax": true,
  "markdown-preview-enhanced.enableHTML5Embed": true,
  "markdown-preview-enhanced.enableScriptExecution": true,
  "markdown-preview-enhanced.enableTypographer": true
}
```

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

使用三个星号或者下划线同时**_加粗和倾斜字体_**。

使用两个波浪号`~`充当删除线，~~当我没说~~。

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

有序列表，数组无意义，会自动按顺序渲染。

1. 第一项
1. 第二项
1. 第三项
1. 第四项

---

## 代码

单词`代码`。

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

三个及以上的星号`*`、破折号`-`或者下划线`_`可以组成分隔线，

---

## 链接

这是一个简单的[链接](link)。

带工具提示的[链接](link "工具提示")。

直接显示网址的连接<https://baidu.com>。

引用链接，[百度首页][1]。

[1]: https://www.baidu.com/

图片链接，语法类似，只不过需要在最前面加个叹号`!`。

![动漫头像](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fc-ssl.duitang.com%2Fuploads%2Fblog%2F202107%2F28%2F20210728204741_a1fd0.thumb.1000_0.png&refer=http%3A%2F%2Fc-ssl.duitang.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1651730896&t=bbc199118f455369bd3e4ab198805dee)

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

在一般的 markdown 解析器中不支持，但是`markdown preview enhance`扩展支持显示数学公式。

$$
c^2=a^2+b^2
$$

## 脚注

脚注需要设置标识符[^id]和链接[^link]。

[^id]: 标识符参考资料<https://markdown.com.cn/extended-syntax/footnotes.html>
[^link]: 链接参考资料<https://markdown.com.cn/extended-syntax/footnotes.html>
