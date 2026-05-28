# frozen_string_literal: true
# typed: true

# Person
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end
  attr_accessor :name, :age

  def to_s
    "Person(name:#{@name}, age:#{@age})"
  end
end

p = Person.new 'jackson', 20

puts p
