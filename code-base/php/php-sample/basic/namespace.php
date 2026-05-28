<?php

# declaring namespace
namespace namespace1 {
  function function_in_namespace1()
  {
    var_dump("in namespace1");
  }
}

namespace namespace2 {
# using global namespace functions
  var_dump(\strlen('abcd'));
}
