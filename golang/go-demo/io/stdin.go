package main

import "fmt"

func main() {
	var a, b string
	fmt.Println("Input a and b:")
	fmt.Scanf("%s %s", &a, &b)
	fmt.Printf("a=%s, b=%s\n", a, b)
}
