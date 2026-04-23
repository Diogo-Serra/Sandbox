import sys
import time
from typing import Callable, List, Tuple


Grid = List[List[int]]
Point = Tuple[int, int]


def hide_cursor() -> None:
    sys.stdout.write("\033[?25l")
    sys.stdout.flush()


def show_cursor() -> None:
    sys.stdout.write("\033[?25h")
    sys.stdout.flush()


def clear_screen() -> None:
    sys.stdout.write("\033[2J\033[H")


def make_draw_step(
    generator,
    delay: float = 0.05,
) -> Callable[[Grid, Point], None]:
    def draw_step(current_grid: Grid, current: Point) -> None:
        clear_screen()
        sys.stdout.write("\n=== Maze Generator (building...) ===\n\n")
        sys.stdout.write(generator.to_ascii(current_grid, current))
        sys.stdout.write("\n")
        sys.stdout.flush()
        time.sleep(delay)

    return draw_step


def render_final(generator, grid: Grid) -> None:
    clear_screen()
    sys.stdout.write("\n=== Maze Generator (done!) ===\n\n")
    sys.stdout.write(generator.to_ascii(grid))
    sys.stdout.write("\n\n")
    sys.stdout.flush()
