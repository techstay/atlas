// slice is applicable for lists and arrays

let array1 = Array.init 10 (fun i -> i)
let list1 = [ 1..10 ]

list1[0..3]
list1[..4]
list1[4..6]
list1[8..]

// multidimensional arrays slicing
let array2 = Array2D.init 3 3 (fun i j -> i * 3 + j + 1)

array2[*, *]
array2[0..1, *]
array2[*, 0]
array2[0, *]
