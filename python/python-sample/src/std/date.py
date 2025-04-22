# %%
import datetime as dt

today = dt.date.today()
# %%
now = dt.datetime.now()

now
# %%
that_day = dt.date(1989, 10, 1)
period = today - that_day
# %%
period.days
# %%
period.days // 365
# %%
now.astimezone(dt.timezone.utc)
# %%
tz = dt.datetime.now().astimezone().tzinfo

tz
# %%
dt.datetime.now(tz=tz).strftime(r"%Y-%m-%d %H:%M:%S")

# %%
