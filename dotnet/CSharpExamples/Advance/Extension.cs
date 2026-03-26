#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

string name = "CSharp";
var greeting = name.HelloWorld();
Console.WriteLine(greeting);
Ensure(greeting == "Hello, CSharp world!", "The extension method result is incorrect.");

int number = 5;
var doubled = number.DoubleThis();
Console.WriteLine(doubled);
Ensure(doubled == 10, "The doubling extension method result is incorrect.");

int memberNumber = 7;
Console.WriteLine(memberNumber.Greet());

static void Ensure(bool condition, string message)
{
  if (!condition)
  {
    throw new InvalidOperationException(message);
  }
}

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

  extension(int number)
  {
    public string Greet() => $"Hello, number {number}!";
  }
}
