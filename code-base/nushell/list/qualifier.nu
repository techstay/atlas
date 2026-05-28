let list1 = [1 2 3 4 5 6]
let list2 = ["Monday" "Tuesday" "Wednesday" "Thursday" "Friday" "Saturday"]
$list1|any $it > 7
$list1|any $it mod 2 == 0
$list2|all ($it|str ends-with "day")
$list2|all ($it|str length) > 7
