##
s = Set("abcdabcd")
bs = BitSet(6)

##
union([1, 2, 3], [1, 4])
[1, 2, 3] ∪ [1, 4]
intersect([1, 2, 3], [1, 4])
[1, 2, 3] ∩ [1, 4]
setdiff([1, 2, 3], [1, 4])
symdiff([1, 2, 3], [1, 4])

##
issubset([1], [1, 2, 3])
# \subseteq \supseteq
⊆([1], [1, 2, 3])
⊈([1], [1, 2, 3])
⊇([1, 2, 3], [1, 2])
[1, 2, 3] ⊉ [1, 2]
isdisjoint([1, 2, 3], [3, 4])

##
issetequal([1, 2], [1, 2])
issetequal([1, 2, 3], [1, 2])
