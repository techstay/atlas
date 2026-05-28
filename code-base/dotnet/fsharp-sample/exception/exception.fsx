exception MyError of string
open System

let foo (a, b) =
  try
    try
      if a = b then
        raise (MyError("a shouldn't be equal with b"))
    with
    | MyError(x) -> printfn "%s" x
    | :? ArithmeticException as ex -> printfn $"arithmatic exception {ex}"
  finally
    printfn "here are some codes that are always executed"

foo (2, 3)
foo (2, 2)
