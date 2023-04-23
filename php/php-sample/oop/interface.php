<?php

interface A
{
  # interface constants
  const PI = 3.142;

  function a();
}

interface B
{
  function b();
}

abstract class C implements A, B
{
}

class D extends C
{
  public function a()
  {
    var_dump("in function a");
  }

  public function b()
  {
    var_dump("in function b");
  }
}

$d = new D();
var_dump(A::PI);
$d->a();
$d->b();
