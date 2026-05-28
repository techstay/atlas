<?php

# another way to share methods
trait A
{
  function a()
  {
    var_dump('a');
  }
}

trait B
{
  function b()
  {
    var_dump('b');
  }
}

trait A2
{
  function a()
  {
    var_dump("a2");
  }
}

class P
{
  use A, B;
}

$p = new P();
$p->a();
$p->b();

class Q
{
  use A, A2 {
    A::a insteadof A2;
    A2::a as a2;
  }
}

$q = new Q();
$q->a();
$q->a2();
