#!/usr/bin/env python3
from abc import ABC, abstractmethod
from math import pi


class Shape(ABC):

    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def perimeter(self):
        pass


class Circle(Shape):

    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return (pi * (self.radius ** 2))

    def perimeter(self):
        return (2 * pi * self.radius)


class Square(Shape):

    def __init__(self, side):
        self.side = side

    def area(self):
        return (self.side ** 2)

    def perimeter(self):
        return (4 * self.side)


def bonus(objects_list):
    for o in objects_list:
        print(f"Area of {type(o).__name__} {o.area()}")
        print(f"Perimeter of {type(o).__name__} {o.perimeter()}")


def tester():
    circle = Circle(3)
    square = Square(4)

    print("First test")
    print(circle.area())
    print(circle.perimeter())

    print("Second test")
    print(square.area())
    print(square.perimeter())

    print("Testing bonus")
    list_objects = [
        Square(4),
        Circle(3),
        Circle(2),
        Square(2)]
    bonus(list_objects)


tester()
