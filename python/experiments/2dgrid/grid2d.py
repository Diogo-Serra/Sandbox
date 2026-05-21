#!/usr/bin/python3
from sys import argv, exit
from os import system


def grid_show(px: int, py: int, grid: list[list[str]]) -> None:

    print("\nCoordinates view")
    for y, row in enumerate(grid):
        for x, col in enumerate(row):
            print(f"({x}, {y})", end='')
        print('\n', end='')

    print("\nGrid view")
    for y, row in enumerate(grid):
        for x, col in enumerate(row):
            if (px, py) == (x, y):
                print(" P ", end='')
            else:
                print(" . ", end='')
        print('\n', end='')
    print(f"\nPlayer position: ({px}, {py})")
    print()


def grid_generator(width: int, height: int) -> list[list[str]]:
    if not (0 < width < 20) or not (0 < height < 20):
        raise ValueError("Grid size must be between 0 and 20")
    else:
        return [[' . ']*width for line in range(height)]


def run(argv: list[str]) -> None:
    if argv[0].strip() != "grid2d.py":
        raise ValueError("Expected grid2d.py script name")
    width = int(argv[1].strip())
    height = int(argv[2].strip())
    grid = grid_generator(width, height)

    px, py = (0, 0)
    while True:

        system('clear')
        grid_show(px, py, grid)

        choice = input("Navigation WASD or Q to exit: ").strip()

        if choice == 'w' and 0 < py:
            py -= 1
        elif choice == 's' and py < height - 1:
            py += 1
        elif choice == 'a' and 0 < px:
            px -= 1
        elif choice == 'd' and px < width - 1:
            px += 1
        elif choice == 'q':
            break
        else:
            continue
    print("Exiting now...")


if __name__ == "__main__":

    if len(argv) == 3:
        try:
            run(argv)
        except (BaseException, Exception) as error:
            if error:
                print(error)
            print("Exiting now...")
            exit()
    else:
        print("Usage: 2dgrid.py <width> <height>")
        exit()
