package main

import "fmt"

// generic functions
func Add[T int | int16 | int32 | int64 | float32 | float64](a, b T) T {
	return a + b
}

func main() {
	// declaring generic types explicitly
	fmt.Printf("%d+%d=%d\n", 8, 1, Add[int](8, 1))
	// generic types can be omitted if possible
	fmt.Printf("%d+%d=%d\n", 3, 5, Add(3, 5))
	// we can see the generic types are working
	fmt.Printf("%f+%f=%f\n", 6.0, 4.0, Add(6.0, 4.0))
}
