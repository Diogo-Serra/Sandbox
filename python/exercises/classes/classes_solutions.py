#!/usr/bin/env python3
"""
Python OOP Exercise Solutions
Reference solutions for the classes.py exercises
"""

from abc import ABC, abstractmethod
import math


# ============================================================================
# EXERCISE 1: Basic Class and Instance Variables - SOLUTION
# ============================================================================
class Dog:
    def __init__(self, name: str, age: int, breed: str):
        self.name = name
        self.age = age
        self.breed = breed
    
    def bark(self):
        return f"{self.name} says: Woof!"
    
    def birthday(self):
        self.age += 1


# ============================================================================
# EXERCISE 2: Class Variables and Methods - SOLUTION
# ============================================================================
class BankAccount:
    interest_rate = 0.02
    
    def __init__(self, account_holder: str, balance: float):
        self.account_holder = account_holder
        self.balance = balance
    
    def deposit(self, amount: float):
        self.balance += amount
    
    def withdraw(self, amount: float):
        self.balance -= amount
    
    def apply_interest(self):
        self.balance *= (1 + self.interest_rate)
    
    @classmethod
    def change_interest_rate(cls, new_rate: float):
        cls.interest_rate = new_rate


# ============================================================================
# EXERCISE 3: Encapsulation with Properties - SOLUTION
# ============================================================================
class Person:
    def __init__(self, name: str, age: int):
        self.name = name
        self.__age = age
    
    @property
    def age(self):
        return self.__age
    
    @age.setter
    def age(self, value: int):
        if not self.__validate_age(value):
            raise ValueError(f"Age must be between 0 and 150, got {value}")
        self.__age = value
    
    def __validate_age(self, value: int):
        return 0 <= value <= 150


# ============================================================================
# EXERCISE 4: String Representation - SOLUTION
# ============================================================================
class Book:
    def __init__(self, title: str, author: str, year: int, pages: int):
        self.title = title
        self.author = author
        self.year = year
        self.pages = pages
    
    def __str__(self):
        return f"'{self.title}' by {self.author} ({self.year}), {self.pages} pages"
    
    def __repr__(self):
        return f"Book(title='{self.title}', author='{self.author}', year={self.year})"


# ============================================================================
# EXERCISE 5: Inheritance - Basic - SOLUTION
# ============================================================================
class Vehicle:
    def __init__(self, brand: str, model: str, year: int):
        self.brand = brand
        self.model = model
        self.year = year
    
    def describe(self):
        return f"{self.year} {self.brand} {self.model}"


class Car(Vehicle):
    def __init__(self, brand: str, model: str, year: int, num_doors: int):
        super().__init__(brand, model, year)
        self.num_doors = num_doors
    
    def describe(self):
        return f"{super().describe()} with {self.num_doors} doors"
    
    def honk(self):
        return "Honk honk!"


# ============================================================================
# EXERCISE 6: Inheritance with super() - SOLUTION
# ============================================================================
class Animal:
    def __init__(self, species: str, age: int, name: str):
        self.species = species
        self.age = age
        self.name = name
    
    def make_sound(self):
        return f"{self.name} makes a sound"


class Cat(Animal):
    def __init__(self, age: int, name: str, color: str, indoor: bool):
        super().__init__("Cat", age, name)
        self.color = color
        self.indoor = indoor
    
    def make_sound(self):
        return f"{self.name} says: Meow!"


# ============================================================================
# EXERCISE 7: Method Overloading - SOLUTION
# ============================================================================
class Calculator:
    def add(self, *numbers):
        return sum(numbers)
    
    def multiply(self, *numbers):
        result = 1
        for num in numbers:
            result *= num
        return result
    
    def power(self, base, exponent=2):
        return base ** exponent


# ============================================================================
# EXERCISE 8: Dunder Methods - SOLUTION
# ============================================================================
class Rectangle:
    def __init__(self, width: float, height: float):
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def __str__(self):
        return f"Rectangle({self.width}x{self.height})"
    
    def __eq__(self, other):
        return self.area() == other.area()
    
    def __lt__(self, other):
        return self.area() < other.area()


# ============================================================================
# EXERCISE 9: Composition - SOLUTION
# ============================================================================
class Address:
    def __init__(self, street: str, city: str, country: str, zip_code: str):
        self.street = street
        self.city = city
        self.country = country
        self.zip_code = zip_code


class Employee:
    def __init__(self, name: str, salary: float, address: Address):
        self.name = name
        self.salary = salary
        self.address = address
    
    def get_full_address(self):
        return f"{self.address.street}, {self.address.city}, {self.address.country} {self.address.zip_code}"


# ============================================================================
# EXERCISE 10: Abstract Base Classes and Polymorphism - SOLUTION
# ============================================================================
class Shape(ABC):
    @abstractmethod
    def area(self):
        pass
    
    @abstractmethod
    def perimeter(self):
        pass


class Circle(Shape):
    def __init__(self, radius: float):
        self.radius = radius
    
    def area(self):
        return math.pi * self.radius ** 2
    
    def perimeter(self):
        return 2 * math.pi * self.radius


class Square(Shape):
    def __init__(self, side: float):
        self.side = side
    
    def area(self):
        return self.side ** 2
    
    def perimeter(self):
        return 4 * self.side


def print_shapes(shapes):
    for shape in shapes:
        print(f"Area: {shape.area():.2f}, Perimeter: {shape.perimeter():.2f}")


# ============================================================================
# EXERCISE 11: Static Methods and Class Methods - SOLUTION
# ============================================================================
class Temperature:
    scale = "Celsius"
    
    def __init__(self, value: float):
        self.value = value
    
    @staticmethod
    def celsius_to_fahrenheit(celsius):
        return (celsius * 9/5) + 32
    
    @staticmethod
    def fahrenheit_to_celsius(fahrenheit):
        return (fahrenheit - 32) * 5/9
    
    @classmethod
    def set_scale(cls, new_scale):
        cls.scale = new_scale


# ============================================================================
# EXERCISE 12: Magic Methods (__call__) - SOLUTION
# ============================================================================
class Counter:
    def __init__(self):
        self.count = 0
    
    def __call__(self):
        self.count += 1
        return self.count
    
    def __str__(self):
        return f"Counter: {self.count}"


# ============================================================================
# EXERCISE 13: Multiple Inheritance - SOLUTION
# ============================================================================
class Flyable:
    def fly(self):
        return "Flying high!"


class Swimmer:
    def swim(self):
        return "Swimming in water!"


class Duck(Flyable, Swimmer):
    def quack(self):
        return "Quack!"


# ============================================================================
# EXERCISE 14: Operator Overloading - SOLUTION
# ============================================================================
class Vector:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y
    
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)
    
    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)
    
    def __str__(self):
        return f"Vector({self.x}, {self.y})"


# ============================================================================
# EXERCISE 15: Private Methods and Attributes - SOLUTION
# ============================================================================
class SecureData:
    def __init__(self, data: str):
        self.__data = self.__encrypt(data)
    
    def __encrypt(self, value: str):
        return value[::-1]
    
    def __decrypt(self, value: str):
        return value[::-1]
    
    def set_data(self, value: str):
        self.__data = self.__encrypt(value)
    
    def get_data(self):
        return self.__decrypt(self.__data)


# ============================================================================
# CHALLENGE: Online Store System - SOLUTION
# ============================================================================
class Product:
    def __init__(self, name: str, price: float, stock: int):
        self.name = name
        self.price = price
        self.stock = stock
    
    def reduce_stock(self, quantity: int):
        self.stock -= quantity
    
    def is_available(self, quantity: int = 1):
        return self.stock >= quantity


class ShoppingCart:
    def __init__(self):
        self.items = []
    
    def add_item(self, product: Product, quantity: int):
        if product.is_available(quantity):
            self.items.append((product, quantity))
        else:
            print(f"Not enough stock for {product.name}")
    
    def remove_item(self, product: Product):
        self.items = [(p, q) for p, q in self.items if p != product]
    
    def calculate_total(self):
        return sum(product.price * quantity for product, quantity in self.items)
    
    def checkout(self):
        total = self.calculate_total()
        invoice = "=== INVOICE ===\n"
        for product, quantity in self.items:
            invoice += f"{product.name} x{quantity}: ${product.price * quantity:.2f}\n"
            product.reduce_stock(quantity)
        invoice += f"Total: ${total:.2f}"
        self.items = []
        return invoice


class Customer:
    def __init__(self, name: str, email: str, address: str):
        self.name = name
        self.email = email
        self.address = address
        self.carts = []
    
    def create_cart(self):
        cart = ShoppingCart()
        self.carts.append(cart)
        return cart
    
    def view_carts(self):
        return self.carts


# ============================================================================
# TEST SECTION
# ============================================================================
if __name__ == "__main__":
    print("=" * 60)
    print("EXERCISE 1 & 2: Basic Classes")
    print("=" * 60)
    dog = Dog("Buddy", 5, "Golden Retriever")
    print(dog.bark())
    dog.birthday()
    print(f"Age after birthday: {dog.age}")
    
    print("\n" + "=" * 60)
    print("EXERCISE 3: Properties and Encapsulation")
    print("=" * 60)
    person = Person("John", 25)
    print(f"Age: {person.age}")
    try:
        person.age = 200
    except ValueError as e:
        print(f"Error: {e}")
    
    print("\n" + "=" * 60)
    print("EXERCISE 4: String Representation")
    print("=" * 60)
    book = Book("1984", "George Orwell", 1949, 328)
    print(str(book))
    print(repr(book))
    
    print("\n" + "=" * 60)
    print("EXERCISE 5 & 6: Inheritance")
    print("=" * 60)
    car = Car("Toyota", "Camry", 2020, 4)
    print(car.describe())
    print(car.honk())
    cat = Cat(3, "Whiskers", "Orange", True)
    print(cat.make_sound())
    
    print("\n" + "=" * 60)
    print("EXERCISE 7: Variable Arguments")
    print("=" * 60)
    calc = Calculator()
    print(f"Sum: {calc.add(1, 2, 3, 4)}")
    print(f"Product: {calc.multiply(2, 3, 4)}")
    print(f"Power: {calc.power(2, 3)}")
    
    print("\n" + "=" * 60)
    print("EXERCISE 8: Dunder Methods")
    print("=" * 60)
    rect1 = Rectangle(4, 5)
    rect2 = Rectangle(2, 10)
    print(f"{rect1} area: {rect1.area()}")
    print(f"{rect2} area: {rect2.area()}")
    print(f"Equal areas? {rect1 == rect2}")
    print(f"rect1 < rect2? {rect1 < rect2}")
    
    print("\n" + "=" * 60)
    print("EXERCISE 9: Composition")
    print("=" * 60)
    addr = Address("123 Main St", "New York", "USA", "10001")
    emp = Employee("Alice", 50000, addr)
    print(emp.get_full_address())
    
    print("\n" + "=" * 60)
    print("EXERCISE 10: Abstract Classes")
    print("=" * 60)
    shapes = [Circle(5), Square(4)]
    print_shapes(shapes)
    
    print("\n" + "=" * 60)
    print("EXERCISE 11: Static/Class Methods")
    print("=" * 60)
    print(f"32°C to F: {Temperature.celsius_to_fahrenheit(32)}")
    print(f"32°F to C: {Temperature.fahrenheit_to_celsius(32)}")
    
    print("\n" + "=" * 60)
    print("EXERCISE 12: Callable Class")
    print("=" * 60)
    counter = Counter()
    print(counter())
    print(counter())
    print(counter())
    print(str(counter))
    
    print("\n" + "=" * 60)
    print("EXERCISE 13: Multiple Inheritance")
    print("=" * 60)
    duck = Duck()
    print(duck.fly())
    print(duck.swim())
    print(duck.quack())
    
    print("\n" + "=" * 60)
    print("EXERCISE 14: Operator Overloading")
    print("=" * 60)
    v1 = Vector(1, 2)
    v2 = Vector(3, 4)
    print(f"{v1} + {v2} = {v1 + v2}")
    print(f"{v1} - {v2} = {v1 - v2}")
    print(f"{v1} * 2 = {v1 * 2}")
    
    print("\n" + "=" * 60)
    print("EXERCISE 15: Secure Data")
    print("=" * 60)
    secure = SecureData("Hello")
    print(f"Retrieved: {secure.get_data()}")
    secure.set_data("World")
    print(f"Retrieved: {secure.get_data()}")
    
    print("\n" + "=" * 60)
    print("CHALLENGE: Online Store")
    print("=" * 60)
    prod1 = Product("Laptop", 999.99, 5)
    prod2 = Product("Mouse", 29.99, 20)
    
    customer = Customer("Bob", "bob@email.com", "456 Oak St")
    cart = customer.create_cart()
    cart.add_item(prod1, 1)
    cart.add_item(prod2, 2)
    print(cart.checkout())
