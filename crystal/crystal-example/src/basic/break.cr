# Break Statement
i = 0
while i < 10
  i += 1
  print "#{i} "
  break if i >= 5
end

puts

# Next Statement
while i < 10
  i += 1
  next if i == 5
  print "#{i} "
end
