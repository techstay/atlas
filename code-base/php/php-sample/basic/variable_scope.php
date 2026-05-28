<?php

# global variable
$a = 300;
function show_global_variable_scope(): void
{
  # local variable
  $a = 30;
  var_dump($a);

  global $a;
  var_dump($a);
}

show_global_variable_scope();

function show_local_variable_scope(): int
{
  $b = 0;
  $b += 1;
  return $b;
}

var_dump(show_local_variable_scope());
var_dump(show_local_variable_scope());

function show_static_variable_scope(): int
{
  static $b = 0;
  $b += 1;
  return $b;
}

var_dump(show_static_variable_scope());
var_dump(show_static_variable_scope());
