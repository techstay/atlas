package main

import (
	"fmt"
	"log"
	"math/rand"
	"time"
)

func MeasureTime(fun func()) {
	start := time.Now()
	fun()
	end := time.Since(start)
	log.Printf("Time used: %v\n", end)
}

func F1() int {
	time.Sleep(500 * time.Millisecond)
	return rand.Intn(100) + 1
}

func F2() int {
	time.Sleep(1500 * time.Millisecond)
	return rand.Intn(100) + 1
}

func Future1() chan int {
	ch := make(chan int)
	go func() {
		ch <- F1()
	}()
	return ch
}

func Future2() chan int {
	ch := make(chan int)
	go func() {
		ch <- F2()
	}()
	return ch
}

func main() {
	MeasureTime(func() {
		future1, future2 := Future1(), Future2()
		// this will await until return values are available
		fmt.Printf("Result is %d\n", <-future1+<-future2)
	})
}
