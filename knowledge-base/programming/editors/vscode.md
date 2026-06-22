---
title: "Visual Studio Code 使用指南"
date: 2026-06-13T21:00:00+08:00
tags:
  - vscode
  - ide
categories:
  - programming
---

# 💻 Visual Studio Code 使用指南

VSCode 是微软推出的轻量级开源代码编辑器，支持几乎所有主流编程语言的开发，拥有丰富的插件生态。

## 基础配置

## 常用插件推荐

### 通用开发

### 前端开发

### 其他语言

## 实用快捷键

## 任务系统（Tasks）

Visual Studio Code (VS Code) 的**任务 (Tasks)** 功能是一个内置的工具集成机制，允许用户将常用的外部命令行工具（如编译器、构建脚本、静态检查器、部署脚本等）直接映射为 VS Code 内部的命令，从而实现一键自动化运行，无需频繁切换至外部终端。

---

### 核心概念

VS Code 的任务系统基于项目工作区进行配置，核心文件为项目根目录下 `.vscode/tasks.json`。

#### 任务类型

- **自动检测的任务 (Detected Tasks)**：VS Code 及其插件能自动识别项目中的构建工具（例如 **npm**、**Gulp**、**Make**、**Maven**），无需手动配置即可直接运行。
- **自定义任务 (Custom Tasks)**：由用户手动在 `tasks.json` 中定义，用于执行特定的 Shell 命令或进程。

---

### 快速使用流程

#### 1. 运行已有任务（自动检测）

如果项目中存在 `package.json`、`Makefile` 或 `tsconfig.json` 等文件，VS Code 会自动生成对应的任务：

1. 使用快捷键 `Ctrl+Shift+P` (Windows/Linux) 或 `Cmd+Shift+P` (macOS) 打开**命令面板**。
2. 输入并选择 **`Tasks: Run Task` (任务: 运行任务)**。
3. 选择对应的工具分类（如 `npm`），即可看到并运行自动检测到的任务（如 `npm: start`）。

#### 2. 创建与配置自定义任务

若要绑定自定义的脚本或命令，需要创建 `tasks.json` 文件：

1. 打开命令面板，选择 **`Tasks: Configure Task` (任务: 配置任务)**。
2. 选择 **`Create tasks.json file from template` (从模板创建 tasks.json 文件)**。
3. 选择 **`Others` (其他)**，VS Code 会在当前工作区生成 `.vscode/tasks.json` 文件。

---

### `tasks.json` 关键配置项解析

以下是一个典型的自定义任务配置示例，包含两个不同的任务：一个用于编译，另一个用于执行清理。

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "编译 C++ 程序",
      "type": "shell",
      "command": "g++",
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}.exe"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "presentation": {
        "echo": true,
        "reveal": "always",
        "focus": false,
        "panel": "shared",
        "showReuseMessage": true,
        "clear": false
      },
      "problemMatcher": ["$gcc"]
    },
    {
      "label": "清理构建产物",
      "type": "shell",
      "command": "rm",
      "args": ["-rf", "*.exe"],
      "group": "none"
    }
  ]
}
```

#### 核心属性一览表

| 属性名               | 类型        | 描述                                                                                                                                                                               |
| -------------------- | ----------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **`label`**          | 字符串      | 任务的标签/名称，在 UI 界面中显示的唯一标识。                                                                                                                                      |
| **`type`**           | 字符串      | 任务执行环境。可选 `shell`（在终端内作为 shell 命令运行）或 `process`（作为独立进程运行）。                                                                                        |
| **`command`**        | 字符串      | 实际要执行的程序或脚本命令（如 `g++`、`python`、`npm`）。                                                                                                                          |
| **`args`**           | 数组        | 传递给命令的参数列表。                                                                                                                                                             |
| **`group`**          | 字符串/对象 | 定义任务所属的分组。若设置为 `{"kind": "build", "isDefault": true}`，则可以直接通过键盘快捷键 **`Ctrl+Shift+B`** (Windows/Linux) 或 **`Cmd+Shift+B`** (macOS) 触发该默认生成任务。 |
| **`presentation`**   | 对象        | 控制内置终端面板的行为（是否聚焦、是否清屏、是否复用面板等）。                                                                                                                     |
| **`problemMatcher`** | 数组        | **问题匹配器**。用于解析命令输出的报错和警告信息，并将其呈现在 VS Code 的“问题 (Problems)”面板中。                                                                                 |

---

### 任务默认属性与默认任务

#### 全局默认属性

可以在 `tasks.json` 顶层添加 `defaults` 字段，为所有任务设置统一的默认配置，避免每个任务重复编写相同属性：

```json
{
  "version": "2.0.0",
  "defaults": {
    "type": "shell",
    "presentation": {
      "reveal": "always",
      "panel": "shared"
    }
  },
  "tasks": [
    // 此处定义的所有任务会自动继承 defaults 中的配置
  ]
}
```

#### 默认生成/测试任务

VS Code 支持两种默认快捷任务：

- **默认生成任务**：分组 `kind` 为 `build` 且 `isDefault: true` 的任务，按 `Ctrl+Shift+B` (Windows/Linux) / `Cmd+Shift+B` (macOS) 直接触发，通常用于编译、打包等构建操作
- **默认测试任务**：分组 `kind` 为 `test` 且 `isDefault: true` 的任务，可通过命令面板的 `Tasks: Run Test Task` 快速触发，通常用于单元测试、代码检查等验证操作

示例默认测试任务配置：

```json
{
  "label": "运行单元测试",
  "command": "npm test",
  "group": {
    "kind": "test",
    "isDefault": true
  }
}
```

---

### 常用预定义变量

在 `args` 或 `command` 中，可以使用 VS Code 提供的动态变量来适配当前激活的文件：

- **`${workspaceFolder}`**：当前在 VS Code 中打开的工作区根目录路径。
- **`${file}`**：当前在编辑器中打开的激活文件的绝对路径。
- **`${fileDirname}`**：当前激活文件所在的目录路径。
- **`${fileBasenameNoExtension}`**：当前激活文件的文件名，不包含扩展名（例如 `main.cpp` 转换为 `main`）。

---

### 进阶技巧

#### 1. 配置全局用户任务

如果你不希望每个项目都配置一遍 `tasks.json`，可以配置全局任务：

1. 打开命令面板（`Ctrl+Shift+P`）。
2. 运行 **`Tasks: Open User Tasks` (任务: 打开用户任务)**。
3. 此处配置的任务将对该机器上所有打开的单文件或工作区生效 (Visual Studio Code 官方文档)。

#### 2. 任务复合与依赖 (`dependsOn`)

可以通过 `dependsOn` 属性让多个任务按顺序串联执行。例如，在运行“测试”任务前必须先执行“编译”任务：

```json
{
  "label": "运行测试",
  "type": "shell",
  "command": "./test_suite",
  "dependsOn": ["编译 C++ 程序"]
}
```

## 高效使用技巧