package yitian.study.basic

/**
  * 面向对象编程
  */
object Oop {
  def main(args: Array[String]): Unit = {
    objectShowCase()
    inheritances()
    singleton()
    traitClass()
  }

  def objectShowCase(): Unit = {
    val info = new PersonInfo
    info.name = "yitian"
    info.age = 25
    info.show()
  }

  def inheritances(): Unit = {
    val person1 = new Person("yitian", 25)
    println(person1)

    val teacher1 = new Teacher(1, "zhang3", 39)
    println(teacher1)

    val student1 = new Student("zhang4", 24)
    //该方法未实现
    //student1.study()

    val goodStudent1 = new GoodStudent("xiaoming", 14)
    goodStudent1.study()
  }

  def singleton(): Unit = {
    val singleton1 = Singleton.getObj
    val singleton2 = Singleton.getObj

    println(singleton1 == singleton2)
  }

  def traitClass(): Unit = {
    val artStudent = new ArtStudent("yitian", 25)
    artStudent.show()

  }
}

class PersonInfo() {
  private var _name: String = ""
  private var _age: Int = 0

  /**
    * getter
    *
    * @return
    */
  def name: String = _name

  /**
    * setter，注意特殊语法
    *
    * @param value
    */
  def name_=(value: String): Unit = {
    _name = value
  }

  def age: Int = _age

  def age_=(value: Int): Unit = {
    _age = value
  }

  def show(): Unit = {
    println(s"Info[name:${_name}, age:${_age}]")
  }

}

/**
  * 继承
  *
  * @param name
  * @param age
  */
class Person(
              val name: String,
              val age: Int) {
  override def toString: String = s"Person(name:$name, age:$age)"

  def show(): Unit = {
    println(s"My name is $name, I'm $age years old")
  }
}

class Teacher(
               private val teacherId: Int,
               name: String,
               age: Int) extends Person(name, age) {
  override def toString: String = s"Teacher(id:$teacherId, name:$name, age:$age)"
}


class Student(name: String, age: Int) extends Person(name, age) {
  /**
    * 三个问号表示方法未实现
    */
  def study(): Unit = ???
}

class GoodStudent(name: String, age: Int) extends Student(name, age) {
  override def study(): Unit = println(s"$name is studying")
}

/**
  * 单例对象
  *
  */
object Singleton {
  private val obj: String = "Singleton"

  def getObj: String = obj
}

/**
  * 特征类，类似于Java的抽象类
  * 但是可以继承多个特征类
  */
trait Dancer {
  def dance(): Unit = println("I can dance")
}

trait Singer {
  def sing(): Unit = println("I can sing")
}

class ArtStudent(name: String, age: Int) extends Dancer with Singer {

  def show(): Unit = {
    dance()
    sing()
  }
}