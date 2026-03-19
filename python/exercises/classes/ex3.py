#!/usr/bin/env python3

class Person:
    def __init__(self):
        self.__age = None

    def __validate_age(self, value):
        """Returns True if 0 <= value <= 150"""
        return 0 <= value <= 150

    @property
    def age(self):
        """Getter - returns __age"""
        return self.__age

    @age.setter
    def age(self, new_age):
        """Setter - validates age before setting"""
        if not isinstance(new_age, int):
            raise ValueError("Age must be an integer")
        if not self.__validate_age(new_age):
            raise ValueError("Not a valid age")
        self.__age = new_age


def tester():
    person1 = Person()

    # Test valid age
    try:
        person1.age = 25
        print(f"Age set to: {person1.age}")
    except ValueError as e:
        print(f"Error: {e}")

    # Test invalid age (negative)
    try:
        person1.age = -5
        print(f"Age set to: {person1.age}")
    except ValueError as e:
        print(f"Error: {e}")
    
    # Test invalid age (too high)
    try:
        person1.age = 200
        print(f"Age set to: {person1.age}")
    except ValueError as e:
        print(f"Error: {e}")
    
    # Test invalid age (not an integer)
    try:
        person1.age = "abc"
        print(f"Age set to: {person1.age}")
    except ValueError as e:
        print(f"Error: {e}")


tester()
