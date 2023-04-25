let tuple1 = (2, 3)
let (a, b) = tuple1

printfn "a=%d, b=%d" a b

let PrintTuple tuple =
  match tuple with
  | (a, b) -> printfn "Tuple(%d, %d)" a b

PrintTuple tuple1

// defining tuple types
type IntTuple = int * int

let foo = IntTuple(3, 4)

// struct tuples
let bar = struct (3, 4)
