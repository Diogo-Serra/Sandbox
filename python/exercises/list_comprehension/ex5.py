#!/usr/bin/env python3

"""
# Ex 5: Given a list of (name, age) tuples, return just the names
# Input:  [("Alice", 30), ("Bob", 25)]
# Output: ["Alice", "Bob"]
def get_names(people):
    pass  # TODO: unpack the tuple in the for clause
"""


def ex5():
    list1 = [("Alice", 30), ("Bob", 25)]
    list2 = [(n) for n, p in list1]
    print(list2)


ex5()
