#!/usr/bin/python3
from sys import argv, exit
from os import system


def grid_generator(width: int, height: int) -> list[list[int]]:
    if not (0 < width < 20) or not (0 < height < 20):
        raise ValueError("Grid size must be between 0 and 20")
    else:
        return [[0xF]*width for line in range(height)]


def run(argv: list[str]) -> None:
    if argv[0].strip() != "grid2d.py":
        raise ValueError("Expected grid2d.py script name")
    width = int(argv[1].strip())
    height = int(argv[2].strip())
    print(grid_generator(width, height))


if __name__ == "__main__":

    if len(argv) == 3:
        try:
            run(argv)
        except (BaseException, Exception) as error:
            print(error)
            exit(1)
    else:
        print("Usage: 2dgrid.py <width> <height>")
        exit(1)
