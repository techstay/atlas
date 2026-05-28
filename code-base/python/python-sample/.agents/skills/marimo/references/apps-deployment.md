# Marimo 应用部署和布局

Marimo 可以将任何笔记本作为交互式 Web 应用运行。`marimo run` 命令将笔记本布局为应用，并启动托管该应用的 Web 服务器。

## 运行应用

### 基本命令

```bash
# 运行单个笔记本作为应用
marimo run notebook.py

# 指定端口
marimo run notebook.py --port 8080

# 主机设置（0.0.0.0 允许外部访问）
marimo run notebook.py --host 0.0.0.0
```

### 运行多个笔记本（Gallery）

```bash
# 运行整个文件夹作为应用 gallery
marimo run folder/

# 运行多个指定文件
marimo run notebook_a.py notebook_b.py folder/

# Watch 模式（开发时使用，自动刷新 gallery 索引）
marimo run folder/ --watch
```

Gallery 会显示一个页面，每个笔记本一个卡片。卡片可以使用笔记本的 OpenGraph 元数据来显示标题、描述和缩略图。

---

## 应用布局

### 垂直布局（默认）

默认布局是垂直布局：cell 输出垂直连接，代码隐藏。

```bash
marimo run notebook.py
```

特点：
- 所有输出按 cell 顺序垂直排列
- 代码默认隐藏（可以配置显示）
- 使用 `mo.hstack`、`mo.vstack` 等函数可以实现复杂的程序化布局

### 网格布局（Grid）

使用拖放网格编辑器来排列应用界面。

**启用方式：**

在 `marimo edit` 编辑器的应用预览中，通过下拉菜单启用网格编辑器。

**使用方法：**

1. 在编辑模式下，点击"预览"按钮查看应用布局
2. 从下拉菜单选择"Grid layout"
3. 拖动输出到网格上
4. 调整大小和位置

特点：
- 可视化拖放界面
- 不需要编写布局代码
- 布局保存在 `layouts/` 文件夹中

### 幻灯片布局（Slides）

使用类似幻灯片的体验展示内容。

**启用方式：**

在应用预览的下拉菜单中选择"Slides layout"。

特点：
- 幻灯片顺序由 notebook 中 cell 的顺序决定
- 不支持拖放重新排列
- 所有输出显示，代码隐藏
- 支持 PDF 导出

**PDF 导出命令：**

```bash
marimo export pdf notebook.py --as=slides --raster-server=live
```

---

## 布局函数

使用 Marimo 的布局函数可以在代码中程序化地组织输出。

### 基础布局

#### `mo.hstack(items, justify="start", align="center", gap=0)`
水平堆叠

```python
mo.hstack([
    mo.ui.button(label="Left"),
    mo.ui.button(label="Center"),
    mo.ui.button(label="Right")
], justify="center", gap=1)
```

参数：
- `justify`: `"start"`, `"center"`, `"end"`, `"between"`, `"around"`, `"evenly"`
- `align`: `"start"`, `"center"`, `"end"`, `"stretch"`
- `gap`: 间距大小（数字，0-4）

#### `mo.vstack(items, justify="start", align="stretch", gap=0)`
垂直堆叠

```python
mo.vstack([
    mo.md("# Title"),
    mo.ui.text(label="Input:"),
    mo.ui.button(label="Submit")
], gap=2)
```

#### `mo.hstack([...], gap=1)` 和 `mo.vstack([...], gap=1)`

快捷创建带间距的布局：

```python
# 水平排列，间距为 1
mo.hstack([component1, component2, component3], gap=1)

# 垂直排列，间距为 2
mo.vstack([header, content, footer], gap=2)
```

### 对齐和分布

#### 水平对齐

```python
# 左对齐（默认）
mo.hstack([a, b, c], justify="start")

# 居中对齐
mo.hstack([a, b, c], justify="center")

# 右对齐
mo.hstack([a, b, c], justify="end")

# 两端对齐
mo.hstack([a, b, c], justify="between")

# 均匀分布
mo.hstack([a, b, c], justify="around")
mo.hstack([a, b, c], justify="evenly")
```

#### 垂直对齐

```python
# 顶部对齐
mo.hstack([a, b, c], align="start")

# 居中对齐
mo.hstack([a, b, c], align="center")

# 底部对齐
mo.hstack([a, b, c], align="end")

# 拉伸填充
mo.hstack([a, b, c], align="stretch")
```

### 高级布局

#### `mo.accordion(items)`
手风琴折叠面板

```python
mo.accordion({
    "Section 1": mo.md("Content for section 1"),
    "Section 2": mo.md("Content for section 2"),
    "Section 3": mo.md("Content for section 3")
})
```

#### `mo.tabs(tabs, value=None)`
标签页

```python
mo.tabs({
    "Plot": mo.ui.plotly(fig),
    "Data": mo.ui.dataframe(df),
    "Summary": mo.md(summary_text)
})
```

#### `mo.sidebar(content)`
侧边栏

```python
mo.sidebar([
    mo.md("## Menu"),
    mo.ui.button(label="Home"),
    mo.ui.button(label="Settings"),
    mo.ui.button(label="About")
])
```

#### `mo.callout(content, kind="info")`
提示框

```python
mo.callout("This is an important note!", kind="info")
mo.callout("Warning: This action cannot be undone.", kind="warn")
mo.callout("Success! Your changes have been saved.", kind="success")
mo.callout("Error: Failed to save file.", kind="error")
```

### 响应式布局

#### 基于条件的显示

```python
show_details = mo.ui.switch(label="Show details")
show_details
```

```python
# 根据 switch 值条件显示
content = [mo.md("## Summary")]

if show_details.value:
    content.append(mo.ui.dataframe(df))
    content.append(mo.ui.plotly(fig))

mo.vstack(content)
```

#### 动态布局

```python
# 根据数据动态创建布局
items = [mo.ui.button(label=f"Button {i}") for i in range(5)]

# 根据数量选择布局方式
if len(items) <= 3:
    layout = mo.hstack(items, gap=1)
else:
    layout = mo.vstack(items, gap=1)

layout
```

---

## 布局保存

### 布局文件夹

Marimo 将布局元数据保存在 `layouts/` 文件夹中：

```
my_notebook/
├── notebook.py
└── layouts/
    └── notebook.json
```

**重要**：
- 分享或部署 notebook 时包含 `layouts/` 文件夹
- 将 `layouts/` 纳入版本控制
- 删除 `layouts/` 会丢失自定义布局

### 布局配置

```python
# 在 notebook 中设置布局选项
import marimo as mo

# 配置应用宽度
mo.app_config({
    "app_width": "medium",  # "narrow", "medium", "full"
    "layout": "vertical"    # "vertical", "grid", "slides"
})
```

---

## 部署检查清单

### 部署前检查

- [ ] 所有依赖在 `requirements.txt` 中列出
- [ ] 敏感信息使用环境变量
- [ ] 数据文件路径是相对路径或环境变量
- [ ] `layouts/` 文件夹包含在部署中
- [ ] 应用在本地通过 `marimo run` 测试

### 环境变量

```python
import os

# 从环境变量读取配置
DATABASE_URL = os.environ.get("DATABASE_URL")
API_KEY = os.environ.get("API_KEY")
```

### Docker 部署示例

```dockerfile
FROM python:3.11-slim

WORKDIR /app

COPY requirements.txt .
RUN pip install -r requirements.txt

COPY . .

EXPOSE 8080

CMD ["marimo", "run", "app.py", "--host", "0.0.0.0", "--port", "8080"]
```
