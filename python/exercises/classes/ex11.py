#!/usr/bin/env python3


class Temperature:

    scale = 'Celsius'

    def __init__(self, value):
        self.value = value

    @classmethod
    def set_scale(cls, scale):
        cls.scale = scale

    @staticmethod
    def celsius_to_fahrenheit(celsius):
        return (celsius * 9/5)

    @staticmethod
    def fahrenheit_to_celsius(fahrenheit):
        return (fahrenheit - 32) * 5/9


def tester():
    print(Temperature.celsius_to_fahrenheit(35))
    print(Temperature.fahrenheit_to_celsius(75))
    Temperature.set_scale("Fahrenheit")

    temp1 = Temperature(35)
    print(temp1.celsius_to_fahrenheit(25))


tester()
