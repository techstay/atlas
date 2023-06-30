struct Person
{
  public string Name { get; set; }
  public string Nickname { get; set; }
  public DateTime Birthday { set; get; }

  override public string ToString() => $"Person(Name:{Name}, Nickname:{Nickname}, Birthday:{Birthday})"
}

var person = new Person { Name = "techstay", Nickname = "Tech", Birthday = new DateTime(1993, 1, 12) };
System.Console.WriteLine(person);

var person2 = person with { Name = "techbro" };
System.Console.WriteLine(person2);
