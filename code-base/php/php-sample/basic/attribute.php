<?php

# declaring attribute class
#[Attribute(Attribute::TARGET_ALL | Attribute::IS_REPEATABLE)]
class MyAttribute
{

}

# attributing other class
#[MyAttribute]
#[MyAttribute(123)]
#[MyAttribute(value: 'abc')]
class MyClass
{
  #[MyAttribute("function attribute")]
  public function do_something()
  {
  }
}

# using reflection to get attributes
$reflection = new ReflectionClass(MyClass::class);
foreach ($reflection->getAttributes() as $attribute) {
  echo("Attribute Name: {$attribute->getName()}\n");
  var_dump($attribute->getArguments());
  var_dump($attribute->getTarget());
}
