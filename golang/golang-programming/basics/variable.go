package basics

import "fmt"

//变量可以定义为包级别的，也可以定义为方法级别的

//变量的类型在变量之后，如果不初始化则为默认零值
var age int

//如果初始化，变量类型可以由初始化值推断
var name = "yitian"

//如果一行声明多个变量且类型相同，可以只在最后一个变量上添加类型，该规则在方法参数声明上同样适用
var x, y int

func hey() {
	//在方法内部声明局部变量，可以使用快速声明方式 :=，不使用var关键字
	k := 5
	fmt.Printf("k=%d", k)

}

//类型转换，所有类型转换都必须显式转换
var count int = int(32.0)

//常量使用const定义，不能使用:=方式
const Pi = 3.1415926
