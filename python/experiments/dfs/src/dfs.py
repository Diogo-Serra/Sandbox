# Maze generator - DFS: Depth-field search


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

    rows = len(grid)
    cols = len(grid[0])
    visited: set[tuple[int, int]] = {(0, 0)}
    stack: list[tuple[int, int]] = [(0, 0)]

    while stack:

        r, c = stack[-1]

        


dfs_generator()
