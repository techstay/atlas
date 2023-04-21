package main

import "fmt"

func setup() {
	fmt.Println("Setting up some resources")
}

func clean() {
	fmt.Println("Cleaning resources")
}

func main() {
	setup()
	defer clean()

	fmt.Println("doing work1")
	fmt.Println("doing work2")
	fmt.Println("doing work3")
}
