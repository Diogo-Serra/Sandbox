import random
from src.maze import Maze
from typing import Callable, List, Optional, Tuple


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

    def generate(self,
                 on_step: Optional[
                     Callable[[Grid, Tuple[int, int]], None]
                 ] = None
                 ) -> List[List[int]]:

        w = self.maze.WIDTH
        h = self.maze.HEIGHT

        grid: List[List[int]] = [
            [self.ALL_WALLS for _ in range(w)] for _ in range(h)
        ]
        visited: List[List[bool]] = [
            [False for _ in range(w)] for _ in range(h)
        ]
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
                if on_step is not None:
                    on_step(grid, (nx, ny))
            else:
                stack.pop()

        return grid

    def to_ascii(self,
                 grid: List[List[int]],
                 current: Optional[Tuple[int, int]] = None
                 ) -> str:
        w = self.maze.WIDTH
        h = self.maze.HEIGHT
        entry_x, entry_y = int(self.maze.ENTRY[0]), int(self.maze.ENTRY[1])
        exit_x, exit_y = int(self.maze.EXIT[0]), int(self.maze.EXIT[1])

        rows = h * 2 + 1
        cols = w * 2 + 1

        wall: List[List[bool]] = [[False] * cols for _ in range(rows)]

        for ry in range(0, rows, 2):
            for rx in range(cols):
                wall[ry][rx] = True
        for ry in range(1, rows, 2):
            for rx in range(0, cols, 2):
                wall[ry][rx] = True

        for y in range(h):
            for x in range(w):
                cy, cx = y * 2 + 1, x * 2 + 1
                cell = grid[y][x]
                if (cell & self.NORTH) == 0:
                    wall[cy - 1][cx] = False
                if (cell & self.SOUTH) == 0:
                    wall[cy + 1][cx] = False
                if (cell & self.WEST) == 0:
                    wall[cy][cx - 1] = False
                if (cell & self.EAST) == 0:
                    wall[cy][cx + 1] = False

        CORNER = {
            (False, False, False, False): ' ',
            (True,  False, False, False): '╵',
            (False, True,  False, False): '╷',
            (False, False, True,  False): '╴',
            (False, False, False, True): '╶',
            (True,  True,  False, False): '│',
            (False, False, True,  True): '─',
            (True,  False, True,  False): '┘',
            (True,  False, False, True): '└',
            (False, True,  True,  False): '┐',
            (False, True,  False, True): '┌',
            (True,  True,  True,  False): '┤',
            (True,  True,  False, True): '├',
            (True,  False, True,  True): '┴',
            (False, True,  True,  True): '┬',
            (True,  True,  True,  True): '┼',
        }

        canvas: List[List[str]] = [[' '] * cols for _ in range(rows)]

        for ry in range(rows):
            for rx in range(cols):
                if not wall[ry][rx]:
                    canvas[ry][rx] = ' '
                elif ry % 2 == 0 and rx % 2 == 0:
                    # Junction: pick the right box-drawing char
                    up = ry > 0 and wall[ry - 1][rx]
                    down = ry < rows - 1 and wall[ry + 1][rx]
                    left = rx > 0 and wall[ry][rx - 1]
                    right = rx < cols - 1 and wall[ry][rx + 1]
                    canvas[ry][rx] = CORNER.get((up, down, left, right), '┼')
                elif ry % 2 == 0:
                    canvas[ry][rx] = '─'   # horizontal segment
                else:
                    canvas[ry][rx] = '│'   # vertical segment

        canvas[entry_y * 2 + 1][entry_x * 2 + 1] = 'O'
        canvas[exit_y * 2 + 1][exit_x * 2 + 1] = 'X'

        if current is not None:
            x, y = current
            if (x, y) != (entry_x, entry_y) and (x, y) != (exit_x, exit_y):
                canvas[y * 2 + 1][x * 2 + 1] = '▓'

        return '\n'.join(''.join(row) for row in canvas)

    def export(self, grid: List[List[int]]) -> None:
        entry_x, entry_y = int(self.maze.ENTRY[0]), int(self.maze.ENTRY[1])
        exit_x, exit_y = int(self.maze.EXIT[0]), int(self.maze.EXIT[1])

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
