package tech.techstay.typing

import scala.collection.mutable.Stack

private class Animal
private class Cat extends Animal
private class Dog extends Animal

// invariance types
class Merchant[T](inventory: Stack[T]):
  def sell(): T = inventory.pop()
  def buy(something: T): Unit = inventory.push(something)

// covariance
trait Seller[+T]:
  def sell(): T

// contravariance
trait Buyer[-T]:
  def buy(thing: T): Unit

class SellingMerchant[T](inventory: Stack[T]) extends Seller[T]:
  override def sell(): T = inventory.pop()

class BuyingMerchant[T](var inventory: Stack[T]) extends Buyer[T]:
  override def buy(thing: T): Unit = inventory.push(thing)

@main def varianceExample(): Unit =
  // invariance
  // buying and selling are ok
  val catMerchant: Merchant[Cat] = Merchant[Cat](Stack.fill(3)(Cat()))
  catMerchant.buy(Cat())
  var cat: Cat = catMerchant.sell()
  println(cat)

  // covariance
  // buying animals from CatMerchant
  val animalMerchant: Seller[Animal] =
    SellingMerchant[Cat](Stack.fill(3)(Cat()))
  var animal: Animal = animalMerchant.sell()
  println(animal)

  // contravariance
  // selling cats to AnimalMerchant
  val buyingMerchant = BuyingMerchant[Animal](Stack.empty[Animal])
  val fakeCatMerchant: Buyer[Cat] = buyingMerchant
  fakeCatMerchant.buy(Cat())
  fakeCatMerchant.buy(Cat())
  // proving he really buys 2 things
  println(buyingMerchant.inventory.length)
