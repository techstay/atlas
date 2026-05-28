package tech.techstay.io

import java.io.File

fun main() {
    // reading the whole file
    val filename = """C:\Windows\System32\drivers\etc\hosts"""
    var file = File(filename)
    println(file.readText())

    // reading files by lines
    file.readLines().take(3).forEach(::println)

    // handling lines directly
    file.forEachLine(action = ::println)

    // writing the whole file
    file = File("test.txt")
    file.writeText("some contents.\nsome more contents.\nmore and more contents.\n")

    // appending contents to files
    file.appendText("appending contents.")

    // deleting files finally
    file.delete()

}
