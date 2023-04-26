package basics

import "fmt"

func Pointer() {
	//Go语言支持指针
	//不过不支持指针运算
	a, b := 3, 5
	pa, pb := &a, &b
	fmt.Println(*pa, *pb)
	//隐式解引用
	p1 := &Person{name: "易天", age: 24}
	fmt.Println((*p1).name)
	fmt.Println(p1.name)

}
