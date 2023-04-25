let foo =
  try
    failwith "foo bar baz"
  with Failure e ->
    printfn "%s" e

foo
