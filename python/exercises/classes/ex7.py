#!/usr/bin/env python3

class Calc:

    def __init__(self):
        pass

    def add(self, *numbers):
        total = 0
        for n in numbers:
            total += n
        return total

    def multiply(self, *numbers):
        total = 1
        for n in numbers:
            total *= n
        return total

    def power(self, base, exponent=2):
        return (base ** exponent)


def tester():
    calc = Calc()
    print(calc.add(1, 2, 3))
    print(calc.multiply(2, 4))
    print(calc.power(2))


tester()
