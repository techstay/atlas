# necessary whitespace between { and following commands
var f = { echo "This is a lambda"}
$f

# lambda with arguments
var f2 = {|a b &opt=default|
    echo $a $b $opt
}

$f2 a b
$f2 a b &opt=optional
