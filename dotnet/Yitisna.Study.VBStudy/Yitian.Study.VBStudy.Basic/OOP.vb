Public Module OOP
    Function Oop()
        Dim contact1 = New Contact("yitian", "")
        contact1.Tel = "1231231234"
        Console.WriteLine(contact1)

        Dim redCircle = New RedCircle(1)
        Console.WriteLine($"Color is {redCircle.Color_GetColor()}, Area is {redCircle.GetArea()}")
    End Function
End Module

Class Contact
    ' 字段
    Private _name As String
    Private _tel As String

    '构造函数
    Public Sub New(name As String, tel As String)
        _name = name
        _tel = tel
    End Sub

    '析构函数
    Protected Overrides Sub Finalize()
    End Sub

    '属性
    Public Property Tel As String
        Get
            Return _tel
        End Get
        Set
            _tel = value
        End Set
    End Property

    Public Property Name As String
        Get
            Return _name
        End Get
        Set(value As String)
            _name = value
        End Set
    End Property

    '重写方法
    Public Overrides Function ToString() As String
        Return $"Contact(Name:{Name}, Tel:{Tel})"
    End Function
End Class

MustInherit Class Shape
    MustOverride Function GetArea() As Double
End Class

Interface Color
    Function GetColor() As String
End Interface

Class Circle
    Inherits Shape
    Protected radius As Double

    Public Sub New(r As Double)
        radius = r
    End Sub

    Public Overrides Function GetArea() As Double
        Return Math.PI*radius*radius
    End Function
End Class

NotInheritable Class RedCircle
    Inherits Circle
    Implements Color

    Public Sub New(r As Double)
        MyBase.New(r)
    End Sub

    Public Function Color_GetColor() As String Implements Color.GetColor
        Return "Red"
    End Function
End Class

Class MyMath
    Public Shared PI As Double = 3.1415926

    Public Shared Function GetPI As Double
        Return PI
    End Function
End Class