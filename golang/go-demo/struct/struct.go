package main

import "fmt"

type Person struct {
	name string
	age  int
	// anonymous fields
	int
}

func main() {
	// initializing instances
	p1 := Person{"techstay", 18, 20}
	// initializing pointers
	var p2 *Person = &Person{"zhang3", 20, 20}

	fmt.Println(p1)
	fmt.Println(p2)

	// accessing anonymous fields
	fmt.Println(p2.int)
}
