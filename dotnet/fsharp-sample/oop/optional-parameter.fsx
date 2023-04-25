type OptionalParameter(?a: int, ?b: string, ?c: bool) =
  let a = defaultArg a 0
  let b = defaultArg b "none"

  let c =
    match c with
    | Some v -> v
    | None -> false

  do printfn $"a: {a}, b: {b}, c: {c}"

let obj1 = new OptionalParameter()
let obj2 = new OptionalParameter(a = 10)
let obj3 = new OptionalParameter(b = "hello")
let obj4 = new OptionalParameter(c = true)
let obj5 = new OptionalParameter(a = 100, b = "foo", c = true)
