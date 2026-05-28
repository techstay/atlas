// normal approach
for i in 1..9 do
  for j in 1..i do
    printf "%d*%d=%-2d\t" j i (i * j)

  printfn ""

printfn ""

// f# approach
[ 1..9 ]
|> List.map (fun x -> [ 1..x ] |> List.map (fun y -> sprintf "%d*%d=%-2d" y x (x * y)))
|> List.map (fun x -> String.concat "\t" x)
|> List.iter (fun x -> printfn "%s" x)
