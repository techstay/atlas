# frozen_string_literal: true
# typed: true

require 'date'

# new date and time
date = Date.new(1999, 1, 1)
today = Date.today
datetime = DateTime.new(2008, 3, 4, 12, 0)
now = DateTime.now

# print date
p date
p datetime
puts "year:#{date.year} month:#{date.month} day:#{date.day}"
puts "hour:#{datetime.hour} minute:#{datetime.minute}, day:#{datetime.day}"

today = DateTime.now
that_day = DateTime.new(2023, 1, 1, 0, 0, 0)
difference = today - that_day
puts "2023-1-1 to today is #{difference.to_i} days"
