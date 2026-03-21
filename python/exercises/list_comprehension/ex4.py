#!/usr/bin/env python3

"""
# Ex 4: Return all strings uppercased, but only if they start with 'a'
# Input:  ["apple", "banana", "avocado", "cherry"]
# Output: ["APPLE", "AVOCADO"]
def upper_a_words(words):
    pass  # TODO: need both a transformation AND a filter
"""


def ex4():
    list1 = ["apple", "banana", "avocado", "cherry"]
    list2 = [x.upper() for x in list1 if x.startswith("a")]
    print(list2)


ex4()
