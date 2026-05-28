from decimal import Decimal

number1 = 0.0
number2 = Decimal("0")

for i in range(10000):
    number1 += 0.01
    number2 += Decimal("0.01")

print(number1)
print(number2)
