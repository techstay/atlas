#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

ListOperations();

static void ListOperations()
{
  List<int> numbers = new() { 1, 2, 3, 4, 5 };
  var n2 = new List<int> { 1, 2, 3, 4, 5 };
  List<int> n3 = [1, 2, 3, 4, 5];

  Console.WriteLine($"Other list counts: {n2.Count}, {n3.Count}");

  numbers.Add(6);
  numbers.AddRange(new[] { 7, 8, 9 });

  Console.WriteLine($"First element: {numbers[0]}");
  Console.WriteLine($"Count: {numbers.Count}");

  Console.WriteLine("All elements:");
  foreach (var number in numbers)
  {
    Console.WriteLine(number);
  }

  numbers.Remove(3);
  numbers.RemoveAt(0);

  Console.WriteLine("Elements after removal:");
  foreach (var number in numbers)
  {
    Console.WriteLine(number);
  }
}
