#!/usr/bin/env python3
"""
Python OOP Exercise Set
Organized from beginner to intermediate level
"""

# ============================================================================
# EXERCISE 1: Basic Class and Instance Variables
# ============================================================================
# TODO: Create a 'Dog' class with:
# - __init__ method that takes: name (str), age (int), breed (str)
# - Instance variables: name, age, breed
# - Instance method 'bark()' that returns f"{self.name} says: Woof!"
# - Instance method 'birthday()' that increments age by 1


# ============================================================================
# EXERCISE 2: Class Variables and Methods
# ============================================================================
# TODO: Create a 'BankAccount' class with:
# - Class variable 'interest_rate' = 0.02
# - Instance variables: account_holder (str), balance (float)
# - Instance method 'deposit(amount)' that adds to balance
# - Instance method 'withdraw(amount)' that subtracts from balance
# - Instance method 'apply_interest()' that multiplies balance by (1 + interest_rate)
# - Class method 'change_interest_rate(new_rate)' that updates the class variable
# Test: Create 2 accounts, apply interest to one, verify class variable changed for both


# ============================================================================
# EXERCISE 3: Encapsulation with Properties
# ============================================================================
# TODO: Create a 'Person' class with:
# - Private variable '__age' initialized in __init__
# - Property 'age' that returns __age (getter)
# - Property 'age.setter' that validates age is between 0-150 before setting
#   (raise ValueError if invalid)
# - Private method '__validate_age(value)' that returns True if 0 <= value <= 150
# Test: Try to set invalid ages and catch the ValueError


# ============================================================================
# EXERCISE 4: String Representation (__str__ and __repr__)
# ============================================================================
# TODO: Create a 'Book' class with:
# - Instance variables: title (str), author (str), year (int), pages (int)
# - __init__ to initialize these
# - __str__ that returns: "'{title}' by {author} ({year}), {pages} pages"
# - __repr__ that returns: "Book(title='{title}', author='{author}', year={year})"
# Test: print() the object and repr() it


# ============================================================================
# EXERCISE 5: Inheritance - Basic
# ============================================================================
# TODO: Create a 'Vehicle' base class with:
# - Instance variables: brand, model, year
# - Method 'describe()' that returns f"{year} {brand} {model}"
#
# TODO: Create a 'Car' class that inherits from Vehicle with:
# - Additional instance variable: num_doors
# - Override 'describe()' to include number of doors
# - Method 'honk()' that returns "Honk honk!"


# ============================================================================
# EXERCISE 6: Inheritance with super()
# ============================================================================
# TODO: Create an 'Animal' base class with:
# - Instance variables: species, age, name
# - __init__ that takes these parameters
# - Method 'make_sound()' returning f"{self.name} makes a sound"
#
# TODO: Create a 'Cat' class that inherits from Animal with:
# - Additional instance variables: color, indoor (bool)
# - __init__ that calls super().__init__() and sets color, indoor
# - Override 'make_sound()' to return f"{self.name} says: Meow!"


# ============================================================================
# EXERCISE 7: Method Overloading (using default parameters and *args)
# ============================================================================
# TODO: Create a 'Calculator' class with:
# - Method 'add(*numbers)' that returns the sum of all arguments
#   Example: calc.add(1, 2, 3) returns 6
# - Method 'multiply(*numbers)' that returns the product of all arguments
# - Method 'power(base, exponent=2)' that returns base ** exponent


# ============================================================================
# EXERCISE 8: Dunder Methods (__eq__, __lt__, __str__)
# ============================================================================
# TODO: Create a 'Rectangle' class with:
# - Instance variables: width, height
# - __init__ to initialize these
# - __str__ that returns f"Rectangle({width}x{height})"
# - __eq__ that compares two rectangles by area
# - __lt__ that checks if this rectangle's area < other rectangle's area
# - Method 'area()' that returns width * height


# ============================================================================
# EXERCISE 9: Composition (Has-A relationship)
# ============================================================================
# TODO: Create an 'Address' class with:
# - Instance variables: street, city, country, zip_code
#
# TODO: Create an 'Employee' class with:
# - Instance variables: name, salary, address (type: Address)
# - __init__ takes: name, salary, and an Address object
# - Method 'get_full_address()' that returns formatted address from the Address object
#   Example: "123 Main St, New York, USA 10001"


# ============================================================================
# EXERCISE 10: Abstract Base Classes and Polymorphism
# ============================================================================
# TODO: Create a 'Shape' abstract base class with:
# - @abstractmethod 'area()' that must be implemented by subclasses
# - @abstractmethod 'perimeter()' that must be implemented by subclasses
#
# TODO: Create 'Circle' class inheriting from Shape with:
# - Instance variable: radius
# - Implement area() using π * radius²
# - Implement perimeter() using 2 * π * radius
#
# TODO: Create 'Square' class inheriting from Shape with:
# - Instance variable: side
# - Implement area() as side²
# - Implement perimeter() as 4 * side
#
# TODO: Create a function that takes a list of Shape objects and prints
# the area and perimeter of each


# ============================================================================
# EXERCISE 11: Static Methods and Class Methods
# ============================================================================
# TODO: Create a 'Temperature' class with:
# - Static method 'celsius_to_fahrenheit(celsius)' that returns (celsius * 9/5) + 32
# - Static method 'fahrenheit_to_celsius(fahrenheit)' that returns (fahrenheit - 32) * 5/9
# - Class variable 'scale' = 'Celsius'
# - Instance variable: value
# - Class method 'set_scale(new_scale)' that updates the class variable
# Test: Use static methods without creating an instance, then create instances


# ============================================================================
# EXERCISE 12: Magic Methods (__init__, __del__, __call__)
# ============================================================================
# TODO: Create a 'Counter' class with:
# - __init__ that initializes count = 0
# - __call__ method that increments count by 1 and returns the new count
#   This allows the instance to be called like a function
# - __str__ that returns f"Counter: {count}"
# Test: Create counter = Counter(), then call counter() multiple times


# ============================================================================
# EXERCISE 13: Multiple Inheritance
# ============================================================================
# TODO: Create a 'Flyable' class with:
# - Method 'fly()' that returns "Flying high!"
#
# TODO: Create a 'Swimmer' class with:
# - Method 'swim()' that returns "Swimming in water!"
#
# TODO: Create a 'Duck' class that inherits from both Flyable and Swimmer with:
# - Method 'quack()' that returns "Quack!"
# Test: Create a duck and call fly(), swim(), and quack() methods


# ============================================================================
# EXERCISE 14: Operator Overloading
# ============================================================================
# TODO: Create a 'Vector' class with:
# - Instance variables: x, y (coordinates)
# - __init__ to initialize x, y
# - __add__ to add two vectors component-wise
#   Example: Vector(1, 2) + Vector(3, 4) = Vector(4, 6)
# - __sub__ to subtract two vectors
# - __mul__ to multiply vector by scalar
# - __str__ that returns f"Vector({x}, {y})"
# Test: Create vectors and perform operations


# ============================================================================
# EXERCISE 15: Class with Private Methods and Attributes
# ============================================================================
# TODO: Create a 'SecureData' class with:
# - Private variable '__data' initialized in __init__
# - Private method '__encrypt(value)' that returns reversed string (simple encryption)
# - Private method '__decrypt(value)' that reverses the string back
# - Public method 'set_data(value)' that calls __encrypt() before storing
# - Public method 'get_data()' that calls __decrypt() before returning
# Test: Set and get data, verify it's encrypted when stored


# ============================================================================
# CHALLENGE EXERCISE: Online Store System
# ============================================================================
# TODO: Design a simple online store with the following classes:
#
# Product:
#   - name, price, stock
#   - method: reduce_stock(quantity), is_available()
#
# ShoppingCart:
#   - items (list of tuples: (product, quantity))
#   - method: add_item(product, quantity)
#   - method: remove_item(product)
#   - method: calculate_total()
#   - method: checkout() that reduces stock and returns invoice string
#
# Customer:
#   - name, email, address
#   - carts (list of ShoppingCart objects)
#   - method: create_cart(), view_carts()
#
# Test: Create products, customers, add items to cart, and checkout


if __name__ == "__main__":
    # Test your exercises here
    pass
