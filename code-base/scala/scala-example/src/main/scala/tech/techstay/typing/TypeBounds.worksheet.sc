/* -------------------------------------------------------------------------- */
/*                              Upper Type Bounds                             */
/* -------------------------------------------------------------------------- */

abstract class Animal:
  def name: String
  override def toString: String = name

abstract class Pet extends Animal
class Dog extends Pet:
  def name: String = "Dog"
class Cat extends Pet:
  def name: String = "Cat"
class Lion extends Animal:
  def name: String = "Lion"

class PetContainer[T <: Pet](pet: T):
  def getPet: T = pet

val dogContainer = PetContainer[Dog](Dog())
val catContainer = PetContainer[Cat](Cat())
// The following line would cause a compile error because Lion is not a Pet
// val lionContainer = PetContainer[Lion](Lion())

println(s"Dog container has pet: ${dogContainer.getPet}")
println(s"Cat container has pet: ${catContainer.getPet}")

/* -------------------------------------------------------------------------- */
/*                              Lower Type Bounds                             */
/* -------------------------------------------------------------------------- */

trait List[+A]:
  def prepend[B >: A](elem: B): NonEmptyList[B] = NonEmptyList(elem, this)

case class NonEmptyList[A](head: A, tail: List[A]) extends List[A]
object Nil extends List[Nothing]

trait Bird
case class AfricanSwallow() extends Bird
case class EuropeanSwallow() extends Bird

val africanSwallows: List[AfricanSwallow] = Nil.prepend(AfricanSwallow())
val swallowsFromAntarctica: List[Bird] = Nil
val someBird: Bird = EuropeanSwallow()

// assign swallows to birds
val birds: List[Bird] = africanSwallows

// add some bird to swallows, `B` is `Bird`
val someBirds = africanSwallows.prepend(someBird)

// add a swallow to birds
val moreBirds = birds.prepend(EuropeanSwallow())

// add disparate swallows together, `B` is `Bird` because that is the supertype common to both swallows
val allBirds = africanSwallows.prepend(EuropeanSwallow())
