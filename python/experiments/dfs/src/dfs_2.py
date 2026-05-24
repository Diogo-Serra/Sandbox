
"""
DFS Maze Generator

Each cell is an int where bits 0-3 represent walls:
    N=bit0,
    E=bit1,
    S=bit2,
    W=bit3.

All walls start up (0xF). The algorithm carves paths by clearing shared
walls between adjacent cells, using a stack to backtrack when no unvisited
neighbours remain.
"""

# (bit, dx, dy, mirror_bit)
DIRECTIONS = [
    (0,  0, -1, 2),  # North
    (1, +1,  0, 3),  # East
    (2,  0, +1, 0),  # South
    (3, -1,  0, 1),  # West
]


def dfs_generator(grid: list[list[int]]) -> list[list[int]]:
    import random

    width = len(grid)
    height = len(grid[0])
    visited: set[tuple[int, int]] = {(0, 0)}
    stack: list[tuple[int, int]] = [(0, 0)]

    while stack:
        x, y = stack[-1]

        neighbors = []
        for bit, dx, dy, mirror_bit in DIRECTIONS:
            nx, ny = x + dx, y + dy
            if (0 <= nx < width
                    and 0 <= ny < height
                    and (nx, ny) not in visited):
                neighbors.append((nx, ny, bit, mirror_bit))

        if neighbors:
            nx, ny, bit, mirror_bit = random.choice(neighbors)
            grid[x][y] &= ~(1 << bit)
            grid[nx][ny] &= ~(1 << mirror_bit)
            visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            stack.pop()

    return grid
