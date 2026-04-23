try:
    import sys
    import time
    from sys import argv
    from src.parser import parse
    from src.dfs_algo import Generator
    from src.maze import Maze, ValidationError
except ImportError as e:
    print(e)
    exit(1)


if __name__ == "__main__":
    print("\n=== Maze Generator ===\n")
    viz_mode = len(argv) == 3 and argv[2] == "--viz"
    if len(argv) == 2 or viz_mode:

        print("Validating config.txt settings")
        file: dict[str, int | float | str] = {}
        try:
            file = parse(argv)
            print("Settings validated and loaded")
        except Exception:
            print("No config.txt found")
            exit(1)

        print("\nCreating maze with the settings file")
        try:
            maze = Maze(**file)
            print(maze)
            generator = Generator(maze)

            if viz_mode:
                sys.stdout.write("\033[?25l")
                sys.stdout.flush()

                def draw_step(current_grid: list[list[int]], current: tuple[int, int]) -> None:
                    sys.stdout.write("\033[2J\033[H")
                    sys.stdout.write("\n=== Maze Generator (building...) ===\n\n")
                    sys.stdout.write(generator.to_ascii(current_grid, current))
                    sys.stdout.write("\n")
                    sys.stdout.flush()
                    time.sleep(0.05)

                grid = generator.generate(on_step=draw_step)
                sys.stdout.write("\033[2J\033[H")
                sys.stdout.write("\n=== Maze Generator (done!) ===\n\n")
                sys.stdout.write(generator.to_ascii(grid))
                sys.stdout.write("\n\n")
                sys.stdout.write("\033[?25h")
                sys.stdout.flush()
            else:
                grid = generator.generate()

            generator.export(grid)
            print(f"Maze generated (hex format) -> {maze.OUTPUT_FILE}")
        except ValidationError as ve:
            error = ve.errors()
            print(error[0]['msg'])
        except ValueError as ve:
            print(ve)
    else:
        print("Usage: python main.py config.txt [--viz]")
