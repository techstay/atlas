# Marimo CLI 命令参考

Marimo 提供丰富的命令行接口（CLI）用于创建、编辑、运行和部署笔记本。

## 安装和基础

### 安装 Marimo

```bash
# 基础安装
pip install marimo

# 包含推荐依赖（SQL、AI 补全等）
pip install "marimo[recommended]"

# 仅 SQL 支持
pip install "marimo[sql]"

# 使用 uv
uv add marimo
uv add "marimo[recommended]"

# 使用 conda
conda install -c conda-forge marimo
```

### 验证安装

```bash
# 检查版本
marimo --version

# 查看帮助
marimo --help
```

---

## 核心命令

### `marimo edit` - 编辑/创建笔记本

启动 Marimo 编辑器来创建或编辑笔记本。

```bash
# 创建新笔记本（自动分配端口）
marimo edit

# 指定端口
marimo edit --port 8080

# 编辑指定文件
marimo edit notebook.py

# 指定主机（允许外部访问）
marimo edit --host 0.0.0.0

# 无头模式（不自动打开浏览器）
marimo edit --headless

# 指定浏览器
marimo edit --browser firefox
```

**常用选项：**

| 选项 | 描述 | 默认值 |
|------|------|--------|
| `--port` | 服务器端口 | 随机可用端口 |
| `--host` | 主机地址 | `127.0.0.1` |
| `--headless` | 不自动打开浏览器 | `False` |
| `--browser` | 指定浏览器 | 系统默认 |
| `--no-token` | 禁用 CSRF 令牌 | - |
| `--token` | 自定义 CSRF 令牌 | - |

### `marimo run` - 运行应用

将笔记本作为交互式 Web 应用运行。

```bash
# 运行单个笔记本
marimo run notebook.py

# 指定端口
marimo run notebook.py --port 8080

# 允许外部访问
marimo run notebook.py --host 0.0.0.0

# 运行整个文件夹（gallery 模式）
marimo run folder/

# 运行多个指定文件
marimo run notebook_a.py notebook_b.py

# Watch 模式（开发时使用）
marimo run folder/ --watch

# 静默模式
marimo run notebook.py --silent
```

**常用选项：**

| 选项 | 描述 | 默认值 |
|------|------|--------|
| `--port` | 服务器端口 | `8080` |
| `--host` | 主机地址 | `127.0.0.1` |
| `--watch` | 监视文件变化 | `False` |
| `--base-url` | 基础 URL 路径 | `/` |
| `--silent` | 减少日志输出 | `False` |

### `marimo export` - 导出

将笔记本导出为各种格式。

```bash
# 导出为 HTML
marimo export html notebook.py

# 导出为带代码的 HTML
marimo export html notebook.py --include-code

# 导出为可运行的 HTML（嵌入 Python 运行时）
marimo export html notebook.py --self-contained

# 导出为 Markdown
marimo export markdown notebook.py

# 导出为纯 Python 脚本
marimo export python notebook.py

# 导出为 Jupyter notebook
marimo export ipynb notebook.py

# 导出为 PDF（需要额外依赖）
marimo export pdf notebook.py

# 幻灯片模式导出 PDF
marimo export pdf notebook.py --as=slides --raster-server=live

# 指定输出文件名
marimo export html notebook.py -o output.html

# 输出到 stdout
marimo export python notebook.py -o -
```

**导出选项：**

| 格式 | 命令 | 说明 |
|------|------|------|
| HTML | `export html` | 静态或交互式 HTML |
| Markdown | `export markdown` | Markdown 格式 |
| Python | `export python` | 纯 Python 脚本 |
| Jupyter | `export ipynb` | Jupyter notebook |
| PDF | `export pdf` | 需要 Playwright |

**HTML 导出选项：**

| 选项 | 描述 |
|------|------|
| `--include-code` | 包含代码 |
| `--self-contained` | 自包含（嵌入运行时）|
| `--no-iframe` | 不使用 iframe |
| `--title` | 自定义标题 |

### `marimo convert` - 转换

将 Jupyter notebook 转换为 Marimo 格式。

```bash
# 转换 Jupyter notebook 到 Marimo
marimo convert notebook.ipynb > notebook.py

# 批量转换
marimo convert *.ipynb

# 使用 web 界面转换
# 访问 https://marimo.io/convert
```

### `marimo tutorial` - 教程

运行内置教程。

```bash
# 列出所有教程
marimo tutorial --help

# 运行介绍教程
marimo tutorial intro

# 运行 UI 组件教程
marimo tutorial ui

# 运行 SQL 教程
marimo tutorial sql

# 运行数据可视化教程
marimo tutorial plots

# 运行布局教程
marimo tutorial layout

# 等等...
```

---

## 配置命令

### `marimo config` - 配置管理

```bash
# 查看当前配置
marimo config show

# 设置配置项
marimo config set key value

# 获取配置项
marimo config get key

# 删除配置项
marimo config remove key

# 重置所有配置
marimo config reset
```

---

## 环境变量

Marimo 支持以下环境变量：

| 变量 | 描述 | 示例 |
|------|------|------|
| `MARIMO_HOST` | 默认主机 | `0.0.0.0` |
| `MARIMO_PORT` | 默认端口 | `8080` |
| `MARIMO_BROWSER` | 默认浏览器 | `firefox` |
| `MARIMO_TOKEN` | CSRF 令牌 | `secret-token` |
| `MARIMO_SQL_OUTPUT_TYPE` | SQL 默认输出类型 | `native` |
| `MARIMO_APP_WIDTH` | 应用默认宽度 | `medium` |

---

## 配置文件

### pyproject.toml 配置

```toml
[tool.marimo]
# SQL 配置
sql_output_type = "native"
sql_linter = true

# 运行时配置
[tool.marimo.runtime]
auto_run = true
auto_run_on_cell_execution = true

# 数据源配置
[tool.marimo.datasources]
auto_discover_schemas = true
auto_discover_tables = "auto"
auto_discover_columns = "auto"

# 编辑器配置
[tool.marimo.editor]
app_width = "medium"  # "narrow", "medium", "full"
```

---

## 完整示例

### 开发工作流

```bash
# 1. 创建新笔记本
marimo edit my_app.py

# 2. 编辑完成后，测试应用模式
marimo run my_app.py

# 3. 导出为 HTML 分享
marimo export html my_app.py -o my_app.html --include-code

# 4. 部署到服务器
marimo run my_app.py --host 0.0.0.0 --port 8080
```

### CI/CD 集成

```yaml
# .github/workflows/deploy.yml
name: Deploy Marimo App

on:
  push:
    branches: [main]

jobs:
  deploy:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      
      - name: Setup Python
        uses: actions/setup-python@v4
        with:
          python-version: '3.11'
      
      - name: Install dependencies
        run: |
          pip install marimo -r requirements.txt
      
      - name: Export HTML
        run: |
          marimo export html app.py -o dist/index.html
      
      - name: Deploy
        uses: peaceiris/actions-gh-pages@v3
        with:
          github_token: ${{ secrets.GITHUB_TOKEN }}
          publish_dir: ./dist
```
