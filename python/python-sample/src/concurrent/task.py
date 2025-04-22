import asyncio
import time
from functools import wraps


def sync_task(f: float):
    time.sleep(f)
    return "foo"


async def async_task(f: float):
    await asyncio.sleep(f)
    return "bar"


def measure_time(func):
    @wraps(func)
    def sync_wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = func(*args, **kwargs)
        end_time = time.perf_counter()
        print(f"{func.__name__} used: {end_time - start_time:.4f} seconds.")
        return result

    @wraps(func)
    async def async_wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        result = await func(*args, **kwargs)
        end_time = time.perf_counter()
        print(f"{func.__name__} used: {end_time - start_time:.4f} seconds.")
        return result

    if asyncio.iscoroutinefunction(func):
        return async_wrapper
    else:
        return sync_wrapper


@measure_time
def sequential_tasks():
    r1 = sync_task(0.5)
    r2 = sync_task(1.5)
    print(r1, r2)


@measure_time
async def async_sequential_tasks():
    r1 = await async_task(0.5)
    r2 = await async_task(1.5)
    print(r1, r2)


@measure_time
async def parallel_tasks():
    r1, r2 = await asyncio.gather(async_task(0.5), async_task(1.5))
    print(r1, r2)


@measure_time
async def parallel_tasks_using_task_group():
    async with asyncio.TaskGroup() as tg:
        r1 = tg.create_task(async_task(0.5))
        r2 = tg.create_task(async_task(1.5))
    print(r1.result(), r2.result())


async def main():
    sequential_tasks()
    await async_sequential_tasks()
    await parallel_tasks()
    await parallel_tasks_using_task_group()


if __name__ == "__main__":
    asyncio.run(main())
