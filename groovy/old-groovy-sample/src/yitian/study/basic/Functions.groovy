package yitian.study.basic

import yitian.study.oop.Objects


class Functions {
    static void main(String[] args) {

        //调用方法
        methodWithDefaultParam()
        methodWithDefaultParam("555", 52)

        //可选的方法括号
        methodWithDefaultParam '555', 42
        //命名参数方法
        methodWithNamedParam(name: "yitian", age: 33)


    }

    static void methodWithDefaultParam(String name = "123", int age = 23) {
        println("name=$name,age=$age")
    }

    static void methodWithNamedParam(Map map) {
        println("name=$map.name,age=$map.age")
    }
}
