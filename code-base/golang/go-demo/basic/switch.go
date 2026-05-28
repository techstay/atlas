package main

import "fmt"

func main() {
	number := 100

	switch {
	case number < 60:
		fmt.Println("failed")
	case 60 <= number && number < 70:
		fmt.Println("pass")
	case 70 <= number && number < 80:
		fmt.Println("good")
	case 80 <= number && number < 90:
		fmt.Println("very good")
	case 90 <= number && number < 100:
		fmt.Println("excellent")
	case number == 100:
		fmt.Println("perfect")
	default:
		fmt.Println("not supported")
	}

	// fallthrough
	number = 3
	switch number {
	case 1:
		fallthrough
	case 2:
		fallthrough
	case 3:
		fallthrough
	case 4:
		fmt.Println("It's one, two, three or four")
	default:
		fmt.Println("It's other number")
	}
}
