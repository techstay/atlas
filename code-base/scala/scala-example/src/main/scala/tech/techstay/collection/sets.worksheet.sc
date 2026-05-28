/* -------------------------------------------------------------------------- */
/*                               Immutable Sets                               */
/* -------------------------------------------------------------------------- */

// Creating Sets
Set(1, 2, 3, 4, 5)
Set.empty[Int]

val set = Set(1, 2, 3, 4, 5)

// Accessing elements
set.contains(3)
set.contains(6)
set.isEmpty
set.size
set.nonEmpty

// Adding elements
set + 6

// Deleting elements
set - 3
set -- Set(2, 4)

// Union and intersection
Set(1, 2, 3) union Set(3, 4, 5)
Set(1, 2, 3) intersect Set(3, 4, 5)
Set(1, 2, 3) diff Set(2, 4)

Set(1, 2, 3) & Set(3, 4, 5)
Set(1, 2, 3) | Set(3, 4, 5)
Set(1, 2, 3) -- Set(2, 4)

// Subset and superset checks
Set(1, 2) subsetOf Set(1, 2, 3)
