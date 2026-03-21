#!/usr/bin/env python3


class Product:

    def __init__(self, name, price, stock):
        self.name = name
        self.price = price
        self.stock = stock

    def reduce_stock(self, quantity):
        pass

    def is_available(self):
        pass


class ShoppingCart:

    items: list[tuple] = []

    def __init__(self):
        pass

    def add_item(product, quantity):
        pass

    def remove_item(product):
        pass

    def calculate_total(self):
        pass

    def checkout(self):
        pass


class Customer:

    carts: list[tuple] = []

    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address

    def create_cart(self):
        self.carts.append(ShoppingCart())

    def view_cart(self):
        return f"{self.carts}"

    def __str__(self):
        return f"{self.name}: {self.email}\nAddress: {self.address}"


def tester():
    customer1 = Customer("Bob", "bob@gmail.com", "123 St. USA")
    print(customer1)


tester()
