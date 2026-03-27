#!/usr/bin/env python3

"""
#3
medium
List comprehension filter
From a list of numbers 1–20, use a list comprehension to build a new list with
only numbers divisible by 3 or 5, squared
💡 Hint: [x**2 for x in range(...) if ...]
"""


def ex3() -> None:
    numbers = []
    for i in range(1, 21):
        numbers.append(i)
    print(numbers)
    result = [x for x in numbers if (x % 5 == 0) or (x % 3 == 0)]
    print(result)


ex3()
