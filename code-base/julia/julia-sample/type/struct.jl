struct Person
  name::String
  age::Int64
end

person = Person("jack", 18)
person.name

# pretty printing
Base.show(io::IO, p::Person) = print(io, "Person(name: $(p.name), age:$(p.age))")

# listing fieldnames
println(fieldnames(Person))

# mutable structs
mutable struct Pair
  left
  right
end

pair = Pair(0, 0)
pair.left = 1
pair.right = 2.0
pair
