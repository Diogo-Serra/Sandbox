

def parser(argv: list[str]) -> tuple[int, int]:
    script = argv[0].strip()
    if script != 'nav.py':
        raise ValueError("Script name needs to be nav.py")
    argv = [arg.strip() for arg in argv]
    width = int(argv[1])
    height = int(argv[2])
    if not (0 < width < 20) or not (0 < height < 20):
        raise ValueError("Grid needs to be between 0 and 20 width x height")
    return (width, height)
