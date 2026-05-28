# %%


import gradio as gr


# YES! YES! YES!
def yesman(message: str, history: list[dict[str, str]]) -> str:
    return "YES!"


gr.ChatInterface(
    fn=yesman,
    type="messages",
).launch()

# %%
import os

from dotenv import load_dotenv

load_dotenv()


gr.load_chat(
    base_url="https://qianfan.baidubce.com/v2",
    model="ernie-4.0-8k",
    token=os.getenv("BAIDU_API_KEY", ""),
    system_message="你是一个强大的AI助理，可以帮我完成任何事情！",
    title="文心一言",
    description="使用文心一言来聊天",
    theme="ocean",
).launch()

# %%
