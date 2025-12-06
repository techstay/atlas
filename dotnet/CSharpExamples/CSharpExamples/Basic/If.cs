namespace CSharpExamples.Basic;

public class IfShowCase
{
  [Test]
  public void If()
  {
    var score = 89;

    if (score < 60)
    {
      Console.WriteLine("Failed");
    }
    else if (score < 80)
    {
      Console.WriteLine("Passed");
    }
    else
    {
      Console.WriteLine("Excellent");
    }
  }
}

