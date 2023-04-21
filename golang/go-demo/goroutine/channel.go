package main

import (
	"fmt"
	"math/rand"
)

func main() {
	ch := make(chan int)
	go SendData(ch)
	GetData(ch)
}

func SendData(ch chan int) {
	for i := 0; i < 5; i++ {
		ch <- rand.Intn(100) + 1
	}
	// close channel manually
	close(ch)
}

func GetData(ch chan int) {
	// for-range will automatically check if channel is closed
	for i := range ch {
		fmt.Printf("Received: %d\n", i)
	}
}
