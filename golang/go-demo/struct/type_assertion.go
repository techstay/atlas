package main

import "fmt"

// two interfaces
type IA interface {
	a()
}
type IB interface {
	b()
}

// some struct declaration
type A struct {
	name string
}

type B struct {
	name string
}

type AB struct {
	name string
	A
	B
}

type C struct {
	name string
}

func (this A) a() {
	fmt.Println("implemented a()")
}

func (this B) b() {
	fmt.Println("implemented b()")
}

func main() {
	objects := [4]interface{}{A{"a"}, B{"b"}, C{"C"}, AB{name: "AB"}}

	// type assertion
	if v, ok := objects[3].(IB); ok {
		fmt.Printf("%v is IB\n", v)
	}

	// type switch
	for i := range objects {
		switch t := objects[i].(type) {
		case IA:
			fmt.Printf("%v is IA\n", t)
		case IB:
			fmt.Printf("%v is IB\n", t)
		default:
			fmt.Printf("%v is not IA nor IB\n", t)
		}
	}
}
