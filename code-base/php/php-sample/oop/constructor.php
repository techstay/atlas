<?php

class Class10
{
  function __construct()
  {
    echo "construct class...\n";
  }

  function __destruct()
  {
    echo "destruct class...\n";
  }
}

$class = new Class10();
