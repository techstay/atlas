namespace CSharpExamples.Advance;

class PatternMatchingShowCase
{
  [Test]
  public void TypePattern()
  {
    object obj = 42;
    if (obj is int number)
    {
      Console.WriteLine($"The number is {number}");
    }
    else
    {
      Console.WriteLine("The object is not an integer.");
    }
  }
  [Test]
  public void RelationalPattern()
  {
    int score = 100;
    var str = score switch
    {
      >= 0 and <= 60 => "failed",
      > 60 and <= 80 => "good",
      > 80 and < 100 => "very good",
      100 => "perfect",
      _ => "something"
    };

    Console.WriteLine($"The performance is: {str}");
  }

  [Test]
  public async Task ListPattern()
  {
    int[] list = { 1, 2, 3 };
    await Assert.That(list is [1, 2, 3]).IsTrue();
    await Assert.That(list is [0 or 1, > 1, > 2]).IsTrue();
    await Assert.That(list is [> 2, > 3, > 4]).IsFalse();
  }
}
