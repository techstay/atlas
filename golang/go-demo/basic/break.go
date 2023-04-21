package main

import "fmt"

func main() {
	// break
	for i := 0; i < 10; i++ {
		if i == 5 {
			break
		}
		fmt.Printf("%d ", i)
	}
	fmt.Println()

	// continue
	for i := 0; i < 10; i++ {
		if i == 5 {
			continue
		}
		fmt.Printf("%d ", i)
	}
	fmt.Println()
}
