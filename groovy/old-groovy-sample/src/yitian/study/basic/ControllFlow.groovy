package yitian.study.basic


class ControllFlow {
    static void main(String[] args) {

        assignment()
        conditionStmt()
        loopStmt()
    }

    static void conditionStmt() {
        def c = true
        if (c) {
            println("true")
        } else {
            println("else")
        }
    }

    static void loopStmt() {
        //传统方式
        for (int i = 0; i < 5; ++i) {
            print("$i ")
        }
        println()

        def list = [1, 2, 3, 4, 5]
        for (int i : list) {
            print("$i ")
        }
        println()

        //for in loop形式
        for (i in list) {
            print("$i ")
        }
        println()

    }

    static void assignment() {
        def i = 200
        int i2 = 13

        //同时赋值
        def (a, b, c) = [12, 23, 45]
        println("a=$a,b=$b,c=$c")

        //对象解构
        def obj = new CustomDestruction(a: 3, b: 4, c: 5)
        def (x, y, z) = obj
        println("x=$x,y=$y,z=$z")
    }
}

class CustomDestruction {
    int a
    int b
    int c
    //解构需要实现getAt方法
    def getAt(int i) {
        switch (i) {
            case 0: a; break
            case 1: b; break
            case 2: c; break
            default: throw new IllegalArgumentException()
        }
    }
}