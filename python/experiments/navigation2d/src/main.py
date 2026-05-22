from .app import run
from sys import exit


def main(argv: list[str]) -> None:
    try:
        if len(argv) == 3:
            run(argv)
        else:
            print("Usage: nav.py <width> <height>")
    except (BaseException, Exception) as error:
        if error is not None:
            print(error)
        print("Exiting now...")
        exit()
