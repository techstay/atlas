##

using Test

@test true

@test 1 + 1 == 2

@test 1 + 1 == 3 skip = true

@test_throws BoundsError [1, 2][100]

##
f1(x) = x

@testset "these are some tests" begin
  @test 1 + 1 == 2
  @test 1 + π ≈ 4.1415926
  @test π ≈ 3.1 rtol = 1e-1
  @test f1(1) == 1
end
