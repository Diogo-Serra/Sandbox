#!/usr/bin/python3
from sys import argv, exit


if len(argv) == 1:
    user = input("Insert Width and Height: \n").strip().split()
    if len(user) == 2:
        width = int(user[0])
        height = int(user[1])
        grid = [[0xF]*width for _ in range(height)]
        for row in grid:
            for cell in row:
                print(int(cell), end='')
            print(end='\n')
    else:
        print("Exiting")
        exit(1)
