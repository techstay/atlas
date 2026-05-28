#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

var person = new Person
{
  Name = "John Doe",
  Age = 30,
  Country = "USA"
};

Console.WriteLine($"Name: {person.Name}, Age: {person.Age}, Country: {person.Country}");

class Person
{
  private string _name = string.Empty;

  public string Name
  {
    get => _name;
    set => _name = value;
  }

  public int Age { get; set; }

  public string Country
  {
    get => field ?? string.Empty;
    set => field = value;
  }
}
