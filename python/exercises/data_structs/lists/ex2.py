#!/usr/bin/env python3

"""
#2
easy
Slicing scores
Given scores = [88, 42, 95, 73, 61, 100, 55], use slicing to get the first 3
the last 2, and every other score. 💡 Hint: list[start:stop:step]
"""


def ex2() -> None:
    scores = [88, 42, 95, 73, 61, 100, 55]
    print(scores[:3])
    print(scores[-2:])
    print(scores[3:-2])


ex2()
