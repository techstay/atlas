##
sort([1, 2, 3])
sort([1, 2, 3], rev=true)
sort([-3, -2, -1], by=abs)
sort([-3, -2, -1], by=abs, rev=true)

##
searchsortedfirst([1, 2, 3, 3, 5], 3)
searchsortedlast([1, 2, 3, 4, 4], 4)

##
issorted([1, 2, 2])

##
partialsort([5, 3, 6, 2, 8], 1:3)
