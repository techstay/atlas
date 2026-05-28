# frozen_string_literal: true
# typed: true

# MyNum
class MyNum
  def initialize(number)
    @number = number
  end
  attr_accessor :number

  def +(other)
    MyNum.new(@number + other.number)
  end

  def -(other)
    MyNum.new(@number - other.number)
  end

  def to_s
    "MyNum(#{@number})"
  end
end

n1 = MyNum.new 6
n2 = MyNum.new 4
n3 = MyNum.new 3

p n1 + n2 - n3
puts n1 - n2 + n3
