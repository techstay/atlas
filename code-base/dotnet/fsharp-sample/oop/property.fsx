open System

type TestProperty() =
  let random = new Random()
  // auto property evaluates only once
  member val AutoProperty = random.Next() with get
  // explicit property evaluates every time
  member this.ExplicitProperty = random.Next()

let testProperty = new TestProperty()

printfn "autoProperty: %d" testProperty.AutoProperty
printfn "autoProperty: %d" testProperty.AutoProperty
printfn "explicitProperty: %d" testProperty.ExplicitProperty
printfn "explicitProperty: %d" testProperty.ExplicitProperty

// static fields and properties
type Counter() =
  static let mutable _count = 0
  static do printfn "counter first use"
  do _count <- _count + 1
  static member count = _count

Counter()
Counter()
Counter()
Counter()

printfn "counter: %d" Counter.count
