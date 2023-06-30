var animals = new List<Animal>
{
  new Cat("kitty"),
  new Bird("jack"),
  new Cat("pussy"),
  new Bird("lucy")
};

foreach (var animal in animals)
{
  animal.Run();

  switch (animal)
  {
    case Bird b:
      b.Speak();
      b.Fly();
      break;
    case Cat c:
      c.Speak();
      break;
  }
}


abstract class Animal
{
  public abstract string Name { get; set; }
  public abstract void Run();
}

class Cat : Animal, ICanSpeak
{
  public override string Name { get; set; }

  public Cat(string name)
  {
    Name = name;
  }

  public override void Run()
  {
    System.Console.WriteLine($"Cat {Name} can run");
  }

  public void Speak()
  {
    System.Console.WriteLine($"Cat {Name} meows");
  }
}

class Bird : Animal, ICanSpeak, ICanFly
{
  public override string Name { get; set; }

  public Bird(string name)
  {
    Name = name;
  }

  public override void Run()
  {
    System.Console.WriteLine($"Bird {Name} can run on the ground");
  }

  public void Speak()
  {
    System.Console.WriteLine($"Bird {Name} chirps");
  }

  public void Fly()
  {
    System.Console.WriteLine($"Bird {Name} flies in the sky");
  }
}

interface ICanSpeak
{
  void Speak();
}

interface ICanFly
{
  void Fly();
}
