package tech.techstay.typing

class Stack[A]:
  private var elements: List[A] = Nil

  def push(x: A): Unit =
    elements = x :: elements

  def peek: A = elements.head

  def pop(): A =
    val head = peek
    elements = elements.tail
    head

@main def genericClass(): Unit =
  val stack = Stack[Int]
  stack.push(1)
  stack.push(2)
  stack.push(3)

  println(stack.peek)
  println(stack.pop())
  println(stack.pop())
  println(stack.pop())
