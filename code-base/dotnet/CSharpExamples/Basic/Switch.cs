#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

SwitchStatement();
SwitchExpression();

static void SwitchStatement()
{
  var score = 88;
  string result;

  switch (score)
  {
    case 90:
      result = "Excellent";
      break;
    case 80:
      result = "Good";
      break;
    case 70:
      result = "Average";
      break;
    default:
      result = "Needs Improvement";
      break;
  }

  Console.WriteLine($"The number is: {result}");
}

static void SwitchExpression()
{
  var number = 2;
  var result = number switch
  {
    1 => "One",
    2 => "Two",
    3 => "Three",
    _ => "Other"
  };

  Console.WriteLine($"The number is: {result}");
}
