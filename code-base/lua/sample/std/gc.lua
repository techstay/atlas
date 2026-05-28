local used_memory_in_kb = collectgarbage("count")
print(string.format("the lua used %f KB\n", used_memory_in_kb))
