#!/usr/bin/env python3
from math import sqrt

numbers = [1, 2, 3, 4, 5]
double = lambda x: x * 2
sqr = lambda x: sqrt(x)
list_double = list(map(lambda x: x*2, numbers))
even_number = list(filter(lambda x: x % 2 == 0, numbers))


print(double(2))
print(sqr(2))
print(list_double)
print(even_number)
