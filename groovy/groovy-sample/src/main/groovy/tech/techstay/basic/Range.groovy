package tech.techstay.basic

assert (1..3).collect() == [1, 2, 3]
assert (1<..3).collect() == [2, 3]
assert (1..<3).collect() == [1, 2]
assert (1<..<3).collect() == [2]
assert (3..1).collect() == [3, 2, 1]
assert 'a'..'c' == ['a', 'b', 'c']
assert (1..5).by(2) == [1, 3, 5]
assert (1..5).step(2) == [1, 3, 5]
