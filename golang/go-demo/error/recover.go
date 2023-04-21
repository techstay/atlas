package main

import (
	"fmt"
	"log"
)

func MayEncounterPanic() {
	defer func() {
		if e := recover(); e != nil {
			log.Println("Catching error!", e)
		}
	}()

	panic("THIS IS AN ERROR!")
}

func main() {
	fmt.Println("Before Function...")
	MayEncounterPanic()
	fmt.Println("After Function...")
}
