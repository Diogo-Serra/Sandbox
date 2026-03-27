#!/usr/bin/env python3

"""
#2
easy
Swap without temp
Use tuple unpacking to swap two variables a = "hello" and b = "world"
in a single line. 💡 Hint: a, b = b, a
"""


def ex2() -> None:
    t_test = ("Hello", "World")
    a, b = t_test
    a, b = b, a


ex2()
