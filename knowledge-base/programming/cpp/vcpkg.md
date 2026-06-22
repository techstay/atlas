---
title: "vcpkg"
date: 2026-06-12T00:00:00+08:00
tags:
  - cpp
  - package-manager
  - vcpkg
categories:
  - C++
---

[vcpkg](https://vcpkg.io/) 是微软出品的 C/C++ 包管理器 📦，跨平台支持 Windows、Linux 和 macOS。支持 **经典模式 (Classic Mode)** 和 **清单模式 (Manifest Mode)** 两种依赖管理方式，与 CMake、MSBuild 等构建系统深度集成。

---

## 安装 📥

### 克隆仓库

```sh
git clone https://github.com/microsoft/vcpkg.git
```

### 初始化

```sh
cd vcpkg

# Windows
.\bootstrap-vcpkg.bat

# Linux / macOS
./bootstrap-vcpkg.sh
```

可选：将 `vcpkg` 可执行文件加入系统 PATH，方便全局调用。

---

## 基本使用 🛠️

vcpkg 提供两种工作模式，命令行为有明显差异：

### 经典模式 (Classic Mode)

默认行为，所有依赖安装在全局仓库中，通过 `vcpkg install <包名>` 主动管理。

```sh
# 搜索包
vcpkg search boost

# 安装（默认当前平台 triplet）
vcpkg install boost-timer boost-format boost-algorithm

# 指定目标平台
vcpkg install boost-test:x64-windows
vcpkg install curl:x64-linux
```

### 清单模式 (Manifest Mode)

推荐用于现代项目。依赖通过项目目录下的 `vcpkg.json` 声明，**禁止**手动指定包名安装。

```sh
# 清单模式下只能执行（自动读取当前目录 vcpkg.json）
vcpkg install
```

---

## 集成到构建系统 🔗

> ⚠️ `vcpkg integrate install` **仅对 MSBuild / Visual Studio 生效**，对 CMake 无效。

### CMake

CMake 必须通过 **Toolchain File** 引入 vcpkg：

```sh
cmake -B build -DCMAKE_TOOLCHAIN_FILE=[vcpkg根目录]/scripts/buildsystems/vcpkg.cmake
```

配置完成后，在 `CMakeLists.txt` 中直接使用：

```cmake
find_package(Boost REQUIRED COMPONENTS timer format algorithm)
target_link_libraries(your_target PRIVATE Boost::timer Boost::format Boost::algorithm)
```

#### CMakePresets.json（推荐 🌟）

CMake 3.24+ 推荐使用预设文件锁定工具链路径，避免每次手动传参：

```json
{
  "version": 3,
  "configurePresets": [
    {
      "name": "vcpkg",
      "binaryDir": "${sourceDir}/build",
      "toolchainFile": "${sourceDir}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    }
  ]
}
```

使用时直接：

```sh
cmake --preset vcpkg
```

### MSBuild / Visual Studio

```sh
vcpkg integrate install
```

执行后，VS 中所有项目自动识别 vcpkg 安装的库，无需修改 `.vcxproj` 或命令行参数。

---

## 清单文件 (Manifests) 📋

在项目根目录创建 `vcpkg.json`，声明式管理依赖：

```json
{
  "name": "my-project",
  "version": "1.0.0",
  "dependencies": [
    "boost-timer",
    "boost-format",
    "boost-algorithm",
    "boost-lexical-cast",
    "boost-circular-buffer"
  ]
}
```

在包含该文件的目录执行 `vcpkg install` 即可自动解析并安装所有依赖。版本控制严格通过 `vcpkg.json` 管理，适合团队协作与 CI/CD。

---

## 卸载与清理 🧹

```sh
# 卸载指定包（若该包被其他包依赖，默认会报错拒绝）
vcpkg remove boost-timer

# 强行级联卸载（连带卸载所有依赖了 boost-timer 的上游包）
vcpkg remove boost-timer --recurse
```

**缓存清理**：vcpkg 没有统一的 `clean` 子命令，垃圾主要堆积在以下三处，可手动删除释放空间：

1. **二进制缓存 (Archives)**
   - Windows：`%LOCALAPPDATA%\vcpkg\archives`
   - Linux/macOS：`~/.cache/vcpkg/archives`
2. **源码下载缓存 (Downloads)**：vcpkg 根目录下的 `/downloads`
3. **编译中间产物 (Buildtrees)**：vcpkg 根目录下的 `/buildtrees`

避免堆积技巧：

```sh
# 安装完成后自动清理编译临时目录（保留二进制缓存以备后用）
vcpkg install boost-timer --clean-after-build
```

---

## 常用命令速查 ⚡

| 命令                    | 说明                       | 适用模式    |
| ----------------------- | -------------------------- | ----------- |
| `vcpkg search`          | 搜索可用包                 | 通用        |
| `vcpkg install`         | 安装包（清单模式不带参数） | 经典 / 清单 |
| `vcpkg remove`          | 卸载包                     | 仅经典模式  |
| `vcpkg list`            | 列出已安装包               | 仅经典模式  |
| `vcpkg update`          | 检查可更新版本             | 仅经典模式  |
| `vcpkg upgrade`         | 升级所有已安装包           | 仅经典模式  |
| `vcpkg integrate`       | 集成到 MSBuild/VS          | 全局        |
| `vcpkg export`          | 导出为压缩包/脚本          | 通用        |
| `vcpkg dependency-info` | 查看依赖树                 | 通用        |

---

## Tips 💡

- **Triplet**：标识目标平台架构与链接方式，如 `x64-windows`、`x64-linux-static`、`arm64-osx`
- **二进制缓存**：vcpkg 默认将编译产物缓存至 `archives` 目录，跨项目共享可大幅节省编译时间
- **更新机制差异**：`update` / `upgrade` 仅在经典模式有效；清单模式下版本由 `vcpkg.json` 的 `builtin-baseline` 或 `version>=` 约束控制
- **项目初始化**：在空目录下执行 `vcpkg new --application` 可快速生成清单模式所需的 `vcpkg.json` 模板文件
- **自定义 Port 与私有源**：通过在项目内或独立仓库中建立 `ports` 目录编写 `portfile.cmake`，配合 `vcpkg-configuration.json` 配置 `registries`（注册表），即可无缝引入企业私有库
- **CI 最佳实践**：结合清单模式 + `vcpkg install --clean-after-build` + 缓存归档目录实现可复现、轻量化的流水线构建
