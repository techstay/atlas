let week = [Monday Tuesday Wednesday Thursday]
$week|each { |it| $"($it)"}
$week|each -n { |it| $"($it.index) ($it.item)"}
