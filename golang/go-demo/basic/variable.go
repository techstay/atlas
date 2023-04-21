package main

import "fmt"

func main() {
	// defining variables
	var a int
	a = 1
	// defining local variables
	b := 2
	// defining constants
	const PI = 3.1415926

	fmt.Println(a)
	fmt.Println(b)
	c, d := 3, 4
	e := c * d
	fmt.Println(e)
	fmt.Println(PI)
}
