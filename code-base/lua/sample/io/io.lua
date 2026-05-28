-- reading files
local path = "C:\\Windows\\System32\\drivers\\etc\\hosts"
local file = io.open(path, "r")

io.input(file)
local content = io.read("a")
io.close(file)

print(content)

-- writing files
path = "hello.txt"
file = io.open(path, "w+")

io.output(file)

io.write(string.format("hello world\n"))
io.close(file)
