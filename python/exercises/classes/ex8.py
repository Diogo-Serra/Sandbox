#!/usr/bin/env python3

class Rectangle:

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def __str__(self):
        return f"Rectangle({self.width}x{self.height})"

    def __eq__(self, other):
        return self.area() == other.area()

    def __lt__(self, other):
        return self.area() < other.area()


def tester():
    rectangle1 = Rectangle(2, 4)
    rectangle2 = Rectangle(4, 8)
    print(rectangle1)
    print(rectangle2)
    print(rectangle1.area())
    print(rectangle2.area())
    print(rectangle1.__eq__(rectangle2))
    print(rectangle1.__lt__(rectangle2))


tester()
