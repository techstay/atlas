# frozen_string_literal: true
# typed: true

# Animal
class Animal
  @@count = 0
  def initialize(name = 'animal')
    @name = name
    @@count += 1
  end

  attr_reader :name

  def to_s
    "Animal{name=#{@name},count=#{@@count}}"
  end
end

# Dog
class Dog < Animal
  def initialize(name = 'dog')
    # super calls the same name method in parent class
    # if no arguments given, super will receive all arguments automatically
    super
  end

  def to_s
    "Dog{name=#{@name}},count=#{@@count}"
  end
end

dog = Dog.new
dog2 = Dog.new
puts dog.name
puts dog2
