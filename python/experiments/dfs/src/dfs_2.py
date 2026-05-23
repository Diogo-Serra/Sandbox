
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

# (bit, dr, dc, mirror_bit)
DIRECTIONS = [
    (0, -1,  0, 2),  # North
    (1,  0, +1, 3),  # East
    (2, +1,  0, 0),  # South
    (3,  0, -1, 1),  # West
]


def dfs_generator(grid: list[list[int]]) -> list[list[int]]:
    import random

    rows = len(grid)
    cols = len(grid[0])
    visited: set[tuple[int, int]] = {(0, 0)}
    stack: list[tuple[int, int]] = [(0, 0)]

    while stack:
        r, c = stack[-1]

        neighbors = []
        for bit, dr, dc, mirror_bit in DIRECTIONS:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in visited:
                neighbors.append((nr, nc, bit, mirror_bit))

        if neighbors:
            nr, nc, bit, mirror_bit = random.choice(neighbors)
            grid[r][c] &= ~(1 << bit)
            grid[nr][nc] &= ~(1 << mirror_bit)
            visited.add((nr, nc))
            stack.append((nr, nc))
        else:
            stack.pop()

    return grid
