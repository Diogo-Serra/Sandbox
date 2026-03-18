#!/usr/bin/env python3
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def process(self):
        pass

    @abstractmethod
    def validate(self):
        pass

    def format_output(message):
        print(f"Format output: {message}")


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__(self)

    def process(self):
        return self

    def validate(self):
        return 2


def main():
    processor = NumericProcessor.process(4)
    print(processor)


main()
