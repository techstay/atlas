using Shouldly;
using Xunit;
using Xunit.Abstractions;

namespace csharp_sample.advance;

public class PatternMatching(ITestOutputHelper output)
{
  [Fact]
  public void TestTypePattern()
  {
    object obj = "abc";
    output.WriteLine(obj.ToString());

    if (obj is string str)
    {
      str.ShouldBe("abc");
    }

    obj.ShouldBe("abc");
  }

  [Fact]
  public void TestRelationalPattern()
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
    str.ShouldBe("perfect");
  }

  [Fact]
  public void TestListPattern()
  {
    int[] list = { 1, 2, 3 };
    (list is [1, 2, 3]).ShouldBeTrue();
    (list is [0 or 1, > 1, > 2]).ShouldBeTrue();
    (list is [> 2, > 3, > 4]).ShouldBeFalse();
  }
}
