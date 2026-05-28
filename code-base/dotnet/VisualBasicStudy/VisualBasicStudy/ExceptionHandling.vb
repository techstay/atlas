Public Module ExceptionHandling
  Function HandleException(n As Integer) As Boolean
    Dim meetException = False
    Try
      Dim result = 1 \ n
    Catch ex As ArithmeticException
      Console.WriteLine($"捕获了数学计算异常:{ex.Message}")
      meetException = True
    Catch ex As Exception
      Console.WriteLine($"捕获了异常:{ex.Message}")
      meetException = True
    Finally
      Console.WriteLine("终结代码")
    End Try
    Return meetException
  End Function
End Module
