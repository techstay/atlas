name = "techstay"
greeting = f"Hello {name}!"


def print_header(header: str, width: int = 80):
    print(f"{header:=^{width}}")


print_header("Magical F-strings")
print(greeting)

big_n = 100000000000
print(f"{big_n:,}")
print(f"{big_n:_}")

print_header("F-strings with expressions")
print(f"{name = }")
print(f"{name.upper() = }")

a, b = 6, 4
print(f"{a + b = }")
