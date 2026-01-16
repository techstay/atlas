### A Pluto.jl notebook ###
# v0.20.21

using Markdown
using InteractiveUtils

# This Pluto notebook uses @bind for interactivity. When running this notebook outside of Pluto, the following 'mock version' of @bind gives bound variables a default value (instead of an error).
macro bind(def, element)
    #! format: off
    return quote
        local iv = try Base.loaded_modules[Base.PkgId(Base.UUID("6e696c72-6542-2067-7265-42206c756150"), "AbstractPlutoDingetjes")].Bonds.initial_value catch; b -> missing; end
        local el = $(esc(element))
        global $(esc(def)) = Core.applicable(Base.get, el) ? Base.get(el) : iv(el)
        el
    end
    #! format: on
end

# ╔═╡ 82f689c5-82b6-41cd-9504-c7821211e50c
using PlutoUI

# ╔═╡ 68d13206-82c1-49fc-bdae-a8f7e55ee629
using Plots

# ╔═╡ 92ce58e0-26ef-11ee-266f-df898ee75454
md"""
# Pluto 示例

Pluto是一个功能强大的笔记本，能以交互式方式执行julia代码，实时查看结果，还能方便的通过控件和代码进行交互。

## 开始使用

首先打开julia交互式终端，然后输入`]`进入包管理器界面，然后输入`add Pluto`就可以安装Pluto了。
```julia
]add Pluto
```

安装完成后打开REPL，然后输入以下命令就可以运行Pluto了。如果在vscode等编辑器中修改了文件，Pluto也会自动识别并在笔记本中更新。
```julia
import Pluto
Pluto.run(auto_reload_from_file=true)
```

在Pluto右边还有`Live Docs`，将鼠标移动到需要查看文档的函数或者变量之上，就可以即时显示对应的文档。

## markdown 示例

### 三级标题

#### 四级标题

##### 五级标题

###### 六级标题

前两个就是一级标题和二级标题的样式。

---

### 表格

markdown 文件里也可以显示表格。

| 姓名 | 年龄 |
| ---- | ---- |
| 张三 | 18   |
| 李四 | 20   |
| 王五 | 22   |
| 赵六 | 68   |

markdown文件的其他语法可以参考[这里](https://github.com/techstay/studyNotes/blob/main/notes/misc/markdown.md)
"""

# ╔═╡ a1d8d651-2598-4bbb-beb6-52fb1a4b8018
html"""
<h2>html示例</h2>
<p>在Pluto中也可以使用html文档</p>
"""

# ╔═╡ 2ba724cd-b40e-4cc3-bba7-f3aef9f558e4
md"""
## 编程

每个单元格只能接受一行代码，Pluto会以交互式的方式显示代码结果，方便随时查看。

### 变量
"""

# ╔═╡ 0ae34422-617d-49dd-b461-b1b16bb7545e
xxx = 100

# ╔═╡ 88c8a083-84ee-42ac-af15-2379e5bd3c1c
yyy = 2

# ╔═╡ 28a970d7-8e58-441d-b993-49ab0b1e80fa
@show xxx - yyy

# ╔═╡ 2e3c1dcf-2f0d-4805-a5ce-ed0e1ba633da
md"### 函数"

# ╔═╡ 2f54871e-40fb-4735-913a-8830f5873673
function foo(x)
  return 2x
end

# ╔═╡ 31b49c51-8a10-4d3d-a9bf-435e728846c3
foo(200)

# ╔═╡ 3dcbffac-374a-43ed-96bb-82eeaa63d61b
md"""
## 交互

这里介绍了一些用于笔记本交互的控件。

### 提示

提示对话框，默认模糊。
"""

# ╔═╡ 89480849-4313-44b8-b01d-539039dbf4be
"利用markdown包Admonition函数实现的hint提示框"
hint(text) = Markdown.MD(Markdown.Admonition("hint", "Hint", [text]))

# ╔═╡ 8cd9d4e9-f3a5-415e-b296-63b027c118ff
hint(md"一些提示，默认隐藏，先思考再看提示")

# ╔═╡ 1cbdbe1d-c017-49d4-8538-b0b044780ee5
md"""
### PlutoUI控件

官方文档链接：<https://featured.Plutojl.org/basic/Plutoui.jl>
"""

# ╔═╡ ebab4a32-8b96-4bcb-8004-168f604958fc
md"""
#### 滑动条
$(@bind sli Slider(0:2:100, default=50))

#### 文本框
$(@bind text TextField(default="default"))

#### 单选框
$(@bind sel Select([1 => "one", 2 => "two", 3 => "three"]))

#### 复选框
$(@bind chck CheckBox())

#### 多重复选框
$(@bind mchck MultiCheckBox(["one","two","three"]))
"""


# ╔═╡ 5766cfa8-5051-44d6-8f4a-4ced2e789255
(sli, text, chck, sel, mchck)

# ╔═╡ 0deadd0a-846a-4d9e-859f-c2301bb4c851
md"""
#### 可变数字
这是一个可以改变的数字: $(@bind num Scrubbable(100))

#### 按钮
按钮可以触发其他单元格的重新计算。

$(@bind btn Button("随机数"))
"""

# ╔═╡ 6114e037-b3cd-4679-8774-4a45edf411f9
let
  btn
  md"随机数字: $(rand(1:100))"
end

# ╔═╡ 45b950fa-3864-4279-93ce-aa8b737071ea
(num)

# ╔═╡ 2724bb74-66db-411c-a1d3-d63d1f2db600
md"""
#### 原生HTML控件

Pluto也支持原生HTML控件，在需要高度自定义的场合可能更有用。
"""

# ╔═╡ 6d7d7bfc-a2b7-462c-821f-8c9a920e73fd
@bind sli2 html"""<input type=range min=0 max=100 value=50>"""

# ╔═╡ f823c77b-21bd-4c5d-8745-c88431aaec58
sli2

# ╔═╡ f94f560d-68a5-4841-a180-a9436855af62
md"""
## 图表

Pluto还支持图表功能，可以使用常见的图表库。

### 图表示例
"""

# ╔═╡ d9f14120-b2a7-472a-8e54-0dc54642af17
begin
  x = -2π:0.1:2π
  y = sin.(x)
  plot(x, y, title="title", lw=2, label="sin(x)")
end

# ╔═╡ e05ccc85-e910-4847-8b70-c55769b3bdb5
plot([sin, cos], -2π:0.1:2π, lw=2)

# ╔═╡ 7bc77181-a1fb-4b1a-948e-1573a4d7f4b2
plot(x -> x, 0:0.1:2π, proj=:polar, lw=2)

# ╔═╡ 0c4b0b33-d24a-42d9-8c4b-008befd69c49

md"""
### 图表和控件

图表还可以和控件结合起来使用。

"""

# ╔═╡ 7b4486c6-fb0a-4d7d-a891-980bfe333e56
@bind k1 Slider(-4:0.1:4, default=1)

# ╔═╡ fba3bf76-278e-4b1a-8b33-6784066ed5ce
plot(x -> k1 * x^2 + x - 4, -10:0.1:10, lw=2)

# ╔═╡ Cell order:
# ╟─92ce58e0-26ef-11ee-266f-df898ee75454
# ╠═a1d8d651-2598-4bbb-beb6-52fb1a4b8018
# ╠═2ba724cd-b40e-4cc3-bba7-f3aef9f558e4
# ╠═0ae34422-617d-49dd-b461-b1b16bb7545e
# ╠═88c8a083-84ee-42ac-af15-2379e5bd3c1c
# ╠═28a970d7-8e58-441d-b993-49ab0b1e80fa
# ╠═2e3c1dcf-2f0d-4805-a5ce-ed0e1ba633da
# ╠═2f54871e-40fb-4735-913a-8830f5873673
# ╠═31b49c51-8a10-4d3d-a9bf-435e728846c3
# ╠═3dcbffac-374a-43ed-96bb-82eeaa63d61b
# ╠═89480849-4313-44b8-b01d-539039dbf4be
# ╠═8cd9d4e9-f3a5-415e-b296-63b027c118ff
# ╠═1cbdbe1d-c017-49d4-8538-b0b044780ee5
# ╠═82f689c5-82b6-41cd-9504-c7821211e50c
# ╠═ebab4a32-8b96-4bcb-8004-168f604958fc
# ╠═5766cfa8-5051-44d6-8f4a-4ced2e789255
# ╠═0deadd0a-846a-4d9e-859f-c2301bb4c851
# ╠═6114e037-b3cd-4679-8774-4a45edf411f9
# ╠═45b950fa-3864-4279-93ce-aa8b737071ea
# ╠═2724bb74-66db-411c-a1d3-d63d1f2db600
# ╠═6d7d7bfc-a2b7-462c-821f-8c9a920e73fd
# ╠═f823c77b-21bd-4c5d-8745-c88431aaec58
# ╠═f94f560d-68a5-4841-a180-a9436855af62
# ╠═68d13206-82c1-49fc-bdae-a8f7e55ee629
# ╠═d9f14120-b2a7-472a-8e54-0dc54642af17
# ╠═e05ccc85-e910-4847-8b70-c55769b3bdb5
# ╠═7bc77181-a1fb-4b1a-948e-1573a4d7f4b2
# ╠═0c4b0b33-d24a-42d9-8c4b-008befd69c49
# ╠═7b4486c6-fb0a-4d7d-a891-980bfe333e56
# ╠═fba3bf76-278e-4b1a-8b33-6784066ed5ce
