package yitian.study.gdk


class Collections {
    static void main(String[] args) {
        //lists()
        //maps()
        ranges()
        operators()
    }

    static void lists() {
        println('列表')
        //定义列表
        def list = [1, 3, 25, 77, 5, 8, 97, 34, 100, 230]

        //访问列表
        println(list[2])

        list[1] = 100
        println(list[2..-1])

        //添加元素
        list << 77
        list << 45
        list.add(12)
        list.addAll([1, 2, 3, 4, 5])
        list += 5
        println(list)

        //删除元素
        list - 77
        //删除下标为6的元素
        list.remove(6)
        list.removeAll([1, 2, 3, 4, 5])
        list -= 5
        println(list)

        //列表排序
        list.sort().reverse()
        println(list)

        //断言
        assert ![]
        assert list
        //迭代
        list.each { print("$it ") }
        println()

        //带序号迭代
        list.eachWithIndex { int e, int index -> print("$index->$e ") }
        println()

        //转换列表
        def multi2 = list.collect { it * 2 }
        println(multi2)

        //和上面等价
        def times2 = list*.multiply(2)
        println(times2)

        //过滤列表
        def greaterThan17 = list.findAll { it > 7 }
        println(greaterThan17)

        //只查找第一个
        def firstGreaterThan7 = list.find { it > 7 }
        println(firstGreaterThan7)

        //判断列表
        assert !list.every { it > 100 }
        assert list.any { it > 100 }

        //求和和最值
        def sum = list.sum()
        println("sum=$sum")
        println("max=${list.max()}")
        println("min=${list.min()}")

        //连接操作
        println([1, 2, 3, 4].join('<->'))

        //累积操作，累加、累乘还有更复杂的操作
        println("累计求和:${[1, 2, 3, 4].inject { s, i -> s + i }}")
        println("累计求积:${[1, 2, 3, 4].inject { s, i -> s * i }}")

        //集合操作
        def list1 = [1, 2, 3, 4]
        def list2 = [2, 3, 5, 4, 23, 2]
        println("求交:${list1.intersect(list2)}")
        println("2出现了几次:${list2.count(2)}")
        println("有几个奇数:${list2.count { it % 2 != 0 }}")

        //无相交元素
        assert [1, 2, 3].disjoint([4, 5, 6])

        //重复元素
        println("[1,2]重复两遍是什么:${[1, 2] * 2}")
        println("[1,2]重复4遍是什么:${[1, 2].multiply(4)}")
    }

    static void maps() {
        println("Map")
        def map = [:]
        //添加元素
        map[7] = 7
        map.put(8, 8)
        (1..6).each { map[it] = it }

        //遍历元素
        println(map)
        map.each { entry -> println("key:$entry.key,value:$entry.value") }
        map.eachWithIndex { Map.Entry<Object, Object> entry, int index ->
            println("index:$index,key:$entry.key,value:$entry.value")
        }
        map.each { key, value ->
            println("key:$key,value:$value")
        }

        //集合
        println("keys:${map.keySet()}")
        println("entries:${map.entrySet()}")
        println("values:${map.values()}")

        //分组
        def list = [1, 2, 3, 4, 5, 6]
        def group = list.groupBy { it % 2 == 0 }
        println("分组后的结果:$group")

        //获取字符串键值
        def couples = [amy: 'leo', king: 'lily', smith: 'lisa']
        println(couples['king'])
        println(couples.smith)

        //字符串键要特别注意
        def name = 'yitian'
        def people = [name: 24]
        println(people)
        //使用括号才能正确将变量的值用作键
        people = [(name): 24]
        println(people)

        //不要用GString作为键，它和String的哈希值不同
        def s = '1234'
        def gs = "${s}"
        println("GString hash:${gs.hashCode()},String hash:${s.hashCode()}")

        //放进去再用String取是读不出来的
        def m = [(gs): 123]
        assert m[s] == null
    }

    static void ranges() {
        def range = 1..10
        println(range)

        //开闭区间
        def range2 = 1..<10
        range2.each { print "$it " }
        println()

        //范围的起止
        println("起:${range.from},止:${range.to}")

        //范围继承了List接口
        assert range instanceof List

        println("第二个和最后第二个元素:${range[1, -2]}")
        println("第二个到倒数第二个:${range[1..-2]}")

        println("3是否在范围内:${3 in range}")

        //范围可用于switch
        def marriedYears = 15
        switch (marriedYears) {
            case 1..5:
                println("小夫妻")
                break
            case 6..10:
                println("老夫妻")
                break
            case 11..30:
                println("老夫老妻")
                break
            default:
                println("成仙了")

        }
    }

    static void operators() {
        //切片运算符
        def list = 1..100
        println("倒数十个元素:${list[-10..-1]}")

        //展开运算符，也就是将两个集合展开合并为一个
        def list2 = [1, 2, 3, *(4..10)]
        println(list2)

        //星点操作符，用于选定一个集合中的某个属性
        def people = [[name: 'yitian'], [name: 'zhang3'], [name: 'li4']]
        println("所有名字是:${people*.name}")
    }
}
