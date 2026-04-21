from sys import argv
from src.parser import Parser, ParsingError
# python3 a_maze_ing.py config.txt

if __name__ == "__main__":
    print("\n=== Maze Generator ===\n")
    if len(argv) == 2:
        print("Validating config.txt settings\n")
        settings: Parser
        try:
            settings = Parser(argv)
            settings.parse()
            print("Settings validated and loaded")
        except ParsingError as e:
            print(e)
    else:
        print("Maze generator only takes a config.txt file")
