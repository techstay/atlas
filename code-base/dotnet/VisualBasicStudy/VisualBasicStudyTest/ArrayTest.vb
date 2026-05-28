Imports Xunit

Public Class ArrayTest
  <Fact>
  Sub TestArray()
    ' initializing an arrya of which index from 0 to 9
    Dim array1(9) As Integer
    Assert.Equal(10, array1.Length)

    Dim array2 = {1, 2, 3, 4, 5}
    Assert.Equal(5, array2.Length)
  End Sub
End Class
