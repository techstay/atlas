/* -------------------------------------------------------------------------- */
/*                                   Tuples                                   */
/* -------------------------------------------------------------------------- */

// Defining a tuple
val tuple1 = (1, "hello", 3.14)

// Decomposing a tuple
val (i, s, d) = tuple1
println(s"i: $i, s: $s, d: $d")

// Pattern matching with tuples
tuple1 match
  case (1, ss, dd) =>
    println(s"Matched tuple with i: 1, s: $ss, d: $dd")
  case _ =>
    println("No match found")
