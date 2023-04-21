package main

import "fmt"

type struct1 struct {
	id   int
	name string
}

// this is a method with receiver type before the method name
func (this *struct1) Hello() {
	fmt.Printf("Hello, %s\n", this.name)
}

// equivalent to Java's toString method
func (this *struct1) String() string {
	return fmt.Sprintf("struct1{id:%d, name:%s}", this.id, this.name)
}

func main() {
	obj := &struct1{1, "techstay"}
	obj.Hello()
	fmt.Printf("%v\n%T\n%#v\n", obj, obj, obj)
}
