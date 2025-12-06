namespace CSharpExamples.Basic;

class WhileShowCase
{
  [Test]
  public void WhileLoop()
  {
    var count = 1;

    while (count <= 5)
    {
      Console.WriteLine($"Count is: {count}");
      count++;
    }
  }

  [Test]
  public void DoWhileLoop()
  {
    var count = 1;
    do
    {
      Console.WriteLine($"Count is: {count}");
      count++;
    } while (count <= 5);
  }
}
