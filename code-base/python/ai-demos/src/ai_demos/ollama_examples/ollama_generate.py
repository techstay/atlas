from ollama import generate


def chat_with_ollama(system_prompt: str, user_prompt: str):
    stream = generate(
        model="qwen3:8b",
        system=system_prompt,
        prompt=user_prompt,
        stream=True,
    )

    for chunk in stream:
        print(chunk.response, end="", flush=True)


if __name__ == "__main__":
    system_prompt = "You are a helpful assistant. Answer questions briefly."
    user_prompt = "What text is often used in the first demo of a programming language? Just give me the answer."
    chat_with_ollama(system_prompt, user_prompt)
