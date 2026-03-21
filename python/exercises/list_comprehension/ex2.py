#!/usr/bin/env python3

"""
# Ex 2: Return only even numbers from the list
# Input:  [1, 2, 3, 4, 5, 6]
# Output: [2, 4, 6]
def only_evens(numbers):
    pass  # TODO: list comprehension with a condition
"""


def ex2():
    list1 = [1, 2, 3, 4, 5, 6]
    list2 = [x for x in list1 if x % 2 == 0]
    print(list2)


ex2()
