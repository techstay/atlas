# creating custom exceptions
struct MyCustomException <: Exception end

# try-catch clause
try
  x = sqrt(-9)
catch e
  println(e)
else
  # executed when try succeeds
  println(x)
finally
  # always executed
  println("do some cleaning tasks")
end

# throw exceptions
f(x) = x > 0 ? x : throw(MyCustomException(x, "arguments must be positive"))

try
  f(-10)
catch e
  println(e)
end

