// creating arrays
let array1 = [| 1; 2; 3 |]
let array2 = [| for i in 1..10 -> float i ** 2 |]
let array3: int array = Array.zeroCreate 10
let array4 = Array.create 10 1
let array5 = Array.init 10 (fun i -> i)
