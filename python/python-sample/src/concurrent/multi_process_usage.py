import time
from concurrent.futures import ProcessPoolExecutor
from multiprocessing.pool import Pool

from loguru import logger


def foo(message: str):
    logger.info(f"task {message} started")
    time.sleep(1)
    return message.upper()


def use_pool():
    with Pool(processes=4) as pool:
        p1 = pool.apply_async(foo, args=("hello",))
        p2 = pool.apply_async(foo, args=("world",))
        logger.info(p1.get(timeout=2))
        logger.info(p2.get(timeout=2))


def use_process_pool_executor():
    with ProcessPoolExecutor(max_workers=4) as executor:
        future1 = executor.submit(foo, ("hello"))
        future2 = executor.submit(foo, ("world"))
        logger.info(future1.result())
        logger.info(future2.result())


if __name__ == "__main__":
    use_pool()
    use_process_pool_executor()
