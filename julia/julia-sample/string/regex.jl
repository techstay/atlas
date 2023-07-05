re = r"ab[cde]"

text = "abc abd abefg abb"

occursin(re, text)

result = match(re, text)

result = match(re, text, 4)

eachmatch(re, text) |> collect
