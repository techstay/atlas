// defining records
type person = { name: string; age: int }

let jack = { name = "jack"; age = 18 }

// ambiguity
type employee = { name: string; age: int }

// the most declared record take precedence
let lucy = { name = "lucy"; age = 23 }

// explicitly property name
let lee = { person.name = "lee"; age = 27 }

// copy and update records
let lee2 = { lee with age = 18 }

// anonymous records
// using references records without struct keyword
let ada = struct {| name = "ada"; age = 16 |}
