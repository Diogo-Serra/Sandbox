#!/usr/bin/env python3

class Calc:

    def __init__(self):
        pass

    def add(*numbers):
        total = 0
        for n in numbers:
            total += n
        return total

    def multiply(*numbers):
        total = 1
        for n in numbers:
            total *= n
        return total

    def power(base, exponent=2):
        return (base ** exponent)


def tester():
    print(Calc.add(1, 2, 3))
    print(Calc.multiply(2, 4))
    print(Calc.power(2))


tester()
