# frozen_string_literal: true
# typed: true

# a simple class
class Utility
  # default public
  def f1; end

  protected

  def f2; end

  private

  def f3; end

  public

  def f4
    # private methods can only be called inside class
    # and cannot be used with self receiver
    f3
    # protected methods can be called by self or directly
    f2
  end
end

u = Utility.new
u.f1
# u.f2
# u.f3
u.f4
