# 输入法

## 小狼毫

### 配置

开源免费的 rime 输入法的 windows 版。

- 下载安装 <https://rime.im/>
- 配置指南 <https://github.com/rime/home/wiki/CustomizationGuide>
- 配色工具 <https://bennyyip.github.io/Rime-See-Me/> -「东风破」配置管理器 <https://github.com/rime/plum>
- 词库 <https://github.com/rime-aca/dictionaries>

安装输入法之后，右键输入法，选择「輸入法設定／獲取更多輸入方案」打开配置管理器。首次使用会自动下载 plum 管理器的本体，然后会自动询问要安装什么包，输入`prelude double-pinyin emoji`可以同时安装这三个。配置会安装到 rime 用户文件夹，可以在输入法托盘处使用右键菜单「用户文件夹」打开。

### 雾凇拼音

一个第三方维护的 Rime 配置和词库，支持全拼、双拼等配置。

首次使用最好备份并清空原配置文件夹，然后使用 git bash 运行东风破，安装雾凇拼音的配置。

```sh
bash rime-install iDvel/rime-ice:others/recipes/full
```

安装完成后在菜单中启用雾凇拼音（全拼）或者微软双拼等拼音方案，即可享受预配置好的各项功能，具体可见[官方说明](https://dvel.me/posts/rime-ice/)。
