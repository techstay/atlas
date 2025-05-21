package tech.techstay.oop

case class Secret(secret: String)

// Companion object or class can access private members of its companion
object Secret:
  def printSecret(secret: Secret): Unit =
    println(s"Secret is: ${secret.secret}")

@main def companionObject(): Unit =
  val secret = Secret("abcdefg")
  Secret.printSecret(secret)
