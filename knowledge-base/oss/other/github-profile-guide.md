---
title: "几个小技巧美化你的 Github Profile"
date: 2022-11-17T22:01:55+08:00
image:
tags:
  - github
categories:
  - dev
---

Github 有个功能，就是当你创建一个和账户同名的仓库时，这个仓库的 README 文件就会当做账户的档案页面被展示出来。所以我们可以通过编辑这个页面来美化自己的 Github 档案。这里简单介绍一下几个常用技巧。

## markdown 语法

README 文件使用 markdown 格式，所以我们可以通过 markdown 语法提供的各种功能来编辑档案内容，必要的时候还可以用 HTML 标签来显示一些额外效果。例如如果你想要一部分内容居中显示，就要通过 align 属性来实现。

<p align="center">
  <img src="https://img.shields.io/badge/made_with-love-red?style=for-the-badge">
</p>

```HTML
<p align="center">
  <img src="https://img.shields.io/badge/made_with-love-red?style=for-the-badge">
</p>
```

## 徽章

如果你觉得显示出来的效果不够味道，还可以添加一些徽章。徽章是一种特殊的图片，可以自定义显示内容、图标，甚至可以显示动态数据。可以在 [badgen.net](https://badgen.net) 或者 [shields.io](https://shields.io) 上找到大量徽章。下面以 shields.io 为例说明。

### 徽章配方

[shields.io](https://shields.io) 的徽章的链接如下所示，可以看到，这是一个 URL 链接地址，当访问这个链接的时候，就会返回一张徽章图片，可以嵌入到 markdown 文件或者 HTML 页面上。_LABEL_、_MESSAGE_ 即是徽章要显示的文字，_STYLE_ 参数则决定了徽章的样式。如果需要显示 LOGO，就可以附上最后两个参数来设定 LOGO 和样式。具体支持的 LOGO 可以在 [simpleicons.org](https://simpleicons.org) 上找到。

```HTML
https://img.shields.io/badge/<LABEL>-<MESSAGE>-<COLOR>?style=<STYLE>&logo=<LOGO>&logoColor=<COLOR>
```

_LABEL_ 和 _MESSAGE_ 中如果有 `-_`（横线、下划线、空格）等特殊字符，需要进行转义。转义方法如下：

- 横线 `-` 用两个横线 `--` 代替
- 下划线 `_` 用两个下划线 `__` 代替
- 空格用一个下划线 `_` 代替

利用上面这些组合，我们就能获得各种各样的徽章。然后，就可以将徽章以 markdown 图片或者 img 标签的形式展示出来了。

![windows 10](https://img.shields.io/badge/windows_10-blue?style=for-the-badge&logo=windows)

![windows 11](https://img.shields.io/badge/windows_11-blue?style=for-the-badge&logo=windows-11)

```HTML
![](https://img.shields.io/badge/windows_10-blue?style=for-the-badge&logo=windows)
<img alt="badge" src="https://img.shields.io/badge/windows_11-blue?style=for-the-badge&logo=windows-11">
```

### 图片链接

既然徽章是图片，所以还可以和链接组合起来，实现按钮的功能，这样就更加有趣了。

<a href="mailto:lovery521@gmail.com"><img src="https://img.shields.io/badge/Gmail-EA4335.svg?style=for-the-badge&logo=Gmail&logoColor=white"></a>

```HTML
[![](https://img.shields.io/badge/Gmail-EA4335.svg?style=for-the-badge&logo=Gmail&logoColor=white)](mailto:lovery521@gmail.com)
<a href="mailto:lovery521@gmail.com"><img src="https://img.shields.io/badge/Gmail-EA4335.svg?style=for-the-badge&logo=Gmail&logoColor=white"></a>
```

下面是几个演示地址，你可以在这里寻找自己需要的徽章。

- <https://github.com/Envoy-VC/awesome-badges>
- <https://github.com/Naereen/badges>
- <https://github.com/Ileriayo/markdown-badges>
- <https://dev.to/envoy_/150-badges-for-github-pnk>
- <https://home.aveek.io/GitHub-Profile-Badges/>
- <https://github.com/alexandresanlim/Badges4-README.md-Profile>

## 数据显示

### 技能图标

<https://github.com/tandpfun/skill-icons>项目可以为你的 Github 档案显示技能图标。用法也十分简单，和徽章类似，在 markdown 中添加下面一行即可。支持的图标类型可以在项目的文档中找到，项目也支持一些样式调整，例如居中显示等。

[![My Skills](https://skillicons.dev/icons?i=linux,py,dotnet,github)](https://skillicons.dev)

```markdown
[![My Skills](https://skillicons.dev/icons?i=linux,py,dotnet,github)](https://skillicons.dev)
```

### github-profile-views-counter

[github-profile-views-counter](https://github.com/antonkomarev/github-profile-views-counter) 可以统计和记录查看 Github 档案的次数，看看你是不是一个 Github 名人。配置方法和徽章类似，只有少部分不同，参考文档获取详细信息。

![profile views](https://komarev.com/ghpvc/?username=techstay&color=blueviolet&style=for-the-badge)

### github-readme-stats

[github-readme-stats](https://github.com/anuraghazra/github-readme-stats) 可以为你的 Github 账户显示动态统计数据卡片。可以显示的卡片分为三种，Github 统计数据卡片、最多使用编程语言卡片以及 wakatime 编程时间卡片（需要在编辑器中启用 wakatime 插件才能统计编程时间）。

[![Anurag's GitHub stats](https://github-readme-stats.vercel.app/api?username=techstay)](https://github.com/anuraghazra/github-readme-stats?show_icons=true)

[![Top Langs](https://github-readme-stats.vercel.app/api/top-langs/?username=techstay&layout=compact)](https://github.com/anuraghazra/github-readme-stats)

[![willianrod's wakatime stats](https://github-readme-stats.vercel.app/api/wakatime?username=techstay)](https://github.com/anuraghazra/github-readme-stats)

统计卡片同样支持修改样式和主题，详情请查看文档。

### Github Readme Streak Stats

[Github Readme Streak Stats](https://github.com/DenverCoder1/github-readme-streak-stats) 可以显示 Github 统计数据，它还提供了一个 [在线 demo](https://streak-stats.demolab.com/demo/)，可以在线调整并实时查看样式。调整好了之后就可以复制到档案中显示了。

[![GitHub Streak](https://streak-stats.demolab.com?user=techstay&date_format=%5BY%20%5DM%20j)](https://git.io/streak-stats)

### GitHub Profile Trophy

[GitHub Profile Trophy](https://github.com/ryo-ma/github-profile-trophy) 可以将 Github 数据显示为一系列奖杯图案。

[![trophy](https://github-profile-trophy.vercel.app/?username=techstay)](https://github.com/ryo-ma/github-profile-trophy)

通过参数可以修改主题样式或者是要显示的奖杯类型，详情可参见文档。

### metrics

[metrics](https://github.com/lowlighter/metrics) 可以统计并显示大量 Github 数据，项目有丰富的模板可供使用，项目地址。

![Metrics](https://metrics.lecoq.io/techstay?template=classic&base=header%2C%20activity%2C%20community%2C%20repositories%2C%20metadata&base.indepth=false&base.hireable=false&base.skip=false&config.timezone=Asia%2FShanghai)

以上只是一个简单示例，大量功能并未启用。如果要启用完整功能的话，可以参考文档 [Using GitHub Action on a profile repository](https://github.com/lowlighter/metrics/blob/master/.github/readme/partials/documentation/setup/action.md) 里介绍的方法，在自己的档案仓库中添加 github 工作流。当工作流执行完毕之后就会在项目中生成一个 svg 文件，最后在 README 中粘贴代码并将图片地址改为项目中的相对链接，就能显示统计数据了。

要配置 Metrics 的样式，需要查看文档，然后在工作流文件中进行编辑。

## 图片

适当添加一张图片也可以让档案更加丰富。为了让图片显示在合适的位置（如页面右方），就需要利用 img 标签的对齐属性了。

```HTML
<img align="right" width="200px" src="https://s2.loli.net/2022/11/18/uzO2nedE9XJLq34.webp">
```
