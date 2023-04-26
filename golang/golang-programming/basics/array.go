package basics

import "fmt"

func Array() {
	//声明数组
	var array1 [2]int
	array1[0] = 1
	array1[1] = 2
	fmt.Println(array1)

	//声明的同时初始化
	array2 := [3]int{1, 2, 3}
	fmt.Println(array2)

	//访问数组
	numbers := [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	for i := 0; i < len(numbers); i++ {
		fmt.Print(numbers[i])
	}
	fmt.Println()
}

func Slice() {
	array := [7]int{1, 2, 3, 4, 5, 6, 6}
	var numbers []int = array[:]
	fmt.Println(numbers)
	array[6] = 7
	fmt.Println(numbers)

	numbers2 := []int{1, 2, 3, 4, 5}
	fmt.Println(numbers2)

	fmt.Printf("长度:%d, 容量:%d\n", len(numbers), cap(numbers))

	numbers3 := make([]int, 5, 10)
	fmt.Printf("长度:%d, 容量:%d\n", len(numbers3), cap(numbers3))

	numbers = append(numbers, 8, 9, 10)
	fmt.Println(numbers)
}
func Range() {
	numbers := make([]int, 3)
	for i := range numbers {
		numbers[i] = i
	}
	fmt.Println(numbers)

	for i, v := range numbers {
		fmt.Printf("numbers[%d]=%d\n", i, v)
	}
	fmt.Println()

}
