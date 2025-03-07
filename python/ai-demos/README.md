# ai-demos

最近学了一下 AI 编程真的感觉很有意思，用对了地方的话非常方便。

## 项目结构

- gradio，几个简单示例，这个框架用来快速的搭建 AI 应用的 web 界面，著名的 stable-diffusion-webui 就是用它搭建的。
- my_utils，项目通用的工具函数，各大主流大模型的配置都在这里，其他地方用到的时候直接从这里调用
- openai_examples，openai 相关示例，主要是 openai agents sdk 框架的示例，这个新出的框架挺不错的，专注 agents 的核心概念，非常干净，适合初学者
- pydantic_ai_examples，使用 pydantic ai 框架的示例，之前看 b 站有人用到，好奇之下搜了一下，感觉不错，所以也学习了一下
- smolagents_examples，smolagents 框架的示例，这个框架特别好玩，因为它和一般 agents 框架的实现原理还不太一样。一般 agents 框架和大模型交互完返回的都是格式化的数据，但是 smolagents 框架返回的是一个大模型生成的代码片段，然后执行这段代码片段。听起来就特别有意思对吧。

项目里也尝试了一些 telemetry 框架，检查和调试 agents 的运行状态很有用。

## 运行

```shell
# 运行
uv run -m pydantic_ai_examples.hello_world
# 运行测试
uv run pytest -s -k <关键字>
```
