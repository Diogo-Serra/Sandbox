#!/usr/bin/env python3

"""
# Ex 6: Given a list of (item, price) tuples, return items that cost more than 10
# Input:  [("pen", 2), ("book", 15), ("laptop", 999)]
# Output: [("pen", 2)]     -- wait, re-read! We want CHEAP items
# Actually: [("pen", 2)]
# Correction - return tuples where price <= 10
def cheap_items(products):
    pass  # TODO: unpack AND filter
"""


def ex6():
    list1 = [("pen", 2), ("book", 15), ("laptop", 999)]
    list2 = [(n, p) for n, p in list1 if p <= 15]
    print(list2)


ex6()
