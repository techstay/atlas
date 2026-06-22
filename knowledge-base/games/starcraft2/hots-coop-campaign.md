---
title: 星际争霸2虫群之心合作战役全科技存档
date: 2025-12-16T22:55:16+08:00
category: 游戏
tags:
  - 星际争霸2
  - 游戏存档
  - 虫群之心
  - 合作战役
aliases:
  - starcraft2-heart-of-swarm-coop-save
cover: https://img.3dmgame.com/uploads/allimg/130330/180_130330133144_1.jpg
create_time: 2025-12-16
update_time: 2026-04-11
---

## 📝 前言

星际国服重开后，以前的自定义地图也逐渐回归了。最近虫群之心的合作战役更新上线，又得重新打一遍科技树，干脆直接研究存档修改——正好之前有修改 [[星际争霸2自由之翼合作战役修改存档]] 的经验，这次上手很顺利。

虫群之心战役做了不少优化：开局就能给每个兵种四选一选科技，不需要通关关卡解锁，这点比自由之翼人性化很多。但也因为这个机制，没法像自由之翼那样做全科技存档了。不过毕竟 ZIMBA，后续科技解锁后打起来还是很轻松，新玩家也不会太坐牢。

## 📂 存档文件结构

虫群之心合作战役的存档路径和自由之翼一致：

```
我的文档\StarCraft II\Accounts\xxx\xxx\Banks\xxx\
```

存档文件名为 `HotSCoopCampaign.SC2Bank`，XML 格式，结构清晰很容易修改，实在搞不定丢给 AI 分析也行。

### 🦗 部队进化分支

合作战役简化了科技系统，英雄和部队科技开局就能选，等级只影响解锁权限。部队变种需要在对应进化关卡完成选择，想要换变种要么重打进化关，要么直接改存档。合作战役比原版多了一种兵种进化，可玩性更高。我后期基本用飞行宿主 + 大龙，战损低还不吃经济，爽得一批。

各兵种进化分支的中英文对照如下：

| 英文 Key    | 中文兵种  |
| ----------- | --------- |
| `mutalisk`  | 异龙      |
| `ultralisk` | 雷兽      |
| `roach`     | 蟑螂      |
| `zergling`  | 小狗/跳虫 |
| `swarmhost` | 虫群宿主  |
| `baneling`  | 爆虫      |
| `hydralisk` | 刺蛇      |

```xml
<Section name="mutation">
    <Key name="mutalisk">
        <Value int="2"/>
    </Key>
    <Key name="ultralisk">
        <Value int="2"/>
    </Key>
    <Key name="roach">
        <Value int="2"/>
    </Key>
    <Key name="zergling">
        <Value int="4"/>
    </Key>
    <Key name="swarmhost">
        <Value int="3"/>
    </Key>
    <Key name="baneling">
        <Value int="1"/>
    </Key>
    <Key name="hydralisk">
        <Value int="3"/>
    </Key>
</Section>
```

### 🦸 英雄技能配置

虫群之心大部分战役都有英雄 RPG 元素，合作战役支持三名玩家各用一个英雄：`凯瑞甘（Kerrigan）`、`纳克图尔（Naktul）` 和 `多瓦迪鲁（Dowadiru）`，英雄技能分支保存在对应节点。

```xml
<Section name="kerrigan">
    <Key name="tier2">
        <Value int="1"/>
    </Key>
    <Key name="tier7">
        <Value int="2"/>
    </Key>
    <Key name="tier6">
        <Value int="3"/>
    </Key>
    <Key name="tier1">
        <Value int="1"/>
    </Key>
    <Key name="tier4">
        <Value int="1"/>
    </Key>
    <Key name="tier3">
        <Value int="3"/>
    </Key>
    <Key name="tier5">
        <Value int="3"/>
    </Key>
</Section>
```

英雄的游玩数据保存在 `playerstats` 节点：

```xml
<Section name="playerstats">
    <Key name="kerrigan">
        <Value int="9999"/>
    </Key>
    <Key name="times_with_2">
        <Value int="1"/>
    </Key>
    <Key name="naktul">
        <Value int="9999"/>
    </Key>
    <Key name="times_with_1">
        <Value int="1"/>
    </Key>
    <Key name="times_with_3">
        <Value int="1"/>
    </Key>
    <Key name="dowadiru">
        <Value int="9999"/>
    </Key>
</Section>
```

### 🎯 任务进度

虫群之心总共 27 个任务，每个任务都有独立数据，玩家等级最高 70 级，影响英雄技能解锁。

```xml
<Section name="mission_4">
    <Key name="times_played">
        <Value int="2"/>
    </Key>
    <Key name="mapcompleted">
        <Value flag="1"/>
    </Key>
    <Key name="levels_given">
        <Value int="0"/>
    </Key>
    <Key name="levels_bonus">
        <Value int="2"/>
    </Key>
    <Key name="herolevel">
        <Value int="70"/>
    </Key>
</Section>
```

### ⌨️ 快捷键保存

这个功能特别实用：合作战役会自动保存你设置的建筑快捷键，开局直接能用，不用每次重新编队，对建筑多的人族尤其友好，虫族相对简单点。

```xml
<Section name="controlgroups">
    <Key name="spire">
        <Value int="5"/>
    </Key>
    <Key name="hatchery">
        <Value int="4"/>
    </Key>
    <Key name="evolutionchamber">
        <Value int="5"/>
    </Key>
</Section>
```

## ✨ 完美存档

修改完直接把英雄等级拉满到 70 级，解锁了全部科技。不过实际意义没有自由之翼的全科技存档大——虫群之心没有全科技模式，打前期关卡还是得用白板兵，多玩几关迟早也能全解锁。

最后还是按惯例放出存档，有需要的自取。吐槽一句：这次偷懒用 Kilo Code 改存档，一下花了 70K token，把字节跳动的免费额度直接用光还倒欠一块多，好在便宜，下次得记得设限额。

> [!warning] 使用说明
> 存档文件：`attachments/HotSCoopCampaign.SC2Bank`
> 替换前请务必备份原有存档，避免数据丢失！
