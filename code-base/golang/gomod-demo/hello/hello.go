package hello

import "fmt"

const PI = 3.1415

var hello_string string = "Hello, World!"

func Hello(s string) string {
	return fmt.Sprintf("Hello, %s", s)
}
