let t1 = [[a b ]; [1 2]]
let t2 = [[c d]; [1 2]]
$t1 | merge $t2
[ $t1 $t2]|reduce {|it,acc|$acc|merge $it}
