#!/usr/bin/env python3

class Person:

    def __init__(self, name):
        self.name = name
        self.age = 18

    def show(self):
        print(f"{self.name}: {self.age}")

    def __str__(self):
        return f"{self.name}: {self.age}"


def main():
    diogo = Person("Diogo")
    diogo.show()
    print(diogo)


main()
