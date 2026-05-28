// creating lists
let list1 = [ 1; 0; -4 ]
open System.Collections.Generic

type Employee() =
  class
  end

type Manager() =
  inherit Employee()

type Boss() =
  inherit Manager()

// employee list
let list2 = [ new Employee(); new Manager(); new Boss() ]

// sequence expressions
let anotherList = [ for i in 1..10 -> float i ** 2 ]

// list properties
anotherList.Head
anotherList.Tail
anotherList.IsEmpty
anotherList.Item(2)

// concatenating lists
let list3 = 100 :: list1
let list4 = list1 @ list3
let list5 = List.append [ 1; 2; 3 ] [ 4; 5; 6 ]
let list6 = List.concat [ [ 1; 2; 3 ]; [ 2; 3; 4 ] ]

// existence
let contains4 = List.exists (fun e -> e = 4) list4

// reversing
let reversedList = List.rev [ 1..10 ]

// sorting
let sortedList1 = List.sort list1
let sortedList4 = List.sortBy (fun e -> abs e) list4

// searching
let find4 = List.find (fun e -> e = 4) [ 1..10 ]
let findIndexOf4 = List.findIndex (fun e -> e = 4) [ 1..10 ]

let findIndexOf20 =
  try
    List.findIndex (fun e -> e = 20) [ 1..10 ]
  with :? KeyNotFoundException as ex ->
    printfn "the element not found"
    -1

let findOptionOf4 = List.tryFind (fun e -> e = 4) [ 1..10 ]
let findOptionOf20 = List.tryFind (fun e -> e = 20) [ 1..10 ]
