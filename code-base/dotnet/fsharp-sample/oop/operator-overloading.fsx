type MyValue(x: int) =

  member this.x = x
  static member (+)(a: MyValue, b: MyValue) = MyValue(a.x + b.x)
  static member (-)(a: MyValue, b: MyValue) = MyValue(a.x - b.x)
  static member (*)(a: MyValue, b: MyValue) = MyValue(a.x * b.x)
  override this.ToString() = $"MyValue({x})"

let a = new MyValue(6)
let b = new MyValue(4)

let c = a + b
let d = a - b
let e = a * b
