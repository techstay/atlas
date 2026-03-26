#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

NamedTuples();
UnnamedTuples();

static void NamedTuples()
{
  var person = (Name: "Alice", Age: 30, IsEmployed: true);

  Console.WriteLine($"Name: {person.Name}");
  Console.WriteLine($"Age: {person.Age}");
  Console.WriteLine($"Is Employed: {person.IsEmployed}");

  var (name, age, isEmployed) = person;
  Console.WriteLine($"Deconstructed - Name: {name}, Age: {age}, Is Employed: {isEmployed}");
}

static void UnnamedTuples()
{
  var point = (10, 20);

  Console.WriteLine($"X: {point.Item1}");
  Console.WriteLine($"Y: {point.Item2}");

  var (x, y) = point;
  Console.WriteLine($"Deconstructed - X: {x}, Y: {y}");
}
