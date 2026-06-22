---
title: "clang-tidy"
date: 2026-06-21T00:00:00+08:00
tags:
  - cpp
  - linter
  - static-analysis
  - clang
categories:
  - C++
---

[clang-tidy](https://clang.llvm.org/extra/clang-tidy/) 是基于 Clang 的 C/C++ 「linter」工具 🔍，用于诊断和修复典型的编程错误，包括代码风格违规、接口误用以及可通过静态分析推断的 bug。模块化设计，支持自定义检查规则。

---

## 安装 📥

```sh
# Ubuntu / Debian
sudo apt install clang-tidy

# macOS (Homebrew)
brew install llvm

# Windows (LLVM 官方安装包)
# 下载 https://releases.llvm.org/ 并安装
```

查看版本：

```sh
clang-tidy --version
```

---

## 核心用法 🛠️

### 基本检查

```sh
# 检查单个文件
clang-tidy test.cpp

# 指定编译选项（放在 -- 之后）
clang-tidy test.cpp -- -I./include -std=c++17

# 使用 compile_commands.json（推荐）
clang-tidy test.cpp -p build/
```

### 选择检查规则

```sh
# 列出默认启用的检查
clang-tidy --list-checks

# 列出所有可用检查
clang-tidy --list-checks --checks='*'

# 只运行特定检查（启用 readability，禁用其他）
clang-tidy test.cpp --checks='-*,readability-*'

# 启用所有检查（慎用，输出会很多）
clang-tidy test.cpp --checks='*'
```

### 自动修复

```sh
# 应用建议的修复
clang-tidy test.cpp --fix

# 即使有编译错误也尝试修复
clang-tidy test.cpp --fix-errors

# 导出修复到文件（后续用 clang-apply-replacements 批量应用）
clang-tidy test.cpp --export-fixes=fixes.yaml
```

### 过滤输出

```sh
# 只显示项目头文件的诊断（过滤系统头文件）
clang-tidy test.cpp --header-filter='.*'

# 排除特定头文件
clang-tidy test.cpp --header-filter='.*' --exclude-header-filter='third_party/.*'

# 只显示特定行范围
clang-tidy test.cpp --line-filter='[{"name":"test.cpp","lines":[[1,50]]}]'
```

---

## 配置文件 `.clang-tidy` ⚙️

在项目根目录创建 `.clang-tidy` 文件，clang-tidy 会自动读取：

```yaml
---
Checks: >
  -*,
  bugprone-*,
  modernize-*,
  performance-*,
  readability-*,
  -modernize-use-trailing-return-type

WarningsAsErrors: ""

HeaderFilterRegex: "src/.*"

FormatStyle: file

CheckOptions:
  - key: readability-implicit-bool-conversion.AllowPointerConditions
    value: true
  - key: modernize-use-override.OverrideSpelling
    value: override
```

### 常用配置项

| 配置项                     | 说明                                                |
| -------------------------- | --------------------------------------------------- |
| `Checks`                   | 启用/禁用的检查规则（同 `--checks`）                |
| `WarningsAsErrors`         | 将警告升级为错误                                    |
| `HeaderFilterRegex`        | 只输出匹配正则的头文件诊断                          |
| `ExcludeHeaderFilterRegex` | 排除匹配的头文件                                    |
| `FormatStyle`              | 修复时的格式化风格（`none`/`file`/`llvm`/`google`） |
| `CheckOptions`             | 各检查的专属选项                                    |
| `InheritParentConfig`      | 是否继承父目录的配置（默认 `true`）                 |

### 导出当前配置

```sh
# 查看生效的完整配置
clang-tidy --dump-config

# 查看某个文件实际使用的配置
clang-tidy test.cpp --dump-config

# 查看所有检查的配置来源
clang-tidy --explain-config
```

---

## 常用检查分组 📋

| 前缀                  | 用途                   | 推荐场景         |
| --------------------- | ---------------------- | ---------------- |
| `bugprone-*`          | 易出错的代码模式       | 所有项目必开 ✅  |
| `modernize-*`         | 推荐使用 C++11+ 新特性 | 升级旧代码 ✅    |
| `performance-*`       | 性能相关问题           | 性能敏感项目 ✅  |
| `readability-*`       | 可读性问题             | 团队协作 ✅      |
| `cppcoreguidelines-*` | C++ Core Guidelines    | 严格项目         |
| `cert-*`              | CERT 安全编码规范      | 安全敏感项目     |
| `google-*`            | Google 代码风格        | 遵循 Google 规范 |
| `clang-analyzer-*`    | Clang 静态分析器       | 深度 bug 检测    |

---

## 并行与自动化 🚀

### 并行运行

```sh
# 使用 run-clang-tidy.py 并行分析整个项目
run-clang-tidy.py -p=build/

# 指定并行数
run-clang-tidy.py -p=build/ -j 4

# 并行 + 自动修复
run-clang-tidy.py -p=build/ -fix -checks='-*,readability-*'
```

### 只检查 Diff

```sh
# 检查 Git 工作区变更
git diff -U0 --no-color HEAD^ | clang-tidy-diff.py -p1

# 检查暂存区变更
git diff -U0 --no-color --cached | clang-tidy-diff.py -p1

# 检查特定提交范围
git diff -U0 --no-color HEAD~3 HEAD | clang-tidy-diff.py -p1
```

---

## 抑制诊断 🤫

### 行内注释

```cpp
// 抑制当前行所有警告
int x = 42; // NOLINT

// 抑制当前行特定检查
int arr[10]; // NOLINT(bugprone-*, readability-*, modernize-*)

// 抑制下一行
// NOLINTNEXTLINE(bugprone-narrowing-conversions)
int y = narrow_cast<int>(large_value);

// 抑制多行区域
// NOLINTBEGIN(bugprone-easily-swappable-parameters)
void func(int a, int b, int c);
// NOLINTEND(bugprone-easily-swappable-parameters)
```

### 配置文件全局抑制

```yaml
---
Checks: >
  -*,
  bugprone-*,
  -bugprone-easily-swappable-parameters
```

---

## CMake 集成 🏗️

```cmake
# 启用 compile_commands.json 生成
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 或在命令行指定
# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build
```

生成后 clang-tidy 会自动查找 `build/compile_commands.json`：

```sh
cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
clang-tidy -p build/ src/main.cpp
```

---

## 实用技巧 💡

### 快速上手推荐配置

```yaml
---
Checks: >
  -*,
  bugprone-*,
  -bugprone-easily-swappable-parameters,
  modernize-*,
  -modernize-use-trailing-return-type,
  performance-*,
  readability-identifier-naming

HeaderFilterRegex: "include/.*"

CheckOptions:
  - key: readability-identifier-naming.ClassCase
    value: CamelCase
  - key: readability-identifier-naming.FunctionCase
    value: camelBack
  - key: readability-identifier-naming.VariableCase
    value: camelBack
  - key: readability-identifier-naming.ConstantCase
    value: UPPER_CASE
```

### 调试配置问题

```sh
# 验证配置文件语法
clang-tidy --verify-config

# 查看某个检查的详细说明
clang-tidy --help-list-hidden | grep bugprone-use-after-move
```

### 与 IDE 集成

- **VS Code**：安装 [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) 扩展，自动运行 clang-tidy
- **CLion**：内置支持，Settings → Inspections → C/C++ → General → Clang-Tidy
- **Neovim**：通过 `nvim-lspconfig` 配置 clangd

---

## 常见问题 ❓

### Q: 如何只检查项目代码，忽略第三方库？

设置 `HeaderFilterRegex`：

```yaml
HeaderFilterRegex: "src/.*" # 只显示 src 目录下的诊断
```

### Q: `compile_commands.json` 怎么生成？

```sh
# CMake
cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Bear（适用于任何构建系统）
bear -- make

# Ninja + CMake
cmake -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

### Q: 如何在 CI 中使用？

```yaml
# GitHub Actions 示例
- name: Run clang-tidy
  run: |
    sudo apt install clang-tidy
    cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
    run-clang-tidy.py -p=build/ -quiet
```

---

## 参考链接 🔗

- 官方文档：<https://clang.llvm.org/extra/clang-tidy/>
- 检查列表：<https://clang.llvm.org/extra/clang-tidy/checks/list.html>
- Clang-Tidy 集成：<https://clang.llvm.org/extra/clang-tidy/Integrations.html>
