namespace CSharpExamples.Type;

class TupleShowCase
{
  [Test]
  public void NamedTuples()
  {
    // create a tuple
    var person = (Name: "Alice", Age: 30, IsEmployed: true);

    // access tuple elements
    Console.WriteLine($"Name: {person.Name}");
    Console.WriteLine($"Age: {person.Age}");
    Console.WriteLine($"Is Employed: {person.IsEmployed}");

    // deconstruct a tuple
    var (name, age, isEmployed) = person;
    Console.WriteLine($"Deconstructed - Name: {name}, Age: {age}, Is Employed: {isEmployed}");
  }

  [Test]
  public void UnnamedTuples()
  {
    // create an unnamed tuple
    var point = (10, 20);

    // access tuple elements by Item1, Item2, etc.
    Console.WriteLine($"X: {point.Item1}");
    Console.WriteLine($"Y: {point.Item2}");

    // deconstruct an unnamed tuple
    var (x, y) = point;
    Console.WriteLine($"Deconstructed - X: {x}, Y: {y}");
  }
}
