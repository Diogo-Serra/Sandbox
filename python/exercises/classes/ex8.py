#!/usr/bin/env python3

class Rectangle:

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def __str__(self):
        return f"{self.width} x {self.height}"

    def __eq__(self, other):
        area1 = self.area()
        area2 = other.area()
        return (area2 - area1)

    def __It__(self, other):
        return (self.area() < other.area())


def tester():
    rectangle1 = Rectangle(2, 4)
    rectangle2 = Rectangle(4, 8)
    print(rectangle1)
    print(rectangle2)
    print(rectangle1.area())
    print(rectangle2.area())
    print(rectangle1.__eq__(rectangle2))
    print(rectangle1.__It__(rectangle2))


tester()
