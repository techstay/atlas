import os
from dataclasses import dataclass

from dotenv import load_dotenv
from openai import OpenAI

load_dotenv()


@dataclass
class OpenAIClientConfig:
    api_key: str = ""
    base_url: str = ""
    model: str = ""


gptdos_config = OpenAIClientConfig(
    api_key=os.environ.get("GPTDOS_API_KEY", ""),
    base_url="https://api.gptdos.com/v1",
    model="gpt-4o-mini",
)

openai_config = OpenAIClientConfig(
    api_key=os.getenv("OPENAI_API_KEY", ""),
    base_url="https://api.openai.com/v1",
    model="gpt-4.1",
)

deepseek_config = OpenAIClientConfig(
    api_key=os.environ.get("DEEPSEEK_API_KEY", ""),
    base_url="https://api.deepseek.com",
    model="deepseek-chat",
)

siliconflow_config = OpenAIClientConfig(
    api_key=os.environ.get("SILICONFLOW_API_KEY", ""),
    base_url="https://api.siliconflow.cn",
    model="deepseek-ai/DeepSeek-R1",
)

ark_config = OpenAIClientConfig(
    api_key=os.getenv("ARK_API_KEY", ""),
    base_url="https://ark.cn-beijing.volces.com/api/v3",
    # model="deepseek-r1-250120",
    model="kimi-k2-250711",
)

ark_config_mini = OpenAIClientConfig(
    api_key=os.getenv("ARK_API_KEY", ""),
    base_url="https://ark.cn-beijing.volces.com/api/v3",
    model="deepseek-v3-250324",
)


baidu_config = OpenAIClientConfig(
    api_key=os.getenv("BAIDU_API_KEY", ""),
    base_url="https://qianfan.baidubce.com/v2",
    model="ernie-x1-32k",
)

openrouter_config = OpenAIClientConfig(
    api_key=os.getenv("OPENROUTER_API_KEY", ""),
    base_url="https://openrouter.ai/api/v1",
    model="qwen/qwq-32b:free",
)

gemini_config = OpenAIClientConfig(
    api_key=os.getenv("GEMINI_API_KEY", ""),
    base_url="https://generativelanguage.googleapis.com/v1beta/openai/",
    model="gemini-2.5-pro",
)

gemini_config_mini = OpenAIClientConfig(
    api_key=os.getenv("GEMINI_API_KEY", ""),
    base_url="https://generativelanguage.googleapis.com/v1beta/openai/",
    model="gemini-2.5-flash",
)

baidu_ai_search_config = OpenAIClientConfig(
    api_key=os.getenv("BAIDU_API_KEY", ""),
    base_url="https://qianfan.baidubce.com/v2/ai_search",
    model="deepseek-v3",
)

qwen_config = OpenAIClientConfig(
    api_key=os.getenv("ALIYUN_API_KEY", ""),
    base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
    model="qwen-plus-latest",
    # model="qwen-turbo-latest",
)

ollama_config = OpenAIClientConfig(
    base_url="http://localhost:11434/v1",
    model="qwen3:14b",
)

hunyuan_config = OpenAIClientConfig(
    api_key=os.getenv("TENCENT_API_KEY", ""),
    base_url="https://api.hunyuan.cloud.tencent.com/v1",
    model="hunyuan-turbos-latest",
)

bigmodel_config = OpenAIClientConfig(
    api_key=os.getenv("BIGMODEL_API_KEY", ""),
    base_url="https://open.bigmodel.cn/api/paas/v4",
    model="glm-4.5-air",
)

moonshot_config = OpenAIClientConfig(
    api_key=os.getenv("MOONSHOT_API_KEY", ""),
    base_url="https://api.moonshot.cn/v1",
    model="kimi-k2-0711-preview",
)

minimax_config = OpenAIClientConfig(
    api_key=os.getenv("MINIMAX_API_KEY", ""),
    base_url="https://api.minimaxi.com/v1",
    model="MiniMax-M1",
)


def baidu_ai_search(query: str) -> str:
    client = OpenAI(
        api_key=baidu_ai_search_config.api_key,
        base_url=baidu_ai_search_config.base_url,
    )
    response = client.chat.completions.create(
        model=baidu_ai_search_config.model,
        messages=[{"role": "user", "content": query}],
        stream=False,
    )
    return response.choices[0].message.content  # type: ignore


class OpenAIClient:
    def __init__(self, api_key: str, base_url: str, model: str):
        self.api_key = api_key
        self.base_url = base_url
        self.model = model
        self.client = OpenAI(api_key=api_key, base_url=base_url)

    def chat(self, prompt: str, message: str):
        response = self.client.chat.completions.create(
            model=self.model,
            messages=[
                {"role": "system", "content": prompt},
                {"role": "user", "content": message},
            ],
            stream=True,
        )
        for chunk in response:
            if chunk.choices:
                delta = chunk.choices[0].delta
                content = delta.content if delta.content else ""
                print(content, end="", flush=True)
        print()

    def list_models(self):
        return self.client.models.list()
