package basics

import "fmt"

func add(a, b int) int {
	return a + b
}

func swap(a, b int) (int, int) {
	return b, a
}

func divide(a, b int) (quotient, remainder int) {
	quotient = a / b
	remainder = a % b
	return
}

func factorial(n int) int {
	if n == 1 || n == 0 {
		return 1
	} else {
		return factorial(n-1) * n
	}
}

func Function() {
	fmt.Printf("%d*%d=%d\n", 3, 4, add(3, 4))
	a, b := 3, 4
	fmt.Printf("交换前 (%d,%d)\n", a, b)
	a, b = swap(a, b)
	fmt.Printf("交换后 (%d,%d)\n", a, b)
	q, r := divide(5, 3)
	fmt.Printf("5/3=%d..%d\n", q, r)
	fmt.Printf("fact(5)=%d\n", factorial(5))
}
