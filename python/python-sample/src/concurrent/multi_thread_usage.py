import time
from concurrent.futures import ThreadPoolExecutor
from multiprocessing.pool import ThreadPool

from loguru import logger


def long_task1():
    logger.info("Task 1 started")
    time.sleep(1.5)
    logger.info("Task 1 is complete")


def long_task2():
    logger.info("Task 2 started")
    time.sleep(1)
    logger.info("Task 2 is complete")


def use_thread_pool():
    with ThreadPool(processes=4) as pool:
        result1 = pool.apply_async(func=long_task1, args=())
        time.sleep(0.1)
        result2 = pool.apply_async(func=long_task2, args=())
        result1.wait()
        result2.wait()


def use_thread_pool_executor():
    with ThreadPoolExecutor(max_workers=4) as executor:
        future1 = executor.submit(long_task1)
        future2 = executor.submit(long_task2)
        future1.result()
        future2.result()


if __name__ == "__main__":
    use_thread_pool()
    use_thread_pool_executor()
