<?php

$rank = 's';
echo match ($rank) {
  'c' => 'bad',
  'b' => 'not bad',
  'a' => 'good',
  's' => 'excellent',
  default => 'not supported'
};
