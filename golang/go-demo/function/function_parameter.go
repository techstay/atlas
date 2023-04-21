package main

import "fmt"

func plus(a, b int) int {
	return a + b
}

func minus(a, b int) int {
	return a - b
}

// functions as parameters
func calculate(fun func(int, int) int, a int, b int) int {
	return fun(a, b)
}

func main() {
	fmt.Printf("%d + %d = %d\n", 3, 5, calculate(plus, 3, 5))
	fmt.Printf("%d - %d = %d\n", 6, 4, calculate(minus, 6, 4))
}
