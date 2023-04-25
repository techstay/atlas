// interfaces

type IMovable =
  abstract member Move: unit -> unit

// implementing interfaces
type Car() =
  interface IMovable with
    member this.Move() = printfn "car moves"

let car = new Car()
(car :> IMovable).Move()

// object expressions
let bikeClass () =
  { new IMovable with
      member this.Move() = printfn "bike moves" }

let bike = bikeClass ()
bike.Move()
