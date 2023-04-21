package main

import (
	"fmt"
	"reflect"
)

type Struct1 struct {
	// the right-hand string is called 'tag'
	name string "The name of the struct"
	id   int    "The id of the struct"
}

func (this *Struct1) F() {
	fmt.Println("F function in Struct1")
}

func main() {
	var instance interface{} = Struct1{"techstay", 1}
	typeOfInstance := reflect.TypeOf(instance)
	valueOfInstance := reflect.ValueOf(instance)

	fmt.Printf("Type: %v\n", typeOfInstance)
	for i := 0; i < valueOfInstance.NumField(); i++ {
		fmt.Printf("Field %d\t %v\t Tag: %v\n", i, valueOfInstance.Field(i), typeOfInstance.Field(i).Tag)
	}
}
