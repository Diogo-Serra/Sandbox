#!/usr/bin/env python3

class Person:
    def __init__(self,):
        self.__age = None

    @property
    def p(self):
        return (f"Age: {self.__age}")

    def getp(self):
        return self.__age

    def setp(self, new_age):
        self.__validate_age(new_age)
        self.__age = new_age

    def __validate_age(self, age):
        try:
            age_int = int(age)
            if age_int <= 0 or age_int >= 150:
                print("Not a valid age")
            else:
                return True
        except ValueError as e:
            print(e)


def tester():
    person1 = Person()
    person1.setp(0)


tester()
