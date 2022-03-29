# frozen_string_literal: true
# typed: true

module Module1
  def f1; end
end

module Module2
  def f2; end
end

class Class1
  include Module2
  include Module1
end

c1 = Class1.new
c1.f1
c1.f2
