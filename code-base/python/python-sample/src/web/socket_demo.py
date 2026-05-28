# %%
import socket
import time
from multiprocessing.pool import ThreadPool

socket.gethostbyname("www.baidu.com")

# %%

socket.gethostname()
# %%

host = socket.gethostbyname("localhost")
port = 20086


def server():
    addr = (host, port)
    with socket.create_server(addr) as s:
        conn, addr = s.accept()
        while True:
            data = conn.recv(1024)
            if not data:
                continue
            data = data.decode()
            if data.lower() == "quit":
                break
            print(data)
    print("Server closed.")


def client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        print("Client wait 1 second and start:")
        time.sleep(1)
        s.connect((host, port))
        for i in range(1, 6):
            msg = f"Hello {i} from client"
            time.sleep(1)
            s.sendall(msg.encode())
        s.sendall(b"quit")
    time.sleep(0.5)
    print("Client finished")


def main():
    with ThreadPool(processes=4) as pool:
        pool.apply_async(func=client)
        pool.apply_async(func=server)
        pool.close()
        pool.join()


if __name__ == "__main__":
    main()
