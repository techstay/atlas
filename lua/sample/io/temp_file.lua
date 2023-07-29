local temp = io.tmpfile()

if temp then
  temp:write("hello world\n")
  temp:write("foo bar\n")
  temp:flush()

  temp:seek("set")

  for line in temp:lines("l") do
    print(line)
  end

  io.close(temp)
end
