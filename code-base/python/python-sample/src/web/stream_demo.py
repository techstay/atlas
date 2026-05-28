# %%
import asyncio
import socket
from asyncio import Event, StreamReader, StreamWriter

socket.gethostbyname("www.baidu.com")

# %%

socket.gethostname()
# %%

host = socket.gethostbyname("localhost")
port = 20086
exit_message = "exit"


async def handle_client(reader: StreamReader, writer: StreamWriter):
    addr = writer.get_extra_info("peername")
    print(f"connection established: {addr}")
    while True:
        data = await reader.read(1024)
        if not data:
            break
        message = data.decode()
        if message == exit_message:
            print(f"received exit signal from {addr}")
            break
        print(f"received from {addr}: {message}")
    print(f"connection closed: {addr}")
    writer.close()
    await writer.wait_closed()


async def server(event: Event):
    server = await asyncio.start_server(
        handle_client,
        host,
        port,
    )
    async with server:
        await server.start_serving()
        # Wait for the exit signal
        await event.wait()

    print("server stopped")


async def client(event: Event):
    _, writer = await asyncio.open_connection(host, port)

    for i in range(1, 6):
        writer.write(f"hello from client: {i}".encode())
        await writer.drain()
        await asyncio.sleep(1)
    writer.write(exit_message.encode())
    await writer.drain()

    writer.close()
    await writer.wait_closed()
    # Notify the server to shut down
    event.set()


async def socket_demo():
    should_exit = asyncio.Event()
    async with asyncio.TaskGroup() as tg:
        tg.create_task(server(should_exit))
        tg.create_task(client(should_exit))


if __name__ == "__main__":
    asyncio.run(socket_demo())
# %%
