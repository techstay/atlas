IEnumerable<int> Generator()
{
  for (int i = 0; i < 10; i++)
  {
    yield return i + 1;
  }
}

IEnumerable<int> Generator2()
{
  int i = 0;
  while (true)
  {
    if (i >= 10)
    {
      yield break;
    }
    yield return i++;

  }
}
IEnumerable<int> Generator3()
{
  yield return 10;
  yield return 20;
  yield return 30;
}

// yield generator
foreach (int i in Generator())
{
  System.Console.Write($"{i} ");
}
System.Console.WriteLine();

foreach (int i in Generator2())
{
  System.Console.Write($"{i} ");
}
System.Console.WriteLine();


foreach (int i in Generator3())
{
  System.Console.Write($"{i} ");
}
System.Console.WriteLine();

