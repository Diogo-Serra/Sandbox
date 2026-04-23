try:
    from sys import argv
    from src.parser import parse
    from src.maze import Maze, ValidationError
    from src.dfs_algo import Generator
except ImportError as e:
    print(e)
    exit(1)


if __name__ == "__main__":
    print("\n=== Maze Generator ===\n")
    if len(argv) == 2:

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
            grid = generator.generate()
            generator.export(grid)
            print(f"Maze generated in hex format -> {maze.OUTPUT_FILE}")
        except ValidationError as ve:
            error = ve.errors()
            print(error[0]['msg'])
        except ValueError as ve:
            print(ve)
    else:
        print("Maze generator takes a config.txt file")
