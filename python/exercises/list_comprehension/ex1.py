#!/usr/bin/env python3

"""
# Ex 1: Return a list of all numbers doubled
# Input:  [1, 2, 3, 4]
# Output: [2, 4, 6, 8]
def double_all(numbers):
    pass  # TODO: one-line list comprehension
"""


def ex1():
    list1 = [1, 2, 3, 4]
    list2 = [x * 2 for x in list1]
    print(list2)


ex1()
