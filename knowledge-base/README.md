---
title: "Knowledge Base README"
date: 2026-05-26T00:00:00+08:00
tags:
  - knowledge-base
categories:
  - knowledge-base
---

# 🗺️ Knowledge Base 个人知识库总索引

本目录是 Atlas 的知识库部分，用于整理可长期复用的笔记、教程、配置经验、资源索引和问题排查记录。内容按主题归档，每个主题目录都有独立的 README 作为二级入口。

## 🌳 目录结构

```text
knowledge-base/
├── AI/              # AI 工具、提示词、智能体与绘画
├── android/         # Android 刷机、Root 与移动端 Linux
├── linux/           # Linux 发行版、系统配置与安全防护
├── network/         # 网络、远程连接、软路由与代理调试
├── oss/             # 开源软件、开发工具、系统工具与生产力工具
├── effectiveness/   # 个人效能与效率方法
├── programming/     # 编程概念、Markdown、Regex、前端与 GUI
├── selfhosted/      # 自部署服务、私有云与家庭服务器
├── software/        # 桌面软件、Obsidian、VLC 与软件配置
├── tech/            # 前沿技术、许可证、图床与技术书签
├── windows/         # Windows 系统管理、WSL、终端与故障排查
├── 创作/            # 创意素材、音视频制作与创作流程
├── 日语/            # 日语学习与 JLPT N4 语法整理
├── 数学/            # 数学笔记与趣味初等数学
├── 影视/            # 影视、动漫与纪录片笔记
└── 游戏/            # 游戏攻略、模拟器、存档修改与资源
```

## 🧭 主题入口

| 主题                                    | 内容范围                                            |
| --------------------------------------- | --------------------------------------------------- |
| [[AI/README\|AI]]                       | AI 工具资源、提示词工程、智能体工作流与 AI 绘画     |
| [[android/README\|Android]]             | 小米 8 刷机、Magisk、救砖排障与 UserLAnd            |
| [[linux/README\|Linux]]                 | 发行版安装配置、树莓派、GPG 与防火墙规则            |
| [[network/README\|Network]]             | OpenWrt、OpenClash、远程桌面、SSH、DDNS 与抓包代理  |
| [[oss/README\|OSS]]                     | Git、Docker、Podman、VSCode、Shell 工具与开源项目   |
| [[effectiveness/README\|Effectiveness]] | 个人效能、时间管理与效率方法                        |
| [[programming/README\|Programming]]     | Markdown、Regex、前端、Qt GUI 与 Python Poetry      |
| [[selfhosted/README\|Self-Hosted]]      | Alist、Jellyfin、Samba 与自部署资源                 |
| [[software/README\|Software]]           | Obsidian、VLC 与常用桌面软件配置                    |
| [[tech/README\|Tech]]                   | 开源许可证、Favicon、图床与技术学习资源             |
| [[windows/README\|Windows]]             | WSL、MSYS2、Scoop、系统修复、共享与美化             |
| [[创作/README\|创作]]                   | 创意素材、音视频制作与创作流程                      |
| [[日语/README\|日语]]                   | JLPT N4 动词、形容词、句型与学习方法                |
| [[数学/README\|数学]]                   | 数学基础笔记、公式整理与趣味习题                    |
| [[影视/README\|影视]]                   | ACG 资源、影视记录与《空中浩劫》科普                |
| [[游戏/README\|游戏]]                   | 模拟器配置、Cheat Engine、存档修改、攻略与 ROM 资源 |

## 📌 分类约定

- 工具或软件的使用笔记优先放入 `oss/` 或 `software/`；开源软件放 `oss/`，专有或通用桌面软件放 `software/`。
- 编程语言示例代码放入 `../code-base/`；概念说明、工具链经验和写作规范放入 `programming/`。
- 系统级内容按平台归档：Linux 放 `linux/`，Windows 放 `windows/`，Android 放 `android/`。
- 个人效能方法论放 `effectiveness/`；具体开源生产力工具放 `oss/productivity/`。
- 图片、配置文件、存档等附件放在对应主题下的 `attachments/` 目录，和引用它们的笔记保持就近存放。
