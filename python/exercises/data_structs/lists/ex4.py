#!/usr/bin/env python3

"""
#4
hard
Matrix transposer
Given a 3×3 matrix as a list of lists, write a function that
returns its transpose — without using zip()
💡 Hint: nested list comprehension with row/col indices
"""


def ex4() -> None:
    col = 4
    row = 5
    matrix = [["x" for col in range(col)] for row in range(row)]
    for m in matrix:
        print(m)


ex4()
