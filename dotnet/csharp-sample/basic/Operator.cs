using Shouldly;
using Xunit;

namespace csharp_sample.basic;

public class Operator
{
  [Fact]
  public void TestArithmeticOperators()
  {
    var a = 6;
    var b = 4;
    (a + b).ShouldBe(10);
    // integer division
    (a / b).ShouldBe(1);
    // remainder operator
    (a % b).ShouldBe(2);
    // increment and decrement operators
    (a++).ShouldBe(6);
    (++a).ShouldBe(8);

  }
}
