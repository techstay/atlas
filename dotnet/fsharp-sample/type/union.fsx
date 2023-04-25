open System

// union as enums
type TrafficLight =
  | RED
  | YELLOW
  | GREEN

  // defining members in unions
  member this.turn =
    match this with
    | RED -> YELLOW
    | YELLOW -> GREEN
    | GREEN -> RED

let traffic = RED
traffic.turn
traffic.turn.turn

// union types
type Shape =
  | Rectangle of length: float * width: float
  | Square of width: float
  | Circle of radius: float

  member this.area =
    match this with
    | Rectangle(l, w) -> l * w
    | Square(w) -> w ** 2
    | Circle(r) -> Math.PI * r ** 2

let circle = Circle(1.)
let circleArea = circle.area

// pattern matching of unions
let printShape shape =
  match shape with
  | Rectangle(l, w) -> printfn "rectangle(%f, %f)" l w
  | Square(w) -> printfn "square(%f)" w
  | Circle(r) -> printfn "circle(%f)" r

printShape (Rectangle(5.0, 4.0))
printShape (Square(3.0))
printShape (Circle(radius = 1.0))

// unwrapping unions
let (Circle radius) = Circle(5.)
printfn "radius is %f" radius
