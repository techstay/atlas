##
push!([], 1, 2, 3)
pushfirst!([2, 3], 1)
pop!([1, 2, 3])
popfirst!([1, 2, 3])

##
insert!([1, 2, 3, 4], 2, 6)
deleteat!([1, 2, 3, 4], 2)
keepat!([1, 2, 3, 4], [1, 3, 4])
splice!([1, 2, 3, 4], [1, 3, 4])
resize!([1], 5)

##
prepend!([1, 2], [4, 5, 6])
