type Person(id: int, name: string, age: int) =
  // private fields
  let mutable _id = id
  let mutable _name = name
  let mutable _value = 0

  // primary constructors
  do
    // here you can do some initialization tasks
    printfn $"primary constructor({id}, {name}, {age})"

  // automatically implemented properties
  member val age = age with get, set

  // secondary constructors
  new() = Person(0, "none", 0)

  // properties
  member this.id
    with get () = id
    and set (value) = _id <- value

  member this.name
    with get () = _name
    and set (value) = _name <- value

  member this.Item
    with get (index) =
      match index with
      | 1 -> "id"
      | 2 -> "name"
      | 3 -> "name"
      | _ -> ""
    and set index value = _value <- value

  // methods
  member this.greet = printfn $"Hello, {name}"

  // static member functions
  static member run = printfn "a person runs"

let p1 = new Person()
p1.age <- 100

let p2 = new Person(1, "techstay", 18)

printfn $"({p1.id} {p1.name} {p1.age})"
printfn $"({p2.id} {p2.name} {p2.age})"

// calling methods
p2.greet
Person.run
