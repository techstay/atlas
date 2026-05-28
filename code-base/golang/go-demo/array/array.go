package main

import "fmt"

func main() {
	// declaring arrays and slices

	// array elements is initialized as default values
	arr1 := [5]int{}
	// specifying elements values
	// declaring slices without specifying arrays' length
	arr2 := []int{1, 2, 3, 4, 5}
	arr3 := [...]int{1, 2, 3, 4, 5}
	// initializing some elements, others are default values
	arr4 := [10]int{1, 2, 3, 4, 5}

	// using slices as parameters
	printArray := func(arr []int) {
		for i := 0; i < len(arr); i++ {
			fmt.Printf("%d ", arr[i])
		}
		fmt.Println()
	}
	printArray(arr1[:])
	printArray(arr2)
	printArray(arr3[:])
	printArray(arr4[:])
}
