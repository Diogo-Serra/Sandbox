#!/usr/bin/env python3

class Address:

    def __init__(self):
        self.street = "123 Main St"
        self.city = "New York"
        self.country = "USA"
        self.zipcode = 10001


class Employee:

    def __init__(self, name, salary, address):
        self.name = name
        self.salary = salary
        self.address = address

    def get_full_address(self):
        return (f"{self.address.street}, {self.address.city}, "
                f"{self.address.country} {self.address.zipcode}")

    def __str__(self):
        return f"{self.name}: {self.salary}"


def tester():
    address = Address()
    employee_1 = Employee("Mark", 2300, address)
    print(employee_1)
    print(employee_1.get_full_address())


tester()
