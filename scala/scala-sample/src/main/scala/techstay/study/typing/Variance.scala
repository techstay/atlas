package techstay.study.typing

import scala.collection.mutable

class Animal
class Cat extends Animal
class Dog extends Animal

// invariance types
class Businessman[T](val inventory: mutable.Stack[T]):
  def sell(): T = inventory.pop()
  def buy(something: T): Unit = inventory.push(something)

// covariance
trait Seller[+T]:
  def sell(): T

// contravariance
trait Buyer[-T]:
  def buy(thing: T): Unit

class SellingBusinessman[T](val inventory: mutable.Stack[T]) extends Seller[T]:
  override def sell(): T = inventory.pop()

class BuyingBusinessman[T](
    val inventory: mutable.Stack[T] = mutable.Stack[T]()
) extends Buyer[T]:
  override def buy(thing: T): Unit = inventory.push(thing)

@main def variance(): Unit =
  // invariance
  // buying and selling are ok
  val catBusinessman: Businessman[Cat] =
    Businessman[Cat](mutable.Stack.fill(3)(Cat()))
  catBusinessman.buy(Cat())
  var cat: Cat = catBusinessman.sell()
  println(cat)

  // covariance
  // buying animals from CatBusinessman
  val animalBusinessman: Seller[Animal] =
    SellingBusinessman[Cat](mutable.Stack.fill(3)(Cat()))
  var animal: Animal = animalBusinessman.sell()
  println(animal)

  // contravariance
  // selling cats to AnimalBusinessman
  val buyingBusinessman = BuyingBusinessman[Animal]()
  val fakeCatBusinessman: Buyer[Cat] = buyingBusinessman
  fakeCatBusinessman.buy(Cat())
  fakeCatBusinessman.buy(Cat())
  // proving he really buys 2 things
  println(buyingBusinessman.inventory.length)
