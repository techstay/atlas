package tech.techstay.basic

def rank = 'a'
switch (rank) {
  case 'a':
    println('very good')
    break
  case 's':
    println('excellent')
    break
}

rank = 's'
// switch pattern matching
println switch (rank) {
  case 's' -> 'excellent'
  case 'a' -> 'very good'
  case 'b' -> 'good'
  case 'c' -> 'not bad'
  case 'd' -> 'bad'
  case String -> "I don't know"
}
