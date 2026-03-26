#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

TestGenerateNumbers();

static void TestGenerateNumbers()
{
  var numbers = GenerateNumbers(5);
  foreach (var number in numbers)
  {
    Console.Write($"{number} ");
  }

  Console.WriteLine();

  var evenNumbers = GenerateEvenNumbers();
  foreach (var even in evenNumbers)
  {
    Console.Write($"{even} ");
  }

  Console.WriteLine();

  var finiteNumbers = GenerateNumbers2();
  foreach (var number in finiteNumbers)
  {
    Console.Write($"{number} ");
  }

  Console.WriteLine();
}

static IEnumerable<int> GenerateNumbers(int count)
{
  for (var i = 1; i <= count; i++)
  {
    yield return i;
  }
}

static IEnumerable<int> GenerateEvenNumbers()
{
  yield return 2;
  yield return 4;
  yield return 6;
}

static IEnumerable<int> GenerateNumbers2()
{
  var i = 0;
  while (true)
  {
    i++;
    yield return i;
    if (i >= 5)
    {
      yield break;
    }
  }
}
