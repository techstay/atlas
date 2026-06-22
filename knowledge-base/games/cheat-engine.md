---
title: "Cheat Engine"
date: 2026-05-08T02:30:52+08:00
tags:
  - gaming
categories:
  - 游戏
---

## Cheat Engine

Cheat Engine 是一款开源的内存扫描与修改工具，主要用于单机游戏的数值修改（如金钱、血量、经验等）。它通过扫描进程内存，定位特定数值的存储地址，并允许用户实时修改这些数值。除了基础扫描功能外，Cheat Engine 还内置了反汇编器、调试器、速度修改（SpeedHack）以及 Lua 脚本支持，能够处理指针、代码注入等高级操作，是游戏修改和逆向学习领域最知名的工具之一。

## Cheat Engine MCP

项目地址： <https://github.com/miscusi-peek/cheatengine-mcp-bridge>

克隆项目：

```bash
git clone https://github.com/miscusi-peek/cheatengine-mcp-bridge
```

打开 Cheat Engine，点击 `Table -> Show Cheat Table Lua Script`，打开 Cheat Table Lua Script 窗口。

输入以下代码：

```lua
dofile([[C:\Users\techs\Desktop\repos\cheatengine-mcp-bridge\MCP_Server\ce_mcp_bridge.lua]])
```

最后在 AI 客户端中配置 MCP。

```json
{
  "mcpServers": {
    "cheatengine": {
      "command": "python",
      "args": [
        "C:/Users/techs/Desktop/repos/cheatengine-mcp-bridge/MCP_Server/mcp_cheatengine.py"
      ]
    }
  }
}
```
