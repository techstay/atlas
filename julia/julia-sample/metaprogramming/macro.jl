macro hello()
  return :(println("Hello world"))
end

@hello()

##
macro hello(name)
  show(name)
  return :(println("Hello, $($name)"))
end

@hello("jack")

##
macro upper_str(str::String)
  return uppercase(str)
end

upper"abcd"
