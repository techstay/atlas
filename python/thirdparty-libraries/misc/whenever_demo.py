#%%

from whenever import Instant, LocalDateTime, OffsetDateTime

now=Instant.now()


# %%
now.to_tz("Asia/Shanghai")

# %%
that_day=LocalDateTime(1989,6,4)

# %%
the_day=that_day.assume_tz("Asia/Shanghai")
the_day.add(hours=12)
# %%
the_day.format_common_iso()

# %%
now.format_rfc2822()
# %%
odt=OffsetDateTime.parse_rfc2822("Wed, 16 Apr 2025 10:23:03 +0800")

# %%
