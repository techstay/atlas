<?php
$obj = new class {
  function function_in_anonymous_class()
  {
    var_dump("in anonymous class");
  }
};

$obj->function_in_anonymous_class();
