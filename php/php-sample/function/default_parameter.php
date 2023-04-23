<?php

function function_with_default_parameter($name = "techstay")
{
  var_dump($name);
}

function_with_default_parameter();
function_with_default_parameter("abcd");

