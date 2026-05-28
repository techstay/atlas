package tech.techstay.io

import java.io.File

fun main() {
    val path = """C:\Windows"""
    val fileTreeWalk: FileTreeWalk = File(path).walk()
    fileTreeWalk.maxDepth(1)
        .filter { it.isFile }
        .filter { it.extension == "exe" }
        .forEach(::println)
}
