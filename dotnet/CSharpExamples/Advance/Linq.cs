#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

LinqFunction();
LinqQueryExpression();

static void LinqFunction()
{
  var numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  var evenSquares = numbers
    .Where(n => n % 2 == 0)
    .Select(n => n * n);

  Console.WriteLine("Even squares:");
  foreach (var square in evenSquares)
  {
    Console.WriteLine(square);
  }
}

static void LinqQueryExpression()
{
  var numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  var evenSquares =
    from n in numbers
    where n % 2 == 0
    select n * n;

  Console.WriteLine("Even squares:");
  foreach (var square in evenSquares)
  {
    Console.WriteLine(square);
  }
}
