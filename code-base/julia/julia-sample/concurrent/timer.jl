let
  i = 0
  cb(timer) = (i += 1; println(i))
  t = Timer(cb, 0, interval=1)
  println("wait for the timer starts:")
  wait(t)
  sleep(5)
  close(t)
end
