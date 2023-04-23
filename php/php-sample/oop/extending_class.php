<?php

class Class1
{
  public $name = "Class1";

  public function greet()
  {
    echo "Hello, $this->name!\n";
  }
}

class Class2 extends Class1
{
  public $name = "Class2";

  public function greet()
  {
    echo "Hi, $this->name!\n";
  }
}

$c1 = new Class1();
$c2 = new Class2();
$c1->greet();
$c2->greet();
