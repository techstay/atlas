# %%

import datetime
from pprint import pprint

from whenever import Date, Instant, OffsetDateTime, PlainDateTime, ZonedDateTime

# The Instant stands for timestamp the UTC time
now = Instant.now()
pprint(now)

time1 = Instant.from_utc(1989, 6, 4, 12, 0, 0)
pprint(time1)

my_timezone = "Asia/Shanghai"
pprint(time1.to_tz(my_timezone))
pprint(time1.to_system_tz())
pprint(time1.to_fixed_offset(8))
# %%

# The PlainDateTime stands for the local time without timezone info
plain_time = PlainDateTime(1989, 6, 4)
pprint(plain_time)

pprint(plain_time.assume_tz(my_timezone))
pprint(plain_time.assume_utc())
pprint(plain_time.assume_fixed_offset(8))
# %%

# The ZonedDateTime stands for the local time with timezone info
zoned_time = ZonedDateTime.now(my_timezone)
pprint(zoned_time)

zoned_time2 = ZonedDateTime(1989, 6, 4, tz=my_timezone)
pprint(zoned_time2)

pprint(zoned_time2.to_fixed_offset(8))
pprint(zoned_time2.to_system_tz())
pprint(zoned_time2.to_plain())
pprint(zoned_time2.to_instant())
# %%

# OffsetDateTime stands for the local time with fixed offset info
offset_time = OffsetDateTime(1989, 6, 4, offset=8)
pprint(offset_time)

pprint(offset_time.to_tz(my_timezone))
pprint(offset_time.to_fixed_offset(0))

# %%

# Integration with the standard library
py_dt = datetime.datetime.now(tz=datetime.timezone.utc)

pprint(Instant.from_py_datetime(py_dt))
pprint((Instant.from_py_datetime(py_dt)).py_datetime())

# %%

# Arithmetic
that_day = ZonedDateTime(1989, 6, 4, tz=my_timezone)
today = ZonedDateTime.now(my_timezone)

delta = today - that_day
pprint(delta)

pprint(delta.in_days_of_24h())
pprint(delta.in_days_of_24h() / 365)
pprint(
    (ZonedDateTime.now(my_timezone).date() - Date(1989, 6, 4)).in_years_months_days()
)

pprint(that_day.add(years=10))
# %%

# Formatting and parsing

that_day = OffsetDateTime(1989, 6, 4, offset=8)
pprint(that_day.format_iso())
pprint(that_day.format_rfc2822())

pprint(OffsetDateTime.parse_iso("1989-06-04T00:00:00+08:00"))
pprint(OffsetDateTime.parse_rfc2822("Sun, 04 Jun 1989 00:00:00 +0800"))

# %%
