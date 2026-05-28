package main

import (
	"fmt"
	"regexp"
)

func main() {
	searchInString := "abc bbc bbbc ccc bcbc"
	ok, error := regexp.MatchString("\\w*c\\s?", searchInString)
	if error != nil {
		fmt.Println(error)
		return
	}
	fmt.Println(ok)

	pattern, error := regexp.Compile("\\w{2}c")
	if error != nil {
		fmt.Println(error)
		return
	}
	// FindAllString takes an int parameter n, returns all matched
	// if n < 0
	result := pattern.FindAllString(searchInString, -1)
	fmt.Println(result)
}
