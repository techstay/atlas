// integers
let sbyteValue: sbyte = 1y
let byteValue: byte = 1uy
let int16Value = 100s
let uint16Value = 100us
let int32Value = 1000l
let uint32Value = 1000ul
let nativeIntValue = 100n
let unativeIntValue = 100un
let int64Value = 1000L
let uint64Value = 1000UL

// float
let float32Value = 3.14f
let float64Value = 3.14159

// big
let bigIntValue = 10000000000000000I

// char
let charValue = 'a'

// unicode string
let stringValue = "abcd"
let verbatimString = @"\abc$def/n"

// byte
let byteChar = 'a'B
let byteArrayValue = "abcd"B

// integers in other bases
let octal = 0o12345
let binary = 0b10101100
let hexadecimal = 0xcafe

// mutable variables
let mutable number = 100
number <- 200
printfn "%d" number
