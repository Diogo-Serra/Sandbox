#!/usr/bin/python3
from sys import argv, exit


def grid_creation(width: int, height: int):

    grid = [[0xF]*width for _ in range(height)]
    for row in grid:
        for cell in row:
            print(hex(cell)[2].capitalize(), end='.')
        print(end='\n')
    print()
    for row in grid:
        for cell in row:
            print(bin(cell)[2:], end='.')
        print('\n')


if __name__ == '__main__':

    if len(argv) == 1:
        user = input("Insert Width and Height: ").strip().split()
        if len(user) == 2:
            width = int(user[0])
            height = int(user[1])
            try:
                grid_creation(width, height)
            except Exception as error:
                print(error)
        else:
            print("Exiting")
            exit(1)
