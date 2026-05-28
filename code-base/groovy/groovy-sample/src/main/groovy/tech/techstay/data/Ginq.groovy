package tech.techstay.data

def numbers = GQ {
  from n in 1..10
  select n
}.toList()
println("numbers: $numbers")

def squareNumbers = GQ {
  from n in 1..10
  select n**2
}.toList()
println("squareNumbers: $squareNumbers")

def squareOfN = GQ {
  from v in (from n in 1..10
    select n, n**2 as squareOfN)
  select v.n, v.squareOfN
}.toList()
println("squareOfN: $squareOfN")

def distinctNumbers = GQ {
  from n in [1, 2, 3, 4, 5, 5, 2, 3, 4, 1]
  select distinct(n)
}.toList()
println("distinctNumbers: $distinctNumbers")

def evenNumbers = GQ {
  from n in 1..20
  where n % 2 == 0
  select n
}.toList()
println("evenNumbers: $evenNumbers")

def inBothSidesNumbers = GQ {
  from n in numbers
  where n in evenNumbers
  select n
}.toList()
println("inBothSidesNumbers: $inBothSidesNumbers")

def notInBothSidesNumbers = GQ {
  from n in numbers
  where n !in evenNumbers
  select n
}.toList()
println("notInBothSidesNumbers: $notInBothSidesNumbers")

def joinNumbers = GQ {
  from n1 in [1, 2, 3]
  join n2 in [1, 3] on n1 == n2
  select n1, n2
}.toList()
println("joinNumbers: $joinNumbers")

def countNumbers = GQ {
  from n in [1, 2, 3, 3, 2, 2, 4, 5, 5, 6, 6, 6, 6, 6]
  groupby n
  // where number appears 3 times
//  having count() == 3
  select n, count(n)
}.toList()
println("countNumbers: $countNumbers")

def averageOfNumbers = GQ {
  from n in [1, 2, 3, 4, 5, 4, 3, 2, 2, 1]
  select avg(n)
}.toList().first()
println("averageOfNumbers: $averageOfNumbers")

def sortedNumbers = GQ {
  from n in [1, 2, 3, 6, 7, 8, 9, 8, 6, 6, 5, 1]
  orderby n in asc
  select n
}.toList()
println("sortedNumbers: $sortedNumbers")

def paginationOfNumbers = GQ {
  from n in 1..5
  limit 3
  select n
}.toList()
println("paginationOfNumbers: $paginationOfNumbers")

def paginationOfNumbers2 = GQ {
  from n in 1..5
  limit 3, 3
  select n
}.toList()
println("paginationOfNumbers2: $paginationOfNumbers2")
