from dataclasses import asdict

import rich

from ai_demos.utils import OpenAIClient, gemini_config, gptdos_config


def test_openai_list_models():
    client = OpenAIClient(**asdict(gptdos_config))
    models = [m.id for m in client.list_models()]
    rich.print(models)


def test_gemini_list_models():
    client = OpenAIClient(**asdict(gemini_config))
    models = [m.id for m in client.list_models()]
    rich.print(models)
