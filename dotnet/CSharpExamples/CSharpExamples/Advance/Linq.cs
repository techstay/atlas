namespace CSharpExamples.Advance;

class LinqShowCase
{
  [Test]
  public void LinqFunction()
  {
    // Sample data
    var numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Use LINQ to filter even numbers and project their squares
    var evenSquares = numbers
      .Where(n => n % 2 == 0)
      .Select(n => n * n);

    // Print the results
    Console.WriteLine("Even squares:");
    foreach (var square in evenSquares)
    {
      Console.WriteLine(square);
    }
  }

  [Test]
  public void LinqQueryExpression()
  {
    // Sample data
    var numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Use LINQ query expression to filter even numbers and project their squares
    var evenSquares = from n in numbers
                      where n % 2 == 0
                      select n * n;

    // Print the results
    Console.WriteLine("Even squares:");
    foreach (var square in evenSquares)
    {
      Console.WriteLine(square);
    }
  }
}
