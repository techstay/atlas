package yitian.study.gdk

import groovy.io.FileType

import java.time.LocalDate


class InputOutput {
    static void main(String[] args) {
        readFiles()
        writeFiles()
        traverseFileTree()
        serializeObjects()
        executeExternalProcess()
    }

    static void readFiles() {
        def baseDir = /C:\Windows\System32\drivers\etc/
        def filename = 'hosts'

        //读取文件
        def file = new File(baseDir, filename)
        file.eachLine {
            println(it)
        }

        //同时获取行号
        file.eachLine { line, num ->
            println("line $num:$line")
        }

        //获取字节流
        byte[] contents = file.bytes
        println(contents.join(''))
        //获取行列表
        String[] lines = file.collect { it }
        println(lines.join('\n'))

        def out = new File(currentDir, 'file1.txt')
        //将文件用作输入
        file.withInputStream { stream ->
            out.withOutputStream {
                it.write(stream.bytes)
            }
        }

    }

    static void writeFiles() {
        def currentDir = getCurrentDir()
        def filename = 'test.txt'
        def file = new File(currentDir, filename)

        //最简单的方式写文件，追加
        file << '非常简单的文件'

        //使用输出流
        file.withOutputStream { stream ->
            stream.write([12, 32, 43, 54, 63, 42, 72, 37] as byte[])
        }

        //使用Writer
        file.withWriter { writer ->
            writer.write('呵呵哒')
        }
    }

    static void traverseFileTree() {
        println('遍历文件树')
        def dir = new File('C:\\Windows')

        println('列出所有文件')
        dir.eachFile {
            if (it.isFile()) {
                println(it)
            }
        }

        println('列出所有可执行文件')
        dir.eachFileMatch(~/.*\.exe$/) {
            println(it)
        }

        dir.traverse(
                maxDepth: 0,
                filter: ~/.*\.exe$/,
                type: FileType.FILES) {
            println(it)
        }
    }

    static void serializeObjects() {
        def person = new Person(id: 1, name: 'yitian', birthday: LocalDate.now())

        def file = new File(getCurrentDir(), 'obj.txt')
        file.withObjectOutputStream { it.writeObject(person) }

        def obj
        file.withObjectInputStream { obj = it.readObject() }
        println(obj)

    }

    static void executeExternalProcess() {
        //列出文件
        def userDir = System.properties['user.dir']
        def process = "cmd /c dir ${userDir}".execute()

        if (process.exitValue()) {
            println(process.err.text)
        } else {
            println(process.text)
        }

    }

    static String getCurrentDir() {
        InputOutput.class.getProtectionDomain().getCodeSource().getLocation().getPath()
    }
}

class Person implements Serializable {
    int id
    String name
    LocalDate birthday

    @Override
    String toString() {
        "Person(id=$id,name=$name,birthday=$birthday"
    }
}