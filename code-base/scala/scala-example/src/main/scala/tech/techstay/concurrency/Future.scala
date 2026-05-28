package tech.techstay.concurrency

import scala.concurrent.ExecutionContext.Implicits.global
import scala.concurrent.Future
import scala.util.{Failure, Success}
import scala.util.control.Breaks._

// Using Futures to execute long-running tasks asynchronously
def aLongWorkingTask(): Future[Int] = Future {
  Thread.sleep(1000)
  42
}

@main def futures(): Unit =
  val result = aLongWorkingTask()
  result.onComplete {
    case Success(x) => println(s"the result is $x")
    case Failure(e) => e.printStackTrace()
  }

  breakable {
    while (true) {
      if result.isCompleted then break
    }
  }

  // Joining multiple Futures together
  val f1 = Future {
    Thread.sleep(300); 1
  }
  val f2 = Future {
    Thread.sleep(400); 2
  }
  val f3 = Future {
    Thread.sleep(1500); 3
  }

  val sum =
    for
      r1 <- f1
      r2 <- f2
      r3 <- f3
    yield r1 + r2 + r3

  sum.onComplete {
    case Success(x) =>
      println(s"the sum is ${x}")
    case Failure(e) => e.printStackTrace()
  }
  // wait for the result
  Thread.sleep(1600)
