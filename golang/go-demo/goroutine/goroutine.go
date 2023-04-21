package main

import (
	"fmt"
	"time"
)

// simulating some long time work
func HardWork() int {
	time.Sleep(200 * time.Millisecond)
	return 42
}

func DoWorkSequential() int {
	sum := 0
	for i := 0; i < 5; i++ {
		sum += HardWork()
	}
	return sum
}

func DoWorkParallel() int {
	sum := 0
	ch1 := make(chan int)
	for i := 0; i < 5; i++ {
		go func() {
			ch1 <- HardWork()
		}()
	}
	for i := 0; i < 5; i++ {
		sum += <-ch1
	}
	return sum
}

func MeasureTime(fun func()) {
	start := time.Now()
	fun()
	usedTime := time.Since(start)
	fmt.Printf("Used time: %v\n", usedTime)
}

func main() {
	MeasureTime(func() {
		fmt.Printf("DoWorkParallel: %d\n", DoWorkParallel())
	})
	MeasureTime(func() {
		fmt.Printf("DoWorkSequential: %d\n", DoWorkSequential())
	})
}
