struct MyList
  values::Array{Number}
end

# implement index methods
Base.getindex(X::MyList, i::Integer) = X.values[i]
Base.setindex!(X::MyList, v::Number, i::Integer) = X.values[i] = v
Base.firstindex(X::MyList) = X.values[begin]
Base.lastindex(X::MyList) = X.values[end]

list = MyList([1, 2, 3, 4])
list[1]
list[2] = 20
list[begin]
list[end]
list
