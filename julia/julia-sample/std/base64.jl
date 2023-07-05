##
using Base64

encoded = base64encode("hello world")

decoded = base64decode(encoded) |> String
