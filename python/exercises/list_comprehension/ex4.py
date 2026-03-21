#!/usr/bin/env python3

def ex4():
    list1 = ["apple", "banana", "avocado", "cherry"]
    list2 = [x.upper() for x in list1 if x.startswith("a")]
    print(list2)


ex4()
