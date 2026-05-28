// explicitly generic constructs
let foo<'T> (a: 'T, b: 'T) = (a, b)

// implicitly generic constructs
let bar (a, b) = (a, b)

// generic with constraints
let baz<'T when 'T: comparison and 'T: equality> (a: 'T, b: 'T) = a = b

let f1 = foo (2, 3)
let f2 = bar (6, 4)
let f3 = baz (6, 4)
