package main

import (
	"fmt"
	"time"
)

func main() {
	// closures, aka anonymous functions
	times := func(a, b int) int {
		return a * b
	}
	divide := func(a, b int) int {
		return a / b
	}
	fmt.Printf("%d * %d = %d\n", 2, 3, times(2, 3))
	fmt.Printf("%d / %d = %d\n", 6, 4, divide(6, 4))

	measureTime := func(f func()) {
		start := time.Now()
		f()
		fmt.Printf("time used: %v\n", time.Since(start))
	}
	measureTime(func() {
		time.Sleep(50 * time.Millisecond)
	})

	measureTime(func() {
		time.Sleep(300 * time.Millisecond)
	})
}
