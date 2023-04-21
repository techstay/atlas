package main

import "fmt"

func main() {
	// pointer
	a, b := 3, 5
	var pa, pb *int = &a, &b

	fmt.Println(a, b)
	fmt.Println(*pa, *pb)

	*pb = 6
	fmt.Println(a, b)
}
