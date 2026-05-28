// defining some units of measure
[<Measure>]
type miter

[<Measure>]
type kilomiter

let convertMToKm (length: float<miter>) = length / 1000.0
let convertKmToM (length: float<kilomiter>) = length * 1000.0

let foo = convertMToKm 3000.0<miter>
let bar = convertKmToM 3.5<kilomiter>

// using predefined units of measure
open FSharp.Data.UnitSystems.SI.UnitSymbols

let velocity = 100<m> / 50<s>
let volume = 100<m> * 100<m> * 100<m>
