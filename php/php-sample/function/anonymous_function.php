<?php
$greeting = function ($name) {
  echo "Hello, $name!\n";
};

$greeting("techstsay");

$sum = fn($a, $b) => $a + $b;
var_dump($sum(3, 4));
