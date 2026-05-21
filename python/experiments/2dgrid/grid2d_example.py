#!/usr/bin/python3
from sys import argv, exit
from os import system


def clear_screen():
    system("clear")


def grid_creation(width: int, height: int):

    grid = [[0xF]*width for _ in range(height)]

    px, py = 0, 0
    while True:
        clear_screen()
        for y, row in enumerate(grid):
            for x, col in enumerate(row):
                if (x, y) == (px, py):
                    print(" P ", end='')
                else:
                    print(" . ", end='')
            print()
        print(f"\n    pos: ({px}, {py})  |  WASD to move, Q to quit\n")

        choice = input("> ").strip().lower()
        if choice == 'w' and py > 0:
            py -= 1
        elif choice == 's' and py < height - 1:
            py += 1
        elif choice == 'a' and px > 0:
            px -= 1
        elif choice == 'd' and px < width - 1:
            px += 1
        elif choice == 'q':
            break


if __name__ == '__main__':

    if len(argv) == 1:

        try:

            user = input("Insert Width and Height: ").strip().split()

            if len(user) == 2:
                width = int(user[0].strip())
                height = int(user[1].strip())
                grid_creation(width, height)
            else:
                print("Exiting\n"
                      "Usage:<int> <int>")
                exit(1)

        except (Exception, BaseException) as error:
            print(error)
            exit(1)
