package main

import "fmt"

func main() {
	// creating maps
	map1 := map[string]int{}
	map2 := make(map[string]int)
	// creating and initializing
	map3 := map[string]int{"a": 1, "b": 2, "c": 3}

	fmt.Println(map1)
	fmt.Println(map2)
	fmt.Println(map3)

	// checking presence of key
	if _, ok := map1["a"]; ok {
		fmt.Println("a is present")
	} else {
		fmt.Println("a is not present")
	}

	// deleting elements safely
	if _, ok := map3["a"]; ok {
		delete(map3, "a")
	}
	fmt.Println(map3)

	// iterating over the map
	for key, value := range map3 {
		fmt.Println(key, value)
	}
}
