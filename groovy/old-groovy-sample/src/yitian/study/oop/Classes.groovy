package yitian.study.oop

class Classes {


    static void main(String[] args) {
        def product = new Product(name: 'AMD Ryzen 1700', price: 2499)
        println("隐式构造器:$product")

        //类使用
        def runner = new FastRunner(id: 1, name: 'yitian')
        println(runner)
        runner.run()

        //使用特性类
        def notebook = new Notebook()
        notebook.read()
        notebook.write("something")

        //调用不存在的属性和方法
        notebook.hello()
        notebook.hello(12, 34, "hehe")
        notebook.pages = 55
        notebook.pages


    }
}

//OOP内容和Java差不多
class Person {
    int id
    String name

    @Override
    String toString() {
        "Person(id=${id},name=${name})"
    }
}

interface HongkongJournalist {
    void run()
}

class FastRunner extends Person implements HongkongJournalist {

    @Override
    void run() {
        println("${name}跑的好快啊")
    }

    @Override
    String toString() {
        "FastRunner(id=${id},name=${name})"
    }
}

class Product {
    String name
    double price

    String toString() {
        "Product(name:$name,price:$price)"
    }
}

trait Readable {
    void read() {
        println("read...")
    }
}

trait Writable {
    void write(String text) {
        println("write $text")
    }
}

trait DynamicInvoke {
    //遇到不存在方法是会调用这个
    def methodMissing(String name, args) {
        def r = "$name($args)"
        println(r)
        r
    }

    def propertyMissing(String name) {
        def r = "$name not found"
        println(r)
        r
    }

    //设置属性时调用这个
    void setProperty(String prop, Object value) {
        println("set $prop with value $value")
    }
}

class Notebook implements Readable, Writable, DynamicInvoke {


}