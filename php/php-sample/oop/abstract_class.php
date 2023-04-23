<?php

abstract class NotImplementedClass
{
  abstract function do_something();
}

class ImplementedClass extends NotImplementedClass
{
  public function do_something(): void
  {
    echo "done something...\n";
  }
}

$obj = new ImplementedClass();
$obj->do_something();

