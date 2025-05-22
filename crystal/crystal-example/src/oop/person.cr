class Person
  def initialize(name : String, age : Int32)
    @name = name
    @age = age
  end

  def name
    @name
  end

  def age
    @age
  end

  def say_hello
    puts "Hello, my name is #{@name} and I am #{@age} years old."
  end
end

person = Person.new("John", 25)
p! person.name
p! person.age

person.say_hello
