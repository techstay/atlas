Public Module ControllFlow
    Sub ConditionStatement()

        'If语句
        Dim num As Integer = 5
        If num\2 = 0 Then
            Console.WriteLine($"{num} is even")
        Else
            Console.WriteLine($"{num} is odd")
        End If

        '多重If语句
        If num = 1 Then
            Console.WriteLine($"{num} is 1")
        ElseIf num = 2
            Console.WriteLine($"{num} is 2")
        Else
            Console.WriteLine($"{num} is other")
        End If

        '多重选择语句
        Dim c As Char = "c"c
        Select c
            Case "a"c
                Console.WriteLine("a")
            Case "b"c, "c"c
                Console.WriteLine("b or c")
            Case Else
                Console.WriteLine("others")

        End Select
    End Sub

    Sub LoopStatement()

        'Do While语句
        Dim i = 0
        Do While i < 5
            If i = 3 Then
                Exit Do
            End If
            Console.Write(i)
            i += 1
        Loop
        Console.WriteLine
        'Do Until语句
        i = 0
        Do Until i > 5
            If i < 3 Then
                i += 2
                Continue Do
            End If
            Console.Write(i)
            i += 1
        Loop
        Console.WriteLine

        '循环条件可以放到最后
        i = 0
        Do
            Console.Write(i)
            i += 1
        Loop While i < 5
        Console.WriteLine

        'While循环
        i = 0
        While i < 5
            Console.Write(i)
            i += 1
        End While

        'For循环
        For counter As Integer = 1 To 9 Step 1
            Console.Write(counter)
        Next
        Console.WriteLine

        ‘ForEach循环
        Dim array() as Integer = {1, 2, 3, 4, 5, 6, 7}
        For Each item As Integer In array
            Console.Write(item)
        Next
        Console.WriteLine

        'With语句，用于减少重复代码
        Dim person As Person = New Person
        With person
            .Name = "yitian"
            .Age = 25
            Console.WriteLine($"Person(Name:{.Name}, Age:{.Age})")
        End With
    End Sub

    Sub JumpStatement()
        'Exit语句
        Dim n As Integer = 5
        While n <= 5
            If n = 3
                Exit While
            End If
            n += 1
        End While

        'Continue语句
        While n <= 5
            If n = 3
                n += 2
                Continue While
            End If
            n += 1
        End While

        'Goto语句
        GoTo Ending
        Console.WriteLine("Print something")
        Ending:
        Console.WriteLine("This is end.")
    End Sub
End Module

Public Class Person
    Public Property Name As String
    Public Property Age As Integer
End Class