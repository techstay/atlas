Public Module Functions
  Function Greet(name As String) As String
    Return $"Hello, {name}"
  End Function

  Function Factorial(n As Integer) As Integer
    If n = 1 Or n = 0 Then
      Return 1
    Else
      Return Factorial(n - 1) * n
    End If
  End Function

  '函数返回值可以用Return语句
  Function ReturnOne() As Integer
    Return 1
  End Function

  '也可以向函数名赋值
  Function ReturnTwo() As Integer
    ReturnTwo = 2
  End Function

  Function SumOf(ParamArray integers As Integer()) As Integer
    Dim sum = 0
    For Each i In integers
      sum += i
    Next
    Return sum
  End Function

  Function ChangeParameterTo10(ByVal a As Integer, ByRef b As Integer)
    a = 10
    b = 10
  End Function

End Module
