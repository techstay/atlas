package main

import "fmt"

type LazyGenerator struct {
	ch      chan int
	counter int
}

func getGenerator() *LazyGenerator {
	obj := &LazyGenerator{ch: make(chan int)}
	go func() {
		for {
			obj.ch <- obj.counter
			obj.counter++
		}
	}()
	return obj
}

func (this *LazyGenerator) Generate() int {
	return <-this.ch
}

func main() {
	counter := getGenerator()
	for i := 0; i < 5; i++ {
		fmt.Println(counter.Generate())
	}
}
