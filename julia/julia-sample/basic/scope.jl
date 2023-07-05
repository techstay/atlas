# global variables
x = 100

# the let clause creates a local scope
let x = 500, y = 10
  println("x=$(x), y=$(y)")
end


function f()
  # here x refers to the local x
  x = 200
  println(x)
end

f()
println(x)

function g()
  # here is the global x
  global x = 300
  println(x)
end

g()
println(x)

function outerFor()
  i = 0
  # by default, the for clause will create a new local scope
  # but we can use outer keyword to indicate reuse outer variables
  for outer i ∈ 1:5
    # do something
  end
  # i remains 5 here
  println(i)

end

outerFor()
