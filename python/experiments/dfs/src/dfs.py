# Maze generator - DFS: Depth-field search
from random import choice


def dfs_generator() -> None:

    # (bit, dx, dy, bit-mirror)
    DIRECTIONS = [
        (0, 0, -1, 2),  # North
        (1, +1, 0, 3),  # East
        (2, 0, +1, 0),  # South
        (3, -1, 0, 1),  # West
    ]

    width, height = 20, 10
    grid = [[0xF] * height for _ in range(width)]

    print()
    for y in range(height):
        for x in range(width):
            print(format(grid[x][y], 'X'), end='')
        print()
    print()

    width = len(grid)
    height = len(grid[0])
    visited: set[tuple[int, int]] = {(0, 0)}
    stack: list[tuple[int, int]] = [(0, 0)]

    while stack:

        x, y = stack[-1]

        neighbors = []
        for bit, dx, dy, mirror in DIRECTIONS:
            nx, ny = x + dx, y + dy
            if (0 <= nx < width
                    and 0 <= ny < height
                    and (nx, ny) not in visited):
                neighbors.append((nx, ny, bit, mirror))

        if neighbors:
            nx, ny, bit, mirror = choice(neighbors)
            grid[x][y] &= ~(1 << bit)
            grid[nx][ny] &= ~(1 << mirror)
            visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            stack.pop()

    print()
    for y in range(height):
        for x in range(width):
            print(format(grid[x][y], 'X'), end='')
        print()
    print()


dfs_generator()
