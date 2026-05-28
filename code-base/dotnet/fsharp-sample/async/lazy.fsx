let print_and_return () =
  let foo = 42
  printfn "print: %d" foo
  foo

let foo = print_and_return ()
let bar = lazy (print_and_return ())

printfn "lazy expression:"
printfn "%d" (bar.Force())
