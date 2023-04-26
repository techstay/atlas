Public Module Functions
    Sub Hello(name As String)
        Console.WriteLine($"Hello,{name}")
    End Sub

    Function Factorial(n As Integer) As Integer
        If n = 1 Or n = 0
            Return 1
        Else
            Return Factorial(n - 1)*n
        End If
    End Function

    '函数返回值可以用Return语句
    Function Return1() As Integer
        Return 1
    End Function

    '也可以向函数名赋值
    Function Return2() As Integer
        Return2 = 2
    End Function

    Function PrintIntegers(ParamArray integers As Integer())
        For Each i In integers
            Console.Write(i)
        Next
        Console.WriteLine
    End Function

    Function GetParam(ByVal a As Integer, ByRef b As Integer)
        a = 10
        b = 10
        Console.WriteLine("Param changed")
    End Function

    Sub Functions()
        Console.WriteLine($"5!={Factorial(5)}")
        Dim a = 1
        Dim b = 2
        GetParam(a, b)
        Console.WriteLine($"a={a}, b={b}")

        PrintIntegers(1, 3, 4)
        PrintIntegers(1)
    End Sub
End Module
