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
        validated_data = self.validate(data)
        return (self.format_output(validated_data))

    def validate(self, data: Any):
        for x in data:
            try:
                int(x)
            except ValueError as v:
                return v
        return (data)

    def format_output(self, message):
        return f"Numbers validated: {message}"


def main():
    processor = NumericProcessor()
    print(processor.process({1, 2, 3}))


main()
