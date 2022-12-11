# while
var i = 0
while (< $i 5) {
    echo $i
    set i = (+ $i 1)
}

# else is executed when while block never executed
set i = 0
while ( > $i 5) {
    echo "this line never runs"
} else {
    echo "and else block runs"
}
