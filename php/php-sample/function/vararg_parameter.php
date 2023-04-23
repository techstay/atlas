<?php

function function_with_vararg(...$args)
{
  foreach ($args as $a) {
    echo $a;
  }
  echo "\n";
}

function_with_vararg();
function_with_vararg(1);
function_with_vararg(1, 2, 3, 4, 5);
