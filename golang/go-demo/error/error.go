package main

import (
	"errors"
	"fmt"
	"log"
)

func PositiveMinus(a, b int) (result int, err error) {
	if a < b {
		err = errors.New("invalid arguments error!")
	}
	result = a - b
	return
}

func main() {
	// valid parameters
	result, err := PositiveMinus(6, 4)
	if err != nil {
		log.Println(err)
	} else {
		fmt.Printf("%d - %d = %d\n", 6, 4, result)
	}
	// invalid parameters
	result, err = PositiveMinus(4, 6)

	if err != nil {
		log.Printf("%s\n", err)
	} else {
		fmt.Printf("%d - %d = %d\n", 6, 4, result)
	}

	result, err = PositiveMinus(4, 6)
}
