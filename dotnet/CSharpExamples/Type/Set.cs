#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

HashSetOperations();

static void HashSetOperations()
{
  HashSet<int> numbers = new() { 1, 2, 3, 4, 5 };

  numbers.Add(6);
  numbers.Add(3);

  Console.WriteLine($"Contains 4: {numbers.Contains(4)}");
  Console.WriteLine($"Count: {numbers.Count}");

  Console.WriteLine("All numbers:");
  foreach (var number in numbers)
  {
    Console.WriteLine(number);
  }

  numbers.Remove(2);

  Console.WriteLine("Numbers after removal:");
  foreach (var number in numbers)
  {
    Console.WriteLine(number);
  }
}
