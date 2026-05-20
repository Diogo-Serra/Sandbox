#!/usr/bin/python3
from sys import argv, exit

coordinates = {
    'NORTH': 0x1,
    'EAST': 0x2,
    'SOUTH': 0x4,
    'WEST': 0x8}

if len(argv) == 1:
    user = input("Insert Width and Height: \n").strip().split()
    if len(user) == 2:
        width = int(user[0])
        height = int(user[1])
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
    else:
        print("Exiting")
        exit(1)
