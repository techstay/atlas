import os

import gradio as gr
from dotenv import load_dotenv
from pydantic_ai import Agent
from pydantic_ai.messages import ModelRequest, ModelResponse

from ai_demos.pydantic_ai_examples.utils import (
    configure_and_get_pydantic_ai_provider,
)
from ai_demos.utils import gemini_config as config

load_dotenv()

guessing_number_agent = Agent(
    configure_and_get_pydantic_ai_provider(config),
)

max_number = 50


@guessing_number_agent.system_prompt
def system_prompt() -> str:
    import random

    n = random.randint(1, max_number)
    return f"""你是一个猜数游戏，当前选中数字{n}，用户输入一个数字，你只需要判断它的大小并输出大了或者小了。
     如果用户猜对了，告诉用户总共猜的次数，然后狠狠的恭喜用户🎉并输出一长串祝福语句！！！要让人看到你的激动！！！"""


def guess_number(
    number: int,
    history: list[ModelRequest | ModelResponse],
) -> tuple[str, list[ModelRequest | ModelResponse]]:
    result = guessing_number_agent.run_sync(
        str(number),
        message_history=history,
    )
    history.extend(result.new_messages())
    return f"{result.data}", history


with gr.Blocks() as demo:
    gr.Markdown(
        """
        # 我的gradio demo程序
        """,
    )
    with gr.Tab("猜数游戏"):
        gr.Interface(
            title="猜数游戏",
            description=f"猜一个1-{max_number}之间的数字",
            fn=guess_number,
            inputs=[
                gr.Slider(1, max_number, value=max_number // 2, step=1),
                gr.State([]),
            ],
            outputs=["text", gr.State([])],
        )
    with gr.Tab("AI对话"):
        gr.load_chat(
            base_url="https://qianfan.baidubce.com/v2",
            model="ernie-4.0-8k",
            token=os.getenv("BAIDU_API_KEY", ""),
            system_message="你是一个强大的AI助理，可以帮我完成任何事情！",
            title="文心一言",
            description="使用文心一言来聊天",
            theme="ocean",
        )

if __name__ == "__main__":
    demo.launch(share=True)
