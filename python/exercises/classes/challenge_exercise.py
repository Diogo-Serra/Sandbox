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
            return "Not enough stock"

    def is_available(self, quantity):
        return self.stock >= quantity

    def __str__(self):
        return f"{self.name}: {self.price}Euros\nAvailable: {self.stock}"


class ShoppingCart:

    def __init__(self):
        self.items: list[tuple[Product, int]] = []

    def add_item(self, product, quantity):
        if product.is_available(quantity):
            self.items.append((product, quantity))
        else:
            return f"Only {product.stock} available"

    def remove_item(self, product):
        self.items = [(p, q) for p, q in self.items if p is not product]

    def calculate_total(self):
        total = 0
        for product, quantity in self.items:
            total += product.price * quantity
        return total

    def checkout(self):
        for product, quantity in self.items:
            result = product.reduce_stock(quantity)
            if result:
                return result
        total = self.calculate_total()
        self.items.clear()
        return f"Checkout complete! Total: {total}Euros"

    def __str__(self):
        if not self.items:
            return "Cart is empty"
        lines = [
            f"  {p.name} x{q} = {p.price * q}Euros"
            for p, q in self.items
        ]
        total = self.calculate_total()
        return "Cart:\n" + "\n".join(lines) + f"\n  Total: {total}Euros"


class Customer:

    def __init__(self, name, email, address):
        self.name = name
        self.email = email
        self.address = address
        self.cart = ShoppingCart()

    def view_cart(self):
        return str(self.cart)

    def __str__(self):
        return f"{self.name}: {self.email}\nAddress: {self.address}"


def tester():
    customer1 = Customer("Bob", "bob@gmail.com", "123 St. USA")
    product1 = Product("Prod1", 78, 5)
    product2 = Product("Prod2", 25, 10)

    print("\n--- Customer ---")
    print(customer1)

    print("\n--- Products ---")
    print(product1)
    print(product2)

    print("\n--- Add to Cart ---")
    customer1.cart.add_item(product1, 2)
    customer1.cart.add_item(product2, 3)
    print(customer1.view_cart())

    print("\n--- Checkout ---")
    print(customer1.cart.checkout())

    print("\n--- Stock After Checkout ---")
    print(product1)
    print(product2)

    print("\n--- Cart After Checkout ---")
    print(customer1.view_cart())


tester()
