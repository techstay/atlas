let-env FOO = 'BAR'

$env.FOO

load-env {"FOO1": "BAR1", "FOO2": "BAR2"}

$env.FOO1
$env.FOO2

with-env { FOO3: BAR3 } { $env.FOO3 }

hide FOO
