##
using Dates

d1 = Date(1989, 6, 4)
d2 = today()
dt1 = DateTime(1989)
dt2 = DateTime(Year(1990), Day(5), Month(2))
dt3 = now()

##
yearmonthday(d1)

day(d1)
Day(d1)

dayofweek(d1)
dayname(d1)

monthname(d1)
daysinmonth(d1)

isleapyear(d1)
dayofyear(d1)

quarterofyear(d1)
dayofquarter(d1)

##
@show d1 < d2
@show d2 - d1
@show d2 - d1 |> canonicalize

Date(1989, 6, 4) + Year(10)

Date(1989, 6, 4):Year(1):Date(2023, 1, 1) |> collect

##
firstdayofweek(d1)
lastdayofmonth(d1)
lastdayofquarter(d1)

tonext(d -> dayofweek(d) == Wednesday, d1)
