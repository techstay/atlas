package yitian.study.function

import java.util.*

fun main(args: Array<String>) {
    //html构造器使用实例
    val text = html(lang = "zh") {
        head {
            script {
                text("alert('123')")
            }
        }
        body {
            h1 {
                text("Hello")
            }
            table {
                thead {
                    tr {
                        th { text("name") }
                        th { text("age") }
                    }
                }
                tbody {
                    tr {
                        td { text("yitian") }
                        td { text("24") }
                    }
                    tr {
                        td { text("liu6") }
                        td { text("16") }
                    }
                }
            }
            p {
                text("This is some words")
            }
        }
    }
    println("html构造器使用实例:\n$text")
}

/*HTML构造器*/
class Attribute(var name: String, var value: String) {
    override fun toString(): String {
        return """$name="$value" """
    }
}

open class Tag(var name: String) {
    val children: MutableList<Tag> = ArrayList()
    val attributes: MutableList<Attribute> = ArrayList()
    override fun toString(): String {
        return """<$name${if (attributes.isEmpty()) "" else attributes.joinToString(prefix = " ", separator = " ")}>
${if (children.isEmpty()) "" else children.joinToString(separator = "\n")}
</$name> """
    }
}

class Text(val text: String) : Tag("") {
    override fun toString(): String = text
}

class Html : Tag("html")
class Body : Tag("body")
class Head : Tag("head")
class Script : Tag("script")
class H1 : Tag("h1")
class Table : Tag("table")
open class TableElement(name: String) : Tag(name)
class Thead : TableElement("thead")
class Tbody : TableElement("tbody")
class Th : Tag("th")
class Tr : Tag("tr")
class Td : Tag("td")
class P : Tag("p")

fun <T : Tag> Tag.doInit(tag: T, init: T.() -> Unit): T {
    tag.init()
    children.add(tag)
    return tag
}

fun <T : Tag> T.set(name: String, value: String?): T {
    if (value != null) {
        attributes.add(Attribute(name, value))
    }
    return this
}

fun html(lang: String = "en", init: Html.() -> Unit): Html = Html().apply(init).set("lang", lang)
fun Html.head(init: Head.() -> Unit) = doInit(Head(), init)
fun Html.body(init: Body.() -> Unit) = doInit(Body(), init)
fun Body.h1(init: H1.() -> Unit) = doInit(H1(), init)
fun Head.script(init: Script.() -> Unit) = doInit(Script(), init)
fun Body.p(init: P.() -> Unit) = doInit(P(), init)
fun Table.thead(init: Thead.() -> Unit) = doInit(Thead(), init)
fun Table.tbody(init: Tbody.() -> Unit) = doInit(Tbody(), init)
fun Body.table(init: Table.() -> Unit) = doInit(Table(), init)
fun TableElement.tr(init: Tr.() -> Unit) = doInit(Tr(), init)
fun Tr.th(init: Th.() -> Unit) = doInit(Th(), init)
fun Tr.td(init: Td.() -> Unit) = doInit(Td(), init)
fun Tag.text(s: Any?) = doInit(Text(s.toString()), {})
