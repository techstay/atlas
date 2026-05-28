Imports Xunit
Imports VisualBasicStudy.Functions

Public Class FunctionTest
  <Fact>
  Sub GreetTest()
    Dim name = "techstay"
    Assert.Equal("Hello, techstay", Greet(name))
  End Sub
  <Fact>
  Sub RecursionTest()
    Assert.Equal(120, Factorial(5))
  End Sub
  <Fact>
  Sub ReturnTest()
    Assert.Equal(1, ReturnOne())
    Assert.Equal(2, ReturnTwo())
  End Sub
  <Fact>
  Sub SubOfTest()
    Assert.Equal(6, SumOf(1, 2, 3))
    Assert.Equal(3, SumOf(1, 2))
  End Sub
  <Fact>
  Sub ChangeParameterTest()
    Dim a = 5
    Dim b = 5
    ChangeParameterTo10(a, b)
    Assert.Equal(5, a)
    Assert.Equal(10, b)
  End Sub
End Class
