<?php
# extracting array elements
$arr1 = [1, 2, 3];
[$a, $b, $c] = $arr1;

var_dump($a, $b, $c);

# omitting some values
[, , $c] = $arr1;
var_dump($c);

$arr2 = [...$arr1];
$arr3 = [0, ...$arr1];
var_dump($arr2);
var_dump($arr3);
