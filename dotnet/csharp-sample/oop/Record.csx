Person p1 = new(FirstName: "Jack", LastName: "Chen");
Console.WriteLine(p1);

Person p2 = p1 with { Birthday = new DateTime(1993, 1, 25) };
Console.WriteLine(p2);

// records
record Person(string FirstName, string LastName)
{
  // init only setters
  public DateTime Birthday { get; init; }
}
