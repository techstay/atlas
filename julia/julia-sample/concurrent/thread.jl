##
using Base.Threads

# first check how many threads julia is using
nthreadpools()
nthreads()
threadid()

##
a = zeros(nthreads())
@threads for i = eachindex(a)
  a[i] = threadid()
end

@show a

##

# a bad multithread sum
badsum(a) = begin
  s = 0
  @threads for i = a
    s += i
  end
  s
end

@show badsum(1:1_000_000)

##
goodsum(a) = begin
  chunks = Iterators.partition(a, length(a) ÷ nthreads())
  tasks = map(sum, chunks)
  chunk_sums = fetch.(tasks)
  sum(chunk_sums)
end

@show goodsum(1:1_000_000)
