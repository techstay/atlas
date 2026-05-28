package main

import "fmt"

func main() {
	for i := 0; i < 5; i++ {
		fmt.Printf("%d ", i)
	}
	fmt.Println()

	i := 0
	for i < 5 {
		fmt.Printf("%d ", i)
		i++
	}
	fmt.Println()

	// for range
	text := "Hello, Go是一门强大的编程语言"
	for _, char := range text {
		fmt.Printf("%c ", char)
	}
	fmt.Println()

	// forever
	i = 0
	for {
		if i == 2 {
			break
		}
		i++
	}
	fmt.Println("i is now", i)
}
