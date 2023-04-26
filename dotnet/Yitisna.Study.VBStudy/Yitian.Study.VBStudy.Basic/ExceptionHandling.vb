Public Module ExceptionHandling
    Sub HandleException()
        Try
            Throw New ArithmeticException("除数不能为零")
        Catch ex As ArithmeticException
            Console.WriteLine($"捕获了数学计算异常:{ex.Message}")
        Catch ex As Exception
            Console.WriteLine($"捕获了异常:{ex.Message}")
        Finally

            Console.WriteLine("终结代码")
        End Try
    End Sub
End Module
