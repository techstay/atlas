namespace CSharpExamples.Basic;

enum TrafficLight
{
  Red,
  Yellow,
  Green
}

class EnumShowCase
{
  [Test]
  public void EnumUsage()
  {
    var light = TrafficLight.Red;

    var signal = light switch
    {
      TrafficLight.Red => "Stop",
      TrafficLight.Yellow => "Caution",
      TrafficLight.Green => "Go",
      _ => "Unknown"
    };
    Console.WriteLine($"The traffic light is: {signal}");
  }
}
