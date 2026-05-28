range1 = 1:5
range2::StepRange = 1:2:10
range3::LinRange = range(-1, 1, length=5)

println(collect(range1))
println(collect(range2))
println(collect(range3))
