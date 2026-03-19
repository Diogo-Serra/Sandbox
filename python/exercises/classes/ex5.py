#!/usr/bin/env python3

class Vehicle:

    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def describe(self):
        return f'{self.year} {self.brand} {self.model}'

    def honk(self):
        pass


class Car(Vehicle):

    def __init__(self, brand, model, year, num_doors):
        super().__init__(brand, model, year)
        self.num_doors = num_doors

    def describe(self):
        return f'{self.year} {self.brand} {self.model} {self.num_doors}'

    def honk(self):
        return 'Honk honk!'


def tester():
    car = Vehicle("Brand", "Model", 1994)
    car1 = Car("Brand", "Model", 1996, 4)
    print(car.describe())
    print(car1.describe())


tester()
