1..100|reduce --fold 0 {|it,acc| $acc + $it}
1..10|reduce --fold 1 {|it,acc| $acc * $it}
[1 2 3]|reduce --numbered {|it,acc| $it.index * $it.item + $acc.item}
