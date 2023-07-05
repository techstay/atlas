import InteractiveUtils: subtypes

##
binary = 0b1011_1100
bitstring(binary)

octal = 0o1234567

hexadecimal = 0xcafe99

# e-notion
typeof(3.14e6)
typeof(3.14f6)

##
# integers
int8::Int8 = typemax(Int8)
uint8::UInt8 = typemax(UInt8)
int16::Int16 = typemax(Int16)
uint16::UInt16 = typemax(UInt16)
int32::Int32 = typemax(Int32)
uint32::UInt32 = typemax(UInt32)
int64::Int64 = typemax(Int64)
uint64::UInt64 = typemax(UInt64)
int128::Int128 = typemax(Int128)
uint128::UInt128 = typemax(UInt128)

subtypes(Signed)
subtypes(Unsigned)

##
# floating-point numbers
float16::Float16 = 3.14
float32::Float32 = 3.1415
float64::Float64 = 3.14159

subtypes(AbstractFloat)

##
# zero and one
one1 = one(Int64)
println(one1)
zero0 = zero(Float64)
println(zero0)
