Imports Xunit
Imports VisualBasicStudy.OOP
Imports Microsoft.VisualStudio.TestPlatform.Common

Public Class ClassTest
  <Fact>
  Sub TestContact()
    Dim contact = New Contact("techstay", "")
    contact.Tel = "1231231234"
    Assert.Equal("techstay", contact.Name)
    Assert.Equal("1231231234", contact.Tel)

  End Sub
  <Fact>
  Sub TestCircle()
    Dim redCircle = New RedCircle(1)
    Assert.Equal("Red", redCircle.GetColor())
    Assert.Equal(Math.PI, redCircle.GetArea())
  End Sub
End Class
