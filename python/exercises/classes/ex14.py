#!/usr/bin/env python3

class Vector:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, vector):
        self.x += int(vector.x)
        self.y += int(vector.y)

    def __str__(self):
        return f"{self.x} {self.y}"


def tester():
    vector1 = Vector(1, 1)
    print(vector1)
    vector2 = Vector(2, 2)
    print(vector2)
    vector1.__add__(vector2)
    print(vector1)


tester()
