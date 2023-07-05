from = "abcdefghijklmnopqrstuvwxyz"
to = "cdefghijklmnopqrstuvwxyzab"
trans = "g fmnc wms bgblr rpylqjyrc gr zw fylb <>"
d = Dict([from[i] => to[i] for i = 1:26])
d[' '] = ' '
map(x -> d[x], filter(x -> isletter(x) || isspace(x), trans))
