#!/usr/bin/env python3

class Animal:

    def __init__(self, species, age, name):
        self.species = species
        self.age = age
        self.name = name

    def make_sound(self):
        return (f"{self.name} makes a sound")


class Cat(Animal):

    def __init__(self, species, age, name, color, indoor):
        super().__init__(species, age, name)
        self.color = color
        self.indoor = indoor

    def make_sound(self):
        return (f"{self.name} says: miau")


def tester():
    animal1 = Animal("cat", 4, "Kovu")
    cat = Cat("cat", 4, "Kovu", "Blue", True)
    print(animal1.make_sound())
    print(cat.make_sound())


tester()
