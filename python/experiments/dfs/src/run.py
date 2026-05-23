from string import punctuation, ascii_letters
from sys import exit


def run(argv: list[str]) -> None:
    try:
        parser(argv)
    except (BaseException, Exception) as error:
        print(error)
        exit()


def parser(argv: list[str]) -> list[list[str]]:

    width = int(argv[1].strip(punctuation + ascii_letters))
    height = int(argv[2].strip(punctuation + ascii_letters))
    print(width, height)


def create_grid(width: int, height: int) -> list[list[str]]:
    pass
