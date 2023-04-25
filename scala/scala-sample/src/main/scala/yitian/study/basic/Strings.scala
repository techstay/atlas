package yitian.study.basic

/**
  * 字符串示例
  */
object Strings {
  def main(args: Array[String]): Unit = {
    operateStrings()
    stringInterpolation()
  }

  /**
    * 字符串常用方法
    */
  def operateStrings(): Unit = {
    var string = "  fUck "
    println(string)
    println(string.length)
    println(string.trim)
    println(string.indexOf("u"))
    println(string.lastIndexOf(" "))
    println(string.substring(2, 7))
    println(string.toUpperCase())
    println(string.toLowerCase())
  }

  /**
    * 字符串互操作
    */
  def stringInterpolation(): Unit = {
    val name = "yitian"
    val age = 25

    //内插字符串
    println(s"Hello, $name")
    println(s"Hello, ${name.toUpperCase()}")
    //格式化字符串
    println(f"Hello, I'm $name%s, I'm $age%-5d.")
    //原始字符串
    println(raw"Hey, \n\n\t")

    //自定义互操作符
    println(hello"yitian")
  }

  implicit class HelloStringHelper(val context: StringContext) extends AnyVal {
    def hello(args: Any*): String = s"Hello, ${context.parts.mkString("")}"
  }

}

