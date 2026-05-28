package tech.techstay.basic

try {
  def result = 1 / 0
} catch (ArithmeticException | ClassNotFoundException e) {
  println('in catch block')
  e.printStackTrace()
} finally {
  println('always executed.')
}
