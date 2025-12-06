namespace CSharpExamples.Object;

class Animal
{
  public string Name { get; set; }
  public void Speak()
  {
    Console.WriteLine($"{Name} the animal speaks");
  }
}

interface IHasLegs
{
  void Walk();
}

interface IHasTail
{
  void WagTail();
}

class Dog : Animal, IHasLegs, IHasTail
{
  public void Walk()
  {
    Console.WriteLine($"Dog {Name} walks on legs");
  }

  public void WagTail()
  {
    Console.WriteLine($"Dog {Name} wags its tail");
  }
}

class Cat : Animal, IHasLegs, IHasTail
{
  public void Walk()
  {
    Console.WriteLine($"Cat {Name} walks on legs");
  }

  public void WagTail()
  {
    Console.WriteLine($"Cat {Name} wags its tail");
  }
}

class InheritanceShowCase
{
  [Test]
  public void Inheritance()
  {
    Dog dog = new() { Name = "Buddy" };
    dog.Speak();
    dog.Walk();
    dog.WagTail();

    Cat cat = new() { Name = "Whiskers" };
    cat.Speak();
    cat.Walk();
    cat.WagTail();
  }
}
