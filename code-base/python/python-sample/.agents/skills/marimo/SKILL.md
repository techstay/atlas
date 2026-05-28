---
name: marimo
description: >
  在 Marimo 中创建和管理响应式 Python Notebook。当用户需要在 Marimo 中创建笔记本、
  添加 UI 输入组件、编写 SQL 查询、部署为应用、或者需要了解 Marimo 的响应式执行模型时使用此技能。
  关键词：marimo notebook, 响应式笔记本, Python notebook, UI 组件, SQL cell, app deployment。
license: MIT
version: "0.23.1"
---

# Marimo 技能

Marimo 是一个开源的响应式 Python Notebook，它将传统的 Jupyter Notebook 重新构想为可复现、可交互、可分享的 Python 程序。

## 快速参考

| 你要做什么 | 该怎么做 |
|------------|----------|
| 创建新笔记本 | 运行 `marimo edit` 或 `marimo edit notebook.py` |
| 添加 UI 输入组件 | 加载 `references/ui-inputs.md`，使用 `mo.ui.*` 组件 |
| 编写 SQL 查询 | 加载 `references/sql-data.md`，创建 SQL cell |
| 部署为 Web 应用 | 加载 `references/apps-deployment.md`，运行 `marimo run notebook.py` |
| 理解响应式执行 | 加载 `references/core-concepts.md`，学习 DAG 执行模型 |
| 查看 CLI 命令 | 加载 `references/cli-commands.md` |

---

## 关键工作流规则

### ⚠️ 最容易出错的地方

#### 变量突变不被追踪

**避免：**

- ❌ 在一个 cell 中定义变量，在另一个 cell 中修改它
- ❌ 使用 `list.append()`、`df['col'] = values` 等突变操作

**遵循：**

- ✅ 在定义变量的同一个 cell 中完成所有修改
- ✅ 创建新变量而不是修改旧变量（`new_list = old_list + [item]`）
- ✅ 使用纯函数式风格处理数据

#### 全局变量名必须唯一

**避免：**

- ❌ 在多个 cell 中定义同名的全局变量
- ❌ 导入的模块名与变量名冲突

**遵循：**

- ✅ 每个全局变量只在一个 cell 中定义
- ✅ 使用下划线前缀创建局部变量（`_temp_var`）
- ✅ 将临时变量封装在函数内部

---

## Reference 文件 — 按需加载

**不要一次全部加载。只加载当前任务所需的文件。**

| 文件 | 内容 | 加载时机 |
|------|------|----------|
| `references/core-concepts.md` | 响应式执行模型、DAG、变量规则 | 需要理解 Marimo 工作原理时 |
| `references/ui-inputs.md` | 所有 UI 输入组件的详细用法 | 需要添加交互控件时 |
| `references/sql-data.md` | SQL cell、数据库连接、数据处理 | 需要使用 SQL 查询时 |
| `references/apps-deployment.md` | 部署应用、布局选项、网格/幻灯片 | 需要部署为 Web 应用时 |
| `references/cli-commands.md` | 所有 CLI 命令和选项 | 需要查看命令行用法时 |

---

## 常见错误

| ❌ 错误写法 | ✅ 正确写法 | 原因 |
|------------|------------|------|
| `df['new_col'] = values` 在另一个 cell | 在同一 cell 中完成 | 突变不被追踪 |
| `my_list.append(x)` 在另一个 cell | 创建新列表：`my_list + [x]` | 突变不被追踪 |
| 在多个 cell 中定义 `x = ...` | 每个变量只在一个 cell 定义 | 违反唯一性规则 |
| 使用全局变量传递中间结果 | 封装为函数或使用返回值 | 避免隐藏依赖 |

---

## 快速示例

### 基本笔记本结构

```python
# Cell 1: 导入
import marimo as mo
import pandas as pd

# Cell 2: 数据准备
data = {"x": [1, 2, 3], "y": [4, 5, 6]}
df = pd.DataFrame(data)

# Cell 3: 添加交互
slider = mo.ui.slider(1, 10, value=5)
slider

# Cell 4: 响应式计算
filtered_df = df[df["x"] < slider.value]
filtered_df
```

### 运行笔记本

```bash
# 编辑模式
marimo edit notebook.py

# 运行应用模式
marimo run notebook.py

# 转换为脚本执行
python notebook.py
```
