from ollama import chat


def chat_with_ollama(prompt: str):
    resp = chat(
        model="qwen3:8b",
        messages=[
            {
                "role": "system",
                "content": "You are a helpful assistant. Answer questions briefly.",
            },
            {"role": "user", "content": prompt},
        ],
    )
    return resp.message.content


if __name__ == "__main__":
    prompt = "What text is often used in the first demo of a programming language? Just give me the answer."
    response = chat_with_ollama(prompt)
    print(response)
