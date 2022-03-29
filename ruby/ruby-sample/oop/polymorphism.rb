# frozen_string_literal: true
# typed: true

# Animal
class Animal
  def speak
    puts 'animal speak'
  end
end

# Dog
class Dog < Animal
  def speak
    puts 'dog wow wow'
  end
end

# Cat
class Cat < Animal
  def speak
    puts 'cat meow meow'
  end
end

animals = [Animal.new, Dog.new, Cat.new, Dog.new, Cat.new]
animals.each(&:speak)
