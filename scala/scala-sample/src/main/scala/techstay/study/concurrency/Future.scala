package techstay.study.concurrency

import scala.concurrent.ExecutionContext.Implicits.global
import scala.concurrent.Future
import scala.util.{Failure, Success}

@main def futures(): Unit =
  // using futures to execute some long term tasks
  val foo: Future[Int] = Future {
    Thread.sleep(800)
    42
  }
  foo.onComplete {
    case Success(x) => println(s"the result is $x")
    case Failure(e) => e.printStackTrace()
  }

  // multiple futures
  val f1 = Future {
    Thread.sleep(300); 1
  }
  val f2 = Future {
    Thread.sleep(400); 2
  }
  val f3 = Future {
    Thread.sleep(500); 3
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
  Thread.sleep(1000)
