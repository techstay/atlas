#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

var score = 89;

if (score < 60)
{
  Console.WriteLine("Failed");
}
else if (score < 80)
{
  Console.WriteLine("Passed");
}
else
{
  Console.WriteLine("Excellent");
}
