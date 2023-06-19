struct Person
{
  string name;
  int age;
}

// all fields in readonly structs should be readonly
readonly struct Employee
{
  readonly string name;
  readonly int age;
}
