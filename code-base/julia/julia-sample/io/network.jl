##
using Sockets

errormonitor(@async begin
  server = listen(10086)
  println("wait for 2 seconds")
  sleep(2)
  sock = accept(server)
  for i = 1:5
    sleep(1)
    println(sock, "hello $i")
  end
  close(sock)
  close(server)
end)

let
  client = connect(10086)
  for i = 1:5
    @show readline(client)
  end

  close(client)
end
##

getaddrinfo("baidu.com")
