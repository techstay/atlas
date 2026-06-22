---
title: "Python 包管理器"
date: 2021-12-06T00:47:28+08:00
updated: 2026-06-22T10:58:00+08:00
tags:
  - python
  - pip
  - poetry
  - uv
  - package-management
categories:
  - dev
---

Python 包管理生态经历了多轮演进，目前主流的方案可以归纳为三种：传统的 `pip + venv + requirements.txt`、一体化的 **Poetry**，以及新一代极速工具 **uv**。

> ⚡ **新项目一律使用 uv。** 2026 年了，没理由再忍受 pip 的龟速和 Poetry 的慢解析。uv 兼容 pip 语法、内置 Python 版本管理、秒级安装——迁移成本几乎为零，体验是降维打击。除非你要发布 PyPI 包（Poetry 更成熟），否则别纠结，直接 `uv venv && uv add`。

---

## 📜 一、历史脉络

| 阶段   | 时间      | 代表工具         | 核心特征                    |
| ------ | --------- | ---------------- | --------------------------- |
| 第一代 | 2008-2012 | pip + virtualenv | 基础安装与环境隔离          |
| 第二代 | 2017-2020 | Pipenv / Poetry  | 依赖解析、锁文件、一体化    |
| 第三代 | 2023-现在 | uv / PDM / Rye   | 极致性能、Rust 重构、现代化 |

根据 2024 年 Python 开发者调查：95%+ 仍日常使用 pip，约 40% 在新项目中使用 Poetry，uv 在 6 个月内下载量突破千万。

---

## 🐍 二、方案一：pip + venv + requirements.txt（传统方案）

这是 Python 最经典、最基础的包管理方式，所有组件都内置在标准库中，无需额外安装。

### 2.1 核心概念

- **pip**：PyPI 包安装器，负责下载和安装包
- **venv**：Python 标准库的虚拟环境模块，为每个项目创建隔离的依赖空间
- **requirements.txt**：纯文本文件，列出项目依赖及版本

### 2.2 完整工作流

```bash
# 1. 创建项目目录
mkdir my-project && cd my-project

# 2. 创建虚拟环境
python -m venv .venv

# 3. 激活虚拟环境
# macOS / Linux:
source .venv/bin/activate
# Windows:
.venv\Scripts\activate

# 4. 安装依赖
python -m pip install requests
python -m pip install "flask>=3.0"

# 5. 导出依赖清单
python -m pip freeze > requirements.txt

# 6. 在其他环境复现
python -m pip install -r requirements.txt

# 7. 退出虚拟环境
deactivate
```

### 2.3 常用命令速查

```bash
# 安装包
python -m pip install <package>
python -m pip install <package>==1.0.0      # 精确版本
python -m pip install "<package>>=2.0,<3.0" # 版本范围

# 卸载
python -m pip uninstall <package>

# 升级
python -m pip install --upgrade <package>

# 列出已安装
python -m pip list
python -m pip show <package>   # 查看单个包的详细信息

# 导出/安装依赖
python -m pip freeze > requirements.txt
python -m pip install -r requirements.txt
```

### 2.4 最佳实践

- **始终使用 `python -m pip`**，避免误调用系统级 pip
- **永远在虚拟环境中工作**，不要全局安装项目依赖
- **区分生产与开发依赖**：使用 `requirements.txt` 和 `requirements-dev.txt`
- 生产环境用 `==` 锁定精确版本，开发环境可用 `>=` 灵活范围
- 提交 `requirements.txt` 到版本控制，但 **不提交 `venv/` 目录**
- 配合 `pip-tools`（`pip-compile`）可生成带哈希的锁定版本文件

### 2.5 优缺点

| 优点                    | 缺点                                        |
| ----------------------- | ------------------------------------------- |
| 标准库自带，零额外依赖  | 无真正的依赖解析（逐个安装，不预检冲突）    |
| 生态最成熟，教程最多    | 需手动管理虚拟环境                          |
| 简单直观                | 无锁文件机制（`freeze` 会导出所有传递依赖） |
| 几乎所有 CI/CD 默认支持 | 不区分直接依赖和间接依赖                    |

### 2.6 适用场景

📝 简单脚本、⚡ 快速原型、🎓 学习阶段、📦 对依赖复杂度要求不高的小型项目——以及那些「跑一次就扔」的临时代码。

---

## 📦 三、方案二：Poetry（一体化方案）

Poetry 是 2018 年诞生的现代 Python 包管理工具，集依赖管理、虚拟环境、打包发布于一体，使用 `pyproject.toml` 作为统一配置文件。

### 3.1 为什么选择 Poetry

- **标准支持**：遵循 PEP 517 / PEP 518 / PEP 621，`pyproject.toml` 已成为 Python 生态的统一配置格式
- **真正的依赖解析**：使用 SAT 求解器，能提前发现冲突并给出清晰的错误信息
- **锁文件机制**：`poetry.lock` 记录精确版本，确保跨环境可重现构建
- **一体化体验**：从初始化到发布 PyPI，一条命令搞定
- **插件生态**：丰富的社区插件（如 `poetry-plugin-export`）

### 3.2 安装

推荐使用 pipx 安装，避免依赖污染全局环境：

```bash
# 使用 pipx（推荐）
pipx install poetry

# Linux 系统包管理器
sudo pacman -S python-poetry   # Arch
sudo apt install python3-poetry  # Debian/Ubuntu

# 官方安装脚本
curl -sSL https://install.python-poetry.org | python3 -
```

> 不建议直接用 `pip install poetry`，因为它依赖较多，容易与系统其他包冲突。

### 3.3 配置

安装后建议先把虚拟环境放到项目目录下：

```bash
poetry config virtualenvs.in-project true
```

配置文件位置：

- macOS: `~/Library/Application Support/pypoetry`
- Windows: `C:\Users\<username>\AppData\Roaming\pypoetry`
- Linux: `~/.config/pypoetry`

### 3.4 常用命令

```bash
# 创建新项目
poetry new my-project

# 在已有项目中初始化
poetry init

# 添加依赖
poetry add requests
poetry add --group dev pytest black   # 开发依赖

# 安装所有依赖
poetry install

# 更新依赖
poetry update                # 更新所有
poetry update requests       # 更新指定包

# 删除包
poetry remove <package>

# 查看依赖树
poetry show --tree
poetry show --why requests   # 查看为什么某包被安装

# 在虚拟环境中运行
poetry run python main.py
poetry shell                  # 进入虚拟环境 shell

# 构建 & 发布
poetry build
poetry publish --build

# 版本管理
poetry version minor          # 升级次版本号
```

### 3.5 pyproject.toml 示例

```toml
[tool.poetry]
name = "my-project"
version = "0.1.0"
description = "A modern Python project"
authors = ["Your Name <email@example.com>"]

[tool.poetry.dependencies]
python = "^3.10"
requests = "^2.31.0"
click = "^8.1.0"

[tool.poetry.group.dev.dependencies]
pytest = "^8.0.0"
black = "^24.0.0"

[build-system]
requires = ["poetry-core"]
build-backend = "poetry.core.masonry.api"
```

### 3.6 优缺点

| 优点                         | 缺点                                |
| ---------------------------- | ----------------------------------- |
| 真正的依赖解析，能检测冲突   | 学习曲线较陡                        |
| 一体化（管理 + 打包 + 发布） | 依赖解析有时较慢（中等项目 15-30s） |
| `pyproject.toml` 统一配置    | 虚拟环境位置灵活性有限              |
| 活跃的社区和插件生态         | 对 monorepo 支持一般                |

### 3.7 适用场景

📚 库开发、🚀 需要发布到 PyPI 的项目、🏗️ 追求现代化工作流的中大型项目。

---

## ⚡ 四、方案三：uv（极速方案）🚀

uv 是由 Astral（Ruff 作者）用 Rust 编写的新一代 Python 包管理器，2024 年发布后迅速崛起。它的核心卖点是 **速度**——比 pip 快 10-100 倍。

### 4.1 核心特性

- **极致性能**：Rust 实现，并行下载，全局缓存
- **完全兼容 pip**：`uv pip install` 可以无缝替换 `pip install`
- **内置 venv 管理**：`uv venv` 一条命令创建虚拟环境
- **Python 版本管理**：`uv python install 3.12` 可直接安装指定 Python
- **锁文件支持**：`uv.lock` 提供跨平台确定性构建
- **零配置**：无需 `pyproject.toml` 也能直接用

### 4.2 安装

```bash
# pip 安装
pip install uv

# macOS/Linux 独立安装
curl -LsSf https://astral.sh/uv/install.sh | sh

# Windows
powershell -c "irm https://astral.sh/uv/install.ps1 | iex"
```

### 4.3 常用命令

```bash
# 创建虚拟环境
uv venv

# 安装包（兼容 pip 语法）
uv pip install requests
uv pip install -r requirements.txt

# 添加/移除依赖（类 Poetry 风格）
uv add requests
uv add --dev pytest
uv remove requests

# 编译依赖锁文件
uv pip compile requirements.in -o requirements.txt

# 同步到锁定版本
uv pip sync requirements.txt

# 在虚拟环境中运行（无需手动激活）
uv run python script.py
uv run pytest

# Python 版本管理
uv python install 3.12
uv python list
```

### 4.4 性能实测（参考数据）

| 场景           | pip    | Poetry | uv    |
| -------------- | ------ | ------ | ----- |
| 安装 50 个依赖 | ~20s   | ~15s   | ~1-2s |
| CI/CD 环境安装 | 分钟级 | 分钟级 | 秒级  |
| 依赖解析       | N/A    | 15-30s | <1s   |

在 CI/CD 环境中，uv 可以将依赖安装时间从分钟级降至秒级。

### 4.5 Docker 中使用 uv

```dockerfile
FROM python:3.12-slim
RUN pip install uv
WORKDIR /app
COPY requirements.txt .
RUN uv pip install --system -r requirements.txt
COPY . .
CMD ["python", "app.py"]
```

### 4.6 优缺点

| 优点                          | 缺点                                |
| ----------------------------- | ----------------------------------- |
| 速度无敌，比 pip 快 10-100 倍 | 仍在快速迭代，API 可能变化          |
| 完全兼容 pip 语法，迁移零成本 | 功能相对简单（暂不支持发布到 PyPI） |
| 内置 Python 版本管理          | 文档还在完善中                      |
| 内存占用低                    | 社区生态尚在成长                    |

### 4.7 适用场景

🏢 大型项目、🚀 对安装速度有极致要求的 CI/CD 环境、🔬 数据科学项目（大量科学计算包）、🐳 容器化构建——以及**所有 2026 年及之后新建的项目**。

---

## 🧭 五、三种方案选型决策

```
新项目开始
    │
    ├── 🚀 你是正常人？
    │   └── 是 → uv（别想了，就它）
    │
    ├── 纯脚本 / 学习 / 快速原型？
    │   └── 是 → pip + venv + requirements.txt（够用，不折腾）
    │
    ├── 需要发布到 PyPI？
    │   └── 是 → Poetry（打包发布最成熟）
    │
    ├── 极致速度要求？（CI/CD、大型项目）
    │   └── 是 → uv（性能无敌）
    │
    └── 老旧项目维护？
        └── 维持原样，别给自己找事
```

### 💡 推荐

| 场景                      | 推荐                       | 理由                                            |
| ------------------------- | -------------------------- | ----------------------------------------------- |
| 🆕 新项目（绝大多数情况） | **uv**                     | 快、兼容 pip、内置 Python 管理，2026 年默认选择 |
| 📚 库开发 / 发布 PyPI     | **Poetry**                 | 打包发布流程最成熟、社区插件丰富                |
| 🏗️ CI/CD 优化             | **uv**                     | 秒级安装，省时间就是省钱                        |
| 📝 快速原型 / 简单脚本    | **pip + venv**             | 零依赖，够用不折腾                              |
| 🔧 混合方案               | Poetry（配置）+ uv（安装） | 各取所长                                        |

---

## 🔒 六、锁文件对比

| 特性         | pip                         | Poetry        | uv         |
| ------------ | --------------------------- | ------------- | ---------- |
| 锁文件       | 无（`pip freeze` 算半锁）   | `poetry.lock` | `uv.lock`  |
| 跨平台确定性 | 否（`freeze` 含平台特定包） | 是            | 是         |
| 哈希校验     | 可选（`pip-compile`）       | 内置          | 内置       |
| 分层依赖     | 否                          | 完整依赖树    | 完整依赖树 |

---

## 🚚 七、迁移指南

### 从 pip 迁移到 Poetry

```bash
# 1. 初始化 Poetry
poetry init

# 2. 导入 requirements.txt
cat requirements.txt | xargs poetry add

# 3. 安装并生成锁文件
poetry install
```

### 从 pip 迁移到 uv

```bash
# 1. 创建虚拟环境
uv venv

# 2. 直接从 requirements.txt 安装
uv pip install -r requirements.txt

# 3. 日常使用
uv run python app.py
```

---

## 📖 参考资料

- [Python Packaging User Guide (pip + venv 官方指南)](https://packaging.python.org/)
- [Poetry 官方文档](https://python-poetry.org/docs/)
- [uv GitHub 仓库](https://github.com/astral-sh/uv)
- [PEP 517 — A build-system independent format for source trees](https://peps.python.org/pep-0517/)
- [PEP 518 — Specifying Minimum Build System Requirements for Python Projects](https://peps.python.org/pep-0518/)
- [PEP 621 — Storing project metadata in pyproject.toml](https://peps.python.org/pep-0621/)
