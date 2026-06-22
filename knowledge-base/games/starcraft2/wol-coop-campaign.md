---
title: 星际争霸2自由之翼合作战役修改存档
date: 2022-01-22T16:54:45+08:00
category: 游戏
tags:
  - 星际争霸2
  - 游戏存档
  - 自由之翼
  - 合作战役
aliases:
  - starcraft2-wings-of-liberty-coop-save
cover: https://blz-contentstack-images.akamaized.net/v3/assets/blt0e00eb71333df64e/blt0c72fa572370924a/6621cf093e3ae61b4d769c56/game_features_legendary_multiplayer.webp
create_time: 2022-01-22
update_time: 2026-04-11
---

## 📝 前言

最近入坑了星际 2 的合作战役模式——最多支持三人联机重温经典单人战役，通关后还能像单机一样解锁科技树。但玩了两天就发现科技解锁速度慢得离谱，重复刷同一关也没法额外获得技能点，打了半天科技树才点了不到三分之一。干脆直接研究存档修改，一次性搞定所有技能点，省得浪费时间刷刷刷。

## ⚙️ 修改技能点数

自由之翼合作战役的存档文件路径是：

```
我的文档\StarCraft II\Accounts\xxx\xxx\Banks\xxx\BankCoop.SC2Bank
```

其中 `xxx` 是账号相关的随机字符串，每个人的路径都不一样。这是个 XML 格式的文件，找到 `playerstats` 节点，把三个科技点数的数值改成 1000，通关后就能直接获得各 1000 点的异虫、星灵和现金点数，直接把所有科技一次性点满！

```xml
<Section name="playerstats">
  <Key name="zerg">
    <Value int="1000"/>
  </Key>
  <Key name="protoss">
    <Value int="1000"/>
  </Key>
  <Key name="cash">
    <Value int="1000"/>
  </Key>
</Section>
```

## 🔓 全科技解锁存档

上面的修改只能解锁所有科技，但实验室里的异虫/星灵科技还是只能二选一，有点遗憾。后来碰到个全科技解锁的大佬分享了存档，可以同时激活二选一的科技，爽度直接拉满——开局就有双倍农民星轨，运营丝滑到飞起，各种黑科技加持的雷诺比合作模式里还猛。

国服重新开服后我重新适配了版本，需要的直接取走就行。

> [!tip] 相关推荐
> 虫群之心合作战役的存档修改教程看这里：[[星际争霸2虫群之心合作战役全科技存档]]

> [!warning] 使用说明
> 完美存档文件：`attachments/BankCoop.SC2Bank`
> 请务必备份原有存档后再替换，避免数据丢失！

## 📂 存档文件结构

两个合作战役的存档结构大同小异，虫群之心的详细分析已经写在 [[星际争霸2虫群之心合作战役全科技存档]] 里了，这里就不重复展开。不过有个小细节值得提一下：第 22 关「媒体轰炸」右下角有个隐藏建筑，打烂之后会解锁隐藏关卡「揭露黑幕」，这个机制在合作战役里也保留了，对应存档里多了个 `wakawaka` 标记：

```xml
<Section name="mission_22">
    <Key name="wakawaka">
        <Value flag="1"/>
    </Key>
    <Key name="zerg">
        <Value int="0"/>
    </Key>
    <Key name="played">
        <Value flag="1"/>
    </Key>
    <Key name="protoss">
        <Value int="0"/>
    </Key>
    <Key name="bonusCash">
        <Value int="0"/>
    </Key>
</Section>
```
