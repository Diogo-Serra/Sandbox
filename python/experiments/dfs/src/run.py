from string import punctuation, ascii_letters
from .dfs import dfs_generator
from sys import exit


def run(argv: list[str]) -> None:
    try:
        grid = parser(argv)
        show_grid_coordinates(grid)
        show_grid_hex(grid)
        print()
        maze = dfs_generator(grid)
        print(maze)
    except (BaseException, Exception) as error:
        print(f"\nError: {error}")
        exit()


def parser(argv: list[str]) -> list[list[str]]:

    width = int(argv[1].strip(punctuation + ascii_letters))
    height = int(argv[2].strip(punctuation + ascii_letters))
    grid = create_grid(width, height)
    return grid


def create_grid(width: int, height: int) -> list[list[str]]:
    return [[0xF] * width for row in range(height)]


def show_grid_coordinates(grid: list[list[str]]) -> None:
    print("\nGrid Coordinates:")
    for y, row in enumerate(grid):
        for x, col in enumerate(row):
            print(f"{x, y}", end='')
        print('\n', end='')


def show_grid_hex(grid: list[list[str]]) -> None:
    print("\nGrid Hex:")
    for y, row in enumerate(grid):
        for x, col in enumerate(row):
            print(f"{format(grid[x][y], 'X')}", end='')
        print('\n', end='')
