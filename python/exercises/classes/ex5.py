#!/usr.bin/env python3

class Vehicle:

    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def describe(self):
        return f'{self.year} {self.brand} {self.model}'


class Car(Vehicle):

    def __init__(self, num_doors):
        super().__init__()
        pass

    def describe(self):
        return (f'{self.num_doors}')


def tester():
    car1 = Car("Brand", "Model", 1996, 5)
    car1.describe()


tester()
