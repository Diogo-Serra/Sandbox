from sys import argv

# python3 a_maze_ing.py config.txt


class ParsingError(Exception):
    ...


class Parser:

    mandatory_settings: list[str] = [
        "WIDTH",
        "HEIGHT",
        "ENTRY",
        "EXIT",
        "OUTPUT_FILE",
        "PERFECT"]

    def __init__(self, args: list[str]):
        self.args = args
        self.settings: dict[str, int | str | float] = {}

    def parse(self):
        with open("config.txt", "r") as f:
            settings_file = f.read().split('\n')
            for setting in settings_file:
                if "=" not in setting:
                    raise ParsingError(f"{setting} missing '='")
                else:
                    key, value = setting.split('=')
                    self.settings[key] = value

    def check_settings(self):


if __name__ == "__main__":
    print("=== Maze Generator ===")
    if len(argv) == 2:
        print("Validating config.txt settings")
        try:
            settings = Parser(argv)
            settings.parse()
            print(settings.settings)
        except ParsingError as e:
            print(e)
    else:
        print("Maze generator only takes a config.txt file")
