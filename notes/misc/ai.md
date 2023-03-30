# 人工智能

## 语言模型

### chatgpt

目前 chatgpt 处于研究测试阶段，可免费使用，但是注册需梯子和国外手机号，可能需要额外花费。

注册参考[V2EX 教程贴](https://www.v2ex.com/t/900126)，注意点：梯子要全局模式；注册时候可开浏览器隐私窗口，清除 cookie 方便注册；从接码平台获取手机号码，往 OpenAI 注册的时候，记得去掉国家代码；如果接码平台收不到验证码，可以把类别从 any 改为 openai，比较容易收到验证码。

注册成功后，访问<https://chat.openai.com/chat>即可开始使用。

若实在无法注册，可以改用网络上的第三方镜像站，但是这些镜像站的服务质量无法保证，也可能随时停止服务。

- <https://github.com/xx025/carrot>
- 提示词教程<https://learningprompt.wiki/>
- 强大的翻译浏览器扩展<https://chrome.google.com/webstore/detail/openai-translator/ogjibjphoadhljaoicdnjnmgokohngcc>
- API 代理，无需翻墙，国内可用<https://github.com/justjavac/openai-proxy>，按照页面提示修改 API 调用地址即可
- chatbox，使用 API 的 chatgpt 客户端<https://github.com/Bin-Huang/chatbox>

### 微软必应

访问<https://www.bing.com>即可，使用最新版 edge 浏览器访问效果更佳。

### Image Creator

链接<https://cn.bing.com/images/create>

### 谷歌 bard

目前需要申请资格<https://bard.google.com>，仅英美地区可用。后续会逐渐开放更多地区。

## AI 绘图

### Adobe Firefly

目前需要申请资格<https://firefly.adobe.com>。

### stable-diffusion-webui

链接<https://github.com/AUTOMATIC1111/stable-diffusion-webui>

```cmd
scoop install miniconda3
conda create -n pyai python=3.10.6
conda activate pyai

cd stable-diffusion-webui
.\webui.bat
```

- AI 画图搜索引擎，可以查看 AI 生成的图片，以及提示词等信息<https://lexica.art>
- AI 社区，类似 github <https://huggingface.co>
- 提示词网站，可以查找和生成各种提示词<https://promptomania.com>
- 模型下载，社区收集，注意识别<https://rentry.org/sdmodels#hentai-diffusion>
- 模型下载和预览图<https://civitai.com>
- SD 教程<https://stable-diffusion-art.com/>
- 以及两篇知乎文章<https://www.zhihu.com/collection/735113743>
- <https://zhuanlan.zhihu.com/p/617133284>
