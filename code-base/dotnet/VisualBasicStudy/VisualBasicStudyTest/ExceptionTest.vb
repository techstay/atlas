Imports VisualBasicStudy
Imports Xunit

Public Class ExceptionTest
  <Fact>
  Sub TestHandlingException()
    Assert.Equal(False, HandleException(1))
    Assert.Equal(True, HandleException(0))
  End Sub
End Class
