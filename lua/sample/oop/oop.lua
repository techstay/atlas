Person = { name = "", age = 0 }
function Person:new(o, n, a)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  self.name = n or ""
  self.age = a or 0
  return o
end

function Person:hello()
  print(string.format("hello, %s\n", self.name))
end

local p = Person:new(nil, "jack", 18)
print(p.name)
p:hello()
