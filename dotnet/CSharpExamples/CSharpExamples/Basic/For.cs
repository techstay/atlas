namespace CSharpExamples.Basic;

public class ForShowCase
{
  [Test]
  public void ForLoop()
  {
    for (var a = 1; a <= 9; a++)
    {
      for (var b = 1; b <= a; b++)
      {
        Console.Write($"{b}*{a}={a * b}\t");
      }

      Console.WriteLine();
    }
  }

  [Test]
  public void ForEachLoop()
  {
    var list = new List<int> { 1, 2, 3, 4, 5 };
    foreach (var item in list)
    {
      Console.Write($"{item} ");
    }

    Console.WriteLine();
  }
}
