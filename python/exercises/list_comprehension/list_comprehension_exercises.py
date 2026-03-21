#!/usr/bin/env python3
"""
List Comprehension Exercises
=============================
Progressive exercises to master list comprehensions.
Each exercise has a TODO for you to fill in and a test to verify.

Pattern reminder:
    [expression for variable in iterable if condition]

Which is the same as:
    new_list = []
    for variable in iterable:
        if condition:
            new_list.append(expression)
"""


# ============================================================================
# LEVEL 1: Basic list comprehensions
# ============================================================================

# Ex 1: Return a list of all numbers doubled
# Input:  [1, 2, 3, 4]
# Output: [2, 4, 6, 8]
def double_all(numbers):
    pass  # TODO: one-line list comprehension


# Ex 2: Return only even numbers from the list
# Input:  [1, 2, 3, 4, 5, 6]
# Output: [2, 4, 6]
def only_evens(numbers):
    pass  # TODO: list comprehension with a condition


# Ex 3: Return the lengths of each word
# Input:  ["hi", "hello", "hey"]
# Output: [2, 5, 3]
def word_lengths(words):
    pass  # TODO


# Ex 4: Return all strings uppercased, but only if they start with 'a'
# Input:  ["apple", "banana", "avocado", "cherry"]
# Output: ["APPLE", "AVOCADO"]
def upper_a_words(words):
    pass  # TODO: need both a transformation AND a filter


# ============================================================================
# LEVEL 2: Tuple unpacking in list comprehensions
# ============================================================================

# Ex 5: Given a list of (name, age) tuples, return just the names
# Input:  [("Alice", 30), ("Bob", 25)]
# Output: ["Alice", "Bob"]
def get_names(people):
    pass  # TODO: unpack the tuple in the for clause


# Ex 6: Given a list of (item, price) tuples, return items that cost more than
# Input:  [("pen", 2), ("book", 15), ("laptop", 999)]
# Output: [("pen", 2)]     -- wait, re-read! We want CHEAP items
# Actually: [("pen", 2)]
# Correction - return tuples where price <= 10
def cheap_items(products):
    pass  # TODO: unpack AND filter


# Ex 7: Given a list of (product, quantity) tuples, return the total cost
#        where each product is just a price (number).
#        This one is NOT a list comprehension — use sum() with a
#        generator expression instead.
# Input:  [(10, 3), (5, 2)]   means: price=10 qty=3, price=5 qty=2
# Output: 40                  because 10*3 + 5*2 = 40
def total_cost(price_qty_pairs):
    pass  # TODO: sum(expression for p, q in ...)


# ============================================================================
# LEVEL 3: Filtering objects (like the shopping cart)
# ============================================================================

class Item:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def __repr__(self):
        return f"Item({self.name}, {self.price})"


# Ex 8: Given a list of Item objects, return only items under a max price
# Input:  [Item("a", 5), Item("b", 20), Item("c", 8)], max_price=10
# Output: [Item("a", 5), Item("c", 8)]
def items_under(items, max_price):
    pass  # TODO: filter objects by attribute


# Ex 9: Remove a specific item from the list BY IDENTITY (use `is not`)
#        Return a NEW list without that item.
# This is exactly the pattern from the shopping cart!
# Input:  items=[item1, item2, item3], target=item2
# Output: [item1, item3]
def remove_by_identity(items, target):
    pass  # TODO: this is the pattern you asked about


# Ex 10: Given a list of (Item, quantity) tuples, remove ALL tuples
#         where the Item's name matches a given name.
#         Return the filtered list.
# Input:  [(Item("pen", 2), 5), (Item("book", 15), 1)], name="pen"
# Output: [(Item("book", 15), 1)]
def remove_by_name(item_pairs, name):
    pass  # TODO: unpack tuple, filter by object attribute


# ============================================================================
# LEVEL 4: Building new structures
# ============================================================================

# Ex 11: Given a list of (Item, quantity) tuples, return a list of strings
#         formatted as "name x quantity"
# Input:  [(Item("pen", 2), 5), (Item("book", 15), 1)]
# Output: ["pen x5", "book x1"]
def format_cart(item_pairs):
    pass  # TODO: unpack tuple, build f-string


# Ex 12: Given a list of (Item, quantity) tuples, return a dict
#         mapping item name to total cost (price * quantity).
#         Use a DICT comprehension: {key: value for ...}
# Input:  [(Item("pen", 2), 5), (Item("book", 15), 1)]
# Output: {"pen": 10, "book": 15}
def cart_to_dict(item_pairs):
    pass  # TODO: dict comprehension with tuple unpacking


# ============================================================================
# TESTS — run this file to check your answers
# ============================================================================

def test(name, got, expected):
    status = "PASS" if got == expected else "FAIL"
    print(f"  [{status}] {name}")
    if got != expected:
        print(f"         Expected: {expected}")
        print(f"         Got:      {got}")


def run_tests():
    print("\n=== LEVEL 1: Basics ===")
    test("double_all", double_all([1, 2, 3, 4]), [2, 4, 6, 8])
    test("double_all empty", double_all([]), [])
    test("only_evens", only_evens([1, 2, 3, 4, 5, 6]), [2, 4, 6])
    test("only_evens none", only_evens([1, 3, 5]), [])
    test("word_lengths", word_lengths(["hi", "hello", "hey"]), [2, 5, 3])
    test("upper_a_words", upper_a_words(["apple", "banana", "avocado",]),
         ["APPLE", "AVOCADO"])

    print("\n=== LEVEL 2: Tuple Unpacking ===")
    test("total_cost", total_cost([(10, 3), (5, 2)]), 40)
    test("total_cost single", total_cost([(7, 1)]), 7)

    print("\n=== LEVEL 3: Filtering Objects ===")
    a, b, c = Item("a", 5), Item("b", 20), Item("c", 8)
    test("items_under", items_under([a, b, c], 10), [a, c])
    test("remove_by_identity", remove_by_identity([a, b, c], b), [a, c])

    p1, p2 = (Item("pen", 2), 5), (Item("book", 15), 1)
    test("remove_by_name", remove_by_name([p1, p2], "pen"), [p2])

    print("\n=== LEVEL 4: Building Structures ===")
    i1 = (Item("pen", 2), 5)
    i2 = (Item("book", 15), 1)
    test("format_cart", format_cart([i1, i2]), ["pen x5", "book x1"])
    test("cart_to_dict", cart_to_dict([i1, i2]), {"pen": 10, "book": 15})

    print()


run_tests()
