#!/usr/bin/env python3

"""
easy
Shopping cart
Create a list of 5 grocery items. Add 2 more items, remove one
by name, and print the final list sorted alphabetically.
"""


def ex1() -> None:
    grocery_list = [
        "Fruit1",
        "Fruit2",
        "Fruit3",
        "Fruit4",
        "Fruit5",]

    grocery_list.append("Banana")
    grocery_list.append("Tomato")
    print(grocery_list)
    grocery_list.remove("Fruit3")
    grocery_list.sort()
    print(grocery_list)


ex1()
