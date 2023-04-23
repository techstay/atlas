<?php

$var = 123;
var_dump($var);

unset($var);
# this will fail
var_dump($var);

# reference
$ref =& $var;
$ref = 6;
var_dump($var);
