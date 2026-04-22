
def parse(argv: str) -> dict[str, int | float | str]:
    settings: dict[str, int | float | str] = {}
    try:
        with open("config.txt", "r") as f:
            settings_file = f.read().split('\n')
            for setting in settings_file:
                if "=" not in setting:
                    raise ValueError(f"{setting} missing '='")
                else:
                    key, value = setting.split('=')
                    settings[key] = value
            settings['ENTRY'] = tuple(settings['ENTRY'].split(','))
            settings['EXIT'] = tuple(settings['EXIT'].split(','))
        return settings
    except Exception:
        raise Exception("Error opening file")
