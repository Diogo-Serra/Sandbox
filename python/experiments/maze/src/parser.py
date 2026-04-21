
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

    settings: dict[str, int | float | str] = {}

    def __init__(self, args: list[str]):
        self.args = args

    def parse(self):
        with open("config.txt", "r") as f:
            settings_file = f.read().split('\n')
            for setting in settings_file:
                if "=" not in setting:
                    raise ParsingError(f"{setting} missing '='")
                else:
                    key, value = setting.split('=')
                    self.settings[key] = value
            for key in self.mandatory_settings:
                if key not in self.settings.keys():
                    raise ParsingError(f"{key} is required as setting")
