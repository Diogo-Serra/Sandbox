import random
from src.maze import Maze
from typing import List, Tuple

class Generator:
    Grid = List[List[int]]
    NORTH = 0x8
    EAST = 0x4
    SOUTH = 0x2
    WEST = 0x1
    ALL_WALLS = NORTH | EAST | SOUTH | WEST

    def __init__(self, maze: Maze) -> None:
        self.maze = maze
        self.rng = random.Random()

    def generate(self) -> List[List[int]]:

        w = self.maze.WIDTH
        h = self.maze.HEIGHT

        grid: List[List[int]] = [[self.ALL_WALLS for _ in range(w)] for _ in range(h)]
        visited: List[List[bool]] = [[False for _ in range(w)] for _ in range(h)]
        start_x = int(self.maze.ENTRY[0])
        start_y = int(self.maze.ENTRY[1])

        stack: List[Tuple[int, int]] = [(start_x, start_y)]
        visited[start_y][start_x] = True

        while stack:
            x, y = stack[-1]
            neighbors: List[Tuple[int, int, int, int]] = []

            for dx, dy, here_wall, next_wall in (
                (0, -1, self.NORTH, self.SOUTH),
                (1, 0, self.EAST, self.WEST),
                (0, 1, self.SOUTH, self.NORTH),
                (-1, 0, self.WEST, self.EAST),
            ):
                nx, ny = x + dx, y + dy
                if 0 <= nx < w and 0 <= ny < h and not visited[ny][nx]:
                    neighbors.append((nx, ny, here_wall, next_wall))

            if neighbors:
                nx, ny, here_wall, next_wall = self.rng.choice(neighbors)
                grid[y][x] &= ~here_wall
                grid[ny][nx] &= ~next_wall
                visited[ny][nx] = True
                stack.append((nx, ny))
            else:
                stack.pop()

        return grid

    def export(self, grid: List[List[int]]) -> None:
        entry_x, entry_y = int(self.maze.ENTRY[0]), int(self.maze.ENTRY[1])
        exit_x, exit_y   = int(self.maze.EXIT[0]), int(self.maze.EXIT[1])

        with open(self.maze.OUTPUT_FILE, 'w', encoding='ascii') as f:
            for y, row in enumerate(grid):
                line = ''
                for x, cell in enumerate(row):
                    if x == entry_x and y == entry_y:
                        line += 'O'
                    elif x == exit_x and y == exit_y:
                        line += 'X'
                    else:
                        line += f"{cell:X}"
                f.write(line + '\n')
