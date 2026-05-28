import asyncio
from random import choice

from loguru import logger


async def number_task(n: int):
    wait_seconds = choice([1, 2, 3, 4, 5]) * 0.5
    await asyncio.sleep(wait_seconds)
    if n == 2:
        raise ValueError(f"Met invalid value {n}")
    return n


async def very_long_work():
    logger.info("very long work started")
    await asyncio.sleep(3600)
    print("SO SO SO SO SO LONG")


async def timeout():
    try:
        await asyncio.wait_for(very_long_work(), timeout=2)
    except TimeoutError:
        logger.error("timeout error: the task took too long")


async def handle_exceptions():
    tasks = [number_task(n) for n in range(5)]
    logger.info("gather tasks started")
    results = await asyncio.gather(*tasks, return_exceptions=True)

    numbers = []
    exceptions = []
    for result in results:
        if isinstance(result, Exception):
            exceptions.append(result)
        else:
            numbers.append(result)

    logger.info(numbers)
    logger.error(exceptions)


async def task_group_with_exceptions():
    try:
        logger.info("task group started")
        async with asyncio.TaskGroup() as tg:
            for i in range(5):
                tg.create_task(number_task(i))
    except BaseExceptionGroup as e:
        logger.error(e)
        logger.error(e.exceptions)


async def cancellation():
    task = asyncio.create_task(very_long_work())
    await asyncio.sleep(1)
    task.cancel()
    await asyncio.sleep(1)
    try:
        await task
    except asyncio.CancelledError:
        logger.info("Task was cancelled")


async def main():
    await timeout()
    await cancellation()
    await handle_exceptions()
    await task_group_with_exceptions()


if __name__ == "__main__":
    asyncio.run(main())
