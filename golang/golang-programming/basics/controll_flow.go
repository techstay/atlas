package basics

import "fmt"

func forStatement() {
	//golang中只有for一种循环
	//for循环不需要小括号，分号是必须的
	for i := 0; i < 5; i++ {
		fmt.Print(i)
	}
	fmt.Println()

	//golang中while循环也是for
	i := 0
	for i < 1000 {
		i++
	}

	//省略其他条件
	i = 0
	for ; i < 1000; {
		i++
	}

	i = 0
	//无限循环
	for {
		if i == 500 {
			break
		}
		i++
	}
}

func ifStatement() {
	//if语句
	var condition = true
	if condition == true {
		fmt.Println("条件为真")
	} else {
		fmt.Println("条件为假")
	}

	//if循环也可以由一个初始化块
	//初始化块中变量的作用域是if块内部
	if i := 0; i == 0 {
		fmt.Println("i==0")
	} else {
		fmt.Println("i!=0")
	}

}

func switchStatement() {
	//switch循环也可以有初始化块
	//每种情况默认break，除非在代码中使用fallthrough
	switch x := 0; x {
	case 0:
		fmt.Println(0)
	case 1:
		fmt.Println(1)
	case 2:
		fallthrough
	case 3:
		fmt.Println("2<=x<=3")
	default:
		fmt.Println("other")
	}

	var i = 0
	//没有代码块默认为switch true，相当于多级if-else
	switch {
	case i == 0:
		fmt.Println("i==0")
	case i == 1:
		fmt.Println("i==1")
	default:
		fmt.Println("other")
	}
}

func deferStatement() {
	//推迟语句，该语句会在所在代码块结束时调用
	//推迟语句的参数求值是立即求值的，只有调用是推迟的
	//如果存在多个推迟语句，按照站的方式执行，即前面的语句后执行
	fmt.Println("使用了资源1")
	defer fmt.Println("释放了资源1")

	fmt.Println("使用了资源2")
	defer fmt.Println("释放了资源2")

	fmt.Println("使用了资源3")
	defer fmt.Println("释放了资源3")

	fmt.Println("使用这些资源处理数据")
}

func ControllFlow() {
	ifStatement()
	switchStatement()
	forStatement()
	deferStatement()
}
