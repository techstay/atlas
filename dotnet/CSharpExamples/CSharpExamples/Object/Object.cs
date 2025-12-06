namespace CSharpExamples.Object;

class Person
{
  // fields
  private string _name;

  // properties
  public string Name
  {
    get
    {
      return _name;
    }
    set
    {
      _name = value;
    }
  }

  // Auto properties
  public int Age { get; set; }

  // backing fields, new in C# 14
  public string Country
  {
    get => field;
    set => field = value;
  }
}
class ObjectShowCase
{
  [Test]
  public void TestObject()
  {
    var person = new Person();
    person.Name = "John Doe";
    person.Age = 30;
    person.Country = "USA";

    Console.WriteLine($"Name: {person.Name}, Age: {person.Age}, Country: {person.Country}");
  }
}
