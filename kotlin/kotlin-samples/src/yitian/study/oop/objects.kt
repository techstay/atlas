package yitian.study.oop

import java.util.concurrent.Executors

fun main(args: Array<String>) {
    val threadPool = Executors.newCachedThreadPool()
    threadPool.execute(MyTask)
    threadPool.shutdown()

    val config1 = MySingleton
    val config2 = MySingleton
    println("两个单例是否相同:${config1 === config2}")
}

//object用作匿名对象
object MyTask : Runnable {
    override fun run() {
        println("Hello ${Thread.currentThread().name}")
    }

}

//Object作为单例对象
object MySingleton : Config {
    override val config: String
        get() {
            return "This is my config"
        }
}

interface Config {
    val config: String
}