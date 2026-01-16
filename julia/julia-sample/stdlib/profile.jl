##
using Profile

function foo()
  s = BigInt(0)
  for i in 1:100000
    s += i
  end
end

@profile foo()

Profile.print()

##

@time foo()

##
@time begin
  sleep(1)
end
