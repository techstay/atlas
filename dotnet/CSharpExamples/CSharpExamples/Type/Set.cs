namespace CSharpExamples.Type;

class SetShowCase
{
  [Test]
  public void HashSetOperations()
  {
    // create a hash set
    HashSet<int> numbers = new() { 1, 2, 3, 4, 5 };

    // add elements
    numbers.Add(6);
    numbers.Add(3);

    // access elements
    Console.WriteLine($"Contains 4: {numbers.Contains(4)}");
    Console.WriteLine($"Count: {numbers.Count}");

    // iterate through the hash set
    Console.WriteLine("All numbers:");
    foreach (var number in numbers)
    {
      Console.WriteLine(number);
    }

    // remove elements
    numbers.Remove(2);

    Console.WriteLine("Numbers after removal:");
    foreach (var number in numbers)
    {
      Console.WriteLine(number);
    }
  }
}
