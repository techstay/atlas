##
task = @task begin
  a = 5
  sleep(3)
  println("task finished")
end

schedule(task)
# block and wait for task finished
wait(task)

