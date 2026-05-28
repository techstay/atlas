# Marimo SQL 和数据处理

Marimo 原生支持 SQL，让你可以混用 Python 和 SQL 来查询数据框、数据库和数据仓库。

## 安装依赖

```bash
# 基础安装（使用 DuckDB）
pip install "marimo[sql]"

# 或使用 uv
uv add "marimo[sql]"

# 或使用 conda
conda install -c conda-forge marimo duckdb polars
```

---

## 创建 SQL Cell

有三种方式创建 SQL cell：

1. **右键** cell 旁边的 "+" 按钮，选择 "SQL cell"
2. 通过 cell 上下文菜单将空 cell 转换为 SQL
3. 点击 notebook 底部出现的 SQL 按钮

创建的 SQL cell 看起来像这样：

```sql
SELECT * FROM my_table LIMIT 10
```

实际上，这是一个 Python f-string 的语法糖：

```python
output_df = mo.sql(f"SELECT * FROM my_table LIMIT {max_rows}")
```

---

## 查询本地数据框

可以直接在 SQL 中引用 Python 变量中的数据框：

```python
import pandas as pd
import marimo as mo

# 创建数据框
df = pd.DataFrame({
    "name": ["Alice", "Bob", "Charlie"],
    "age": [25, 30, 35],
    "city": ["NYC", "LA", "Chicago"]
})
```

```sql
-- 可以直接引用 df 变量
SELECT * FROM df WHERE age > 25
```

如果数据库中有同名表，数据库表优先使用。

---

## 输出变量

在 SQL cell 中定义输出变量来在其他 cell 中使用结果：

```sql
-- 定义输出变量 filtered_data
filtered_data = SELECT * FROM df WHERE age > 25
```

```python
# 在 Python cell 中使用结果
print(filtered_data.value)

# 结果是一个 Polars 或 Pandas DataFrame
import matplotlib.pyplot as plt
plt.hist(filtered_data.value['age'])
```

**注意**：使用下划线前缀（如 `_df`）会使变量私有化，其他 cell 无法引用。

---

## 查询文件和 API

Marimo 的 SQL 基于 DuckDB，可以直接查询多种数据源：

### 查询 CSV 文件

```sql
SELECT * FROM read_csv('path/to/file.csv')
```

### 查询 Parquet 文件

```sql
SELECT * FROM read_parquet('path/to/file.parquet')
```

### 查询 JSON 文件

```sql
SELECT * FROM read_json('path/to/file.json')
```

### 查询 HTTP API

```sql
SELECT * FROM read_csv_auto('https://api.example.com/data.csv')
```

### 查询 S3 存储

```sql
SELECT * FROM read_parquet('s3://my-bucket/data.parquet')
```

---

## 连接数据库

### 通过 UI 连接

点击 notebook 中的"添加数据库连接"按钮，支持：
- PostgreSQL
- MySQL
- SQLite
- DuckDB
- Snowflake
- BigQuery

### 通过代码连接

可以使用多种库创建连接引擎：

**SQLAlchemy:**

```python
import sqlalchemy

# 创建 SQLite 内存数据库
engine = sqlalchemy.create_engine("sqlite:///:memory:")
```

**SQLModel:**

```python
import sqlmodel

engine = sqlmodel.create_engine("sqlite:///:memory:")
```

**Ibis:**

```python
import ibis

engine = ibis.connect("sqlite:///:memory:")
```

**DuckDB:**

```python
import duckdb

conn = duckdb.connect("file.db")
```

创建引擎后，在 SQL cell 的连接下拉菜单中选择它。

---

## SQL 输出类型

Marimo 支持不同的 SQL 查询输出类型，在处理大数据集时特别有用。

### 配置输出类型

在应用配置的右上角设置输出类型：

| 选项 | 描述 |
|------|------|
| `native` | 使用 DuckDB 原生惰性关系（推荐最佳性能） |
| `lazy-polars` | 返回惰性 Polars DataFrame |
| `polars` | 返回急切 Polars DataFrame |
| `pandas` | 返回 Pandas DataFrame |
| `auto` | 基于安装的包自动选择 |

### 推荐设置

- **大数据集**: 使用 `native` 避免将整个结果加载到内存
- **需要 Python 处理**: 使用 `polars` 或 `pandas`
- **链式 SQL**: 使用 `native` 更容易连接 SQL cell

---

## SQL 实用功能

### SQL Linter

自动检查 SQL 代码，提供更好的自动补全和错误高亮。

在 `pyproject.toml` 中禁用：

```toml
[tool.marimo]
sql_linter = false
```

### SQL 格式化

点击 SQL cell 右下角油漆滚筒图标自动格式化 SQL 代码。

### SQL 模式

对于内存 DuckDB，Marimo 提供验证模式，在编写时验证 SQL。

---

## 完整示例

### 交互式 SQL 查询工具

```python
import marimo as mo
import pandas as pd

# 加载数据
@mo.cache
def load_data():
    return pd.read_csv("sales_data.csv")

df = load_data()

# 创建查询控件
controls = mo.vstack([
    mo.md("## SQL Query Builder"),
    mo.hstack([
        mo.ui.dropdown(df.columns.tolist(), label="Select column"),
        mo.ui.dropdown(["=", ">", "<", ">=", "<=", "!="], label="Operator", value="="),
        mo.ui.text(label="Value")
    ]),
    mo.ui.button(label="Execute Query", on_click=lambda: None)
])
controls
```

```sql
-- 动态生成的查询
{% raw %}
{% set col = controls[1][0].value %}
{% set op = controls[1][1].value %}
{% set val = controls[1][2].value %}

SELECT * FROM df WHERE {{ col }} {{ op }} '{{ val }}' LIMIT 100
{% endraw %}
```
