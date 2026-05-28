<?php

$single_quoted_string = '"This is" some strings.\n';
$double_quoted_string = "ab'\t'cd";

# heredoc
$name = 'techstay';
$here_doc = <<<eol
abc
$name
  abc\n
eol;

var_dump($single_quoted_string);
var_dump($double_quoted_string);
echo($here_doc);

# nowdoc
$nowdoc = <<<'eol'
abc
$name
  abc\n
eol;
echo($nowdoc);
