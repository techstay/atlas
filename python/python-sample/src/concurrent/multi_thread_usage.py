import time
from multiprocessing.pool import ThreadPool


def long_task1():
    print("Task 1")
    time.sleep(2)
    print("Task 1 is complete")


def long_task2():
    time.sleep(1)
    print("Task 2")
    print("Task 2 is complete")


if __name__ == "__main__":
    with ThreadPool(processes=4) as pool:
        result1 = pool.apply_async(func=long_task1, args=())
        result2 = pool.apply_async(func=long_task2, args=())
        result1.wait()
        result2.wait()
