# typed: true

# replacing whole strings
s1 = 'some strings'
p s1.replace 'other strings'

# repeating strings
p 'ha' * 3

# inserting into strings
p s1.insert 0, 'some '

# remove the trailing character
s2 = 'some strings!'
p s2.chop

# remove the record seperator which is by default \n
s3 = "some strings\n"
p s3.chomp

# reversing strings
p 'abcd'.reverse
