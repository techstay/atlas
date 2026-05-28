from typing import Union


def sun_angle(time: str) -> Union[float, str]:
    hours, minutes = map(int, time.split(":"))
    if hours < 6 or hours > 18 or (hours == 18 and minutes > 0):
        return "I don't see the sun!"
    return (hours - 6) * 15 + minutes * 0.25


print("Example:")
print(sun_angle("07:00"))

assert sun_angle("07:00") == 15
assert sun_angle("12:15") == 93.75

print("The mission is done! Click 'Check Solution' to earn rewards!")
