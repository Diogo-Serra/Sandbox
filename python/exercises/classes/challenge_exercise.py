#!/usr/bin/env python3


class Product:

    def __init__(self, name, price, stock):
        self.name = name
        self.price = price
        self.stock = stock

    def reduce_stock(self, quantity):
        if self.stock >= quantity:
            self.stock -= quantity
        else:
            return "Not enought stock"

    def is_available(self, quantity):
        if self.stock > quantity:
            return True
        else:
            return False

    def __str__(self):
        return f"{self.name}: {self.price}Euros\nAvailable: {self.stock}"


class ShoppingCart:

    items: list[tuple] = []

    def __init__(self):
        pass

    def add_item(self, product, quantity):
        if product.is_available(quantity):
            self.items.append(product)
        else:
            return f"Only {product.stock} available"

    def remove_item(self, product):
        for p in self.items:
            if p is product:
                del p

    def calculate_total(self):
        total = 0
        for p in self.items:
            total += p.price
        return total

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
    product1 = Product("Prod1", 78, 5)
    print(customer1)
    print(product1)


tester()
