package main

import "fmt"

func main() {
	condition := true

	// the parenthese following if keyword can be omitted
	if condition {
		fmt.Println("yes!")
	} else {
		fmt.Println("no!")
	}

	// else if
	integer := 1
	if integer == 2 {
		fmt.Println("It's two.")
	} else if integer == 1 {
		fmt.Println("It's one.")
	} else if integer != 1 && integer != 2 {
		fmt.Println("It's other number.")
	}
}
