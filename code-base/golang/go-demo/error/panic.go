package main

import "fmt"

func main() {
	positiveNumber := -1
	if positiveNumber < 0 {
		panic("The number should be greater than 0!")
	}
	fmt.Println(positiveNumber)
}
