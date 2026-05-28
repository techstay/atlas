<?php

class Class1
{
  public $name = "Class1";

  public function greet()
  {
    echo "Hello, $this->name!\n";
  }
}

readonly class ReadOnlyClass1
{
  # class constants
  const PI = 3.1415926;
}

$c1 = new Class1();
$c1->greet();
var_dump(ReadOnlyClass1::PI);
