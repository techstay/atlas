package basics

import "fmt"

type Person struct {
	age  int
	name string
}

func Struct() {
	fmt.Println("初始化结构体")
	p1 := Person{24, "易天"}
	p2 := Person{age: 24, name: "易天"}
	p3 := Person{age: 24}
	p4 := Person{name: "张三"}
	fmt.Println(p1, p2, p3, p4)

	p1.age = 26
	p1.name = "王五"
	fmt.Println(p1)

}
