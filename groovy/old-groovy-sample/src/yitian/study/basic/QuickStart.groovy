package yitian.study.basic


class QuickStart {
    static void main(String[] args) {
        comments()
        strings()
        chars()
        numbers()
        lists()
        arrays()
        maps()
        operators()
    }

    static void comments() {
        //单行注释
        /*多行
        注释*/
    }

    static void strings() {
        println("字符串\n")
        String single = '单引号字符串'
        println(single)

        String multiline = '''三个单引号
可跨越多行'''
        println(multiline)
        int i = 5
        //内插字符串
        String special = "i=${i}"
        println(special)

        String equation = "result=${1 + 2 * 3}"
        println(equation)

        //斜杠字符串
        String pattern = /s\w+/
        println(pattern)

        //原始字符串
        String raw = $/line1
line2
/\/\/\/\
/$
        println(raw)
    }

    static void chars() {
        char char1 = 'A'
        char char2 = 'A' as char
        char char3 = (char) 'A'
    }

    static void numbers() {
        //各种整数
        byte b = 1
        char c = 2
        short s = 3
        int i = 10
        long l = 10L
        int bin = 0b110
        int oct = 0175
        int hex = 0xcafe
        BigInteger bigInteger = 10000000000000000000000

        //各种浮点数
        float f = 12.3
        double df = 3.1415926
        BigDecimal bigDecimal = 10.00000000000000000000000001
        double pi = 3.1415926E1

        //后缀类型，和Java类似，不一样的只有g，代表BigXXX
        def bi = 123456G
        assert bi instanceof BigInteger

        def bf = 12345.6
        assert bf instanceof BigDecimal
    }

    static void lists() {
        println("列表\n")
        def list = [1, 2, 3, 4]
        println(list)

        println(list[1])
        println(list[-1])
        list << 5
        println(list[1..3])
    }

    static void arrays() {
        println("数组\n")
        int[] intArray = [1, 2, 3, 4, 5]

        def intArray2 = [1, 2, 3, 4, 5, 6] as int[]

        println(intArray[1..4])
    }

    static void maps() {
        def map1 = ["yitian": 24, "zhang3": 25, "li4": 26]
        assert map1.yitian == 24
        assert map1["li4"] == 26
        def map2 = ["zhang3": 25] as HashMap
        assert map2 instanceof HashMap
    }

    static void operators() {
        println("运算符\n")

        //可空运算符
        def personWithoutName = new Person(name: null, age: 24)
        def name = personWithoutName.name ?: '佚名'
        println(name)

        //安全导航
        def nullPerson = null as Person
        println(nullPerson?.name)

        //直接引用字段
        def person = new Person(name: "yitian", age: 24)
        println("使用属性:${person.nickname}")
        println("直接引用字段:${person.@nickname}")

        //方法引用
        def fun = "abc123".&toUpperCase
        println("方法引用:${fun()}")

        //展开运算符
        def people = [person, new Person(name: 'zhang3', age: 25)]
        def names = people*.name
        println("展开运算符:${names}")

        //范围运算符
        def range = 1..5
        assert range.collect() == [1, 2, 3, 4, 5]

        //比较运算符，相当于调用compareTo方法
        assert (1 <=> 1) == 0

        //成员运算符
        assert 1 in [1, 2, 4, 5]

        //相等运算符
        def p1 = '123'
        def p2 = "${p1}"
        assert p1 == p2
        assert !p1.is(p2)
        //call运算符
        person()
    }
}

class Person {
    String name
    int age
    public String nickname = "2dog"

    String getNickname() {
        return nickname.toUpperCase()
    }

    def call() {
        println("调用Call:Person(name:$name,age:$age)")
    }
}