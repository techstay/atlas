from dataclasses import asdict

import rich

from ai_demos.openai_examples.helloworld import helloworld
from ai_demos.utils import (
    OpenAIClient,
    ark_config_mini,
    gemini_config,
)


def test_ark_api():
    client = OpenAIClient(**asdict(ark_config_mini))
    client.chat("你擅长解答数学问题", "199^200和200^199哪个大")


def test_gemini():
    client = OpenAIClient(**asdict(gemini_config))
    client.chat("你是一位数学老师", "199^200和200^199哪个大")


def test_openai_list_models():
    client = OpenAIClient(**asdict(gemini_config))
    models = [m.id for m in client.list_models()]
    rich.print(models)


def test_helloworld():
    helloworld()
