##
using Random

# rand elements from given collection
rand(1:10)
rand("abcd")

##
# generate random bit arrays
bitrand(5)

##
# normally-distributed random number
randn()

##
# exponential distrubution
randexp()

##
randstring()

##
randsubseq(1:10, 0.2)

randperm(4)

randcycle(4)

shuffle(Vector(1:5))

##

# seeds
Random.default_rng()
Xoshiro(1234)
MersenneTwister(1234)
