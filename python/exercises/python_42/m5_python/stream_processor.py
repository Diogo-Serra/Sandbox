#!/usr/bin/env python3
from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def process(self, data):
        pass

    @abstractmethod
    def validate(self, data):
        pass

    def format_output(message):
        return f"Format output: {message}"


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def process(self, data: Any):
        self.format_output(self.validate(data))

    def validate(self, data: Any):
        for x in data:
            try:
                int(x)
            except ValueError as v:
                return v

    def format_output(self, message):
        return f"{self} + test"


def main():
    processor = NumericProcessor()
    processor.process({1, 2, 3})


main()
