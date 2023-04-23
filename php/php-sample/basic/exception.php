<?php

class MyException extends Exception
{

}

try {
  throw new MyException("my exception");
} catch (MyException|Exception $e) {
  echo "{$e->getMessage()}\n";
} finally {
  var_dump('always executed.');
}
