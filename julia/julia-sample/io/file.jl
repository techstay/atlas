##

# writing to files
f = open("hello.txt", "w")

println(f, "hello world")
println(f, "Across the great wall, we can reach every corner in the world.")
close(f)

##

# reading from files
f = open("hello.txt")

lines = readlines(f)
close(f)

##

# open a file, do something and then close it
open("hello.txt") do f
  map(uppercase, readlines(f))
end

##

# finally delete the file
Base.Filesystem.rm("hello.txt")
