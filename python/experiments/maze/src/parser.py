
def parse(argv: str) -> dict[str, int | float | str]:
    settings: dict[str, int | float | str] = {}
    with open("config.txt", "r") as f:
        settings_file = f.read().split('\n')
        for setting in settings_file:
            if "=" not in setting:
                raise ValueError(f"{setting} missing '='")
            else:
                key, value = setting.split('=')
                if not key or value:
                    raise ValueError(f"{setting} is incorrect")
                settings[key] = value
        settings['ENTRY'] = tuple(settings['ENTRY'].split(','))
        settings['EXIT'] = tuple(settings['EXIT'].split(','))
    return settings
