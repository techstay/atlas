// sequences are equivalent to IEnumerable in dotnet
// most operations here are applicable for lists and arrays

// creating sequences
let seq1 = seq { 1..10..100 }
let seq2 = seq { for i in 1..10 -> i }
let seqEmpty = Seq.empty

// initializing sequences
let seq6 = Seq.init 10 (fun i -> i + 1)
let seq7 = Seq.initInfinite (fun i -> i + 1)

// seq with only one element
let seqOne = Seq.singleton 10

// seq from arrays and lists
let seqFromArray = [| 1..5 |] |> Seq.ofArray
let seqFromList = [ 1..5 ] |> Seq.ofList
let seqFromCast = [ 1..5 ] |> seq<int>

let seq3 =
  seq {
    for i in 1..10 do
      i * i
  }

// yield! is used for generating values into outer sequences
let seq4 =
  seq {
    for _ in 1..3 do
      yield!
        seq {
          1
          2
          3
        }
  }

// unfolding
let fib =
  (0, 1)
  |> Seq.unfold (fun state ->
    let cur, next = state

    if cur < 0 then // overflow
      None
    else
      let next' = cur + next
      let state' = next, next'
      Some(cur, state'))

let fibonacciNumbers = List.ofSeq fib
