#!/usr/bin/python3
from sys import argv, exit


def grid_creation(width: int, height: int):

    print()
    grid = [[0xF]*width for _ in range(height)]
    for y, row in enumerate(grid):
        for x, col in enumerate(row):
            print(grid[x][y], end='')
        print('\n', end='')
    print()

    for y, row in enumerate(grid):
        for x, col in enumerate(row):
            print(f"({x}, {y})", end='')
        print('\n', end='')
    print()


if __name__ == '__main__':

    if len(argv) == 1:

        try:

            user = input("Insert Width and Height: ").strip().split()

            if len(user) == 2:
                width = int(user[0])
                height = int(user[1])
                grid_creation(width, height)
            else:
                print("Exiting\n"
                      "Usage:<int> <int>")
                exit(1)

        except (Exception, BaseException) as error:
            print(error)
            exit(1)
