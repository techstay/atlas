-- base class
Shape = { name = "", area = 0 }

function Shape:new(o)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  self.name = "shape"
  return o
end

function Shape:printArea()
  print(string.format("%s's area is %f", self.name, self.area))
end

-- derived class
Square = Shape:new()

function Square:new(o, side)
  o = o or Shape:new(o)
  setmetatable(o, self)
  self.__index = self
  self.name = "square"
  self.side = side
  self.area = side * side
  return o
end

function Square:printArea()
  print(string.format("%s's area is %f", self.name, self.area))
end

local square = Square:new(nil, 4)
square:printArea()
