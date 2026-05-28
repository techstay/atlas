# frozen_string_literal: true
# typed: true

# class Person
class Person
  def initialize(name = '')
    @name = name
  end

  attr_reader :name

  def to_s
    "Person(name:#{@name})"
  end
end

person = Person.new 'Jack'
puts person.name
puts person
p person
