##
using Base.Threads
# without atomic
s = Ref(0)
@threads for i = 1:1000
  s[] += 1
end

# expected to be 1000
@show s

##

# we can get the correct answer using atomic
s = Atomic{Int}(0)
@threads for i = 1:1000
  atomic_add!(s, 1)
end

@show s
