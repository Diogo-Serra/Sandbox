#!/usr/bin/env python3
"""
Python OOP Learning Guide
Tips, progression, and explanations for the exercises
"""

# ============================================================================
# HOW TO USE THESE EXERCISES
# ============================================================================
"""
1. Work through each exercise in order - they build on each other
2. Implement the class in classes.py as directed in the TODO comments
3. Test your implementation in the if __name__ == "__main__" section
4. Compare your solution with classes_solutions.py
5. Don't skip exercises even if they seem easy - they build fundamentals

PROGRESSION OVERVIEW:
- Exercises 1-4: Core concepts (classes, variables, methods, dunder methods)
- Exercises 5-6: Inheritance (is-a relationships)
- Exercise 7: Advanced method techniques
- Exercises 8-9: Object relationships and comparisons
- Exercise 10: Polymorphism through abstract base classes
- Exercises 11-12: Advanced method types and special behaviors
- Exercise 13: Alternative multiple inheritance
- Exercise 14: Making classes work with operators
- Exercise 15: Security through privacy
- Challenge: Putting it all together
"""

# ============================================================================
# KEY OOP CONCEPTS SUMMARY
# ============================================================================
"""
CLASSES:
- Blueprint for creating objects
- Define attributes (data) and methods (behavior)
- self refers to the current instance

INSTANCE vs CLASS VARIABLES:
- Instance variables: unique to each object (self.x = 5)
- Class variables: shared across all instances (ClassName.x = 5)

METHODS:
- Instance method: operates on specific object (self as first param)
- Class method: operates on class (@classmethod, cls as first param)
- Static method: standalone function in class (@staticmethod, no self)

MAGIC/DUNDER METHODS:
- __init__: Constructor, called when object is created
- __str__: Called by str() and print(), user-friendly
- __repr__: Called by repr(), developer-friendly
- __eq__: Equality comparison (==)
- __lt__: Less than comparison (<)
- __add__, __sub__, __mul__: Operator overloading
- __call__: Makes instance callable like a function
- __del__: Destructor, called when object is deleted

INHERITANCE:
- Create hierarchy of classes
- Subclass inherits all methods/attributes from superclass
- super() calls parent class methods
- Can override methods to change behavior
- Multiple inheritance: inherit from multiple classes (use with caution)

ENCAPSULATION:
- Hide implementation details behind public interface
- Private attributes: __attribute (name mangling)
- Properties: use @property decorator for getters/setters
- Protects data from invalid states

POLYMORPHISM:
- Different classes implement same method differently
- Use abstract base classes (ABC) and @abstractmethod
- Allows treating different types uniformly

COMPOSITION:
- Objects contain other objects (has-a relationship)
- Opposite of inheritance (is-a relationship)
- Often more flexible than inheritance
"""

# ============================================================================
# COMMON PATTERNS AND TIPS
# ============================================================================
"""
1. INITIALIZATION BEST PRACTICES:
   - Initialize all expected attributes in __init__
   - Use type hints for clarity
   - Call super().__init__() in subclass constructors

2. PRIVATE ATTRIBUTES:
   - Use double underscore: __attribute
   - Python name-mangles it to _ClassName__attribute
   - Prevents accidental access but not truly private
   - Use single underscore for "internal use" convention

3. PROPERTIES vs GETTERS/SETTERS:
   - Properties are more Pythonic than get_attribute() / set_attribute()
   - Use @property decorator for getter
   - Use @attribute.setter for setter
   - Allows validation and computed properties

4. STRING REPRESENTATIONS:
   - __str__: for end users (str(obj), print(obj))
   - __repr__: for developers (repr(obj), debugging)
   - Write __repr__ to be unambiguous, ideally executable code

5. EQUALITY and COMPARISON:
   - Don't compare object identity (is) with equality (==)
   - Implement __eq__ to define what equality means
   - Also implement __lt__, __le__, __gt__, __ge__, __ne__ for consistency

6. OPERATOR OVERLOADING:
   - __add__, __sub__, __mul__, __div__, etc. make + - * / work
   - __getitem__ and __setitem__ make indexing work [key]
   - __len__ makes len() work
   - Keep operations simple and intuitive

7. ABSTRACT BASE CLASSES:
   - Use for enforcing interface contracts
   - Cannot instantiate ABC directly
   - All @abstractmethod must be implemented by subclasses
   - Makes polymorphism safer and clearer

8. CLASS VARIABLES:
   - Shared across all instances
   - Useful for constants or counters
   - Be careful: modifying class var affects all instances
   - Use @classmethod to modify class variables

9. INHERITANCE HIERARCHY:
   - Keep it shallow (2-3 levels usually enough)
   - Use composition instead of deep hierarchies
   - Multiple inheritance can create complexity (diamond problem)
   - Use Method Resolution Order (MRO): ClassName.__mro__

10. NAMING CONVENTIONS:
    - Classes: PascalCase (MyClass)
    - Methods/Attributes: snake_case (my_method)
    - Constants: UPPER_SNAKE_CASE (MAX_SIZE)
    - Private: _leading_underscore (internal use)
    - Private: __double_underscore (name mangling)
"""

# ============================================================================
# DEBUGGING TECHNIQUES
# ============================================================================
"""
1. Print instance variables:
   print(obj.__dict__)  # Shows {attribute: value} dict

2. Check class hierarchy:
   print(MyClass.__mro__)  # Method Resolution Order
   isinstance(obj, MyClass)  # Check if instance of class

3. List available methods:
   print(dir(obj))  # All attributes and methods

4. Inspect method:
   print(help(obj.method))  # Documentation for method

5. Debug private attributes:
   print(obj._ClassName__private)  # Access name-mangled attribute

6. Check if attribute exists:
   hasattr(obj, 'attribute')

7. Get attribute value:
   getattr(obj, 'attribute', default_value)

8. Set attribute dynamically:
   setattr(obj, 'attribute', value)
"""

# ============================================================================
# COMMON MISTAKES TO AVOID
# ============================================================================
"""
1. Forgetting 'self' in method definitions or calls:
   ❌ def method():          ✓ def method(self):
   ❌ obj.method(obj)        ✓ obj.method()

2. Mutable default arguments:
   ❌ def __init__(self, items=[]):     # Shared across instances!
   ✓ def __init__(self, items=None):   # Create new list in method
       self.items = items if items else []

3. Not calling super().__init__() in subclass:
   ❌ class Child(Parent):
       def __init__(self, x):
           self.x = x  # Parent's __init__ not called!
   
   ✓ class Child(Parent):
       def __init__(self, x, y):
           super().__init__(x)
           self.y = y

4. Confusing class and instance variables:
   ❌ class Counter:
       count = 0  # This is shared!
       def increment(self):
           Counter.count += 1  # Affects all instances
   
   ✓ class Counter:
       def __init__(self):
           self.count = 0  # Each instance has its own

5. Not implementing __eq__ correctly:
   ❌ def __eq__(self, other):
       return True if self.value == other.value else False
   
   ✓ def __eq__(self, other):
       if not isinstance(other, MyClass):
           return False
       return self.value == other.value

6. Overusing inheritance:
   ❌ Everything inherits from everything
   ✓ Use inheritance for is-a relationships
   ✓ Use composition for has-a relationships

7. Ignoring type hints:
   ❌ def add(self, x):
       return x + self.value
   
   ✓ def add(self, x: int) -> int:
       return x + self.value
"""

# ============================================================================
# PRACTICE PROGRESSION TIPS
# ============================================================================
"""
BEGINNER (Exercises 1-4):
- Focus on understanding basic syntax
- Test each class with simple examples
- Make sure __init__ works correctly
- Practice reading error messages

INTERMEDIATE (Exercises 5-12):
- Understand inheritance chains
- Think about object relationships
- Test edge cases
- Use properties for validation

ADVANCED (Exercises 13-15 + Challenge):
- Design class hierarchies
- Think about API design
- Handle error conditions
- Build reusable components

When you get stuck:
1. Re-read the requirements carefully
2. Check your syntax with Python
3. Look at the solutions only to understand the approach
4. Rewrite the solution from memory
5. Test with different inputs
"""

# ============================================================================
# EXERCISE DIFFICULTY RATINGS
# ============================================================================
"""
⭐ Easy (1-2 lines per method):
   - Exercise 1: Basic class with simple methods
   - Exercise 4: String representations

⭐⭐ Medium (3-5 lines per method):
   - Exercise 2: Class variables and class methods
   - Exercise 5: Basic inheritance
   - Exercise 7: Variable arguments

⭐⭐⭐ Medium-Hard (5-10 lines or tricky concepts):
   - Exercise 3: Properties and validation
   - Exercise 6: Inheritance with super()
   - Exercise 8: Dunder methods for comparison
   - Exercise 9: Composition pattern

⭐⭐⭐⭐ Hard (Complex concepts):
   - Exercise 10: Abstract base classes and polymorphism
   - Exercise 11: Static methods and class methods
   - Exercise 12: __call__ magic method

⭐⭐⭐⭐⭐ Very Hard (Tricky or advanced):
   - Exercise 13: Multiple inheritance (can be confusing)
   - Exercise 14: Operator overloading (needs careful design)
   - Exercise 15: Private methods and encryption
   - Challenge: Entire system design

Tip: Don't judge yourself by difficulty. All exercises are valuable.
"""

# ============================================================================
# NEXT STEPS AFTER COMPLETING THESE EXERCISES
# ============================================================================
"""
1. DESIGN PATTERNS:
   - Learn common patterns: Singleton, Factory, Observer, etc.
   - Understand when to use each pattern

2. TESTING:
   - Learn unit testing with unittest or pytest
   - Write tests for your classes

3. DECORATORS:
   - Understand how decorators work (@property is a decorator)
   - Create custom decorators for logging, timing, etc.

4. GENERATORS AND ITERATORS:
   - Implement __iter__ and __next__ for custom iteration
   - Use yield for generator functions

5. CONTEXT MANAGERS:
   - Implement __enter__ and __exit__
   - Use with statement for resource management

6. METACLASSES:
   - Advanced topic: classes that create classes
   - Usually not needed but good to understand

7. BUILD REAL PROJECTS:
   - Apply OOP to real problems
   - Build libraries, games, tools, etc.
   - Contribute to open source projects

8. STUDY FRAMEWORKS:
   - Django, Flask, FastAPI use OOP extensively
   - Study their code to see OOP best practices
"""
