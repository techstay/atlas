let numbers = [1, 2, 3, 4, 5]
$numbers|wrap 'Number'|upsert Square {|it|
    $it.Number * $it.Number
}
