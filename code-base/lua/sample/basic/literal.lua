-- boolean
local truth = true
local lie = false
print(type(truth))

-- null
local none = nil
print(type(none))

-- numbers
-- double precision floating numbers
local integer = 3
local real = 3.1415
print(type(real))

-- strings
local str = "abcd"
print(type(str))

-- functions
local function foo()
  return "foo"
end

print(type(foo))
print(foo())
