let str = "Hello world!"
let verbatimString = @"""abcd"""
let tripleQuotedString = """<a href="/api/get">click</a>"""
let stringConcatenation = "abc" + "xyz"

// string slicing
printfn "%s" str[0..5]

// string interpolation
printfn $"{str}!!"
