package yitian.study.io

import java.io.*
import java.net.URL


fun main(args: Array<String>) {
    readAndWriteFromConsole()
    readFile()
    writeFile()
    traverseFileTree()
    readFromNet()
}

fun readFile() {
    val filename = """C:\Windows\System32\drivers\etc\hosts"""
    val file = File(filename)
    val contents = file.readText()
    println(contents)

    //大写前三行
    file.readLines().take(3).forEach {
        println(it.toUpperCase())
    }

    //直接处理行
    file.forEachLine(action = ::println)

    //读取为bytes
    val bytes: ByteArray = file.readBytes()
    println(bytes.joinToString(separator = ""))

    //直接处理Reader或InputStream
    val reader: Reader = file.reader()
    val inputStream: InputStream = file.inputStream()
    val bufferedReader: BufferedReader = file.bufferedReader()
}

fun writeFile() {
    val currentDir = System.getProperty("user.dir") + "\\out"
    val file = File(currentDir, "hehe.txt")
    file.writeText("呵呵呵哈哈哈")
    println(file.readText())

    file.writeBytes(byteArrayOf(12, 56, 83, 57))
    println(file.readText())

    //追加方式写入字节或字符
    file.appendBytes(byteArrayOf(93, 85, 74, 93))
    file.appendText("吼啊")
    println(file.readText())

    //直接使用writer和outputstream
    val writer: Writer = file.writer()
    val outputStream: OutputStream = file.outputStream()
    val printWriter: PrintWriter = file.printWriter()

}

fun readAndWriteFromConsole() {
    println("请输入内容：")
    val line = readLine()
    println("output:$line")

}

fun traverseFileTree() {
    val systemDir = File("""C:\Windows""")
    val fileTree: FileTreeWalk = systemDir.walk()
    fileTree.maxDepth(1)
            .filter { it.isFile }
            .filter { it.extension == "exe" }
            .forEach(::println)

}

fun readFromNet() {
    //返回百度首页
    val baidu = URL("http://www.baidu.com")
    val contents = baidu.readText()
    //println(contents)

    //获取必应首页图片并保存
    //获取XML格式图片信息
    val bing = URL("http://www.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1&mkt=en-US")
    val texts = bing.readText()
    //获取url地址和文件名
    val regex = Regex("""<url>(.*)</url>""")
    val result = regex.find(texts)
    val imageUrl = "http://www.bing.com" + result!!.groupValues[1]
    val filename = imageUrl.substring(imageUrl.lastIndexOf('/'))
    //写入文件
    val output = File(System.getProperty("user.dir") + "\\out", filename)
    val requestUrl = URL(imageUrl)
    output.writeBytes(requestUrl.readBytes())

}