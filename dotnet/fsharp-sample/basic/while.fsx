open System

let mutable condition = true
let rand = new Random()

// the iteration will terminate when found 5
while condition do
  let num = rand.Next(10)
  printf "%d " num

  if num = 5 then
    printfn "\n%d found!" num
    condition <- false
