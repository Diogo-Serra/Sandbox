#!/usr/bin/env python3

"""
#1
easy
Coordinate unpacking
Define a tuple point = (10, 25, -3) representing x, y, z.
Unpack it into three variables and print each axis label with its value
Hint: x, y, z = point
"""


def ex1() -> None:
    coordinate = (10, 25, -3)

    x, y, z = coordinate
    print(x)
    print(y)
    print(z)


ex1()
