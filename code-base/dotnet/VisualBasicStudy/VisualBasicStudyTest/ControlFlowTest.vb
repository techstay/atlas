Imports System.Collections.Specialized
Imports Xunit

Namespace VisualBasicStudyTest
  Public Class ControlFlowTest
    <Fact>
    Sub IfElseTest()
      Dim num = 5
      Dim isOdd As Boolean

      If num \ 2 = 0 Then
        isOdd = False
      Else
        isOdd = True
      End If
      Assert.True(isOdd)

    End Sub
    <Fact>
    Sub IfElseIfTest()
      Dim num = 1
      Dim str As String

      If num = 1 Then
        str = "one"
      ElseIf num = 2 Then
        str = "two"
      Else
        str = "other"
      End If
      Assert.Equal("one", str)
    End Sub
    <Fact>
    Sub SelectTest()
      Dim num = 1
      Dim str As String
      Select Case num
        Case 1
          str = "one"
        Case 2
          str = "two"
        Case Else
          str = "other"
      End Select
      Assert.Equal("one", str)
    End Sub
    <Fact>
    Sub DoWhileTest()
      Dim i = 0
      Dim count = 0
      Do While i < 5
        i += 1
        count += 1
      Loop
      Assert.Equal(5, count)
    End Sub
    <Fact>
    Sub DoUntilTest()
      Dim i = 0
      Dim count = 0
      Do Until i > 5
        i += 1
        count += 1
      Loop
      Assert.Equal(6, count)
      i = 0
      count = 0
      Do
        i += 1
        count += 1
      Loop Until i > 5
      Assert.Equal(6, count)
    End Sub
    <Fact>
    Sub WhileTest()
      Dim i = 0
      Dim count = 0
      While i < 5
        i += 1
        count += 1
      End While
      Assert.Equal(5, count)
    End Sub
    <Fact>
    Sub ForTest()
      Dim count = 0
      For i As Integer = 1 To 9 Step 1
        count += 1
      Next
      Assert.Equal(9, count)
    End Sub
    <Fact>
    Sub ExitTest()
      Dim count = 0
      For i = 1 To 9 Step 1
        count += 1
        If i = 5 Then
          Exit For
        End If
      Next
      Assert.Equal(5, count)
    End Sub
    <Fact>
    Sub ContinueTest()
      Dim count = 0
      For i = 1 To 9
        If i = 5 Then
          Continue For
        End If
        count += 1
      Next
      Assert.Equal(8, count)
    End Sub
    <Fact>
    Sub GotoTest()
      Dim i = 10
      GoTo GOTOHERE
      i = 50
GOTOHERE:
      i = 100
      Assert.Equal(100, i)
    End Sub
    <Fact>
    Sub WithTest()
      Dim p As Person = New Person()
      With p
        .Name = "techstay"
        .Age = 18
      End With
      Assert.Equal(18, p.Age)
      Assert.Equal("techstay", p.Name)
    End Sub
  End Class
  Class Person
    Public Property Name As String
    Public Property Age As Integer
  End Class
End Namespace

