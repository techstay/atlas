open System.Runtime.CompilerServices

[<Extension>]
type StringExtension =
  [<Extension>]
  static member inline Greet(x: string) = printfn $"Hello, {x}"


"jackson".Greet()
