package main

import "fmt"

func plus(a int, b int) int {
	return a + b
}

// returning multiple values
func swap(a, b int) (int, int) {
	return b, a
}

// named return variables
func divide(a, b int) (quotient, remainder int) {
	quotient = a / b
	remainder = a % b
	return
}

// recursive functions
func factorial(n int) int {
	if n == 1 || n == 0 {
		return 1
	} else {
		return factorial(n-1) * n
	}
}

// varargs
func greeting(names ...string) {
	for _, v := range names {
		fmt.Printf("%s ", v)
	}
	fmt.Println()
}

func main() {
	fmt.Printf("plus(3, 4) = %d\n", plus(3, 4))
	a, b := 3, 4
	a, b = swap(a, b)
	fmt.Printf("a, b = %d, %d\n", a, b)
	quotient, remainder := divide(6, 4)
	fmt.Printf("%d / %d = %d .. %d\n", 6, 4, quotient, remainder)
	fmt.Printf("5! = %d\n", factorial(5))
	greeting("techstay")
	greeting("techstay", "zhang3", "li4")
}
