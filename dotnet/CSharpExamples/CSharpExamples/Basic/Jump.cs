namespace CSharpExamples.Basic;

class JumpShowCase
{
  [Test]
  public void BreakStatement()
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

  [Test]
  public void ContinueStatement()
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
}
