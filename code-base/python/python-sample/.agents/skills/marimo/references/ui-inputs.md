# Marimo UI 输入组件

Marimo 提供了丰富的交互式 UI 组件，用于构建强大的笔记本和应用。这些组件都在 `marimo.ui` 命名空间下。

## 基本用法

使用 UI 组件的三步：

1. **导入**：`import marimo as mo`
2. **创建**：组件赋值给全局变量
3. **显示**：在 cell 末尾输出组件

```python
import marimo as mo

# 创建一个滑块
slider = mo.ui.slider(1, 100, value=50)
slider
```

## 访问组件值

组件的值通过 `.value` 属性访问：

```python
# 在其他 cell 中使用组件值
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 100)
y = np.sin(x * slider.value / 10)

plt.plot(x, y)
plt.title(f"Frequency: {slider.value}")
plt.show()
```

当用户与组件交互时，`.value` 自动更新，所有引用该组件的 cell 会自动重新运行。

---

## 输入组件

### 文本输入

#### `mo.ui.text(label=None, value="")`
单行文本输入

```python
name = mo.ui.text("Enter your name:", value="Alice")
name
```

#### `mo.ui.text_area(label=None, value="", rows=4)`
多行文本输入

```python
bio = mo.ui.text_area("Tell us about yourself:", rows=6)
bio
```

#### `mo.ui.code_editor(language="python", value="")`
代码编辑器

```python
code = mo.ui.code_editor(language="python", value="print('Hello World')")
code
```

### 数值输入

#### `mo.ui.number(start, stop, value=None, label=None)`
数字输入框

```python
age = mo.ui.number(0, 150, value=25, label="Age:")
age
```

#### `mo.ui.slider(start, stop, value=None, step=None, label=None)`
滑块

```python
slider = mo.ui.slider(0, 100, value=50, step=5, label="Value:")
slider
```

#### `mo.ui.range_slider(start, stop, value=None, label=None)`
范围滑块（选择区间）

```python
range_slider = mo.ui.range_slider(0, 100, value=(20, 80), label="Range:")
range_slider
```

### 选择类输入

#### `mo.ui.dropdown(options, value=None, label=None)`
下拉选择框

```python
color = mo.ui.dropdown(
    ["red", "green", "blue", "yellow"],
    value="blue",
    label="Favorite color:"
)
color
```

#### `mo.ui.radio(options, value=None, label=None)`
单选按钮组

```python
size = mo.ui.radio(["small", "medium", "large"], value="medium", label="Size:")
size
```

#### `mo.ui.multiselect(options, value=None, label=None)`
多选下拉框

```python
toppings = mo.ui.multiselect(
    ["cheese", "pepperoni", "mushrooms", "onions"],
    value=["cheese"],
    label="Pizza toppings:"
)
toppings
```

#### `mo.ui.checkbox(value=False, label=None)`
复选框

```python
agree = mo.ui.checkbox(value=False, label="I agree to the terms")
agree
```

#### `mo.ui.switch(value=False, label=None)`
开关（切换按钮）

```python
dark_mode = mo.ui.switch(value=False, label="Dark mode")
dark_mode
```

### 日期时间输入

#### `mo.ui.date(value=None, label=None)`
日期选择器

```python
birth_date = mo.ui.date(value="1990-01-01", label="Birth date:")
birth_date
```

#### `mo.ui.datetime(value=None, label=None)`
日期时间选择器

```python
appointment = mo.ui.datetime(label="Appointment:")
appointment
```

#### `mo.ui.date_range(start=None, end=None, label=None)`
日期范围选择器

```python
trip_dates = mo.ui.date_range(label="Trip dates:")
trip_dates
```

---

## 高级组件

### 文件上传

#### `mo.ui.file(label=None, multiple=False)`
文件上传组件

```python
uploaded_file = mo.ui.file(label="Upload a file:", multiple=False)
uploaded_file
```

访问上传的文件：

```python
# 获取文件内容
if uploaded_file.value:
    content = uploaded_file.value[0].contents
    filename = uploaded_file.value[0].name
```

#### `mo.ui.file_browser(start_path=".", label=None)`
文件浏览器

```python
selected_file = mo.ui.file_browser(start_path="./data", label="Select file:")
selected_file
```

### 按钮

#### `mo.ui.button(label="Click me", on_click=None)`
普通按钮

```python
click_count = mo.ui.state(0)

def on_click():
    click_count.value += 1

button = mo.ui.button(label=f"Clicked {click_count.value} times", on_click=on_click)
button
```

#### `mo.ui.run_button(label="Run")`
运行按钮（触发 cell 重新执行）

```python
run_btn = mo.ui.run_button(label="Refresh data")
run_btn
```

#### `mo.ui.refresh(label="Refresh", seconds=None)`
自动刷新按钮/定时器

```python
# 手动刷新按钮
refresh_btn = mo.ui.refresh(label="Update")

# 每 5 秒自动刷新
auto_refresh = mo.ui.refresh(seconds=5)
auto_refresh
```

### 数据结构编辑

#### `mo.ui.array(elements, label=None)`
数组编辑器

```python
arr = mo.ui.array([mo.ui.number(0, 100) for _ in range(3)], label="Values:")
arr
```

#### `mo.ui.dictionary(value, label=None)`
字典编辑器

```python
dict_editor = mo.ui.dictionary(
    {"name": mo.ui.text("Name"), "age": mo.ui.number(0, 150)},
    label="Person:"
)
dict_editor
```

#### `mo.ui.matrix(shape, value=None, label=None)`
矩阵/向量编辑器

```python
matrix = mo.ui.matrix((3, 3), label="Matrix:")
matrix
```

### 表单

#### `mo.ui.form(children, on_submit=None)`
表单组件（批量提交多个输入）

```python
name_input = mo.ui.text(label="Name:")
age_input = mo.ui.number(0, 150, label="Age:")
email_input = mo.ui.text(label="Email:")

form = mo.ui.form([name_input, age_input, email_input], label="Submit")
form
```

访问表单值：

```python
if form.value:
    print(f"Name: {form.value['Name:']}")
    print(f"Age: {form.value['Age:']}")
```

### 标签页

#### `mo.ui.tabs(tabs, value=None)`
标签页组件

```python
tabs = mo.ui.tabs({
    "Tab 1": mo.ui.text("Content for tab 1"),
    "Tab 2": mo.ui.text("Content for tab 2"),
    "Tab 3": mo.ui.text("Content for tab 3")
})
tabs
```

获取当前选中的标签：

```python
print(tabs.value)  # 输出当前选中的标签名
```

---

## 数据展示组件

### 数据框

#### `mo.ui.dataframe(df, selection=None)`
交互式数据框查看器

```python
df = pd.DataFrame({"A": [1, 2, 3], "B": [4, 5, 6]})
table = mo.ui.dataframe(df, selection="multi")
table
```

### 表格

#### `mo.ui.table(data, pagination=10)`
表格组件

```python
data = [{"name": "Alice", "age": 25}, {"name": "Bob", "age": 30}]
table = mo.ui.table(data, pagination=5)
table
```

### 数据探索器

#### `mo.ui.data_explorer(df)`
数据探索器（自动分析数据）

```python
df = pd.DataFrame({"A": [1, 2, 3, 4, 5], "B": [5, 4, 3, 2, 1]})
explorer = mo.ui.data_explorer(df)
explorer
```

---

## 集成组件

### 图表集成

#### `mo.ui.altair_chart(chart)`
交互式 Altair 图表

```python
import altair as alt

chart = alt.Chart(df).mark_point().encode(x='A', y='B')
interactive_chart = mo.ui.altair_chart(chart)
interactive_chart
```

#### `mo.ui.plotly(fig)`
交互式 Plotly 图表

```python
import plotly.express as px

fig = px.scatter(df, x="A", y="B")
interactive_plot = mo.ui.plotly(fig)
interactive_plot
```

#### `mo.ui.matplotlib(fig)`
响应式 Matplotlib 图表

```python
import matplotlib.pyplot as plt

fig, ax = plt.subplots()
ax.plot([1, 2, 3], [1, 4, 2])
mo.ui.matplotlib(fig)
```

### 聊天界面

#### `mo.ui.chat(messages=None, on_send=None)`
聊天界面组件

```python
def on_send(message):
    return f"Echo: {message}"

chat = mo.ui.chat(on_send=on_send)
chat
```

### 自定义 Widget

#### `mo.ui.anywidget(widget)`
使用 anywidget 的自定义 widget

```python
import anywidget
import traitlets

class CounterWidget(anywidget.AnyWidget):
    _esm = """
    export function render({ model, el }) {
      let count = () => model.get("count");
      let btn = document.createElement("button");
      btn.innerHTML = `Count is ${count()}`;
      btn.addEventListener("click", () => {
        model.set("count", count() + 1);
        model.save_changes();
      });
      el.appendChild(btn);
    }
    """
    count = traitlets.Int(0).tag(sync=True)

counter = mo.ui.anywidget(CounterWidget())
counter
```

---

## 最佳实践

### 组件组合模式

将多个组件组合成更复杂的界面：

```python
import marimo as mo

# 创建表单组件
name = mo.ui.text(label="Name")
age = mo.ui.number(0, 150, label="Age")
email = mo.ui.text(label="Email")
submit = mo.ui.button(label="Submit")

# 组合成表单界面
form = mo.vstack([
    mo.md("## User Registration"),
    name,
    age,
    email,
    submit
])
form
```

### 条件显示

根据组件值条件显示内容：

```python
toggle = mo.ui.switch(label="Show advanced options")
toggle
```

```python
# 根据 switch 值显示不同内容
if toggle.value:
    mo.vstack([
        mo.ui.number(label="Advanced param 1"),
        mo.ui.number(label="Advanced param 2")
    ])
else:
    mo.md("Basic mode enabled")
```

### 状态管理

使用 `mo.ui.state()` 管理复杂状态：

```python
# 创建状态
counter = mo.ui.state(0)

def increment():
    counter.value += 1

button = mo.ui.button(label=f"Count: {counter.value}", on_click=increment)
button
```

---

## 完整示例

### 交互式数据探索器

```python
import marimo as mo
import pandas as pd
import matplotlib.pyplot as plt

# 加载数据
@mo.cache

def load_data():
    return pd.read_csv("data.csv")

df = load_data()

# 创建交互控件
filters = mo.vstack([
    mo.md("## Data Explorer"),
    mo.hstack([
        mo.ui.dropdown(df.columns.tolist(), label="X axis"),
        mo.ui.dropdown(df.columns.tolist(), label="Y axis")
    ]),
    mo.ui.range_slider(0, len(df), label="Row range"),
    mo.ui.checkbox(label="Show trend line")
])
filters
```

```python
# 根据控件值生成图表
x_col = filters[1][0].value
y_col = filters[1][1].value
row_range = filters[2].value
show_trend = filters[3].value

filtered_df = df.iloc[row_range[0]:row_range[1]]

fig, ax = plt.subplots()
ax.scatter(filtered_df[x_col], filtered_df[y_col])

if show_trend:
    z = np.polyfit(filtered_df[x_col], filtered_df[y_col], 1)
    p = np.poly1d(z)
    ax.plot(filtered_df[x_col], p(filtered_df[x_col]), "r--")

ax.set_xlabel(x_col)
ax.set_ylabel(y_col)
mo.ui.matplotlib(fig)
```
