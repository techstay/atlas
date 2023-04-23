<?php

# in php arrays are actually hashmaps
$arr1 = [];
$arr2 = array();
$arr3 = [1, 2, 3,];
$arr4 = [1 => 'a', "2" => 3, 'abc' => 4, 5];

var_dump($arr4);

# accessing array elements
assert(1 == $arr3[1]);

# deleting elements
unset($arr4['abc']);



