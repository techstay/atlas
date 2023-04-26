package basics

import "fmt"

func compute(fun func(int, int) int, a int, b int) {
	fmt.Println("计算结果是:", fun(a, b))
}

func getCounter() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}
func Closure() {
	fmt.Println("函数作为参数")
	add := func(a, b int) int {
		return a + b
	}
	compute(add, 3, 4)
	subtract := func(a, b int) int {
		return a - b
	}
	compute(subtract, 3, 4)
	fmt.Println("闭包")

	counter := getCounter()
	fmt.Println(counter())
	fmt.Println(counter())
	fmt.Println(counter())

}
