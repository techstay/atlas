package yitian.study.other

import groovy.json.JsonOutput
import groovy.json.JsonSlurper

import java.time.LocalDate


class JsonParser {
    static void main(String[] args) {
        parseSimpleObject()
        parseSimpleJson()
        parseArrays()
        parseComplexObject()
        parseComplexJson()
    }

    static void parseSimpleObject() {
        def book = new Book(id: 1, name: 'Thinking in Java')
        def jsonOutput = new JsonOutput()
        def result = jsonOutput.toJson(book)
        println(result)

        //格式化输出
        println(jsonOutput.prettyPrint(result))
    }

    static void parseSimpleJson() {
        def text = '{"id":1,"name":"Thinking in Java"}'
        def jsonSlurper = new JsonSlurper()

        //获取到的是Map对象
        def map = jsonSlurper.parseText(text)
        println(map)
        //将Map转换为实际对象
        def obj = new Book(map)
        println(obj)
    }

    static void parseArrays() {
        def books = [new Book(id: 1, name: 'Thinking in Java')
                     , new Book(id: 2, name: 'Effective Java')]
        def jsonOutput = new JsonOutput()
        def result = jsonOutput.toJson(books)
        println(result)
    }

    static void parseComplexObject() {
        def books = [new Book(id: 1, name: 'Thinking in Java')
                     , new Book(id: 2, name: 'Effective Java')]
        def person = new Person(id: 1, name: 'yitian', books: books)

        def jsonOutput = new JsonOutput()
        def result = jsonOutput.toJson(person)
        println(result)
    }

    static void parseComplexJson() {
        def text = '{"books":[{"id":1,"name":"Thinking in Java"},{"id":2,"name":"Effective Java"}],"id":1,"name":"yitian"}'
        def jsonSlurper = new JsonSlurper()

        def map = jsonSlurper.parseText(text)
        println(map)
    }
}

class Person {
    int id
    String name
    List<Book> books

    @Override
    String toString() {
        "Book(id;$id,name:$name,books:${books})"
    }
}

class Book {
    int id
    String name

    @Override
    String toString() {
        "Book(id:$id,name:$name)"
    }
}