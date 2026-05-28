<?php

function my_generator($limit)
{
  for ($i = 0; $i < $limit; $i++) {
    yield $i;
  }
}

foreach (my_generator(10) as $i) {
  print "$i ";
}
echo "\n";
