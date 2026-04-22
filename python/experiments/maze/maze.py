try:
    from sys import argv
    from src.parser import parse
    from src.maze import Maze, ValidationError
except ImportError:
    print("Error importing modules")
    exit(1)


if __name__ == "__main__":
    print("\n=== Maze Generator ===\n")
    if len(argv) == 2:

        print("Validating config.txt settings")
        settings: dict[str, int | float | str] = {}
        try:
            settings = parse(argv)
            print("Settings validated and loaded")
        except Exception:
            print("Error parsing arguments")
            exit(1)

        print("\nCreating Maze with settings")
        try:
            maze = Maze(**settings)
            print(maze)
        except ValidationError as ve:
            error = ve.errors()
            print(error[0]['msg'])
    else:
        print("Maze generator takes a config.txt file")
