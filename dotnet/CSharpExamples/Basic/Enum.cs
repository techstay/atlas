#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

var light = TrafficLight.Red;

var signal = light switch
{
  TrafficLight.Red => "Stop",
  TrafficLight.Yellow => "Caution",
  TrafficLight.Green => "Go",
  _ => "Unknown"
};

Console.WriteLine($"The traffic light is: {signal}");

enum TrafficLight
{
  Red,
  Yellow,
  Green
}
