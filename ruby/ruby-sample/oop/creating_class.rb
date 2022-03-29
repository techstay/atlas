# frozen_string_literal: true
# typed: true

# class Person
class Person
  def initialize(name)
    @name = name
  end

  def get_name
    @name
  end

  def to_s
    "Person(name:#{@name}})"
  end
end

zhang3 = Person.new 'zhang3'
puts zhang3.get_name
puts zhang3
p zhang3
