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
    coordinate = (10.0, 25.0, -3.0)

    print(type(coordinate))
    x, y, z = coordinate
    print(f"X: {x}")
    print(f"Y: {y}")
    print(f"Z: {z}")


ex1()
