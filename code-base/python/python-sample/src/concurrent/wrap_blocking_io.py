import asyncio
import time

from loguru import logger


def blocking_io(n: int):
    time.sleep(1)
    return 42 + n


async def main():
    logger.info("task started")
    result = await asyncio.to_thread(blocking_io, 42)
    logger.info(result)


if __name__ == "__main__":
    asyncio.run(main())
