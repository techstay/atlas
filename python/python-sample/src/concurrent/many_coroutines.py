import asyncio
import random

from loguru import logger


async def task(n: int):
    await asyncio.sleep(random.randrange(10, 20) * 0.1)
    return n


async def main():
    n = 100000
    logger.info(f"start {n:_} coroutines")
    tasks = [task(i) for i in range(n)]
    results = await asyncio.gather(*tasks)
    logger.info(f"Got {len(results)} results")
    logger.info(f"first 10 results: {results[:10]}")
    logger.info(f"last 10 results: {results[-10:]}")


if __name__ == "__main__":
    asyncio.run(main())
