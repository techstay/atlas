package main

import (
	"encoding/json"
	"fmt"
	"log"
)

type Person struct {
	id   int
	name string
}

func main() {
	objList := []*Person{{1, "techstay"}, {2, "zhang3"}, {3, "li4"}}
	jsonText, err := json.Marshal(objList)
	if err != nil {
		log.Println("Json marshal error", err)
	}
	// I need to find out why the output is empty
	fmt.Printf("%s\n", jsonText)

	jsonText = []byte(`{"name":"techstay","age":18}`)
	var obj map[string]interface{}
	err = json.Unmarshal(jsonText, &obj)

	if err != nil {
		fmt.Println("Json unmarshal error", err)
	}
	fmt.Println(obj)
}
