#!/usr/bin/env python3

class Address:

    def __init__(self):
        self.street = "123 Main St"
        self.city = "New York"
        self.country = "USA"
        self.zipcode = 10001


class Employee:

    def __init__(self, name, salary, address=Address()):
        self.name = name
        self.salary = salary

    def get_full_address(self):
        return (f"{Address.street}, {Address.city}"
                f"{Address.country} {Address.zipcode}")

    def __str__(self):
        return f"{self.name}: {self.salary}"


def tester():
    employee_1 = Employee("Mark", 2300)
    print(employee_1)


tester()
