Public Module Arrays
    Sub Arrays()

        '下标0-9的十个元素的数组
        Dim array1(9) As Integer
        '11X11的二维数组
        Dim array2(2, 2) As Integer
        '定义并初始化数组
        Dim array3() = {1, 2, 3, 4, 5}
        '锯齿数组，也就是数组的数组
        Dim array4 As Integer()() = New Integer(1)() {}
        array4(0) = New Integer() {1, 2}
        array4(1) = New Integer() {3, 4}
        '初始化一维数组
        For i As Integer = 0 To 9
            array1(i) = i
        Next

        '初始化二维数组
        For i = 0 To 2
            For j = 0 To 2
                array2(i, j) = (i + 1)*(j + 1)
            Next
        Next


        '显示数组
        For Each e In array1
            Console.Write(e)
        Next
        Console.WriteLine

        For i As Integer = 0 To 2
            For j = 0 To 2
                Console.Write(array2(i, j))
            Next
            Console.WriteLine
        Next

        For Each e In array3
            Console.Write(e)
        Next
        Console.WriteLine
        For i As Integer = 0 To 1
            For j = 0 To 1
                Console.Write(array4(i)(j))
            Next
            Console.WriteLine
        Next
    End Sub
End Module
