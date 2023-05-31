Imports System
Imports Xunit

Namespace VisualBasicStudyTest
  Public Class BasicTest
    <Fact>
    Sub TestComment()
      'a single line comment
      REM this is also a single line comment
    End Sub
    <Fact>
    Sub TestOperator()
      Assert.Equal(1, 6 \ 4)
      Assert.Equal(1.5, 6 / 4)
    End Sub
    <Fact>
    Sub TestDataType()
      Dim b As Byte = 1
      Dim sh As Short = 100
      Dim i As Integer = 2
      Dim l As Long = 3000

      Dim s As Single = 3.14
      Dim d As Double = 3.14159

      Dim c As Char = "a"c
      Dim str As String = "abcd"

      Dim bool As Boolean = True

    End Sub
  End Class
End Namespace



