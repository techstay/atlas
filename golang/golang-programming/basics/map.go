package basics

import "fmt"

func Map() {
	//创建Map
	map1 := make(map[int]int)
	map1[1] = 1
	map1[2] = 2
	fmt.Println(map1)

	map2 := map[int]int{
		1: 1,
		2: 2,
	}
	fmt.Println(map2)

	//Map操作
	map3 := make(map[int]int)
	//增加
	map3[1] = 1
	//修改
	map3[1] = 2
	//删除
	delete(map3, 1)
	//检查键是否存在
	value, ok := map3[1]
	fmt.Printf("%v %v\n", value, ok)
}
