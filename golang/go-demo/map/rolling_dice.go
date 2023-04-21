package main

import (
	"fmt"
	"math/rand"
)

func main() {
	// rolling dice
	dice := map[int]int{}
	N := 6000000
	for i := 0; i < N; i++ {
		dice[rand.Intn(6)+1]++
	}

	fmt.Println(dice)
}
