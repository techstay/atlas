<?php

$arr = [1, 2, 3, 4, 5];
foreach ($arr as $i) {
  echo $i;
}
echo "\n";

$arr = [1 => 1, 2 => 3, "abc" => 5];
foreach ($arr as $k => $v) {
  echo "$k => $v, ";
}
echo "\n";
