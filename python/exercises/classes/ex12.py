#!/usr/bin/env python3

class Counter:

    count = 0

    def __init__(self):
        self.count = 0

    def __call__(self):
        self.count += 1
        return (self.count)

    def __str__(self):
        return f"Counter: {self.count}"


def tester():
    counter1 = Counter()
    counter1()
    print(counter1)


tester()
