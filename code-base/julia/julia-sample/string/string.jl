# strings
str = "abcde"

# triple double quotes strings
longStr = """abc"de"fg"""

# indice
longStr[begin:end]
longStr[begin:end-2]

# iteration
unicodeString = "我们是一家人"
for c in str
  print(c)
end
println()

for c in unicodeString
  print(c)
end
println()

# byte array strings
byteArray = b"hello world"

# version number strings
v2 = v"2.0"
v3 = v"3.5"
v3 > v2

# raw strings
rawString = raw"\\\w\b"

# unicode
s = "\u2200 x \u2203 y"
