namespace CSharpExamples.Type;

class ListShowCase
{
  [Test]
  public void ListOperations()
  {
    // create a list
    List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
    var n2 = new List<int> { 1, 2, 3, 4, 5 };
    List<int> n3 = [1, 2, 3, 4, 5];

    // add elements
    numbers.Add(6);
    numbers.AddRange(new int[] { 7, 8, 9 });

    // access elements
    Console.WriteLine($"First element: {numbers[0]}");
    Console.WriteLine($"Count: {numbers.Count}");

    // iterate through the list
    Console.WriteLine("All elements:");
    foreach (var number in numbers)
    {
      Console.WriteLine(number);
    }

    // remove elements
    numbers.Remove(3);
    numbers.RemoveAt(0);

    Console.WriteLine("Elements after removal:");
    foreach (var number in numbers)
    {
      Console.WriteLine(number);
    }
  }
}
