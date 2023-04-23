<?php

class MyClass
{
  public $a = 1;
  public $b = 2;
  public $c = 100;
  private $hidden = "guess";
  protected $unvisible = "cannot see me";
}

$obj = new MyClass();
foreach ($obj as $property => $value) {
  print "$property => $value\n";
}
echo "\n";
