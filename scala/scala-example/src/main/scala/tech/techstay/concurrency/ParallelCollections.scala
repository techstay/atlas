package tech.techstay.concurrency

import scala.collection.parallel.CollectionConverters._

def measureTime[T](block: => T) =
  val start = System.currentTimeMillis()
  val result = block
  val end = System.currentTimeMillis()
  val duration = end - start
  println(s"Time taken: $duration ms")
  result

@main def parallelCollections(): Unit =
  val numbers = (1 to 100000000).toVector.map(BigInt(_))
  val parallelNumbers = numbers.par

  measureTime {
    val sum = parallelNumbers.sum
    println(s"The sum of numbers from 1 to 100,000,000 is: $sum")
  }

  measureTime {
    val sum = numbers.sum
    println(s"The sum of numbers from 1 to 100,000,000 is: $sum")
  }
