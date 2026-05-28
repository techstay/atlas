package tech.techstay.oop

def parseInt(str: String) =
  try Some(Integer.parseInt(str))
  catch case e: Exception => None

def getInt(str: String) =
  parseInt(str) match
    case Some(i) => println(i)
    case None    => println("invalid number")

@main def option(): Unit =
  getInt("3")
  getInt("yes")
