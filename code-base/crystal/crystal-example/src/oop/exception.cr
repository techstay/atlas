class MyException < Exception
end

begin
  raise MyException.new("something oops!")
rescue ex : MyException
  puts "My Exception: #{ex.message}"
ensure
  puts "Ensure block, codes here will always run"
end
