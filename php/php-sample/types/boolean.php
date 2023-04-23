<?php

# boolean, case-insensitive
var_dump(true);
var_dump(False);

# below values are false implicitly
$we_are_false = false || 0 || 0.0 || -0.0 || "" || "0" || array() || null;
var_dump($we_are_false);
