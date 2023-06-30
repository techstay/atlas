Person p1 = new("Jack", "Chen");
System.Console.WriteLine(p1);

p1.Greet();
System.Console.WriteLine(p1.FirstName);

_ = new Person();
_ = new Person();
System.Console.WriteLine(Person.GetPeopleCount());

class Person
{
  // fields
  private string _firstName = "";

  // auto implemented properties
  public string LastName { set; get; }

  // static fields
  private static int _peopleCount = 0;

  // constructors
  public Person(string firstName, string lastName) : this()
  {
    _firstName = firstName;
    LastName = lastName;
  }

  // default constructors
  public Person()
  {
    _peopleCount++;
  }

  // properties
  public string FirstName
  {
    get => _firstName;
    set => _firstName = value;
  }

  // methods
  public void Greet()
  {
    System.Console.WriteLine($"Hello, {FirstName} {LastName}");
  }

  // overriding methods
  public override string ToString() => $"Person{{FirstName: {_firstName}, LastName: {LastName}}}";

  // static methods
  public static int GetPeopleCount() => _peopleCount;
}
