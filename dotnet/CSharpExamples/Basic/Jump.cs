#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

BreakStatement();
ContinueStatement();

static void BreakStatement()
{
  for (var i = 1; i <= 10; i++)
  {
    if (i == 5)
    {
      break;
    }

    Console.Write($"{i} ");
  }

  Console.WriteLine();
}

static void ContinueStatement()
{
  for (var i = 1; i <= 10; i++)
  {
    if (i % 2 == 0)
    {
      continue;
    }

    Console.Write($"{i} ");
  }

  Console.WriteLine();
}
