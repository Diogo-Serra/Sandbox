#!/usr/bin/env python3


class Dog:
    def __init__(self, name: str, age: int, breed: str) -> None:
        self.name = name
        self.age = age
        self.breed = breed

    def bark(self):
        return f"{self.name} says: Woof!"

    def birthday(self):
        self.age += 1
        return (self.age)


def main():
    dog = Dog("Kovu", 4, "York")
    print(dog.bark())


main()
