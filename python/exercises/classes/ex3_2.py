#!/usr/bin/env python3

class Person:

    def __init__(self):
        self.__age = None

    def __validate_age(self, new_age):
        return 0 <= new_age <= 150

    @property
    def age(self):
        return f"Age: {self.__age}"

    @age.setter
    def age(self, new_age):
        if not isinstance(new_age, int):
            raise ValueError("Not a digit")
        if not self.__validate_age(new_age):
            raise ValueError("Not a valid age")
        self.__age = new_age

    @age.deleter
    def age(self):
        del self.__age


def tester():
    print("=== Creating Person ===")
    person = Person()

    # Good age
    try:
        person.age = 5
        print(f"Age changed: {person.age}")
    except ValueError as e:
        print(e)

    # Invalid age
    try:
        person.age = -5
        print(f"Age changed: {person.age}")
    except ValueError as e:
        print(e)

    # Invalid age
    try:
        person.age = "a"
        print(f"Age changed: {person.age}")
    except ValueError as e:
        print(e)


tester()
