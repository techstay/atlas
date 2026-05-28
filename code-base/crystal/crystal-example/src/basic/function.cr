def add(a : Int32, b : Int32) : Int32
  a + b
end

p! add(1, 2)

def sum(*args : Int32)
  total = 0
  args.each do |arg|
    total += arg
  end
  total
end

p! sum(1, 2, 3, 4, 5)
