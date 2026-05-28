package main

func main() {
	// bool
	var b bool = true || false

	// signed
	var i8 int8 = 16
	var i16 int16 = 32
	var i32 int32 = 6000
	var i64 int64 = 50000

	// unsigned
	var ui8 uint8 = 255
	var ui16 uint16 = 65535
	var ui32 uint32 = 7777770
	var ui64 uint64 = 11111111111111

	// int
	var i int
	var ui uint

	octal := 01234567
	binary := 0b10101100
	hexadecimal := 0xcafe

	// pointer
	var ptr uintptr

	// byte, alias for int8
	var bb byte

	// rune, unicode code point, alias for int32
	var cp rune

	// float
	var float float32
	var float64 float64

	// complex
	var com64 complex64 = 5 + 6i
	var com128 complex128 = 100 + 200i

	// string
	var str string = "abc"
}
