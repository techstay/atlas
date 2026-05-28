import asyncio


async def task1():
    await asyncio.sleep(2)
    return 42


async def main():
    rst = await task1()
    print(rst)


if __name__ == "__main__":
    asyncio.run(main())
