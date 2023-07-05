struct Point{T}
  x::T
  y::T
end

Point{Int} <: Point{Real}
Point{<:Real} <: Point{Real}

# type aliases
const MyInt = Int64

x::MyInt = 128
typeof(x)
