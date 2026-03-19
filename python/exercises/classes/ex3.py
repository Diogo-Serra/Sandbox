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
        
        self.__age = age_int
        except ValueError:
            print("Not a valid age!")
            return

    def __validate_age(age):
        try:
            age_int = int(new_age)
            if age_int <= 0 or age_int >= 150:
                return True
            else:
                return False
        

def tester():
    person1 = Person()
    person1.setp(0)


tester()
