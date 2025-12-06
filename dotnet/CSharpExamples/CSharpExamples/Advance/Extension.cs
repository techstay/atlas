namespace CSharpExamples.Advance;

static class MyExtensions
{
  public static string HelloWorld(this string str)
  {
    return $"Hello, {str} world!";
  }

  public static int DoubleThis(this int number)
  {
    return number * 2;
  }

  // Extension members, new in C# 14
  extension(int number)
  {
    public string Greet() => $"Hello, number {number}!";
  }
}

class ExtensionShowCase
{
  [Test]
  public async Task ExtensionFunction()
  {
    string name = "CSharp";
    var result = name.HelloWorld();
    Console.WriteLine(result);
    await Assert.That(result).IsEqualTo("Hello, CSharp world!");

    int number = 5;
    var num = number.DoubleThis();
    Console.WriteLine(num);
    await Assert.That(num).IsEqualTo(10);
  }

  [Test]
  public async Task ExtensionMember()
  {
    int number = 7;
    Console.WriteLine(number.Greet());
  }
}

