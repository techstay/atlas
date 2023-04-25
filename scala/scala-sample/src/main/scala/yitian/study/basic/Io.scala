package yitian.study.basic

import scala.io.{Source, StdIn}

/**
  * 输入输出
  */
object Io {
  def main(args: Array[String]): Unit = {
    consoleIo()
    fileIo()
  }

  /**
    * 控制台读写
    */
  def consoleIo(): Unit = {
    var line = StdIn.readLine()
    println(line)

    Console.print(line)
  }

  /**
    * 文件读写
    */
  def fileIo(): Unit = {
    val hosts = raw"C:\Windows\System32\drivers\etc\hosts"
    Source.fromFile(hosts).foreach {
      print
    }
  }
}
