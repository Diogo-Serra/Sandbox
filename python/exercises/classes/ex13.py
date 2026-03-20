#!/usr/bin/env python3

class Flyable:

    def fly(self):
        return "Fly!"


class Swimmer:

    def swim(self):
        return "Swim!"


class Duck(Flyable, Swimmer):

    def quack(self):
        return "Quack!"


def tester():
    duck1 = Duck()
    print(duck1.quack())
    print(duck1.fly())
    print(duck1.swim())


tester()
