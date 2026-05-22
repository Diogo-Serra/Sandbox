#!/usr/bin/env python3

class Grid:
    def __init__(self, width: int, height: int) -> None:
        self.width = width
        self.height = height
        self.grid: Grid = self.generate_grid()

    def generate_grid(self) -> list[list[str]]:
        return [[' . ']*self.width for line in range(self.height)]

    def show_grid(self) -> None:
        print("\nShowing grid:")
        for y, row in enumerate(self.grid):
            for x, col in enumerate(row):
                print(self.grid[x][y], end='')
            print('\n', end='')


class Player:
    def __init__(self, name: str) -> None:
        self.name = name
        self.x: int = 0
        self.y: int = 0


class Navigation:
    def __init__(self, grid: Grid, player: Player) -> None:
        self.grid = grid
        self.player = player

    def render_navigation(self) -> list[list[str]]:
        print(f"Grid info: {self.grid.width} x {self.grid.height}")
        print(f"Player pos: {self.player.x} x {self.player.y}\n")
        for y, row in enumerate(self.grid.grid):
            for x, col in enumerate(row):
                if (x, y) == (self.player.x, self.player.y):
                    print(" P ", end='')
                else:
                    print(" . ", end='')
            print('\n', end='')

    def navigate(self, flag: str) -> int:
        if flag == 'w' and self.player.y > 0:
            self.player.y -= 1
        elif flag == 's' and self.player.y < self.grid.height - 1:
            self.player.y += 1
        elif flag == 'a' and self.player.x > 0:
            self.player.x -= 1
        elif flag == 'd' and self.player.x < self.grid.width - 1:
            self.player.x += 1
        self.render_navigation()
