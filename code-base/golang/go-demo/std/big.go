package main

import (
	"fmt"
	"math/big"
)

func main() {
	// using big.Int for factorial calculation
	factorial := func(n int) *big.Int {
		result := big.NewInt(1)
		for i := 1; i <= n; i++ {
			result.Mul(result, big.NewInt(int64(i)))
		}
		return result
	}
	fmt.Printf("factorial(%d) = %v\n", 100, factorial(100))

	// rational
	fmt.Println(big.NewRat(1, 3).FloatString(100))
}
