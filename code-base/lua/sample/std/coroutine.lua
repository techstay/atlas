local foo = coroutine.create(function(f1, f2)
  print("in coroutine:", f1 + f2)
  return f1 + f2
end)

local status, res = coroutine.resume(foo, 6, 4)
print(string.format("status: %s, result :%d\n", status, res))

-- yield will suspend the coroutine and wait the caller call resume again
local three_steps_tasks = coroutine.create(function()
  print("now is step 1:")
  coroutine.yield(6 + 4)

  print("now is step 2:")
  coroutine.yield("success")

  print("finally step 3:")
  coroutine.yield(0)
end)

status, res = coroutine.resume(three_steps_tasks)
print(status, res)

status, res = coroutine.resume(three_steps_tasks)
print(status, res)

status, res = coroutine.resume(three_steps_tasks)
print(status, res)
