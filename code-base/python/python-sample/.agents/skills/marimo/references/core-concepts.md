# Marimo 核心概念

## 响应式执行模型

Marimo 使用**响应式执行模型**（Reactive Execution），这是它与 Jupyter 最大的区别之一。

### 如何工作

1. **静态分析**：Marimo 在不执行代码的情况下分析每个 cell，确定：
   - **引用（references）**：cell 读取但未定义的全局变量
   - **定义（definitions）**：cell 定义的全局变量

2. **构建 DAG**：基于引用和定义关系，Marimo 构建一个有向无环图（DAG）

3. **响应式执行**：当一个 cell 运行时，所有引用它定义的变量的 cell 会自动重新运行

```
Cell A: x = 1          (defines x)
   ↓
Cell B: y = x + 1      (references x, defines y)
   ↓
Cell C: print(y)       (references y)
```

当 Cell A 改变时，Cell B 和 Cell C 会自动重新执行。

### 执行顺序

- Cell 的执行顺序由变量关系决定，而不是在页面上的位置
- 这类似于电子表格的行为
- 你可以把辅助函数放在笔记本底部，逻辑上仍然可以工作

### 删除 Cell 会删除变量

**关键特性**：在 Marimo 中，**删除一个 cell 会从程序内存中删除它的全局变量**。

- 引用这些变量的 cell 会自动重新运行并失效
- 这消除了传统 Notebook 中常见的隐藏状态问题

---

## 变量规则

### 1. 变量突变不被追踪

Marimo **不会追踪变量的突变**（mutations）。

**❌ 错误做法：**

```python
# Cell 1
my_list = [1, 2, 3]

# Cell 2
my_list.append(4)  # 这不会触发 Cell 1 的重新运行
```

**✅ 正确做法：**

```python
# Cell 1
my_list = [1, 2, 3]

# Cell 2
new_list = my_list + [4]  # 创建新变量
```

**为什么？**

- 可靠地追踪 Python 中的突变是不可能的
- 响应突变可能导致意外的 cell 重新运行

### 2. 全局变量名必须唯一

**每个全局变量只能在一个 cell 中定义**。

**❌ 错误做法：**

```python
# Cell 1
x = 1

# Cell 2
x = 2  # 错误！x 已经在 Cell 1 中定义
```

**✅ 正确做法：**

```python
# Cell 1
x = 1

# Cell 2
y = 2  # 使用不同的变量名
```

**为什么？**

- 这确保 Marimo 能保持代码和输出的一致性
- 鼓励减少全局变量的数量

---

## 创建临时变量

### 使用下划线前缀

变量以下划线开头（例如 `_temp`）是"局部"于 cell 的：

- 其他 cell 无法读取它们
- 多个 cell 可以重复使用相同的局部变量名

```python
# Cell 1
_temp = expensive_computation()  # 只在 Cell 1 中可见
result1 = _temp + 1

# Cell 2
_temp = another_computation()  # 可以重用 _temp
result2 = _temp * 2
```

### 使用函数封装

如果你想让一个 cell 中的大多数变量都是临时的，可以将代码封装在函数中：

```python
def _():
    import matplotlib.pyplot as plt
    fig, ax = plt.subplots()
    ax.plot([1, 2])
    return ax

_()
```

这里的 `plt`、`fig` 和 `ax` 不会添加到全局变量中。

---

## 配置运行模式

### 运行时配置

通过 notebook 设置菜单，你可以配置 Marimo 如何运行 cell：

| 选项 | 描述 |
|------|------|
| 启动时自动运行 | 打开 notebook 时是否自动运行所有 cell |
| 执行时自动运行 | 修改 cell 后是否自动运行依赖的 cell |
| 模块自动重载 | 修改导入的模块时是否自动重载 |

### 禁用 Cell

有时你想编辑 notebook 的一部分，而不触发依赖 cell 的自动执行：

- **禁用 cell**：右键点击 cell，选择"禁用"
- 禁用的 cell 及其依赖 cell 不会运行
- 重新启用时，如果祖先 cell 已运行，Marimo 会自动运行该 cell

---

## 最佳实践

### ✅ 应该做的

1. **创建新变量而不是修改旧变量**
   ```python
   # 好
   new_list = old_list + [item]
   
   # 不好
   old_list.append(item)
   ```

2. **在定义变量的 cell 中完成所有修改**
   ```python
   # Cell 1
   df = pd.DataFrame({"a": [1, 2]})
   df["b"] = [3, 4]  # 在同一 cell 中修改
   ```

3. **使用局部变量减少全局变量数量**
   ```python
   _temp = compute()  # _ 前缀 = 局部变量
   result = _temp + 1
   ```

4. **使用函数封装复杂逻辑**
   ```python
   def _():
       # 复杂计算
       return result
   _()
   ```

### ❌ 不应该做的

1. **不要在不同 cell 中修改同一个变量**
2. **不要使用 `global` 关键字**
3. **不要依赖 cell 的执行顺序**（应该依赖变量关系）
4. **不要创建过多的全局变量**

---

## 故障排除

### 问题：Cell 没有自动运行

**可能原因：**
1. 运行时配置设置为"惰性"模式
2. Cell 被禁用
3. 变量关系没有正确建立

**解决方案：**
- 检查设置菜单中的运行时配置
- 确认 cell 没有被禁用
- 检查变量名是否拼写正确

### 问题：变量值不正确

**可能原因：**
1. 隐藏状态（应该已经被 Marimo 防止）
2. Cell 执行顺序不符合预期

**解决方案：**
- 使用"运行时 > 重启并运行所有 cell"
- 检查变量依赖关系
- 确保没有在多个 cell 中定义同名变量

### 问题：性能缓慢

**解决方案：**
- 启用惰性模式（标记为过时而不是自动运行）
- 使用 `mo.stop()` 条件停止执行
- 参考 [昂贵笔记本指南](https://docs.marimo.io/guides/expensive_notebooks/)
