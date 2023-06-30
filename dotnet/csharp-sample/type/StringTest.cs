using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using Shouldly;
using Xunit;

namespace csharp_sample.type;

public class StringTest
{
  [Fact]
  public void TestString()
  {
    string a = "abc";
    // multiline string doesn't contain the starting and ending newline
    string b = """
      abc
      xyz
      """;
    a.ShouldBe("abc");
    b.ShouldBe("abc\r\nxyz");

    // utf8 strings
    _ = "this is an utf8 string"u8;
  }

  [Fact]
  public void TestVerbatimString()
  {
    var c = @"\n\a";
    c.ShouldBe("\\n\\a");
  }

  [Fact]
  public void TestStringInterpolation()
  {
    var name = "jack";
    var age = 18;
    var str = $"Name: {name}, age: {age}, brackets: {{}}";
    str.ShouldBe(string.Format("Name: {0}, age: {1}, brackets: {{}}", name, age));
  }
}
