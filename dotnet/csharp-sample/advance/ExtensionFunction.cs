using Shouldly;
using Xunit;
using Xunit.Abstractions;

namespace csharp_sample.advance;

public class ExtensionFunction(ITestOutputHelper output)
{
  private ITestOutputHelper output = output;

  [Fact]
  public void TestExtensionFunction()
  {
    "abc".HelloWorld();
    4.Double().ShouldBe(8);
  }

}

// extension functions

static class Extension
{
  public static void HelloWorld(this string str)
  {
    Console.WriteLine("Hello World!");
  }
  public static int Double(this int integer) => integer * 2;
}


