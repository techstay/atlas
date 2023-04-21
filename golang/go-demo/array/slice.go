package main

import "fmt"

func main() {
	// creating slices
	slice1 := make([]int, 10)

	for i := range slice1 {
		slice1[i] = i + 1
	}

	slice2 := make([]int, 5, 10)

	inspectSlice := func(slice []int) {
		fmt.Printf("Slice:%v len=%d cap=%d\n", slice, len(slice), cap(slice))
	}

	inspectSlice(slice1)
	inspectSlice(slice2)

	// appending elements
	slice2 = append(slice2, slice1...)
	inspectSlice(slice2)
}
