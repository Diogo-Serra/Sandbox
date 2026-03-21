#!/usr/bin/env python3


def ex6():
    list1 = [("pen", 2), ("book", 15), ("laptop", 999)]
    list2 = [(n, p) for n, p in list1 if p <= 15]
    print(list2)


ex6()
