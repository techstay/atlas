import asyncio
from random import choice


async def number_task(n: int):
    wait_seconds = choice([1, 2, 3, 4, 5]) * 0.5
    await asyncio.sleep(wait_seconds)
    if n == 2:
        raise ValueError(f"Met invalid parameter {n}")
    return n


async def handle_exceptions():
    tasks = [number_task(n) for n in range(5)]
    results = await asyncio.gather(*tasks, return_exceptions=True)

    for result in results:
        if isinstance(result, Exception):
            print("Exception occurred:", result)
        else:
            print("Result:", result)


if __name__ == "__main__":
    asyncio.run(handle_exceptions())
