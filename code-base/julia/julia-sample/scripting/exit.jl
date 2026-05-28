function on_exit(n::Int32)
  println("before exiting")
  println("catching result value: $(n)")
end

atexit(on_exit)
exit(0)
