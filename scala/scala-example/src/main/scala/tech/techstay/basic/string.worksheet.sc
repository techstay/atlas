/* -------------------------------------------------------------------------- */
/*                                   Strings                                  */
/* -------------------------------------------------------------------------- */

val name = "techstay"
val age = 18

"My name is " + name + ", my age is " + age

// string interpolation
s"My name is ${name.toUpperCase()}, my age is $age"

s"Dollars: $$${100.0}"

s"""{"name": "${name.toUpperCase()}", "age": $age}"""

// raw strings
raw"abcde$name/\55"

// f strings
f"My name is $name%s, my age is $age%d"
