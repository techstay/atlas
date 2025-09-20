from time import strftime, strptime


def date_time(time: str) -> str:
    t = strptime(time, "%d.%m.%Y %H:%M")
    date_str = f"{t.tm_mday} {strftime('%B', t)} {t.tm_year} year"
    time_str = f"{t.tm_hour} hour{'' if t.tm_hour == 1 else 's'} {t.tm_min} minute{'' if t.tm_min == 1 else 's'}"
    return f"{date_str} {time_str}"


print("Example:")
print(date_time("01.01.2000 00:00"))

assert date_time("01.01.2000 00:00") == "1 January 2000 year 0 hours 0 minutes"
assert date_time("09.05.1945 06:07") == "9 May 1945 year 6 hours 7 minutes"

print("The mission is done! Click 'Check Solution' to earn rewards!")
