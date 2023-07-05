# is a subtype of
Integer <: Real
Int64 <: Integer

# is type of
isa(128, Int)
isa(128, AbstractFloat)

# type of
typeof(128)

# supertype
supertype(Integer)
supertype(Real)
