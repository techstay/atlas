let rand = new System.Random()

let getRandomPositiveNumber () =
  let n = rand.Next(-10, 11)
  if n > 0 then Some(n) else None

let foo = getRandomPositiveNumber ()
let bar = getRandomPositiveNumber ()
let baz = getRandomPositiveNumber ()

// consuming options
let result =
  match baz with
  | Some(x) -> x
  | None -> -1

// value options
let getRandomPositiveNumberValue () =
  let n = rand.Next(-10, 11)
  if n > 0 then ValueSome(n) else ValueNone

let result2 = getRandomPositiveNumberValue ()
