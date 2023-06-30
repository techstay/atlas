record Person(string FirstName, string LastName) { }

var p1 = new Person("Jack", "Nard");
System.Console.WriteLine(p1);

var p2 = p1 with { LastName = "Vinci" };
System.Console.WriteLine(p2);
