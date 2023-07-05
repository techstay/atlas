using Logging

# enable debug Logging
ENV["JULIA_DEBUG"] = Main
@debug "sum([1,2]) is $(sum([1,2]))"

@warn "this is a warning"

m = zeros(Int, 3, 3)
@info "this matrix: " m

@error "this is some errors!" "foo"
