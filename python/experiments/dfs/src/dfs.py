# Maze generator - DFS

def dfs_generator(grid: list[list[int]]) -> list[list[int]]:
    from random import choice

    # (bit, dx, dy, mirror)
    DIRECTIONS = [
        (0, 0, -1, 2),  # NORTH
        (1, +1, 0, 3),  # EAST
        (2, 0, +1, 0),  # SOUTH
        (3, -1, 0, 1),  # WEST
    ]

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
                neighbors.append(nx, ny, bit, mirror)

        if neighbors:
            nx, ny, bit, mirror = choice(neighbors)
            grid[x][y] &= ~(1 << bit)
            grid[nx][ny] &= ~(1 << mirror)
            visited.add((nx, ny))
            stack.append((nx, ny))
        else:
            stack.pop()

    return grid
