#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

var p1 = new Person("John", "Doe");
var p2 = p1 with { BirthDay = new DateTime(1991, 2, 2) };

Console.WriteLine(p1);
Console.WriteLine($"p1 == p2: {p1 == p2}");
Console.WriteLine(p2);

record Person(string FirstName, string LastName)
{
  public DateTime BirthDay { get; init; }
}
