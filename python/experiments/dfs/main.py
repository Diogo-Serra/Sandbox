from sys import argv
from src import run


def main() -> None:
    if len(argv) == 3:
        run(argv)
    else:
        print("Usage: dfs.py <width> <height>")


if __name__ == "__main__":
    main()
