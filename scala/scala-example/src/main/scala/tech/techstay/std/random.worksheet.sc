/* -------------------------------------------------------------------------- */
/*                                   Random                                   */
/* -------------------------------------------------------------------------- */

import scala.util.Random

// Random numbers
Random.nextInt(10)
Random.nextLong()
Random.nextBoolean()
Random.nextPrintableChar()
Random.nextFloat()
Random.nextDouble()
Random.nextGaussian()
Random.nextString(10)
Random.alphanumeric.take(10).mkString

var bytes = new Array[Byte](10)
Random.nextBytes(bytes)
bytes

// Shuffling
val list = List(1, 2, 3, 4, 5)
Random.shuffle(list)

// Setting seeds
val r = new Random(100)
r.nextInt(10)
r.nextInt(10)

Random.setSeed(100L)
Random.nextInt(10)
Random.nextInt(10)
