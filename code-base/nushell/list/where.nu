let week = [Monday Tuesday Wednesday Thursday]

$week|where ($it | str starts-with 'T')
$week|where ($it|str length)  > 8
