import asyncio

from loguru import logger


async def long_task(task_id: int, semaphore: asyncio.Semaphore):
    async with semaphore:
        await asyncio.sleep(1)
    logger.info(f"Task {task_id} is complete")


async def main():
    semaphore = asyncio.Semaphore(4)
    await asyncio.gather(*[long_task(i, semaphore) for i in range(1, 11)])


if __name__ == "__main__":
    asyncio.run(main())
