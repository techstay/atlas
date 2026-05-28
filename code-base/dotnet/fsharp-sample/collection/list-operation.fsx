// operations here are most applicable for sequences, lists and arrays
// TODO: this file is intended to be rewritten in dib format

// aggregation
let sumOfList = List.sum [ 1..10 ]
let squareSumOfList = List.sumBy (fun e -> e * e) [ 1..3 ]
let averageOfList = List.average [ 1.0 .. 10.0 ]
let averageOfSquareOfList = List.averageBy (fun e -> e * e) [ 1.0 .. 4.0 ]

// zipping
let zippedList = List.zip [ 1..5 ] [ 2..6 ]
let unzippedList = List.unzip zippedList

// iterating
List.iter (fun e -> printfn "element: %d" e) [ 1..5 ]
List.iteri (fun i e -> printfn "element %d: %d" i e) [ 1..5 ]
List.iter2 (fun x y -> printfn "element: %d, %d" x y) [ 1..3 ] [ 2..4 ]

// mapping
let evenList = List.map (fun e -> e * 2) [ 0..5 ]
let sameValueList = List.map2 (fun x y -> x + y) [ 1..5 ] [ 5..-1..1 ]
let multipleList = List.mapi (fun i e -> i * e) [ 0..3 ]

// collecting
let collectedList = List.collect (fun e -> [ for i in 1..e -> i ]) [ 1..4 ]

// filtering
let oddList = List.filter (fun e -> e % 2 <> 0) [ 0..10 ]

// choosing
// accepting a function returning options
// and return only the present values
let oddList2 = List.choose (fun e -> if e % 2 <> 0 then Some(e) else None) [ 0..10 ]

// folding
let sumOfList2 = List.fold (fun acc e -> acc + e) 0 [ 1..10 ]
let sumOfList3 = List.foldBack (fun e acc -> e + acc) [ 1..10 ] 0

let foldedList =
  List.fold2 (fun acc e1 e2 -> acc @ [ e1 + e2 ]) [] [ 1..5 ] [ 5..-1..1 ]

// reducing
let reducedSum = List.reduce (fun acc e -> acc + e) [ 1..10 ]

// windowed
let windowsOfList = List.windowed 3 [ 1..5 ]

// grouping
let groupedList = List.groupBy (fun e -> e % 2 = 0) [ 1..10 ]

// distinct
let distinctList = List.distinct [ 1; 1; 5; 5; 6; 6; 7 ]
let distinctByList = List.distinctBy (fun e -> abs e) [ 1; -1; 5; 5; 6; 7 ]
