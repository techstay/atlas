local str1 = "abc"
local str2 = 'abc'
local str3 = [[hello world]]

-- uppercase and lowercase
print(string.upper(str1))

-- find and replace
print(string.find(str3, "world"))
print(string.gsub(str1, 'a', 'xx'))

-- reverse
print(string.reverse(str3))

-- repeat
print(string.rep(str2, 3))

-- format
print(string.format("name: %s, age: %d", "jack", 18))

-- char and byte
print(string.byte("a"))
print(string.char(97))
